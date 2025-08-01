#include "Parser.h"
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_0 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '<', 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '>', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_1 = {
::Parser::Tokens::cll_COMPARE_OP, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::cll_COMPARE_OP data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::cll_COMPARE_OP>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_2 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_3 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_4 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_5 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_6 = {
	ISPA_STD::DFAAPI::CharTransition { '#', 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_7 = {
::Parser::Tokens::AUTO_5, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_5 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_5>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_8 = {
	ISPA_STD::DFAAPI::CharTransition { '$', 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_9 = {
::Parser::Tokens::AUTO_12, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_12 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_12>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_10 = {
	ISPA_STD::DFAAPI::CharTransition { '%', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 },
	ISPA_STD::DFAAPI::CharTransition { '*', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::CharTransition { '-', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_11 = {
::Parser::Tokens::cll_OP, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::cll_OP data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::cll_OP>(data);
	}
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 3> Parser::Lexer::dfa_state_12 = {
	ISPA_STD::DFAAPI::CharTransition { '%', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_19, 3, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '=', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_13 = {
::Parser::Tokens::MODULO, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		return std::any {};
	}
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_14 = {
::Parser::Tokens::cll_ASSIGNMENT_OP, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::cll_ASSIGNMENT_OP data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::cll_ASSIGNMENT_OP>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_15 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 3> Parser::Lexer::dfa_state_16 = {
	ISPA_STD::DFAAPI::CharTableTransition<::Parser::Tokens> { dfa_span_57, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTableTransition<::Parser::Tokens> { dfa_span_56, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '&', 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_17 = {
::Parser::Tokens::AUTO_23, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::AUTO_23 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_23>(data);
	}
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_18 = {
::Parser::Tokens::cll_LOGICAL_OP, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::cll_LOGICAL_OP data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::cll_LOGICAL_OP>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_19 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_20 = {
	ISPA_STD::DFAAPI::CharTransition { 'n', 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_21 = {
	ISPA_STD::DFAAPI::CharTransition { '&', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_22 = {
	ISPA_STD::DFAAPI::CharTransition { 'd', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_23 = {
::Parser::Tokens::cll_LOGICAL_AND, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		return std::any {};
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_24 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_25 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_26 = {
	ISPA_STD::DFAAPI::CharTransition { '|', 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_27 = {
::Parser::Tokens::cll_LOGICAL_OR, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		return std::any {};
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_28 = {
	ISPA_STD::DFAAPI::CharTransition { '(', 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_29 = {
::Parser::Tokens::AUTO_3, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_3 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_3>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_30 = {
	ISPA_STD::DFAAPI::CharTransition { ')', 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_31 = {
::Parser::Tokens::AUTO_4, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_4 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_4>(data);
	}
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 3> Parser::Lexer::dfa_state_32 = {
	ISPA_STD::DFAAPI::CharTransition { '*', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_19, 3, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '=', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_33 = {
::Parser::Tokens::MULTIPLE, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		return std::any {};
	}
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 14> Parser::Lexer::dfa_state_34 = {
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 9, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '-', 3, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_19, 8, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '=', 7, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_35 = {
::Parser::Tokens::AUTO_19, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::AUTO_19 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_19>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<12> Parser::Lexer::dfa_state_36 = {
	ISPA_STD::DFAAPI::CharTransition { '5', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ',', 4, false, false, true, 1, 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '.', 4, false, false, true, 1, 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<10> Parser::Lexer::dfa_state_37 = {
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<10> Parser::Lexer::dfa_state_38 = {
	ISPA_STD::DFAAPI::CharTransition { '\x00', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<10> Parser::Lexer::dfa_state_39 = {
	ISPA_STD::DFAAPI::CharTransition { '\x00', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_40 = {
::Parser::Tokens::NUMBER, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::NUMBER data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data.sign, 0, mb, dv);
		::ISPA_STD::DFAAPI::cst_group_store<Tokens>(data.main, 0, gb, dv);
		::ISPA_STD::DFAAPI::cst_group_store<Tokens>(data.dec, 1, gb, dv);
		return std::make_any<Types::NUMBER>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_41 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 7, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_42 = {
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_43 = {
	ISPA_STD::DFAAPI::CharTransition { ',', 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_44 = {
::Parser::Tokens::AUTO_1, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_1 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_1>(data);
	}
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 14> Parser::Lexer::dfa_state_45 = {
	ISPA_STD::DFAAPI::CharTransition { '-', 10, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_19, 9, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 3, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '=', 8, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_46 = {
::Parser::Tokens::AUTO_20, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::AUTO_20 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_20>(data);
	}
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_47 = {
::Parser::Tokens::AUTO_11, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::AUTO_11 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_11>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_48 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 8, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_49 = {
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, true, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '>', 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '-', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_50 = {
	ISPA_STD::DFAAPI::CharTransition { '.', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_51 = {
::Parser::Tokens::DOT, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		return std::any {};
	}
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 3> Parser::Lexer::dfa_state_52 = {
	ISPA_STD::DFAAPI::CharTransition { '/', 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_19, 5, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '=', 4, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<128> Parser::Lexer::dfa_state_53 = {
	ISPA_STD::DFAAPI::CharTransition { '\xF6', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD2', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEA', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFA', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFC', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA0', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFF', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFE', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFD', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9E', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD0', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFB', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF9', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF8', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF7', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF5', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF4', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF3', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF2', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF1', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF0', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEF', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEE', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xED', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEC', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEB', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE9', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE8', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE7', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE6', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE5', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE4', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE3', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE2', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE1', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE0', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDE', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDD', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDC', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDB', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDA', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD9', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD8', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD7', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD6', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD5', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD4', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD3', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD1', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCF', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCE', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCD', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCC', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCB', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCA', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC9', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC8', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC7', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC6', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC5', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC4', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC3', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC2', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC1', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC0', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBF', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBE', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBD', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBC', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBB', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBA', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB9', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB8', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB7', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB6', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB5', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB4', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB3', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB2', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB1', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB0', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAF', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAE', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAC', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAB', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAA', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA9', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA8', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA7', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA6', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA5', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA4', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA3', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA2', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA1', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9F', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9D', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9C', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9B', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9A', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x99', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x98', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x97', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x96', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x94', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x93', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x92', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x91', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x90', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8F', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8E', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8D', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8C', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8B', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8A', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x88', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x87', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x86', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x85', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x84', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x82', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x81', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x80', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDF', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x83', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x95', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAD', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x89', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<128> Parser::Lexer::dfa_state_54 = {
	ISPA_STD::DFAAPI::CharTransition { '\xF6', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD2', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEA', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFA', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFC', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA0', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFF', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFE', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFD', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9E', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD0', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFB', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF9', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF8', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF7', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF5', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF4', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF3', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF2', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF1', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF0', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEF', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEE', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xED', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEC', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEB', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE9', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE8', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE7', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE6', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE5', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE4', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE3', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE2', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE1', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE0', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDE', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDD', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDC', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDB', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDA', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD9', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD8', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD7', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD6', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD5', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD4', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD3', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD1', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCF', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCE', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCD', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCC', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCB', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCA', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC9', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC8', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC7', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC6', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC5', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC4', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC3', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC2', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC1', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC0', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBF', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBE', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBD', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBC', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBB', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBA', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB9', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB8', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB7', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB6', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB5', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB4', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB3', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB2', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB1', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB0', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAF', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAE', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAC', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAB', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAA', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA9', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA8', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA7', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA6', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA5', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA4', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA3', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA2', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA1', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9F', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9D', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9C', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9B', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9A', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x99', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x98', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x97', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x96', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x94', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x93', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x92', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x91', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x90', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8F', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8E', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8D', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8C', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8B', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8A', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x88', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x87', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x86', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x85', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x84', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x82', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x81', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x80', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDF', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x83', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x95', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAD', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x89', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_55 = {
::Parser::Tokens::LINEAR_COMMENT, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		return std::any {};
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_56 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 4, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_57 = {
	ISPA_STD::DFAAPI::CharTransition { '/', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_58 = {
	ISPA_STD::DFAAPI::CharTransition { '0', 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_59 = {
	ISPA_STD::DFAAPI::CharTransition { '0', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_60 = {
	ISPA_STD::DFAAPI::CharTransition { '0', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_61 = {
::Parser::Tokens::rule_BIN, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::rule_BIN data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::rule_BIN>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<22> Parser::Lexer::dfa_state_62 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 5, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<22> Parser::Lexer::dfa_state_63 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 5, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_64 = {
::Parser::Tokens::rule_HEX, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::rule_HEX data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::rule_HEX>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_65 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_66 = {
	ISPA_STD::DFAAPI::CharTransition { ':', 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_67 = {
::Parser::Tokens::AUTO_6, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_6 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_6>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_68 = {
	ISPA_STD::DFAAPI::CharTransition { ';', 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_69 = {
::Parser::Tokens::AUTO_7, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_7 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_7>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_70 = {
	ISPA_STD::DFAAPI::CharTransition { '>', 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '<', 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '=', 4, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_71 = {
::Parser::Tokens::AUTO_21, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_21 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_21>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_72 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_73 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_74 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_75 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_76 = {
	ISPA_STD::DFAAPI::CharTransition { '?', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_77 = {
::Parser::Tokens::QUESTION_MARK, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		return std::any {};
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_78 = {
	ISPA_STD::DFAAPI::CharTransition { '@', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_79 = {
::Parser::Tokens::AT, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		return std::any {};
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<53> Parser::Lexer::dfa_state_80 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 1, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_81 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_82 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_83 = {
::Parser::Tokens::ID, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::ID data;
		::ISPA_STD::DFAAPI::cst_group_store<Tokens>(data, 0, gb, dv);
		return std::make_any<Types::ID>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_84 = {
	ISPA_STD::DFAAPI::CharTransition { '[', 4, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_85 = {
::Parser::Tokens::AUTO_13, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::AUTO_13 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_13>(data);
	}
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_86 = {
::Parser::Tokens::rule_CSEQUENCE, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::rule_CSEQUENCE data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data._not, 0, mb, dv);
		::ISPA_STD::DFAAPI::cst_group_store<Tokens>(data.val, 0, gb, dv);
		return std::make_any<Types::rule_CSEQUENCE>(data);
	}
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 4> Parser::Lexer::dfa_state_87 = {
	ISPA_STD::DFAAPI::CharTransition { ']', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, 0, 0 },
	ISPA_STD::DFAAPI::CharTableTransition<::Parser::Tokens> { dfa_span_30, 3, false, false, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTableTransition<::Parser::Tokens> { dfa_span_29, 3, false, false, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_28, 3, false, false, true, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_88 = {
	ISPA_STD::DFAAPI::CharTransition { ']', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '^', 3, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> Parser::Lexer::dfa_state_89 = {
	ISPA_STD::DFAAPI::CharTableTransition<::Parser::Tokens> { dfa_span_30, 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_90 = {
::Parser::Tokens::rule_CSEQUENCE_DIAPASON, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::rule_CSEQUENCE_DIAPASON data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data.from, 0, mb, dv);
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data.to, 1, mb, dv);
		return std::make_any<Types::rule_CSEQUENCE_DIAPASON>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_91 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_92 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_93 = {
};
const ::ISPA_STD::DFAAPI::CharTableState<129> Parser::Lexer::dfa_state_94 = {
	ISPA_STD::DFAAPI::CharTransition { '\x88', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x87', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x89', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x80', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xDF', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xAD', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x83', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x85', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x82', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xE1', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xAF', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x84', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xE3', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x86', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xE4', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x81', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x8A', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x8B', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x8C', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x8D', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x8E', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x8F', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x90', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x91', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x92', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x93', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x94', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x96', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x97', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x98', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x99', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x9A', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x9B', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x9C', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x9D', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x9F', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xA1', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xA2', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xA3', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xA4', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xA5', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xA6', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xA7', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xA8', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xA9', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xAA', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xAB', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xAC', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xAE', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xB0', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xB1', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xB2', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xB3', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xB4', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xB5', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xB6', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xB7', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xB8', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xB9', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xBA', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xBB', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xBC', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xBD', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xBE', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xBF', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xC0', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xC1', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xC2', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xC3', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xC4', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xC5', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xC6', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xC7', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xC8', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xC9', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xCA', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xCB', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xCC', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xCD', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xCE', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xCF', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xD0', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xD1', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xD3', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xD4', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xD5', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xD6', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xD7', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xD8', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xD9', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xDA', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xDB', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xDC', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xDD', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xDE', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xE0', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xE2', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xE5', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xE6', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xE7', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xE8', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xE9', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xEB', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xEC', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xED', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xEE', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xEF', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xF0', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xF1', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xF2', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xF3', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xF4', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xF5', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xF8', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x95', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\xF9', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xFA', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xFB', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\x9E', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xFD', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xFE', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xFC', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xF6', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xEA', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xD2', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xA0', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xFF', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\xF7', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_95 = {
::Parser::Tokens::rule_CSEQUENCE_SYMBOL, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::rule_CSEQUENCE_SYMBOL data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::rule_CSEQUENCE_SYMBOL>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_96 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_97 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_98 = {
	ISPA_STD::DFAAPI::CharTransition { '0', 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_99 = {
::Parser::Tokens::rule_NOSPACE, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		return std::any {};
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<129> Parser::Lexer::dfa_state_100 = {
	ISPA_STD::DFAAPI::CharTransition { '\xFF', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD2', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEA', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF6', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFC', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFE', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFD', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9E', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD0', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFB', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9C', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xFA', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF9', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF8', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF7', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF5', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF4', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF3', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF2', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF1', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xF0', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEF', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEE', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xED', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEC', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xEB', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE9', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE8', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE7', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE6', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE5', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE4', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE2', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE0', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDE', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDD', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDC', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDB', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDA', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD9', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD8', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD7', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD6', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD5', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD4', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD3', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xD1', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCF', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCE', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCD', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCC', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCB', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xCA', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC9', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC8', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC7', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC6', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC5', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC4', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC3', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC2', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC1', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xC0', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBF', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBE', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBD', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBC', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBB', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xBA', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB9', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB8', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB7', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB6', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB5', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB4', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB3', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB2', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB1', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xB0', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAF', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAE', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAC', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAB', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAA', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA9', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA8', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA7', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA6', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA5', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA4', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA3', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA2', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA1', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9F', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9D', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9B', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x95', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\\', 8, true, true, true, 1, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x9A', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x99', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x98', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x97', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x96', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x94', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x93', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x92', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x91', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x90', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8F', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8E', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8D', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8C', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8A', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x88', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x86', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x85', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE3', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x84', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x81', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x80', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xDF', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x83', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xAD', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x89', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xE1', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x82', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x8B', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x87', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\xA0', 4, false, false, true, 1, 0, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_101 = {
::Parser::Tokens::STRING, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::STRING data;
		::ISPA_STD::DFAAPI::cst_group_store<Tokens>(data, 0, gb, dv);
		return std::make_any<Types::STRING>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_102 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\'', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_103 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_104 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\'', 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_105 = {
	ISPA_STD::DFAAPI::CharTransition { ']', 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_106 = {
::Parser::Tokens::AUTO_14, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_14 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_14>(data);
	}
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 59> Parser::Lexer::dfa_state_107 = {
	ISPA_STD::DFAAPI::CharTableTransition<::Parser::Tokens> { dfa_span_57, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 1, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTableTransition<::Parser::Tokens> { dfa_span_56, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 20, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 19, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_108 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_109 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_110 = {
::Parser::Tokens::ID, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::ID data;
		::ISPA_STD::DFAAPI::cst_group_store<Tokens>(data, 0, gb, dv);
		return std::make_any<Types::ID>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_111 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_112 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_113 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_114 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_115 = {
	ISPA_STD::DFAAPI::CharTransition { 'j', 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_116 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_117 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_118 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_119 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_120 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> Parser::Lexer::dfa_state_121 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_50, 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_122 = {
::Parser::Tokens::cll_TYPE, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::cll_TYPE data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data.type, 0, mb, dv);
		return std::make_any<Types::cll_TYPE>(data);
	}
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> Parser::Lexer::dfa_state_123 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_50, 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_124 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_125 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 't', 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_126 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_127 = {
	ISPA_STD::DFAAPI::CharTransition { '<', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> Parser::Lexer::dfa_state_128 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_48, 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_129 = {
::Parser::Tokens::cll_TEMPLATE, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::cll_TEMPLATE data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data.first, 0, mb, dv);
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data.second, 1, mb, dv);
		return std::make_any<Types::cll_TEMPLATE>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<57> Parser::Lexer::dfa_state_130 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 1, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 19, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 18, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<55> Parser::Lexer::dfa_state_131 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 17, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 4, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 14, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 14, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_132 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_133 = {
::Parser::Tokens::AUTO_17, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_17 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_17>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_134 = {
::Parser::Tokens::AUTO_16, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_16 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_16>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_135 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_136 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_137 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_138 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_139 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_140 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_141 = {
::Parser::Tokens::BOOLEAN, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::BOOLEAN data;
		::ISPA_STD::DFAAPI::cst_group_store<Tokens>(data, 0, gb, dv);
		return std::make_any<Types::BOOLEAN>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_142 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_143 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_144 = {
::Parser::Tokens::AUTO_9, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_9 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_9>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_145 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 15, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 15, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_146 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 15, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_147 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'r', 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<53> Parser::Lexer::dfa_state_148 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 10, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 7, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_149 = {
	ISPA_STD::DFAAPI::CharTransition { 'p', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_150 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_151 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_152 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_153 = {
::Parser::Tokens::AUTO_22, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_22 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_22>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_154 = {
::Parser::Tokens::AUTO_15, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_15 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_15>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_155 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 8, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 8, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_156 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 8, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_157 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 8, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<53> Parser::Lexer::dfa_state_158 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 6, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_159 = {
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_160 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_161 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_162 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_163 = {
::Parser::Tokens::AUTO_10, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_10 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_10>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_164 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 7, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_165 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 7, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_166 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 7, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<57> Parser::Lexer::dfa_state_167 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 1, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 23, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 22, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_168 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_169 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> Parser::Lexer::dfa_state_170 = {
	ISPA_STD::DFAAPI::CharTableTransition<::Parser::Tokens> { dfa_span_53, 7, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_171 = {
	ISPA_STD::DFAAPI::CharTransition { ';', 8, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_172 = {
::Parser::Tokens::NAME, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::NAME data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::NAME>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_173 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_174 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_175 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_176 = {
	ISPA_STD::DFAAPI::CharTransition { 'j', 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_177 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_178 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_179 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_180 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_181 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> Parser::Lexer::dfa_state_182 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_50, 19, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> Parser::Lexer::dfa_state_183 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_50, 19, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_184 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_185 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 't', 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_186 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_187 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<53> Parser::Lexer::dfa_state_188 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 1, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_189 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 2, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_190 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<57> Parser::Lexer::dfa_state_191 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 31, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 33, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 1, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 45, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 44, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_192 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_193 = {
	ISPA_STD::DFAAPI::CharTransition { 'c', 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_194 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_195 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_196 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_197 = {
	ISPA_STD::DFAAPI::CharTransition { 'd', 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_198 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_199 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 12, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 13, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 14, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_200 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_201 = {
	ISPA_STD::DFAAPI::CharTransition { 'k', 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_202 = {
	ISPA_STD::DFAAPI::CharTransition { 'i', 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_203 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_204 = {
	ISPA_STD::DFAAPI::CharTransition { 'i', 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_205 = {
	ISPA_STD::DFAAPI::CharTransition { 'x', 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_206 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_207 = {
	ISPA_STD::DFAAPI::CharTransition { 'p', 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_208 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_209 = {
	ISPA_STD::DFAAPI::CharTransition { 'w', 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_210 = {
	ISPA_STD::DFAAPI::CharTransition { 'p', 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_211 = {
	ISPA_STD::DFAAPI::CharTransition { 'd', 26, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_212 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_213 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_214 = {
	ISPA_STD::DFAAPI::CharTransition { ';', 29, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_215 = {
::Parser::Tokens::SPACEMODE, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		Types::SPACEMODE data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::SPACEMODE>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_216 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 35, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_217 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 36, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_218 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_219 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 39, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_220 = {
	ISPA_STD::DFAAPI::CharTransition { 'j', 40, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_221 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 41, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_222 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 42, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_223 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 41, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_224 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 43, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_225 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 41, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> Parser::Lexer::dfa_state_226 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_50, 41, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> Parser::Lexer::dfa_state_227 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_50, 41, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_228 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 41, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_229 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 't', 37, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_230 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 2, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 34, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<55> Parser::Lexer::dfa_state_231 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 1, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 2, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 9, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 9, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_232 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_233 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_234 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_235 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_236 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_237 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_238 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 10, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 10, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_239 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 10, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<53> Parser::Lexer::dfa_state_240 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 3, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 3, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_241 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_242 = {
::Parser::Tokens::AUTO_8, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_8 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_8>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_243 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 4, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 4, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_244 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 4, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_245 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 4, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<53> Parser::Lexer::dfa_state_246 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 5, false, false, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 8, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 5, true, true, false, 0, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_247 = {
	ISPA_STD::DFAAPI::CharTransition { 'i', 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_248 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_249 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_250 = {
::Parser::Tokens::AUTO_18, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_18 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_18>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_251 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 6, true, true, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 6, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_252 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\x00', 6, true, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_253 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 6, false, false, true, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_254 = {
	ISPA_STD::DFAAPI::CharTransition { '{', 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_255 = {
::Parser::Tokens::AUTO_0, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_0 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_0>(data);
	}
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 3> Parser::Lexer::dfa_state_256 = {
	ISPA_STD::DFAAPI::CharTableTransition<::Parser::Tokens> { dfa_span_57, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::CharTableTransition<::Parser::Tokens> { dfa_span_56, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::CharTransition { '|', 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_257 = {
::Parser::Tokens::rule_OP, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::MultiTableDataVector<::Parser::Tokens> &dv)
	{
		return std::any {};
	}
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_258 = {
	ISPA_STD::DFAAPI::CharTransition { '}', 1, true, true, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> Parser::Lexer::dfa_state_259 = {
::Parser::Tokens::AUTO_2, [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::CharTableDataVector &dv)
	{
		Types::AUTO_2 data;
		::ISPA_STD::DFAAPI::cst_store<Tokens>(data, 0, mb, dv);
		return std::make_any<Types::AUTO_2>(data);
	}
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 6> Parser::Lexer::dfa_table_0 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_0.data(), dfa_state_0.size()}},
	dfa_state_1,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_2.data(), dfa_state_2.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_3.data(), dfa_state_3.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 2, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 3, {dfa_state_5.data(), dfa_state_5.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_1 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_6.data(), dfa_state_6.size()}},
	dfa_state_7,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_2 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_8.data(), dfa_state_8.size()}},
	dfa_state_9,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_3 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_10.data(), dfa_state_10.size()}},
	dfa_state_11,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 4> Parser::Lexer::dfa_table_4 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_12.data(), dfa_state_12.size()}},
	dfa_state_13,
	dfa_state_14,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 2, 0, {dfa_state_15.data(), dfa_state_15.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_5 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_16.data(), dfa_state_16.size()}},
	dfa_state_17,
	dfa_state_18,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 5> Parser::Lexer::dfa_table_6 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_19.data(), dfa_state_19.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_20.data(), dfa_state_20.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 4, 0, {dfa_state_21.data(), dfa_state_21.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 4, 0, {dfa_state_22.data(), dfa_state_22.size()}},
	dfa_state_23,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> Parser::Lexer::dfa_table_7 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_24.data(), dfa_state_24.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_25.data(), dfa_state_25.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_26.data(), dfa_state_26.size()}},
	dfa_state_27,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_8 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_28.data(), dfa_state_28.size()}},
	dfa_state_29,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_9 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_30.data(), dfa_state_30.size()}},
	dfa_state_31,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_10 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_10.data(), dfa_state_10.size()}},
	dfa_state_11,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 4> Parser::Lexer::dfa_table_11 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_32.data(), dfa_state_32.size()}},
	dfa_state_33,
	dfa_state_14,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 2, 0, {dfa_state_15.data(), dfa_state_15.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_12 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_10.data(), dfa_state_10.size()}},
	dfa_state_11,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 10> Parser::Lexer::dfa_table_13 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_34.data(), dfa_state_34.size()}},
	dfa_state_35,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 6, 0, {dfa_state_36.data(), dfa_state_36.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 6, 0, {dfa_state_37.data(), dfa_state_37.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 6, 0, {dfa_state_38.data(), dfa_state_38.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 8, 0, {dfa_state_39.data(), dfa_state_39.size()}},
	dfa_state_40,
	dfa_state_14,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 7, 0, {dfa_state_41.data(), dfa_state_41.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_42.data(), dfa_state_42.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_14 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_43.data(), dfa_state_43.size()}},
	dfa_state_44,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_15 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_10.data(), dfa_state_10.size()}},
	dfa_state_11,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 11> Parser::Lexer::dfa_table_16 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_45.data(), dfa_state_45.size()}},
	dfa_state_46,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 6, 0, {dfa_state_36.data(), dfa_state_36.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 6, 0, {dfa_state_37.data(), dfa_state_37.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 6, 0, {dfa_state_38.data(), dfa_state_38.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 8, 0, {dfa_state_39.data(), dfa_state_39.size()}},
	dfa_state_40,
	dfa_state_47,
	dfa_state_14,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 8, 0, {dfa_state_48.data(), dfa_state_48.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_49.data(), dfa_state_49.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_17 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_50.data(), dfa_state_50.size()}},
	dfa_state_51,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_18 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_10.data(), dfa_state_10.size()}},
	dfa_state_11,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 7> Parser::Lexer::dfa_table_19 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_53.data(), dfa_state_53.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 4, 0, {dfa_state_54.data(), dfa_state_54.size()}},
	dfa_state_55,
	dfa_state_14,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 4, 0, {dfa_state_56.data(), dfa_state_56.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_57.data(), dfa_state_57.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 8> Parser::Lexer::dfa_table_20 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_58.data(), dfa_state_58.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_59.data(), dfa_state_59.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 4, 0, {dfa_state_60.data(), dfa_state_60.size()}},
	dfa_state_61,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 6, 0, {dfa_state_62.data(), dfa_state_62.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 9, 0, {dfa_state_63.data(), dfa_state_63.size()}},
	dfa_state_64,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_65.data(), dfa_state_65.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_21 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_66.data(), dfa_state_66.size()}},
	dfa_state_67,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_22 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_68.data(), dfa_state_68.size()}},
	dfa_state_69,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 7> Parser::Lexer::dfa_table_23 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_70.data(), dfa_state_70.size()}},
	dfa_state_71,
	dfa_state_1,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 2, 0, {dfa_state_72.data(), dfa_state_72.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_73.data(), dfa_state_73.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 6, 3, {dfa_state_74.data(), dfa_state_74.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 6, 2, {dfa_state_75.data(), dfa_state_75.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_24 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_76.data(), dfa_state_76.size()}},
	dfa_state_77,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_25 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_78.data(), dfa_state_78.size()}},
	dfa_state_79,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> Parser::Lexer::dfa_table_26 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_80.data(), dfa_state_80.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_81.data(), dfa_state_81.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_82.data(), dfa_state_82.size()}},
	dfa_state_83,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 5> Parser::Lexer::dfa_table_27 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_84.data(), dfa_state_84.size()}},
	dfa_state_85,
	dfa_state_86,
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 2, 0, {dfa_state_87.data(), dfa_state_87.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_88.data(), dfa_state_88.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_28 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_89.data(), dfa_state_89.size()}},
	dfa_state_90,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_29 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_91.data(), dfa_state_91.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 2, 0, {dfa_state_92.data(), dfa_state_92.size()}},
	dfa_state_93,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_30 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_94.data(), dfa_state_94.size()}},
	dfa_state_95,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_96.data(), dfa_state_96.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 9> Parser::Lexer::dfa_table_31 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_97.data(), dfa_state_97.size()}},
	dfa_state_93,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_98.data(), dfa_state_98.size()}},
	dfa_state_99,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_100.data(), dfa_state_100.size()}},
	dfa_state_101,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_102.data(), dfa_state_102.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_103.data(), dfa_state_103.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_104.data(), dfa_state_104.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_32 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_105.data(), dfa_state_105.size()}},
	dfa_state_106,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 21> Parser::Lexer::dfa_table_33 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 3, 0, {dfa_state_107.data(), dfa_state_107.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_108.data(), dfa_state_108.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_109.data(), dfa_state_109.size()}},
	dfa_state_110,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_111.data(), dfa_state_111.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_112.data(), dfa_state_112.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_113.data(), dfa_state_113.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_114.data(), dfa_state_114.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_115.data(), dfa_state_115.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 15, 0, {dfa_state_116.data(), dfa_state_116.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_117.data(), dfa_state_117.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 15, 0, {dfa_state_118.data(), dfa_state_118.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_119.data(), dfa_state_119.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 15, 0, {dfa_state_120.data(), dfa_state_120.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 15, 0, {dfa_state_121.data(), dfa_state_121.size()}},
	dfa_state_122,
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 15, 0, {dfa_state_123.data(), dfa_state_123.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 15, 0, {dfa_state_124.data(), dfa_state_124.size()}},
	dfa_state_18,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_125.data(), dfa_state_125.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_126.data(), dfa_state_126.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_34 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	dfa_state_129,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_35 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	dfa_state_129,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 5> Parser::Lexer::dfa_table_36 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_19.data(), dfa_state_19.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_20.data(), dfa_state_20.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 4, 0, {dfa_state_21.data(), dfa_state_21.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 4, 0, {dfa_state_22.data(), dfa_state_22.size()}},
	dfa_state_23,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> Parser::Lexer::dfa_table_37 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_24.data(), dfa_state_24.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_25.data(), dfa_state_25.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_26.data(), dfa_state_26.size()}},
	dfa_state_27,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 20> Parser::Lexer::dfa_table_38 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_130.data(), dfa_state_130.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_108.data(), dfa_state_108.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_109.data(), dfa_state_109.size()}},
	dfa_state_110,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_111.data(), dfa_state_111.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_112.data(), dfa_state_112.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_113.data(), dfa_state_113.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_114.data(), dfa_state_114.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_115.data(), dfa_state_115.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 15, 0, {dfa_state_116.data(), dfa_state_116.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_117.data(), dfa_state_117.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 15, 0, {dfa_state_118.data(), dfa_state_118.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_119.data(), dfa_state_119.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 15, 0, {dfa_state_120.data(), dfa_state_120.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 15, 0, {dfa_state_121.data(), dfa_state_121.size()}},
	dfa_state_122,
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 15, 0, {dfa_state_123.data(), dfa_state_123.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 15, 0, {dfa_state_124.data(), dfa_state_124.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_125.data(), dfa_state_125.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_126.data(), dfa_state_126.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_39 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	dfa_state_129,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_40 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	dfa_state_129,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 18> Parser::Lexer::dfa_table_41 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_131.data(), dfa_state_131.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 2, 0, {dfa_state_132.data(), dfa_state_132.size()}},
	dfa_state_133,
	dfa_state_134,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_135.data(), dfa_state_135.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_136.data(), dfa_state_136.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_137.data(), dfa_state_137.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_138.data(), dfa_state_138.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 10, 0, {dfa_state_139.data(), dfa_state_139.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 10, 0, {dfa_state_140.data(), dfa_state_140.size()}},
	dfa_state_141,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_142.data(), dfa_state_142.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 13, 0, {dfa_state_143.data(), dfa_state_143.size()}},
	dfa_state_144,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 16, 0, {dfa_state_145.data(), dfa_state_145.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 14, 0, {dfa_state_146.data(), dfa_state_146.size()}},
	dfa_state_83,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_147.data(), dfa_state_147.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 11> Parser::Lexer::dfa_table_42 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_148.data(), dfa_state_148.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_149.data(), dfa_state_149.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_150.data(), dfa_state_150.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 5, 0, {dfa_state_152.data(), dfa_state_152.size()}},
	dfa_state_153,
	dfa_state_154,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 9, 0, {dfa_state_155.data(), dfa_state_155.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 9, 0, {dfa_state_156.data(), dfa_state_156.size()}},
	dfa_state_83,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_157.data(), dfa_state_157.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 10> Parser::Lexer::dfa_table_43 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_158.data(), dfa_state_158.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_159.data(), dfa_state_159.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_160.data(), dfa_state_160.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_161.data(), dfa_state_161.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 5, 0, {dfa_state_162.data(), dfa_state_162.size()}},
	dfa_state_163,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 8, 0, {dfa_state_164.data(), dfa_state_164.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 10, 0, {dfa_state_165.data(), dfa_state_165.size()}},
	dfa_state_83,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_166.data(), dfa_state_166.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 25> Parser::Lexer::dfa_table_44 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_167.data(), dfa_state_167.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_108.data(), dfa_state_108.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_109.data(), dfa_state_109.size()}},
	dfa_state_110,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_168.data(), dfa_state_168.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_169.data(), dfa_state_169.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_170.data(), dfa_state_170.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 8, 0, {dfa_state_171.data(), dfa_state_171.size()}},
	dfa_state_172,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_173.data(), dfa_state_173.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_174.data(), dfa_state_174.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_175.data(), dfa_state_175.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_176.data(), dfa_state_176.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 19, 0, {dfa_state_177.data(), dfa_state_177.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_178.data(), dfa_state_178.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 19, 0, {dfa_state_179.data(), dfa_state_179.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_180.data(), dfa_state_180.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 19, 0, {dfa_state_181.data(), dfa_state_181.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 19, 0, {dfa_state_182.data(), dfa_state_182.size()}},
	dfa_state_122,
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 19, 0, {dfa_state_183.data(), dfa_state_183.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 19, 0, {dfa_state_184.data(), dfa_state_184.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_185.data(), dfa_state_185.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_186.data(), dfa_state_186.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_187.data(), dfa_state_187.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> Parser::Lexer::dfa_table_45 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_188.data(), dfa_state_188.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_189.data(), dfa_state_189.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_190.data(), dfa_state_190.size()}},
	dfa_state_83,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_46 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	dfa_state_129,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_47 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	dfa_state_129,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 46> Parser::Lexer::dfa_table_48 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_191.data(), dfa_state_191.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_108.data(), dfa_state_108.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_109.data(), dfa_state_109.size()}},
	dfa_state_110,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_192.data(), dfa_state_192.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_193.data(), dfa_state_193.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_194.data(), dfa_state_194.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_195.data(), dfa_state_195.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_196.data(), dfa_state_196.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_197.data(), dfa_state_197.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_198.data(), dfa_state_198.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_199.data(), dfa_state_199.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_200.data(), dfa_state_200.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_201.data(), dfa_state_201.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_202.data(), dfa_state_202.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_203.data(), dfa_state_203.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_204.data(), dfa_state_204.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_205.data(), dfa_state_205.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_206.data(), dfa_state_206.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_207.data(), dfa_state_207.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_208.data(), dfa_state_208.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_209.data(), dfa_state_209.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_210.data(), dfa_state_210.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_211.data(), dfa_state_211.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_212.data(), dfa_state_212.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_213.data(), dfa_state_213.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 29, 0, {dfa_state_214.data(), dfa_state_214.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_211.data(), dfa_state_211.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_211.data(), dfa_state_211.size()}},
	dfa_state_215,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_216.data(), dfa_state_216.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_217.data(), dfa_state_217.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_218.data(), dfa_state_218.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_219.data(), dfa_state_219.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_220.data(), dfa_state_220.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 41, 0, {dfa_state_221.data(), dfa_state_221.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_222.data(), dfa_state_222.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 41, 0, {dfa_state_223.data(), dfa_state_223.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_224.data(), dfa_state_224.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 41, 0, {dfa_state_225.data(), dfa_state_225.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 41, 0, {dfa_state_226.data(), dfa_state_226.size()}},
	dfa_state_122,
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 41, 0, {dfa_state_227.data(), dfa_state_227.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 41, 0, {dfa_state_228.data(), dfa_state_228.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_229.data(), dfa_state_229.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_230.data(), dfa_state_230.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_49 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	dfa_state_129,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_50 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	dfa_state_129,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 12> Parser::Lexer::dfa_table_51 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_231.data(), dfa_state_231.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_232.data(), dfa_state_232.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_233.data(), dfa_state_233.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_234.data(), dfa_state_234.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_235.data(), dfa_state_235.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 8, 0, {dfa_state_236.data(), dfa_state_236.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 8, 0, {dfa_state_237.data(), dfa_state_237.size()}},
	dfa_state_141,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 11, 0, {dfa_state_238.data(), dfa_state_238.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 12, 0, {dfa_state_239.data(), dfa_state_239.size()}},
	dfa_state_83,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 7> Parser::Lexer::dfa_table_52 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_240.data(), dfa_state_240.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 2, 0, {dfa_state_241.data(), dfa_state_241.size()}},
	dfa_state_242,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 5, 0, {dfa_state_243.data(), dfa_state_243.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 7, 0, {dfa_state_244.data(), dfa_state_244.size()}},
	dfa_state_83,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_245.data(), dfa_state_245.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 9> Parser::Lexer::dfa_table_53 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_246.data(), dfa_state_246.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_247.data(), dfa_state_247.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_248.data(), dfa_state_248.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 4, 0, {dfa_state_249.data(), dfa_state_249.size()}},
	dfa_state_250,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 7, 0, {dfa_state_251.data(), dfa_state_251.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 9, 0, {dfa_state_252.data(), dfa_state_252.size()}},
	dfa_state_83,
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_253.data(), dfa_state_253.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_54 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_254.data(), dfa_state_254.size()}},
	dfa_state_255,
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_55 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_256.data(), dfa_state_256.size()}},
	dfa_state_257,
	dfa_state_18,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 5> Parser::Lexer::dfa_table_56 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_19.data(), dfa_state_19.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_20.data(), dfa_state_20.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 4, 0, {dfa_state_21.data(), dfa_state_21.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 4, 0, {dfa_state_22.data(), dfa_state_22.size()}},
	dfa_state_23,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> Parser::Lexer::dfa_table_57 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_24.data(), dfa_state_24.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_25.data(), dfa_state_25.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 3, 0, {dfa_state_26.data(), dfa_state_26.size()}},
	dfa_state_27,
};
const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> Parser::Lexer::dfa_table_58 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, 1, 0, {dfa_state_258.data(), dfa_state_258.size()}},
	dfa_state_259,
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_0 = {
	dfa_table_0.data(), dfa_table_0.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_1 = {
	dfa_table_1.data(), dfa_table_1.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_2 = {
	dfa_table_2.data(), dfa_table_2.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_3 = {
	dfa_table_3.data(), dfa_table_3.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_4 = {
	{ 	dfa_table_4.data(), dfa_table_4.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_5 = {
	{ 	dfa_table_5.data(), dfa_table_5.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_6 = {
	dfa_table_6.data(), dfa_table_6.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_7 = {
	dfa_table_7.data(), dfa_table_7.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_8 = {
	dfa_table_8.data(), dfa_table_8.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_9 = {
	dfa_table_9.data(), dfa_table_9.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_10 = {
	dfa_table_10.data(), dfa_table_10.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_11 = {
	{ 	dfa_table_11.data(), dfa_table_11.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_12 = {
	dfa_table_12.data(), dfa_table_12.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_13 = {
	{ 	dfa_table_13.data(), dfa_table_13.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_14 = {
	dfa_table_14.data(), dfa_table_14.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_15 = {
	dfa_table_15.data(), dfa_table_15.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_16 = {
	{ 	dfa_table_16.data(), dfa_table_16.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_17 = {
	dfa_table_17.data(), dfa_table_17.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_18 = {
	dfa_table_18.data(), dfa_table_18.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_19 = {
	{ 	dfa_table_19.data(), dfa_table_19.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_20 = {
	dfa_table_20.data(), dfa_table_20.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_21 = {
	dfa_table_21.data(), dfa_table_21.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_22 = {
	dfa_table_22.data(), dfa_table_22.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_23 = {
	dfa_table_23.data(), dfa_table_23.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_24 = {
	dfa_table_24.data(), dfa_table_24.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_25 = {
	dfa_table_25.data(), dfa_table_25.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_26 = {
	dfa_table_26.data(), dfa_table_26.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_27 = {
	{ 	dfa_table_27.data(), dfa_table_27.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_28 = {
	{ 	dfa_table_28.data(), dfa_table_28.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_29 = {
	dfa_table_29.data(), dfa_table_29.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_30 = {
	dfa_table_30.data(), dfa_table_30.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_31 = {
	dfa_table_31.data(), dfa_table_31.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_32 = {
	dfa_table_32.data(), dfa_table_32.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_33 = {
	{ 	dfa_table_33.data(), dfa_table_33.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_34 = {
	{ 	dfa_table_34.data(), dfa_table_34.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_35 = {
	{ 	dfa_table_35.data(), dfa_table_35.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_36 = {
	dfa_table_36.data(), dfa_table_36.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_37 = {
	dfa_table_37.data(), dfa_table_37.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_38 = {
	{ 	dfa_table_38.data(), dfa_table_38.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_39 = {
	{ 	dfa_table_39.data(), dfa_table_39.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_40 = {
	{ 	dfa_table_40.data(), dfa_table_40.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_41 = {
	dfa_table_41.data(), dfa_table_41.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_42 = {
	dfa_table_42.data(), dfa_table_42.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_43 = {
	dfa_table_43.data(), dfa_table_43.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_44 = {
	{ 	dfa_table_44.data(), dfa_table_44.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_45 = {
	dfa_table_45.data(), dfa_table_45.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_46 = {
	{ 	dfa_table_46.data(), dfa_table_46.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_47 = {
	{ 	dfa_table_47.data(), dfa_table_47.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_48 = {
	{ 	dfa_table_48.data(), dfa_table_48.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_49 = {
	{ 	dfa_table_49.data(), dfa_table_49.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_50 = {
	{ 	dfa_table_50.data(), dfa_table_50.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_51 = {
	dfa_table_51.data(), dfa_table_51.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_52 = {
	dfa_table_52.data(), dfa_table_52.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_53 = {
	dfa_table_53.data(), dfa_table_53.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_54 = {
	dfa_table_54.data(), dfa_table_54.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_55 = {
	{ 	dfa_table_55.data(), dfa_table_55.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_56 = {
	dfa_table_56.data(), dfa_table_56.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_57 = {
	dfa_table_57.data(), dfa_table_57.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> Parser::Lexer::dfa_span_58 = {
	dfa_table_58.data(), dfa_table_58.size()
};
const ISPA_STD::fcdt_table<::Parser::Tokens> Parser::Lexer::first_character_dispatch_table = {
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x00'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x01'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x02'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x03'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x04'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x05'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x06'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\a'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\b'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\t'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\n'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\v'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\f'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\r'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x0E'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x0F'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x10'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x11'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x12'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x13'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x14'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x15'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x16'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x17'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x18'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x19'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x1A'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x1B'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x1C'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x1D'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x1E'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x1F'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ' '
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_0, }, // '!'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\"'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_1, }, // '#'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_2, }, // '$'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_3, }, // '%'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_5, }, // '&'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_8, }, // '('
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_9, }, // ')'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_10, }, // '*'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_12, }, // '+'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_14, }, // ','
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_15, }, // '-'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_17, }, // '.'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_18, }, // '/'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_20, }, // '0'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '1'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '2'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '3'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '4'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '5'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '6'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '7'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '8'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '9'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_21, }, // ':'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // ';'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_0, }, // '<'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_23, }, // '='
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_0, }, // '>'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_24, }, // '?'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_25, }, // '@'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'A'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'B'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'C'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'D'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'E'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'F'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'G'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'H'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'I'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'J'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'K'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'L'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'M'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'N'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'O'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'P'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'Q'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'R'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'S'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'T'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'U'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'V'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'W'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'X'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'Y'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'Z'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_27, }, // '['
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_31, }, // '\\'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_32, }, // ']'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '^'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // '_'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '`'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_33, }, // 'a'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_38, }, // 'b'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'c'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'd'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'e'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_41, }, // 'f'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'g'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'h'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_42, }, // 'i'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'j'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'k'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'l'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_43, }, // 'm'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_44, }, // 'n'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_33, }, // 'o'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'p'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'q'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'r'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_48, }, // 's'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_51, }, // 't'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_52, }, // 'u'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_38, }, // 'v'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_53, }, // 'w'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'x'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'y'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'z'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_54, }, // '{'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_55, }, // '|'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_58, }, // '}'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '~'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x7F'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x80'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x81'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x82'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x83'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x84'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x85'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x86'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x87'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x88'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x89'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x8A'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x8B'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x8C'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x8D'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x8E'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x8F'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x90'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x91'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x92'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x93'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x94'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x95'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x96'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x97'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x98'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x99'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x9A'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x9B'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x9C'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x9D'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x9E'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\x9F'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xA0'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xA1'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xA2'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xA3'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xA4'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xA5'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xA6'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xA7'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xA8'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xA9'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xAA'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xAB'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xAC'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xAD'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xAE'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xAF'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xB0'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xB1'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xB2'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xB3'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xB4'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xB5'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xB6'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xB7'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xB8'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xB9'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xBA'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xBB'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xBC'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xBD'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xBE'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xBF'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xC0'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xC1'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xC2'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xC3'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xC4'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xC5'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xC6'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xC7'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xC8'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xC9'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xCA'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xCB'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xCC'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xCD'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xCE'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xCF'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xD0'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xD1'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xD2'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xD3'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xD4'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xD5'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xD6'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xD7'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xD8'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xD9'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xDA'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xDB'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xDC'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xDD'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xDE'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xDF'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xE0'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xE1'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xE2'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xE3'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xE4'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xE5'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xE6'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xE7'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xE8'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xE9'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xEA'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xEB'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xEC'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xED'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xEE'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xEF'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xF0'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xF1'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xF2'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xF3'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xF4'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xF5'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xF6'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xF7'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xF8'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xF9'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xFA'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xFB'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xFC'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xFD'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xFE'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\xFF'
};
auto ::Parser::Lexer::makeToken(const char* &pos) -> Token {
	fcdt_lookup(first_character_dispatch_table, pos);
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
void ::Parser::Parser::printAST(std::ostream &os) {
	size_t indentLevel = 0;
	printRule(os, tree, indentLevel, false);
}
void ::Parser::Parser::printRule(std::ostream &os, const ::Parser::Token &token, std::size_t &indentLevel, bool addSpaceOnBegin) {
	Lexer::printToken(os, token);
}
void ::Parser::Parser::printRule(std::ostream &os, const ::Parser::Rule &rule, std::size_t &indentLevel, bool addSpaceOnBegin) {
	printRule(os, rule.data(), indentLevel, addSpaceOnBegin);
}
void ::Parser::Parser::printRule(std::ostream &os, const std::any &data, std::size_t &indentLevel, bool addSpaceOnBegin) {
	using Token = ::Parser::Token;
	using Rule = ::Parser::Rule;

	if (addSpaceOnBegin) os << std::string(indentLevel, '\t');

if (data.type() == typeid(str_t)) {
        os << '"' << std::any_cast<str_t>(data) << '"';
    } else if (data.type() == typeid(num_t)) {
        os << std::any_cast<num_t>(data);
    } else if (data.type() == typeid(bool_t)) {
        os << std::boolalpha << std::any_cast<bool_t>(data);
    } else if (data.type() == typeid(Token)) {
        os << std::string(indentLevel, '\t');
        Lexer::printToken(os, std::any_cast<Token>(data));
    } else if (data.type() == typeid(arr_t<Token>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<Token>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t');
            Lexer::printToken(os, *it);
        }
        os << std::string(--indentLevel, '\t') << "]";
    } else if (data.type() == typeid(Rule)) {
        os << "{\n";
        indentLevel++;
        printRule(os, std::any_cast<Rule>(data), indentLevel, true);
        os << std::string(--indentLevel, '\t') << "}";
    } else if (data.type() == typeid(arr_t<Rule>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<Rule>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            printRule(os, *it, indentLevel, true);
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(arr_t<str_t>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<str_t>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t') << '"' << *it << '"';
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(arr_t<num_t>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<num_t>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t') << *it;
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(arr_t<bool_t>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<bool_t>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t') << std::boolalpha << *it;
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(std::any)) {
        printRule(os, std::any_cast<const std::any&>(data), indentLevel, addSpaceOnBegin);
    } else if (data.type() == typeid(arr_t<std::any>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<const arr_t<std::any>&>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            printRule(os, *it, indentLevel, true);
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    }	else if (data.type() == typeid(Types::rule_data_block_regular_datablock_key)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule_data_block_regular_datablock_key>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "dt"<< ": ";
		printRule(os, dt.dt, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_function_call)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_function_call>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "body"<< ": ";
		printRule(os, dt.body, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_function_decl)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_function_decl>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "stmt"<< ": ";
		printRule(os, dt.stmt, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "type"<< ": ";
		printRule(os, dt.type, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_expr_term)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_expr_term>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "sequence"<< ": ";
		printRule(os, dt.sequence, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "operators"<< ": ";
		printRule(os, dt.operators, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_expr_logical)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_expr_logical>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "right"<< ": ";
		printRule(os, dt.right, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "op"<< ": ";
		printRule(os, dt.op, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "left"<< ": ";
		printRule(os, dt.left, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll__var)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll__var>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "value"<< ": ";
		printRule(os, dt.value, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "op"<< ": ";
		printRule(os, dt.op, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "id"<< ": ";
		printRule(os, dt.id, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "type"<< ": ";
		printRule(os, dt.type, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_loop_while)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_loop_while>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "stmt"<< ": ";
		printRule(os, dt.stmt, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "expr"<< ": ";
		printRule(os, dt.expr, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_loop_for)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_loop_for>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "stmt"<< ": ";
		printRule(os, dt.stmt, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "cond"<< ": ";
		printRule(os, dt.cond, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "end"<< ": ";
		printRule(os, dt.end, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "decl"<< ": ";
		printRule(os, dt.decl, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll__variable)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll__variable>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "pos"<< ": ";
		printRule(os, dt.pos, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "brace_expression"<< ": ";
		printRule(os, dt.brace_expression, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "pre"<< ": ";
		printRule(os, dt.pre, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::_use_unit)) {
		os << "{\n";
		auto dt = std::any_cast<Types::_use_unit>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "value"<< ": ";
		printRule(os, dt.value, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::moduleImport_from_import_list)) {
		os << "{\n";
		auto dt = std::any_cast<Types::moduleImport_from_import_list>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "sequence"<< ": ";
		printRule(os, dt.sequence, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::_use)) {
		os << "{\n";
		auto dt = std::any_cast<Types::_use>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "second"<< ": ";
		printRule(os, dt.second, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_expr_arithmetic)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_expr_arithmetic>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "sequence"<< ": ";
		printRule(os, dt.sequence, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "operators"<< ": ";
		printRule(os, dt.operators, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::rule)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "nested_rules"<< ": ";
		printRule(os, dt.nested_rules, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "rule"<< ": ";
		printRule(os, dt.rule, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "data_block"<< ": ";
		printRule(os, dt.data_block, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::rule_member)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule_member>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "val"<< ": ";
		printRule(os, dt.val, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "quantifier"<< ": ";
		printRule(os, dt.quantifier, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "prefix"<< ": ";
		printRule(os, dt.prefix, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::rule_data_block_templated_datablock)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule_data_block_templated_datablock>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "second_name"<< ": ";
		printRule(os, dt.second_name, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first_name"<< ": ";
		printRule(os, dt.first_name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::rule_name)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule_name>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "nested_name"<< ": ";
		printRule(os, dt.nested_name, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "is_nested"<< ": ";
		printRule(os, dt.is_nested, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::moduleDeclaration)) {
		os << "{\n";
		auto dt = std::any_cast<Types::moduleDeclaration>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "base"<< ": ";
		printRule(os, dt.base, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll__if)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll__if>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "stmt"<< ": ";
		printRule(os, dt.stmt, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "expr"<< ": ";
		printRule(os, dt.expr, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::moduleImport_from)) {
		os << "{\n";
		auto dt = std::any_cast<Types::moduleImport_from>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "from"<< ": ";
		printRule(os, dt.from, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "what"<< ": ";
		printRule(os, dt.what, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::object)) {
		os << "{\n";
		auto dt = std::any_cast<Types::object>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "values"<< ": ";
		printRule(os, dt.values, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "keys"<< ": ";
		printRule(os, dt.keys, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "value"<< ": ";
		printRule(os, dt.value, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "key"<< ": ";
		printRule(os, dt.key, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_expr_compare)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_expr_compare>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "sequence"<< ": ";
		printRule(os, dt.sequence, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "operators"<< ": ";
		printRule(os, dt.operators, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_method_call)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_method_call>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "body"<< ": ";
		printRule(os, dt.body, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_function_arguments)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_function_arguments>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "second"<< ": ";
		printRule(os, dt.second, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_function_parameters)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_function_parameters>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "second"<< ": ";
		printRule(os, dt.second, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
else os << "<UNDEF TYPE>";
}Parser::Rule_res Parser::Parser::getRule(Lexer::lazy_iterator &pos) {
        return main(pos);
    }
Parser::Rule_res Parser::Parser::getRule(Lexer::iterator &pos) {
        return main(pos);
    }
void ::Parser::Parser::parseFromTokens() {
        auto pos = Lexer::iterator(lexer);
        parseFromPos(pos);
    }
void ::Parser::Parser::lazyParse() {
        auto pos = Lexer::lazy_iterator(lexer, text);
        parseFromPos(pos);
    }
const ::Parser::Types::AUTO_4& Parser::get::AUTO_4(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_4) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_4, "Parser");
	return std::any_cast<const Types::AUTO_4&>(token.data());
}
::Parser::Types::AUTO_4& Parser::get::AUTO_4(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_4) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_4, "Parser");
	return std::any_cast<Types::AUTO_4&>(token.data());
}
const ::Parser::Types::cll_TYPE& Parser::get::cll_TYPE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TYPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TYPE, "Parser");
	return std::any_cast<const Types::cll_TYPE&>(token.data());
}
::Parser::Types::cll_TYPE& Parser::get::cll_TYPE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TYPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TYPE, "Parser");
	return std::any_cast<Types::cll_TYPE&>(token.data());
}
const ::Parser::Types::NAME& Parser::get::NAME(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NAME) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NAME, "Parser");
	return std::any_cast<const Types::NAME&>(token.data());
}
::Parser::Types::NAME& Parser::get::NAME(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NAME) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NAME, "Parser");
	return std::any_cast<Types::NAME&>(token.data());
}
const ::Parser::Types::AUTO_2& Parser::get::AUTO_2(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_2) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_2, "Parser");
	return std::any_cast<const Types::AUTO_2&>(token.data());
}
::Parser::Types::AUTO_2& Parser::get::AUTO_2(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_2) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_2, "Parser");
	return std::any_cast<Types::AUTO_2&>(token.data());
}
const ::Parser::Types::cll_COMPARE_OP& Parser::get::cll_COMPARE_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_COMPARE_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_COMPARE_OP, "Parser");
	return std::any_cast<const Types::cll_COMPARE_OP&>(token.data());
}
::Parser::Types::cll_COMPARE_OP& Parser::get::cll_COMPARE_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_COMPARE_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_COMPARE_OP, "Parser");
	return std::any_cast<Types::cll_COMPARE_OP&>(token.data());
}
const ::Parser::Types::AUTO_11& Parser::get::AUTO_11(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_11) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_11, "Parser");
	return std::any_cast<const Types::AUTO_11&>(token.data());
}
::Parser::Types::AUTO_11& Parser::get::AUTO_11(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_11) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_11, "Parser");
	return std::any_cast<Types::AUTO_11&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_DIAPASON& Parser::get::rule_CSEQUENCE_DIAPASON(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_DIAPASON) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_DIAPASON, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_DIAPASON&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_DIAPASON& Parser::get::rule_CSEQUENCE_DIAPASON(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_DIAPASON) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_DIAPASON, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_DIAPASON&>(token.data());
}
const ::Parser::Types::cll_OP& Parser::get::cll_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_OP, "Parser");
	return std::any_cast<const Types::cll_OP&>(token.data());
}
::Parser::Types::cll_OP& Parser::get::cll_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_OP, "Parser");
	return std::any_cast<Types::cll_OP&>(token.data());
}
const ::Parser::Types::AUTO_9& Parser::get::AUTO_9(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_9) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_9, "Parser");
	return std::any_cast<const Types::AUTO_9&>(token.data());
}
::Parser::Types::AUTO_9& Parser::get::AUTO_9(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_9) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_9, "Parser");
	return std::any_cast<Types::AUTO_9&>(token.data());
}
const ::Parser::Types::AUTO_0& Parser::get::AUTO_0(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_0) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_0, "Parser");
	return std::any_cast<const Types::AUTO_0&>(token.data());
}
::Parser::Types::AUTO_0& Parser::get::AUTO_0(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_0) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_0, "Parser");
	return std::any_cast<Types::AUTO_0&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE& Parser::get::rule_CSEQUENCE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE&>(token.data());
}
::Parser::Types::rule_CSEQUENCE& Parser::get::rule_CSEQUENCE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE&>(token.data());
}
const ::Parser::Types::NUMBER& Parser::get::NUMBER(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NUMBER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NUMBER, "Parser");
	return std::any_cast<const Types::NUMBER&>(token.data());
}
::Parser::Types::NUMBER& Parser::get::NUMBER(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NUMBER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NUMBER, "Parser");
	return std::any_cast<Types::NUMBER&>(token.data());
}
const ::Parser::Types::cll_LOGICAL_OP& Parser::get::cll_LOGICAL_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OP, "Parser");
	return std::any_cast<const Types::cll_LOGICAL_OP&>(token.data());
}
::Parser::Types::cll_LOGICAL_OP& Parser::get::cll_LOGICAL_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OP, "Parser");
	return std::any_cast<Types::cll_LOGICAL_OP&>(token.data());
}
const ::Parser::Types::AUTO_3& Parser::get::AUTO_3(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_3) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_3, "Parser");
	return std::any_cast<const Types::AUTO_3&>(token.data());
}
::Parser::Types::AUTO_3& Parser::get::AUTO_3(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_3) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_3, "Parser");
	return std::any_cast<Types::AUTO_3&>(token.data());
}
const ::Parser::Types::AUTO_13& Parser::get::AUTO_13(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_13) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_13, "Parser");
	return std::any_cast<const Types::AUTO_13&>(token.data());
}
::Parser::Types::AUTO_13& Parser::get::AUTO_13(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_13) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_13, "Parser");
	return std::any_cast<Types::AUTO_13&>(token.data());
}
const ::Parser::Types::AUTO_18& Parser::get::AUTO_18(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_18) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_18, "Parser");
	return std::any_cast<const Types::AUTO_18&>(token.data());
}
::Parser::Types::AUTO_18& Parser::get::AUTO_18(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_18) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_18, "Parser");
	return std::any_cast<Types::AUTO_18&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_ESCAPE& Parser::get::rule_CSEQUENCE_ESCAPE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_ESCAPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_ESCAPE, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_ESCAPE&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_ESCAPE& Parser::get::rule_CSEQUENCE_ESCAPE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_ESCAPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_ESCAPE, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_ESCAPE&>(token.data());
}
const ::Parser::Types::AUTO_1& Parser::get::AUTO_1(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_1) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_1, "Parser");
	return std::any_cast<const Types::AUTO_1&>(token.data());
}
::Parser::Types::AUTO_1& Parser::get::AUTO_1(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_1) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_1, "Parser");
	return std::any_cast<Types::AUTO_1&>(token.data());
}
const ::Parser::Types::SPACEMODE& Parser::get::SPACEMODE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::SPACEMODE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::SPACEMODE, "Parser");
	return std::any_cast<const Types::SPACEMODE&>(token.data());
}
::Parser::Types::SPACEMODE& Parser::get::SPACEMODE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::SPACEMODE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::SPACEMODE, "Parser");
	return std::any_cast<Types::SPACEMODE&>(token.data());
}
const ::Parser::Types::AUTO_7& Parser::get::AUTO_7(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_7) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_7, "Parser");
	return std::any_cast<const Types::AUTO_7&>(token.data());
}
::Parser::Types::AUTO_7& Parser::get::AUTO_7(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_7) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_7, "Parser");
	return std::any_cast<Types::AUTO_7&>(token.data());
}
const ::Parser::Types::BOOLEAN& Parser::get::BOOLEAN(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::BOOLEAN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::BOOLEAN, "Parser");
	return std::any_cast<const Types::BOOLEAN&>(token.data());
}
::Parser::Types::BOOLEAN& Parser::get::BOOLEAN(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::BOOLEAN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::BOOLEAN, "Parser");
	return std::any_cast<Types::BOOLEAN&>(token.data());
}
const ::Parser::Types::rule_BIN& Parser::get::rule_BIN(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_BIN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_BIN, "Parser");
	return std::any_cast<const Types::rule_BIN&>(token.data());
}
::Parser::Types::rule_BIN& Parser::get::rule_BIN(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_BIN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_BIN, "Parser");
	return std::any_cast<Types::rule_BIN&>(token.data());
}
const ::Parser::Types::AUTO_10& Parser::get::AUTO_10(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_10) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_10, "Parser");
	return std::any_cast<const Types::AUTO_10&>(token.data());
}
::Parser::Types::AUTO_10& Parser::get::AUTO_10(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_10) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_10, "Parser");
	return std::any_cast<Types::AUTO_10&>(token.data());
}
const ::Parser::Types::rule_HEX& Parser::get::rule_HEX(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_HEX) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_HEX, "Parser");
	return std::any_cast<const Types::rule_HEX&>(token.data());
}
::Parser::Types::rule_HEX& Parser::get::rule_HEX(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_HEX) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_HEX, "Parser");
	return std::any_cast<Types::rule_HEX&>(token.data());
}
const ::Parser::Types::AUTO_19& Parser::get::AUTO_19(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_19) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_19, "Parser");
	return std::any_cast<const Types::AUTO_19&>(token.data());
}
::Parser::Types::AUTO_19& Parser::get::AUTO_19(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_19) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_19, "Parser");
	return std::any_cast<Types::AUTO_19&>(token.data());
}
const ::Parser::Types::AUTO_16& Parser::get::AUTO_16(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_16) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_16, "Parser");
	return std::any_cast<const Types::AUTO_16&>(token.data());
}
::Parser::Types::AUTO_16& Parser::get::AUTO_16(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_16) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_16, "Parser");
	return std::any_cast<Types::AUTO_16&>(token.data());
}
const ::Parser::Types::cll_TEMPLATE& Parser::get::cll_TEMPLATE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TEMPLATE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TEMPLATE, "Parser");
	return std::any_cast<const Types::cll_TEMPLATE&>(token.data());
}
::Parser::Types::cll_TEMPLATE& Parser::get::cll_TEMPLATE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TEMPLATE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TEMPLATE, "Parser");
	return std::any_cast<Types::cll_TEMPLATE&>(token.data());
}
const ::Parser::Types::AUTO_12& Parser::get::AUTO_12(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_12) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_12, "Parser");
	return std::any_cast<const Types::AUTO_12&>(token.data());
}
::Parser::Types::AUTO_12& Parser::get::AUTO_12(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_12) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_12, "Parser");
	return std::any_cast<Types::AUTO_12&>(token.data());
}
const ::Parser::Types::AUTO_15& Parser::get::AUTO_15(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_15) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_15, "Parser");
	return std::any_cast<const Types::AUTO_15&>(token.data());
}
::Parser::Types::AUTO_15& Parser::get::AUTO_15(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_15) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_15, "Parser");
	return std::any_cast<Types::AUTO_15&>(token.data());
}
const ::Parser::Types::AUTO_14& Parser::get::AUTO_14(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_14) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_14, "Parser");
	return std::any_cast<const Types::AUTO_14&>(token.data());
}
::Parser::Types::AUTO_14& Parser::get::AUTO_14(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_14) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_14, "Parser");
	return std::any_cast<Types::AUTO_14&>(token.data());
}
const ::Parser::Types::AUTO_17& Parser::get::AUTO_17(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_17) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_17, "Parser");
	return std::any_cast<const Types::AUTO_17&>(token.data());
}
::Parser::Types::AUTO_17& Parser::get::AUTO_17(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_17) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_17, "Parser");
	return std::any_cast<Types::AUTO_17&>(token.data());
}
const ::Parser::Types::rule_ESCAPED& Parser::get::rule_ESCAPED(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_ESCAPED) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_ESCAPED, "Parser");
	return std::any_cast<const Types::rule_ESCAPED&>(token.data());
}
::Parser::Types::rule_ESCAPED& Parser::get::rule_ESCAPED(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_ESCAPED) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_ESCAPED, "Parser");
	return std::any_cast<Types::rule_ESCAPED&>(token.data());
}
const ::Parser::Types::AUTO_5& Parser::get::AUTO_5(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_5) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_5, "Parser");
	return std::any_cast<const Types::AUTO_5&>(token.data());
}
::Parser::Types::AUTO_5& Parser::get::AUTO_5(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_5) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_5, "Parser");
	return std::any_cast<Types::AUTO_5&>(token.data());
}
const ::Parser::Types::cll_ASSIGNMENT_OP& Parser::get::cll_ASSIGNMENT_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_ASSIGNMENT_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_ASSIGNMENT_OP, "Parser");
	return std::any_cast<const Types::cll_ASSIGNMENT_OP&>(token.data());
}
::Parser::Types::cll_ASSIGNMENT_OP& Parser::get::cll_ASSIGNMENT_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_ASSIGNMENT_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_ASSIGNMENT_OP, "Parser");
	return std::any_cast<Types::cll_ASSIGNMENT_OP&>(token.data());
}
const ::Parser::Types::AUTO_20& Parser::get::AUTO_20(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_20) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_20, "Parser");
	return std::any_cast<const Types::AUTO_20&>(token.data());
}
::Parser::Types::AUTO_20& Parser::get::AUTO_20(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_20) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_20, "Parser");
	return std::any_cast<Types::AUTO_20&>(token.data());
}
const ::Parser::Types::AUTO_8& Parser::get::AUTO_8(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_8) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_8, "Parser");
	return std::any_cast<const Types::AUTO_8&>(token.data());
}
::Parser::Types::AUTO_8& Parser::get::AUTO_8(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_8) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_8, "Parser");
	return std::any_cast<Types::AUTO_8&>(token.data());
}
const ::Parser::Types::AUTO_21& Parser::get::AUTO_21(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_21) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_21, "Parser");
	return std::any_cast<const Types::AUTO_21&>(token.data());
}
::Parser::Types::AUTO_21& Parser::get::AUTO_21(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_21) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_21, "Parser");
	return std::any_cast<Types::AUTO_21&>(token.data());
}
const ::Parser::Types::STRING& Parser::get::STRING(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::STRING) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::STRING, "Parser");
	return std::any_cast<const Types::STRING&>(token.data());
}
::Parser::Types::STRING& Parser::get::STRING(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::STRING) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::STRING, "Parser");
	return std::any_cast<Types::STRING&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_SYMBOL& Parser::get::rule_CSEQUENCE_SYMBOL(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_SYMBOL) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_SYMBOL, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_SYMBOL&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_SYMBOL& Parser::get::rule_CSEQUENCE_SYMBOL(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_SYMBOL) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_SYMBOL, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_SYMBOL&>(token.data());
}
const ::Parser::Types::AUTO_23& Parser::get::AUTO_23(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_23) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_23, "Parser");
	return std::any_cast<const Types::AUTO_23&>(token.data());
}
::Parser::Types::AUTO_23& Parser::get::AUTO_23(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_23) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_23, "Parser");
	return std::any_cast<Types::AUTO_23&>(token.data());
}
const ::Parser::Types::ID& Parser::get::ID(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::ID) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::ID, "Parser");
	return std::any_cast<const Types::ID&>(token.data());
}
::Parser::Types::ID& Parser::get::ID(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::ID) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::ID, "Parser");
	return std::any_cast<Types::ID&>(token.data());
}
const ::Parser::Types::AUTO_22& Parser::get::AUTO_22(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_22) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_22, "Parser");
	return std::any_cast<const Types::AUTO_22&>(token.data());
}
::Parser::Types::AUTO_22& Parser::get::AUTO_22(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_22) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_22, "Parser");
	return std::any_cast<Types::AUTO_22&>(token.data());
}
const ::Parser::Types::AUTO_6& Parser::get::AUTO_6(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_6) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_6, "Parser");
	return std::any_cast<const Types::AUTO_6&>(token.data());
}
::Parser::Types::AUTO_6& Parser::get::AUTO_6(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_6) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_6, "Parser");
	return std::any_cast<Types::AUTO_6&>(token.data());
}
const ::Parser::Types::cll_function_parameters& Parser::get::cll_function_parameters(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_parameters) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_parameters, "Parser");
	return std::any_cast<const Types::cll_function_parameters&>(rule.data());
}
::Parser::Types::cll_function_parameters& Parser::get::cll_function_parameters(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_parameters) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_parameters, "Parser");
	return std::any_cast<Types::cll_function_parameters&>(rule.data());
}
const ::Parser::Types::rule_keyvalue& Parser::get::rule_keyvalue(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_keyvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_keyvalue, "Parser");
	return std::any_cast<const Types::rule_keyvalue&>(rule.data());
}
::Parser::Types::rule_keyvalue& Parser::get::rule_keyvalue(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_keyvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_keyvalue, "Parser");
	return std::any_cast<Types::rule_keyvalue&>(rule.data());
}
const ::Parser::Types::cll_function_arguments& Parser::get::cll_function_arguments(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_arguments) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_arguments, "Parser");
	return std::any_cast<const Types::cll_function_arguments&>(rule.data());
}
::Parser::Types::cll_function_arguments& Parser::get::cll_function_arguments(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_arguments) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_arguments, "Parser");
	return std::any_cast<Types::cll_function_arguments&>(rule.data());
}
const ::Parser::Types::cll_method_call& Parser::get::cll_method_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_method_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_method_call, "Parser");
	return std::any_cast<const Types::cll_method_call&>(rule.data());
}
::Parser::Types::cll_method_call& Parser::get::cll_method_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_method_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_method_call, "Parser");
	return std::any_cast<Types::cll_method_call&>(rule.data());
}
const ::Parser::Types::cll_expr_compare& Parser::get::cll_expr_compare(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_compare) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_compare, "Parser");
	return std::any_cast<const Types::cll_expr_compare&>(rule.data());
}
::Parser::Types::cll_expr_compare& Parser::get::cll_expr_compare(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_compare) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_compare, "Parser");
	return std::any_cast<Types::cll_expr_compare&>(rule.data());
}
const ::Parser::Types::cll_stmt& Parser::get::cll_stmt(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_stmt) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_stmt, "Parser");
	return std::any_cast<const Types::cll_stmt&>(rule.data());
}
::Parser::Types::cll_stmt& Parser::get::cll_stmt(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_stmt) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_stmt, "Parser");
	return std::any_cast<Types::cll_stmt&>(rule.data());
}
const ::Parser::Types::object& Parser::get::object(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::object) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::object, "Parser");
	return std::any_cast<const Types::object&>(rule.data());
}
::Parser::Types::object& Parser::get::object(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::object) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::object, "Parser");
	return std::any_cast<Types::object&>(rule.data());
}
const ::Parser::Types::rule_value& Parser::get::rule_value(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_value, "Parser");
	return std::any_cast<const Types::rule_value&>(rule.data());
}
::Parser::Types::rule_value& Parser::get::rule_value(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_value, "Parser");
	return std::any_cast<Types::rule_value&>(rule.data());
}
const ::Parser::Types::moduleImport_from& Parser::get::moduleImport_from(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport_from) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport_from, "Parser");
	return std::any_cast<const Types::moduleImport_from&>(rule.data());
}
::Parser::Types::moduleImport_from& Parser::get::moduleImport_from(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport_from) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport_from, "Parser");
	return std::any_cast<Types::moduleImport_from&>(rule.data());
}
const ::Parser::Types::rule_quantifier& Parser::get::rule_quantifier(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_quantifier) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_quantifier, "Parser");
	return std::any_cast<const Types::rule_quantifier&>(rule.data());
}
::Parser::Types::rule_quantifier& Parser::get::rule_quantifier(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_quantifier) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_quantifier, "Parser");
	return std::any_cast<Types::rule_quantifier&>(rule.data());
}
const ::Parser::Types::cll__if& Parser::get::cll__if(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__if) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__if, "Parser");
	return std::any_cast<const Types::cll__if&>(rule.data());
}
::Parser::Types::cll__if& Parser::get::cll__if(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__if) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__if, "Parser");
	return std::any_cast<Types::cll__if&>(rule.data());
}
const ::Parser::Types::moduleDeclaration& Parser::get::moduleDeclaration(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleDeclaration) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleDeclaration, "Parser");
	return std::any_cast<const Types::moduleDeclaration&>(rule.data());
}
::Parser::Types::moduleDeclaration& Parser::get::moduleDeclaration(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleDeclaration) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleDeclaration, "Parser");
	return std::any_cast<Types::moduleDeclaration&>(rule.data());
}
const ::Parser::Types::cll& Parser::get::cll(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll, "Parser");
	return std::any_cast<const Types::cll&>(rule.data());
}
::Parser::Types::cll& Parser::get::cll(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll, "Parser");
	return std::any_cast<Types::cll&>(rule.data());
}
const ::Parser::Types::cll_expr_group& Parser::get::cll_expr_group(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_group, "Parser");
	return std::any_cast<const Types::cll_expr_group&>(rule.data());
}
::Parser::Types::cll_expr_group& Parser::get::cll_expr_group(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_group, "Parser");
	return std::any_cast<Types::cll_expr_group&>(rule.data());
}
const ::Parser::Types::moduleImport& Parser::get::moduleImport(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport, "Parser");
	return std::any_cast<const Types::moduleImport&>(rule.data());
}
::Parser::Types::moduleImport& Parser::get::moduleImport(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport, "Parser");
	return std::any_cast<Types::moduleImport&>(rule.data());
}
const ::Parser::Types::rule_data_block_regular_datablock& Parser::get::rule_data_block_regular_datablock(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock, "Parser");
	return std::any_cast<const Types::rule_data_block_regular_datablock&>(rule.data());
}
::Parser::Types::rule_data_block_regular_datablock& Parser::get::rule_data_block_regular_datablock(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock, "Parser");
	return std::any_cast<Types::rule_data_block_regular_datablock&>(rule.data());
}
const ::Parser::Types::rule_name& Parser::get::rule_name(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_name) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_name, "Parser");
	return std::any_cast<const Types::rule_name&>(rule.data());
}
::Parser::Types::rule_name& Parser::get::rule_name(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_name) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_name, "Parser");
	return std::any_cast<Types::rule_name&>(rule.data());
}
const ::Parser::Types::cll_function_body_decl& Parser::get::cll_function_body_decl(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_decl, "Parser");
	return std::any_cast<const Types::cll_function_body_decl&>(rule.data());
}
::Parser::Types::cll_function_body_decl& Parser::get::cll_function_body_decl(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_decl, "Parser");
	return std::any_cast<Types::cll_function_body_decl&>(rule.data());
}
const ::Parser::Types::cll_expr_value& Parser::get::cll_expr_value(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_value, "Parser");
	return std::any_cast<const Types::cll_expr_value&>(rule.data());
}
::Parser::Types::cll_expr_value& Parser::get::cll_expr_value(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_value, "Parser");
	return std::any_cast<Types::cll_expr_value&>(rule.data());
}
const ::Parser::Types::rule_group& Parser::get::rule_group(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_group, "Parser");
	return std::any_cast<const Types::rule_group&>(rule.data());
}
::Parser::Types::rule_group& Parser::get::rule_group(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_group, "Parser");
	return std::any_cast<Types::rule_group&>(rule.data());
}
const ::Parser::Types::rule_data_block_templated_datablock& Parser::get::rule_data_block_templated_datablock(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_templated_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_templated_datablock, "Parser");
	return std::any_cast<const Types::rule_data_block_templated_datablock&>(rule.data());
}
::Parser::Types::rule_data_block_templated_datablock& Parser::get::rule_data_block_templated_datablock(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_templated_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_templated_datablock, "Parser");
	return std::any_cast<Types::rule_data_block_templated_datablock&>(rule.data());
}
const ::Parser::Types::rule_member& Parser::get::rule_member(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_member) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_member, "Parser");
	return std::any_cast<const Types::rule_member&>(rule.data());
}
::Parser::Types::rule_member& Parser::get::rule_member(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_member) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_member, "Parser");
	return std::any_cast<Types::rule_member&>(rule.data());
}
const ::Parser::Types::array& Parser::get::array(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::array) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::array, "Parser");
	return std::any_cast<const Types::array&>(rule.data());
}
::Parser::Types::array& Parser::get::array(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::array) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::array, "Parser");
	return std::any_cast<Types::array&>(rule.data());
}
const ::Parser::Types::main& Parser::get::main(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::main) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::main, "Parser");
	return std::any_cast<const Types::main&>(rule.data());
}
::Parser::Types::main& Parser::get::main(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::main) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::main, "Parser");
	return std::any_cast<Types::main&>(rule.data());
}
const ::Parser::Types::rule& Parser::get::rule(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule, "Parser");
	return std::any_cast<const Types::rule&>(rule.data());
}
::Parser::Types::rule& Parser::get::rule(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule, "Parser");
	return std::any_cast<Types::rule&>(rule.data());
}
const ::Parser::Types::cll_expr_arithmetic& Parser::get::cll_expr_arithmetic(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_arithmetic) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_arithmetic, "Parser");
	return std::any_cast<const Types::cll_expr_arithmetic&>(rule.data());
}
::Parser::Types::cll_expr_arithmetic& Parser::get::cll_expr_arithmetic(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_arithmetic) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_arithmetic, "Parser");
	return std::any_cast<Types::cll_expr_arithmetic&>(rule.data());
}
const ::Parser::Types::_use& Parser::get::_use(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use, "Parser");
	return std::any_cast<const Types::_use&>(rule.data());
}
::Parser::Types::_use& Parser::get::_use(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use, "Parser");
	return std::any_cast<Types::_use&>(rule.data());
}
const ::Parser::Types::moduleImport_from_import_list& Parser::get::moduleImport_from_import_list(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport_from_import_list) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport_from_import_list, "Parser");
	return std::any_cast<const Types::moduleImport_from_import_list&>(rule.data());
}
::Parser::Types::moduleImport_from_import_list& Parser::get::moduleImport_from_import_list(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport_from_import_list) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport_from_import_list, "Parser");
	return std::any_cast<Types::moduleImport_from_import_list&>(rule.data());
}
const ::Parser::Types::_use_unit& Parser::get::_use_unit(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use_unit) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use_unit, "Parser");
	return std::any_cast<const Types::_use_unit&>(rule.data());
}
::Parser::Types::_use_unit& Parser::get::_use_unit(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use_unit) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use_unit, "Parser");
	return std::any_cast<Types::_use_unit&>(rule.data());
}
const ::Parser::Types::rvalue& Parser::get::rvalue(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rvalue, "Parser");
	return std::any_cast<const Types::rvalue&>(rule.data());
}
::Parser::Types::rvalue& Parser::get::rvalue(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rvalue, "Parser");
	return std::any_cast<Types::rvalue&>(rule.data());
}
const ::Parser::Types::rule_nested_rule& Parser::get::rule_nested_rule(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_nested_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_nested_rule, "Parser");
	return std::any_cast<const Types::rule_nested_rule&>(rule.data());
}
::Parser::Types::rule_nested_rule& Parser::get::rule_nested_rule(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_nested_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_nested_rule, "Parser");
	return std::any_cast<Types::rule_nested_rule&>(rule.data());
}
const ::Parser::Types::cll__variable& Parser::get::cll__variable(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__variable) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__variable, "Parser");
	return std::any_cast<const Types::cll__variable&>(rule.data());
}
::Parser::Types::cll__variable& Parser::get::cll__variable(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__variable) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__variable, "Parser");
	return std::any_cast<Types::cll__variable&>(rule.data());
}
const ::Parser::Types::cll_loop_for& Parser::get::cll_loop_for(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_for) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_for, "Parser");
	return std::any_cast<const Types::cll_loop_for&>(rule.data());
}
::Parser::Types::cll_loop_for& Parser::get::cll_loop_for(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_for) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_for, "Parser");
	return std::any_cast<Types::cll_loop_for&>(rule.data());
}
const ::Parser::Types::cll_loop_while& Parser::get::cll_loop_while(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_while) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_while, "Parser");
	return std::any_cast<const Types::cll_loop_while&>(rule.data());
}
::Parser::Types::cll_loop_while& Parser::get::cll_loop_while(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_while) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_while, "Parser");
	return std::any_cast<Types::cll_loop_while&>(rule.data());
}
const ::Parser::Types::cll__var& Parser::get::cll__var(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__var) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__var, "Parser");
	return std::any_cast<const Types::cll__var&>(rule.data());
}
::Parser::Types::cll__var& Parser::get::cll__var(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__var) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__var, "Parser");
	return std::any_cast<Types::cll__var&>(rule.data());
}
const ::Parser::Types::cll_expr_logical& Parser::get::cll_expr_logical(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_logical) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_logical, "Parser");
	return std::any_cast<const Types::cll_expr_logical&>(rule.data());
}
::Parser::Types::cll_expr_logical& Parser::get::cll_expr_logical(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_logical) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_logical, "Parser");
	return std::any_cast<Types::cll_expr_logical&>(rule.data());
}
const ::Parser::Types::cll_expr_term& Parser::get::cll_expr_term(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_term) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_term, "Parser");
	return std::any_cast<const Types::cll_expr_term&>(rule.data());
}
::Parser::Types::cll_expr_term& Parser::get::cll_expr_term(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_term) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_term, "Parser");
	return std::any_cast<Types::cll_expr_term&>(rule.data());
}
const ::Parser::Types::cll_expr& Parser::get::cll_expr(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr, "Parser");
	return std::any_cast<const Types::cll_expr&>(rule.data());
}
::Parser::Types::cll_expr& Parser::get::cll_expr(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr, "Parser");
	return std::any_cast<Types::cll_expr&>(rule.data());
}
const ::Parser::Types::cll_function_decl& Parser::get::cll_function_decl(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_decl, "Parser");
	return std::any_cast<const Types::cll_function_decl&>(rule.data());
}
::Parser::Types::cll_function_decl& Parser::get::cll_function_decl(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_decl, "Parser");
	return std::any_cast<Types::cll_function_decl&>(rule.data());
}
const ::Parser::Types::cll_function_call& Parser::get::cll_function_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_call, "Parser");
	return std::any_cast<const Types::cll_function_call&>(rule.data());
}
::Parser::Types::cll_function_call& Parser::get::cll_function_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_call, "Parser");
	return std::any_cast<Types::cll_function_call&>(rule.data());
}
const ::Parser::Types::rule_data_block& Parser::get::rule_data_block(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block, "Parser");
	return std::any_cast<const Types::rule_data_block&>(rule.data());
}
::Parser::Types::rule_data_block& Parser::get::rule_data_block(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block, "Parser");
	return std::any_cast<Types::rule_data_block&>(rule.data());
}
const ::Parser::Types::cll_function_body_call& Parser::get::cll_function_body_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_call, "Parser");
	return std::any_cast<const Types::cll_function_body_call&>(rule.data());
}
::Parser::Types::cll_function_body_call& Parser::get::cll_function_body_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_call, "Parser");
	return std::any_cast<Types::cll_function_body_call&>(rule.data());
}
const ::Parser::Types::rule_data_block_regular_datablock_key& Parser::get::rule_data_block_regular_datablock_key(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock_key) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock_key, "Parser");
	return std::any_cast<const Types::rule_data_block_regular_datablock_key&>(rule.data());
}
::Parser::Types::rule_data_block_regular_datablock_key& Parser::get::rule_data_block_regular_datablock_key(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock_key) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock_key, "Parser");
	return std::any_cast<Types::rule_data_block_regular_datablock_key&>(rule.data());
}
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_0 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_1 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_2 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 26, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_3 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> Parser::Parser::dfa_state_4 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 34, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_5 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_6 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_7 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_8 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> Parser::Parser::dfa_state_9 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_10 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_11 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_12 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_13 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_14 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_15 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_16 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_17 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_18 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_19 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_20 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_21 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 31, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_22 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 33, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_23 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 35, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_24 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_25 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_26 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_27 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_28 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_29 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 26, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_30 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_31 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 33, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 31, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_32 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> Parser::Parser::dfa_state_33 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 39, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 37, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 35, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_34 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_21, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_35 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_36 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_37 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_38 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_39 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 41, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_40 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 43, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_41 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_42 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_43 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_44 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_45 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_46 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_47 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_48 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_49 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_50 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_51 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_52 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 34, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_53 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 36, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_54 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_55 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 40, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_56 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 42, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_57 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 39, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 37, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 44, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_58 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 36, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_59 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_60 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_61 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_62 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> Parser::Parser::dfa_state_63 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 36, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 35, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 34, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 6 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 7 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 9 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 8 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 10 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_64 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_65 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 15> Parser::Parser::dfa_state_66 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 48, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_18, 46, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_17, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 45, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 44, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 43, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 41, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_15, 39, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_67 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_68 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_69 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 19> Parser::Parser::dfa_state_70 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 66, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 64, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 62, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 60, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 54, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 52, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 50, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 58, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 56, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_71 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_72 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 68, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_73 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 17> Parser::Parser::dfa_state_74 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 83, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 81, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 79, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 77, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 75, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 73, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 71, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 69, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_75 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_76 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_77 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 87, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 85, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_78 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_79 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 92, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 91, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 89, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_80 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 94, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 29, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 29, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_81 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 98, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 96, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_82 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_83 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 19> Parser::Parser::dfa_state_84 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> Parser::Parser::dfa_state_85 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_86 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_87 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 100, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_88 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 26, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_89 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_90 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_91 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_92 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 31, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_93 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 33, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_94 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_95 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 37, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_96 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_97 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 40, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_98 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 31, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 42, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_99 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_100 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_101 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 47, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_102 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 49, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_103 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 51, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_104 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 53, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_105 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 55, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_106 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 57, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_107 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 59, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_108 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 61, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_109 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 63, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_110 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 65, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_111 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 67, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_112 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_113 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 70, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_114 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 72, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_115 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 74, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_116 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 76, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_117 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 78, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_118 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 80, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_119 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 82, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_120 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 84, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_121 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 86, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_122 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 88, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 21> Parser::Parser::dfa_state_123 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 66, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 60, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 90, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 64, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 62, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 54, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 52, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 50, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 58, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 56, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_124 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 26, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_125 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 93, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_126 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 95, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 21> Parser::Parser::dfa_state_127 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 66, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 60, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 97, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 64, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 62, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 54, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 52, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 50, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 58, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 56, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_128 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 99, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_129 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 101, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 31, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_130 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_8, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NAME, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::SPACEMODE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_131 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_132 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_133 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_8, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 15> Parser::Parser::dfa_state_134 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 48, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_18, 46, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_17, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 45, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 44, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 43, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 41, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_15, 39, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_135 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_136 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_137 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 53, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 51, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_138 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_139 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 59, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 58, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 55, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_140 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 61, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_141 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 66, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 63, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_142 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_143 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_144 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_145 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_17, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> Parser::Parser::dfa_state_146 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_147 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 68, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 20> Parser::Parser::dfa_state_148 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 100, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 98, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 96, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 94, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 92, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 91, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 88, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 86, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 84, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 82, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 80, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 78, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 74, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 76, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 72, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 70, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_149 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 17> Parser::Parser::dfa_state_150 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 108, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 106, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 104, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 102, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_151 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_152 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_153 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 31, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_154 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_155 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_156 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> Parser::Parser::dfa_state_157 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_18, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_17, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_158 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_159 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_160 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_161 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_162 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_163 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 13> Parser::Parser::dfa_state_164 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> Parser::Parser::dfa_state_165 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 127, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 125, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 123, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 121, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 119, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 117, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 115, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 113, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 111, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 18> Parser::Parser::dfa_state_166 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 155, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 153, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 151, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 149, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 146, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 144, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 142, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 140, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 138, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 136, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 132, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 134, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 130, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 128, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> Parser::Parser::dfa_state_167 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_168 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 35, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_169 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 163, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 161, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 159, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 157, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> Parser::Parser::dfa_state_170 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 35, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_171 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 34, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_172 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 40, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> Parser::Parser::dfa_state_173 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 42, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_174 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_175 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 47, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_176 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 49, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_177 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 50, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_178 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 52, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_179 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 54, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 13> Parser::Parser::dfa_state_180 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 57, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 56, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 26, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_181 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_182 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 60, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_183 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 62, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 13> Parser::Parser::dfa_state_184 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 65, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 64, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 26, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_185 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 67, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_186 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 69, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_187 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 71, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_188 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 73, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_189 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 75, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_190 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 77, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_191 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 79, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_192 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 81, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_193 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 83, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_194 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 85, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_195 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 87, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_196 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 90, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 89, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_197 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 34, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 36, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_198 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_199 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 93, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_200 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 95, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_201 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 97, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_202 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 99, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_203 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 101, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_204 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 103, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_205 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 105, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_206 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 107, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_207 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 109, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_208 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 33, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_209 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 112, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_210 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 114, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_211 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 116, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_212 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 118, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_213 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 120, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_214 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 122, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_215 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 124, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_216 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 126, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_217 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 35, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 37, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_218 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 129, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_219 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 131, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_220 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 133, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_221 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 135, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_222 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 137, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_223 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 139, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_224 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 141, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_225 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 143, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 34, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> Parser::Parser::dfa_state_226 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 123, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 127, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 125, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 117, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 115, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 121, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 119, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 113, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 111, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_227 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 145, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 19> Parser::Parser::dfa_state_228 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 148, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 98, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 91, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 96, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 92, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 147, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 88, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 84, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 86, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 82, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 80, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 78, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 74, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 76, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 72, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 70, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_229 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 95, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> Parser::Parser::dfa_state_230 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 101, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_231 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 150, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_232 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 152, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_233 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 154, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 110, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_234 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 156, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> Parser::Parser::dfa_state_235 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 37, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 158, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> Parser::Parser::dfa_state_236 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 37, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 160, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> Parser::Parser::dfa_state_237 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 37, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 162, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_238 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 164, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> Parser::Parser::dfa_state_239 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 3 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 6 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_240 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 6 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_241 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 6 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 6 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_242 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_243 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_244 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_245 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_246 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_247 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_248 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 5 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 6 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> Parser::Parser::dfa_state_249 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 6 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 6 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_250 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_251 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_252 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 6 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_253 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_254 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_255 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_256 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_257 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_258 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_259 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_260 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_261 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_262 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_263 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 26, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_264 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_265 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_266 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 34, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_267 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_21, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_268 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_269 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_270 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_271 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> Parser::Parser::dfa_state_272 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 41, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_273 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 43, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_274 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_275 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_276 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_277 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_278 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_279 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_280 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_281 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_282 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_283 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 31, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_284 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 33, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_285 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 35, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_286 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_287 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 40, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_288 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 42, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_289 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 39, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 37, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 44, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> Parser::Parser::dfa_state_290 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 36, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> Parser::Parser::dfa_state_291 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 22, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 21, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 19, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 18, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 17, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_292 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_293 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_294 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> Parser::Parser::dfa_state_295 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 31, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_296 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 33, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_297 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 37, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 35, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_298 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_299 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_300 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_301 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 8, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 39, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_302 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_303 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 16, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_304 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_305 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> Parser::Parser::dfa_state_306 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_307 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_308 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_309 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 20, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> Parser::Parser::dfa_state_310 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_311 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 24, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 23, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_312 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 12, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_313 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 26, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_314 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_315 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_316 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 32, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_317 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 34, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_318 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 36, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_319 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 38, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> Parser::Parser::dfa_state_320 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 25, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 40, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 11, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 27, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_321 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_322 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_323 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_9, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_324 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_325 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_326 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 1, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_9, 3, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 4, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_327 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, false, false, false, ::ISPA_STD::DFAAPI::null_state, ::ISPA_STD::DFAAPI::null_state, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 36> Parser::Parser::dfa_table_0 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_0.data(), dfa_state_0.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_1.data(), dfa_state_1.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_2.data(), dfa_state_2.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_3.data(), dfa_state_3.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_5.data(), dfa_state_5.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_7.data(), dfa_state_7.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_8.data(), dfa_state_8.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_9.data(), dfa_state_9.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_10.data(), dfa_state_10.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_11.data(), dfa_state_11.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_12.data(), dfa_state_12.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 4, {dfa_state_13.data(), dfa_state_13.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 1, {dfa_state_14.data(), dfa_state_14.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 1, {dfa_state_14.data(), dfa_state_14.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_15.data(), dfa_state_15.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_16.data(), dfa_state_16.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_17.data(), dfa_state_17.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_18.data(), dfa_state_18.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_19.data(), dfa_state_19.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_20.data(), dfa_state_20.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_21.data(), dfa_state_21.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_22.data(), dfa_state_22.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_23.data(), dfa_state_23.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 5> Parser::Parser::dfa_table_1 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 2, 0, {dfa_state_24.data(), dfa_state_24.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_25.data(), dfa_state_25.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_26.data(), dfa_state_26.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_2 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_27.data(), dfa_state_27.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_28.data(), dfa_state_28.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 45> Parser::Parser::dfa_table_3 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_29.data(), dfa_state_29.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_30.data(), dfa_state_30.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_31.data(), dfa_state_31.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_32.data(), dfa_state_32.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_33.data(), dfa_state_33.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_34.data(), dfa_state_34.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_35.data(), dfa_state_35.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_36.data(), dfa_state_36.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_37.data(), dfa_state_37.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_38.data(), dfa_state_38.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_39.data(), dfa_state_39.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_40.data(), dfa_state_40.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_41.data(), dfa_state_41.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 0, {dfa_state_42.data(), dfa_state_42.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_43.data(), dfa_state_43.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_44.data(), dfa_state_44.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_45.data(), dfa_state_45.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_46.data(), dfa_state_46.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, 1, {dfa_state_47.data(), dfa_state_47.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_48.data(), dfa_state_48.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_48.data(), dfa_state_48.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_49.data(), dfa_state_49.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_50.data(), dfa_state_50.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_51.data(), dfa_state_51.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_53.data(), dfa_state_53.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_54.data(), dfa_state_54.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_55.data(), dfa_state_55.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_56.data(), dfa_state_56.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_57.data(), dfa_state_57.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_58.data(), dfa_state_58.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 6> Parser::Parser::dfa_table_4 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 3, 0, {dfa_state_59.data(), dfa_state_59.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 3, 0, {dfa_state_60.data(), dfa_state_60.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 3, 0, {dfa_state_61.data(), dfa_state_61.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_62.data(), dfa_state_62.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 102> Parser::Parser::dfa_table_5 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_63.data(), dfa_state_63.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_65.data(), dfa_state_65.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_66.data(), dfa_state_66.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_67.data(), dfa_state_67.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_68.data(), dfa_state_68.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_69.data(), dfa_state_69.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_70.data(), dfa_state_70.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_71.data(), dfa_state_71.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_72.data(), dfa_state_72.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_73.data(), dfa_state_73.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_74.data(), dfa_state_74.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_75.data(), dfa_state_75.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_76.data(), dfa_state_76.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_77.data(), dfa_state_77.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_78.data(), dfa_state_78.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_79.data(), dfa_state_79.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_80.data(), dfa_state_80.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_81.data(), dfa_state_81.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_82.data(), dfa_state_82.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_83.data(), dfa_state_83.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_84.data(), dfa_state_84.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_85.data(), dfa_state_85.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_86.data(), dfa_state_86.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_87.data(), dfa_state_87.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_88.data(), dfa_state_88.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_89.data(), dfa_state_89.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_90.data(), dfa_state_90.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_91.data(), dfa_state_91.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_90.data(), dfa_state_90.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_92.data(), dfa_state_92.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_93.data(), dfa_state_93.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_94.data(), dfa_state_94.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_67.data(), dfa_state_67.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_95.data(), dfa_state_95.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_96.data(), dfa_state_96.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_97.data(), dfa_state_97.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_98.data(), dfa_state_98.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_99.data(), dfa_state_99.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_100.data(), dfa_state_100.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_99.data(), dfa_state_99.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_101.data(), dfa_state_101.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_102.data(), dfa_state_102.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_103.data(), dfa_state_103.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_104.data(), dfa_state_104.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_105.data(), dfa_state_105.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_106.data(), dfa_state_106.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_107.data(), dfa_state_107.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_108.data(), dfa_state_108.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_109.data(), dfa_state_109.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_110.data(), dfa_state_110.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_111.data(), dfa_state_111.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_112.data(), dfa_state_112.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_113.data(), dfa_state_113.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_114.data(), dfa_state_114.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_115.data(), dfa_state_115.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_116.data(), dfa_state_116.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_117.data(), dfa_state_117.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_118.data(), dfa_state_118.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_119.data(), dfa_state_119.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_120.data(), dfa_state_120.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_121.data(), dfa_state_121.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_122.data(), dfa_state_122.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 11, {dfa_state_123.data(), dfa_state_123.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_124.data(), dfa_state_124.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_125.data(), dfa_state_125.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_126.data(), dfa_state_126.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_129.data(), dfa_state_129.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 6> Parser::Parser::dfa_table_6 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_130.data(), dfa_state_130.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_131.data(), dfa_state_131.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_132.data(), dfa_state_132.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_133.data(), dfa_state_133.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 165> Parser::Parser::dfa_table_7 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_134.data(), dfa_state_134.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_135.data(), dfa_state_135.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_136.data(), dfa_state_136.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_137.data(), dfa_state_137.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_138.data(), dfa_state_138.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_139.data(), dfa_state_139.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_140.data(), dfa_state_140.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_141.data(), dfa_state_141.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_142.data(), dfa_state_142.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_143.data(), dfa_state_143.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_144.data(), dfa_state_144.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_145.data(), dfa_state_145.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_146.data(), dfa_state_146.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_147.data(), dfa_state_147.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_148.data(), dfa_state_148.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_149.data(), dfa_state_149.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_150.data(), dfa_state_150.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_154.data(), dfa_state_154.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_155.data(), dfa_state_155.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_157.data(), dfa_state_157.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_158.data(), dfa_state_158.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_159.data(), dfa_state_159.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_160.data(), dfa_state_160.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_161.data(), dfa_state_161.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_162.data(), dfa_state_162.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_163.data(), dfa_state_163.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_164.data(), dfa_state_164.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_165.data(), dfa_state_165.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_166.data(), dfa_state_166.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_167.data(), dfa_state_167.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_168.data(), dfa_state_168.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_169.data(), dfa_state_169.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_170.data(), dfa_state_170.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_171.data(), dfa_state_171.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 4, {dfa_state_172.data(), dfa_state_172.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_173.data(), dfa_state_173.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_174.data(), dfa_state_174.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_143.data(), dfa_state_143.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_174.data(), dfa_state_174.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 4, {dfa_state_175.data(), dfa_state_175.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_176.data(), dfa_state_176.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_177.data(), dfa_state_177.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_178.data(), dfa_state_178.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_179.data(), dfa_state_179.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_180.data(), dfa_state_180.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 4, {dfa_state_181.data(), dfa_state_181.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_182.data(), dfa_state_182.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_183.data(), dfa_state_183.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_184.data(), dfa_state_184.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_185.data(), dfa_state_185.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_186.data(), dfa_state_186.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_187.data(), dfa_state_187.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_188.data(), dfa_state_188.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_189.data(), dfa_state_189.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_190.data(), dfa_state_190.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_191.data(), dfa_state_191.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_192.data(), dfa_state_192.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_193.data(), dfa_state_193.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_194.data(), dfa_state_194.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_195.data(), dfa_state_195.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_196.data(), dfa_state_196.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_197.data(), dfa_state_197.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_198.data(), dfa_state_198.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_199.data(), dfa_state_199.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_200.data(), dfa_state_200.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_201.data(), dfa_state_201.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_202.data(), dfa_state_202.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_203.data(), dfa_state_203.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_204.data(), dfa_state_204.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_205.data(), dfa_state_205.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_206.data(), dfa_state_206.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_207.data(), dfa_state_207.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_208.data(), dfa_state_208.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_209.data(), dfa_state_209.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_210.data(), dfa_state_210.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_211.data(), dfa_state_211.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_212.data(), dfa_state_212.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_213.data(), dfa_state_213.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_214.data(), dfa_state_214.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_215.data(), dfa_state_215.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_216.data(), dfa_state_216.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_217.data(), dfa_state_217.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_218.data(), dfa_state_218.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_219.data(), dfa_state_219.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_220.data(), dfa_state_220.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_221.data(), dfa_state_221.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_222.data(), dfa_state_222.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_223.data(), dfa_state_223.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_224.data(), dfa_state_224.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_225.data(), dfa_state_225.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_226.data(), dfa_state_226.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_227.data(), dfa_state_227.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_228.data(), dfa_state_228.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_229.data(), dfa_state_229.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_230.data(), dfa_state_230.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_231.data(), dfa_state_231.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_232.data(), dfa_state_232.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_233.data(), dfa_state_233.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_234.data(), dfa_state_234.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_235.data(), dfa_state_235.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_236.data(), dfa_state_236.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_237.data(), dfa_state_237.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_238.data(), dfa_state_238.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 20> Parser::Parser::dfa_table_8 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 3, 0, {dfa_state_239.data(), dfa_state_239.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 3, 0, {dfa_state_240.data(), dfa_state_240.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_241.data(), dfa_state_241.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_242.data(), dfa_state_242.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_243.data(), dfa_state_243.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_244.data(), dfa_state_244.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_245.data(), dfa_state_245.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_246.data(), dfa_state_246.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 3, 0, {dfa_state_247.data(), dfa_state_247.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 3, 0, {dfa_state_248.data(), dfa_state_248.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_249.data(), dfa_state_249.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_250.data(), dfa_state_250.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_251.data(), dfa_state_251.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_252.data(), dfa_state_252.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_253.data(), dfa_state_253.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_9 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_254.data(), dfa_state_254.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_255.data(), dfa_state_255.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_10 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_254.data(), dfa_state_254.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_255.data(), dfa_state_255.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_11 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_256.data(), dfa_state_256.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_257.data(), dfa_state_257.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_12 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_256.data(), dfa_state_256.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_257.data(), dfa_state_257.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_13 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_258.data(), dfa_state_258.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_259.data(), dfa_state_259.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_14 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_260.data(), dfa_state_260.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_261.data(), dfa_state_261.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 45> Parser::Parser::dfa_table_15 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_262.data(), dfa_state_262.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_263.data(), dfa_state_263.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_264.data(), dfa_state_264.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_265.data(), dfa_state_265.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_266.data(), dfa_state_266.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_267.data(), dfa_state_267.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_268.data(), dfa_state_268.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_269.data(), dfa_state_269.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_270.data(), dfa_state_270.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_271.data(), dfa_state_271.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 5, 0, {dfa_state_272.data(), dfa_state_272.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_273.data(), dfa_state_273.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_274.data(), dfa_state_274.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_275.data(), dfa_state_275.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_276.data(), dfa_state_276.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_277.data(), dfa_state_277.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_278.data(), dfa_state_278.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_279.data(), dfa_state_279.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_280.data(), dfa_state_280.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_281.data(), dfa_state_281.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_281.data(), dfa_state_281.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_282.data(), dfa_state_282.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_283.data(), dfa_state_283.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_284.data(), dfa_state_284.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_285.data(), dfa_state_285.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_286.data(), dfa_state_286.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_287.data(), dfa_state_287.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_288.data(), dfa_state_288.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_289.data(), dfa_state_289.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_290.data(), dfa_state_290.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 41> Parser::Parser::dfa_table_16 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_291.data(), dfa_state_291.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_292.data(), dfa_state_292.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_293.data(), dfa_state_293.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_294.data(), dfa_state_294.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_295.data(), dfa_state_295.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_296.data(), dfa_state_296.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_297.data(), dfa_state_297.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_298.data(), dfa_state_298.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_299.data(), dfa_state_299.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_300.data(), dfa_state_300.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_301.data(), dfa_state_301.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_302.data(), dfa_state_302.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_303.data(), dfa_state_303.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_304.data(), dfa_state_304.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_305.data(), dfa_state_305.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 0, {dfa_state_306.data(), dfa_state_306.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 1, {dfa_state_307.data(), dfa_state_307.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_308.data(), dfa_state_308.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_309.data(), dfa_state_309.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_310.data(), dfa_state_310.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_308.data(), dfa_state_308.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_311.data(), dfa_state_311.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, 1, {dfa_state_312.data(), dfa_state_312.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_313.data(), dfa_state_313.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_314.data(), dfa_state_314.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_315.data(), dfa_state_315.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_316.data(), dfa_state_316.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_317.data(), dfa_state_317.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_318.data(), dfa_state_318.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_319.data(), dfa_state_319.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_320.data(), dfa_state_320.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_321.data(), dfa_state_321.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 8> Parser::Parser::dfa_table_17 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 2, 0, {dfa_state_322.data(), dfa_state_322.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_323.data(), dfa_state_323.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 2, 0, {dfa_state_324.data(), dfa_state_324.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_325.data(), dfa_state_325.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 2, 0, {dfa_state_326.data(), dfa_state_326.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_327.data(), dfa_state_327.size()}},
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_0 = {
	dfa_table_0.data(), dfa_table_0.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_1 = {
	dfa_table_1.data(), dfa_table_1.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_2 = {
	dfa_table_2.data(), dfa_table_2.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_3 = {
	dfa_table_3.data(), dfa_table_3.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_4 = {
	dfa_table_4.data(), dfa_table_4.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_5 = {
	dfa_table_5.data(), dfa_table_5.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_6 = {
	dfa_table_6.data(), dfa_table_6.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_7 = {
	dfa_table_7.data(), dfa_table_7.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_8 = {
	dfa_table_8.data(), dfa_table_8.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_9 = {
	dfa_table_9.data(), dfa_table_9.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_10 = {
	dfa_table_10.data(), dfa_table_10.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_11 = {
	dfa_table_11.data(), dfa_table_11.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_12 = {
	dfa_table_12.data(), dfa_table_12.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_13 = {
	dfa_table_13.data(), dfa_table_13.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_14 = {
	dfa_table_14.data(), dfa_table_14.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_15 = {
	dfa_table_15.data(), dfa_table_15.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_16 = {
	dfa_table_16.data(), dfa_table_16.size()
};
const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> Parser::Parser::dfa_span_17 = {
	dfa_table_17.data(), dfa_table_17.size()
};

