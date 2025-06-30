#include "Parser.h"
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_0 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::EmptyTableState Parser::Lexer::dfa_state_1 = {
};
const ::ISPA_STD::DFAAPI::CharTableState<11> Parser::Lexer::dfa_state_2 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '>', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '=', 5, 1 },
	ISPA_STD::DFAAPI::CharTransition { '<', 14, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_3 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_4 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<10> Parser::Lexer::dfa_state_5 = {
	ISPA_STD::DFAAPI::CharTransition { '>', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 5, 1 },
	ISPA_STD::DFAAPI::CharTransition { '<', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { '!', 5, 3 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_6 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_7 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 5, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_8 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 5, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_9 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 5, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_10 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 5, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_11 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 5, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_12 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 5, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_13 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '#', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_14 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '$', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_15 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '%', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '-', 1, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '*', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 8> Parser::Lexer::dfa_state_16 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_17 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_18 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_19 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_20 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_21 = {
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_22 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 11> Parser::Lexer::dfa_state_23 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '&', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_38, 1, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_24 = {
	ISPA_STD::DFAAPI::CharTransition { '&', 4, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_25 = {
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_26 = {
	ISPA_STD::DFAAPI::CharTransition { '&', 1, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_27 = {
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 2> Parser::Lexer::dfa_state_28 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 6, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 4> Parser::Lexer::dfa_state_29 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 6, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '&', 4, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 5> Parser::Lexer::dfa_state_30 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '&', 4, 1 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 6, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 2> Parser::Lexer::dfa_state_31 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_38, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 10, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 6> Parser::Lexer::dfa_state_32 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '&', 4, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 7> Parser::Lexer::dfa_state_33 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '&', 4, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 8> Parser::Lexer::dfa_state_34 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '&', 4, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 9> Parser::Lexer::dfa_state_35 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '&', 4, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_36 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '(', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_37 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ')', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_38 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '*', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '-', 1, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '%', 1, 4 },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_39 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_40 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_41 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_42 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_43 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_44 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 25> Parser::Lexer::dfa_state_45 = {
	ISPA_STD::DFAAPI::CharTransition { '\t', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '-', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '.', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { ',', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '/', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '%', 2, 4 },
	ISPA_STD::DFAAPI::CharTransition { '*', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_46 = {
	ISPA_STD::DFAAPI::CharTransition { '+', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<20> Parser::Lexer::dfa_state_47 = {
	ISPA_STD::DFAAPI::CharTransition { '+', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '-', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '.', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { ',', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<11> Parser::Lexer::dfa_state_48 = {
	ISPA_STD::DFAAPI::CharTransition { '/', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '%', 2, 4 },
	ISPA_STD::DFAAPI::CharTransition { '-', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '*', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 8> Parser::Lexer::dfa_state_49 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_50 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_51 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_52 = {
	ISPA_STD::DFAAPI::CharTransition { '+', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_53 = {
	ISPA_STD::DFAAPI::CharTransition { '5', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<9> Parser::Lexer::dfa_state_54 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<11> Parser::Lexer::dfa_state_55 = {
	ISPA_STD::DFAAPI::CharTransition { '5', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<12> Parser::Lexer::dfa_state_56 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 11, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_57 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ',', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 25> Parser::Lexer::dfa_state_58 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '-', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '.', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ',', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '%', 1, 4 },
	ISPA_STD::DFAAPI::CharTransition { '*', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<20> Parser::Lexer::dfa_state_59 = {
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '-', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '.', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ',', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<11> Parser::Lexer::dfa_state_60 = {
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '%', 1, 4 },
	ISPA_STD::DFAAPI::CharTransition { '-', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '*', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_61 = {
	ISPA_STD::DFAAPI::CharTransition { '>', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 8> Parser::Lexer::dfa_state_62 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_63 = {
	ISPA_STD::DFAAPI::CharTransition { '+', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '-', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_64 = {
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_65 = {
	ISPA_STD::DFAAPI::CharTransition { '0', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '-', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_66 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '-', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<10> Parser::Lexer::dfa_state_67 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '-', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<12> Parser::Lexer::dfa_state_68 = {
	ISPA_STD::DFAAPI::CharTransition { '+', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '-', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<13> Parser::Lexer::dfa_state_69 = {
	ISPA_STD::DFAAPI::CharTransition { '0', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '+', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '-', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_70 = {
	ISPA_STD::DFAAPI::CharTransition { '-', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_71 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '.', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_72 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '/', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '%', 1, 4 },
	ISPA_STD::DFAAPI::CharTransition { '-', 1, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '*', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_73 = {
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_74 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_75 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_76 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_77 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_78 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_79 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_80 = {
	ISPA_STD::DFAAPI::CharTransition { '/', 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<28> Parser::Lexer::dfa_state_81 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<28> Parser::Lexer::dfa_state_82 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_83 = {
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_84 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_85 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_86 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_87 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_88 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_89 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<9> Parser::Lexer::dfa_state_90 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<9> Parser::Lexer::dfa_state_91 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '0', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_92 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_93 = {
	ISPA_STD::DFAAPI::CharTransition { '9', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_94 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ':', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_95 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 12> Parser::Lexer::dfa_state_96 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '<', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '>', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_33, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ',', 3, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 10> Parser::Lexer::dfa_state_97 = {
	ISPA_STD::DFAAPI::CharTransition { '<', 2, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_33, 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { ',', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '>', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_98 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { '<', 2, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_99 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { '<', 2, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_100 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { '<', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_101 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '<', 2, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_102 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { '<', 2, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_103 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '<', 2, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 2> Parser::Lexer::dfa_state_104 = {
	ISPA_STD::DFAAPI::CharTransition { '<', 2, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_33, 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<10> Parser::Lexer::dfa_state_105 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 3, 3 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '=', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '>', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '<', 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<10> Parser::Lexer::dfa_state_106 = {
	ISPA_STD::DFAAPI::CharTransition { '>', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 3, 1 },
	ISPA_STD::DFAAPI::CharTransition { '<', 1, 5 },
	ISPA_STD::DFAAPI::CharTransition { '!', 3, 3 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_107 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_108 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 3, 3 },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_109 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 3, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_110 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 3, 3 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_111 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 3, 3 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_112 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 3, 3 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_113 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 3, 3 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<10> Parser::Lexer::dfa_state_114 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { '<', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '>', 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_115 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '?', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_116 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '@', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_117 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 12> Parser::Lexer::dfa_state_118 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_25, 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '[', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_25, 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '^', 1, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_24, 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 12> Parser::Lexer::dfa_state_119 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_25, 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '^', 1, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_24, 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '[', 1, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_25, 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_120 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '[', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_121 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '[', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_122 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '[', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 6> Parser::Lexer::dfa_state_123 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '[', 1, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_25, 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 7> Parser::Lexer::dfa_state_124 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_25, 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '[', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 8> Parser::Lexer::dfa_state_125 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_25, 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '[', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 10> Parser::Lexer::dfa_state_126 = {
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\\', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_25, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\'', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_127 = {
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_128 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_129 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_130 = {
	ISPA_STD::DFAAPI::CharTransition { '0', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_131 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\'', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_132 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 9, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_133 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_134 = {
	ISPA_STD::DFAAPI::CharTransition { '\'', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 14, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_135 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 17, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_136 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 20, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_137 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 23, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_138 = {
	ISPA_STD::DFAAPI::CharTransition { '\r', 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 26, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_139 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\'', 6, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 9> Parser::Lexer::dfa_state_140 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\\', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { ']', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_25, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_141 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_142 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_143 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_144 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\\', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_145 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\\', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_146 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\\', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_147 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\\', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_148 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\\', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 74> Parser::Lexer::dfa_state_149 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_38, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 61, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_150 = {
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 5 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 1, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_151 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 10, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_152 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 11, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_153 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 12, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_154 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 13, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_155 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 12, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_156 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 14, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_157 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 3, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_158 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_159 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 1, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_160 = {
	ISPA_STD::DFAAPI::CharTransition { 'j', 3, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_161 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 15, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_162 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 2> Parser::Lexer::dfa_state_163 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 16, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 11> Parser::Lexer::dfa_state_164 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 1, 5 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 16, 1 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 2> Parser::Lexer::dfa_state_165 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_38, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 20, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_166 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 2 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_167 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 12, 2 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 2 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_168 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_169 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 26, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_170 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 29, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_171 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_172 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 32, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_173 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 35, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 16> Parser::Lexer::dfa_state_174 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 11, 4 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 15> Parser::Lexer::dfa_state_175 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 41, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 40, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_176 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 39, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_177 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 43, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 16> Parser::Lexer::dfa_state_178 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 45, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 47, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 48, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 50, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_179 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 46, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_180 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 49, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 17> Parser::Lexer::dfa_state_181 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 52, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 54, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 55, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 57, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_182 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 53, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_183 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 56, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 17> Parser::Lexer::dfa_state_184 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 59, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_185 = {
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 60, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 29, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 18> Parser::Lexer::dfa_state_186 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 10, 5 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '&', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 62, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_187 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 11, 4 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 70> Parser::Lexer::dfa_state_188 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 0, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 41, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 48, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 55, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_189 = {
	ISPA_STD::DFAAPI::CharTransition { 'v', 7, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 5, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 5 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 1, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_190 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 9, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_191 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 10, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_192 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 11, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_193 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 12, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_194 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 11, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_195 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 13, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_196 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 2, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_197 = {
	ISPA_STD::DFAAPI::CharTransition { 'j', 2, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 9> Parser::Lexer::dfa_state_198 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 5, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 7, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, 5 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 1, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 10> Parser::Lexer::dfa_state_199 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 5, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 7, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 18, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_200 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 19, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 11> Parser::Lexer::dfa_state_201 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 11, 2 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 5, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 10> Parser::Lexer::dfa_state_202 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_203 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 18, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 11> Parser::Lexer::dfa_state_204 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 11> Parser::Lexer::dfa_state_205 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_206 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 32, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_207 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 10, 4 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 4 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 12> Parser::Lexer::dfa_state_208 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 40, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_209 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 39, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_210 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 5 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 43, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 45, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 47, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_211 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 46, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_212 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 49, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 41, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 50, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 52, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 54, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_213 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 53, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_214 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 41, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 56, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 48, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_215 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 57, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_216 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 12, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 15> Parser::Lexer::dfa_state_217 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 9, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 41, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 48, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 55, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_218 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 12, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_219 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_220 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_221 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_222 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 7, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_223 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_224 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_225 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_226 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 10, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_227 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 11, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_228 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_229 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 12, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_230 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_231 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_232 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'f', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_233 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_234 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_235 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_236 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 't', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_237 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 't', 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<9> Parser::Lexer::dfa_state_238 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 't', 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 12, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_239 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_240 = {
	ISPA_STD::DFAAPI::CharTransition { 'p', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_241 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_242 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_243 = {
	ISPA_STD::DFAAPI::CharTransition { 'i', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_244 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_245 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_246 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 7, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_247 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_248 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_249 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_250 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 11, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_251 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_252 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_253 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_254 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 7, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_255 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_256 = {
	ISPA_STD::DFAAPI::CharTransition { 'd', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_257 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_258 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_259 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_260 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 7, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_261 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_262 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_263 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_264 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 9, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_265 = {
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_266 = {
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_267 = {
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 73> Parser::Lexer::dfa_state_268 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 0, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 50, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 61, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_269 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 9> Parser::Lexer::dfa_state_270 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 1, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 11> Parser::Lexer::dfa_state_271 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 12> Parser::Lexer::dfa_state_272 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 12, 2 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 11> Parser::Lexer::dfa_state_273 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_274 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 19, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 12> Parser::Lexer::dfa_state_275 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 12> Parser::Lexer::dfa_state_276 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_277 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 30, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_278 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 11, 4 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 32, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_279 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_280 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'r', 10, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_281 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_282 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 38, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_283 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 11, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 40, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 41, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_284 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 43, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, 5 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 45, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 47, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_285 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 11, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 48, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 49, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 15> Parser::Lexer::dfa_state_286 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 's', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 52, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 53, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 55, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_287 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 54, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_288 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 11, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 56, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 57, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 15> Parser::Lexer::dfa_state_289 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 50, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 59, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_290 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 60, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 16> Parser::Lexer::dfa_state_291 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 10, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 50, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_36, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 74> Parser::Lexer::dfa_state_292 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_38, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 61, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_293 = {
	ISPA_STD::DFAAPI::CharTransition { '|', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 11> Parser::Lexer::dfa_state_294 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 1, 5 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 16, 1 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 2 },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_295 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 1 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 2 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_296 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 12, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 2 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_297 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_298 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 29, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_299 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 16> Parser::Lexer::dfa_state_300 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 11, 4 },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 15> Parser::Lexer::dfa_state_301 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 40, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 41, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 16> Parser::Lexer::dfa_state_302 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 48, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 45, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 47, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 50, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 17> Parser::Lexer::dfa_state_303 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 55, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 52, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 54, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 57, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 3, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 17> Parser::Lexer::dfa_state_304 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 59, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 18> Parser::Lexer::dfa_state_305 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 10, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '|', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 's', 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 71> Parser::Lexer::dfa_state_306 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 0, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 49, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 50, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 65, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 72, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 75, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_307 = {
	ISPA_STD::DFAAPI::CharTransition { 'i', 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_308 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_309 = {
	ISPA_STD::DFAAPI::CharTransition { 'x', 8, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_310 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 9, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_311 = {
	ISPA_STD::DFAAPI::CharTransition { 'i', 10, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_312 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 11, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_313 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_314 = {
	ISPA_STD::DFAAPI::CharTransition { 'c', 13, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_315 = {
	ISPA_STD::DFAAPI::CharTransition { 'p', 14, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_316 = {
	ISPA_STD::DFAAPI::CharTransition { 'w', 15, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_317 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 16, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_318 = {
	ISPA_STD::DFAAPI::CharTransition { 'p', 17, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_319 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 18, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_320 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 12, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_321 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 19, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_322 = {
	ISPA_STD::DFAAPI::CharTransition { 'd', 20, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_323 = {
	ISPA_STD::DFAAPI::CharTransition { 'v', 26, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 25, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 24, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 23, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 21, 5 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 1, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 21, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_324 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 28, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_325 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 29, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_326 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 30, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_327 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 31, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_328 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 30, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_329 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 32, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_330 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 21, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_331 = {
	ISPA_STD::DFAAPI::CharTransition { 'j', 21, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_332 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 33, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 10> Parser::Lexer::dfa_state_333 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 24, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 21, 5 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 1, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 26, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 25, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 23, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 12> Parser::Lexer::dfa_state_334 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 24, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 26, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 25, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 23, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 37, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 15> Parser::Lexer::dfa_state_335 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 30, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 24, 2 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 25, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 23, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 12> Parser::Lexer::dfa_state_336 = {
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 40, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 41, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 25, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 23, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_337 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 30, 2 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_338 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 37, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_339 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 43, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 25, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 23, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 13> Parser::Lexer::dfa_state_340 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 45, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 46, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 47, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 23, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_341 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 48, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 15> Parser::Lexer::dfa_state_342 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 29, 4 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 23, 4 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 15> Parser::Lexer::dfa_state_343 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 49, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 14> Parser::Lexer::dfa_state_344 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 52, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 53, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 54, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 55, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 57, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 15> Parser::Lexer::dfa_state_345 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 60, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 59, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 61, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 63, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 64, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_346 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 62, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 16> Parser::Lexer::dfa_state_347 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 66, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 67, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 68, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 69, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 71, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_348 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 70, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 16> Parser::Lexer::dfa_state_349 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 50, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 73, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 65, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 27, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 49, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_350 = {
	ISPA_STD::DFAAPI::CharTransition { '\v', 21, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 43, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 74, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 23, 4 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 18> Parser::Lexer::dfa_state_351 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 28, 5 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_17, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 50, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 65, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'b', 72, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 49, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_352 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_353 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_354 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_355 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_356 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_357 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 7, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_358 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_359 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_360 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_361 = {
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_362 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_363 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 't', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_364 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 't', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 14, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<9> Parser::Lexer::dfa_state_365 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 't', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_366 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_367 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_368 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_369 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_370 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_371 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_372 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_373 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_374 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_375 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_376 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_377 = {
	ISPA_STD::DFAAPI::CharTransition { 'f', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_378 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_379 = {
	ISPA_STD::DFAAPI::CharTransition { 'i', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_380 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_381 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<69> Parser::Lexer::dfa_state_382 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '1', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '2', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '3', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '4', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '5', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '8', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '6', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '0', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '9', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '7', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_383 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_384 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_385 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_386 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 9, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_387 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_388 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_389 = {
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_390 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '{', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 11> Parser::Lexer::dfa_state_391 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '|', 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 1 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_38, 1, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<8> Parser::Lexer::dfa_state_392 = {
	ISPA_STD::DFAAPI::CharTransition { '|', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_393 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 1, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 2> Parser::Lexer::dfa_state_394 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 5, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 4> Parser::Lexer::dfa_state_395 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 5, 1 },
	ISPA_STD::DFAAPI::CharTransition { '|', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 5> Parser::Lexer::dfa_state_396 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 1 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 5, 1 },
	ISPA_STD::DFAAPI::CharTransition { '|', 4, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 2> Parser::Lexer::dfa_state_397 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_38, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 9, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 6> Parser::Lexer::dfa_state_398 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '|', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 7> Parser::Lexer::dfa_state_399 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '|', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 8> Parser::Lexer::dfa_state_400 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '|', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<Parser::Tokens, 9> Parser::Lexer::dfa_state_401 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { dfa_span_0, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { '|', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<7> Parser::Lexer::dfa_state_402 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 0, 0 },
	ISPA_STD::DFAAPI::CharTransition { '}', 1, 0 }
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_0 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_0.data(), dfa_state_0.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::CharTable<15>Parser::Lexer::dfa_table_1 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_2.data(), dfa_state_2.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_3.data(), dfa_state_3.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_5.data(), dfa_state_5.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_7.data(), dfa_state_7.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_8.data(), dfa_state_8.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_9.data(), dfa_state_9.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_10.data(), dfa_state_10.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_11.data(), dfa_state_11.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_12.data(), dfa_state_12.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 1, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 5, {dfa_state_6.data(), dfa_state_6.size()}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_2 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_13.data(), dfa_state_13.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_3 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_14.data(), dfa_state_14.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 10>Parser::Lexer::dfa_table_4 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_15.data(), dfa_state_15.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 4, 0, {dfa_state_16.data(), dfa_state_16.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_17.data(), dfa_state_17.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_18.data(), dfa_state_18.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_19.data(), dfa_state_19.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_20.data(), dfa_state_20.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_21.data(), dfa_state_21.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_22.data(), dfa_state_22.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 16>Parser::Lexer::dfa_table_5 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_23.data(), dfa_state_23.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_24.data(), dfa_state_24.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_25.data(), dfa_state_25.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_26.data(), dfa_state_26.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_27.data(), dfa_state_27.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_28.data(), dfa_state_28.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_29.data(), dfa_state_29.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_30.data(), dfa_state_30.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_31.data(), dfa_state_31.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_32.data(), dfa_state_32.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_33.data(), dfa_state_33.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_34.data(), dfa_state_34.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_35.data(), dfa_state_35.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_26.data(), dfa_state_26.size()}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_6 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_36.data(), dfa_state_36.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_7 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_37.data(), dfa_state_37.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 10>Parser::Lexer::dfa_table_8 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_38.data(), dfa_state_38.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 4, 0, {dfa_state_16.data(), dfa_state_16.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_39.data(), dfa_state_39.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_40.data(), dfa_state_40.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_41.data(), dfa_state_41.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_42.data(), dfa_state_42.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_43.data(), dfa_state_43.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_44.data(), dfa_state_44.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 24>Parser::Lexer::dfa_table_9 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_45.data(), dfa_state_45.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_46.data(), dfa_state_46.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 4, 0, {dfa_state_47.data(), dfa_state_47.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_48.data(), dfa_state_48.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 9, 0, {dfa_state_49.data(), dfa_state_49.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_50.data(), dfa_state_50.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_51.data(), dfa_state_51.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_53.data(), dfa_state_53.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_54.data(), dfa_state_54.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_55.data(), dfa_state_55.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_56.data(), dfa_state_56.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_46.data(), dfa_state_46.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_52.data(), dfa_state_52.size()}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_10 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_57.data(), dfa_state_57.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 24>Parser::Lexer::dfa_table_11 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_58.data(), dfa_state_58.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, 0, {dfa_state_59.data(), dfa_state_59.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_60.data(), dfa_state_60.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_61.data(), dfa_state_61.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 10, 0, {dfa_state_62.data(), dfa_state_62.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_63.data(), dfa_state_63.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_65.data(), dfa_state_65.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_66.data(), dfa_state_66.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_67.data(), dfa_state_67.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_68.data(), dfa_state_68.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_69.data(), dfa_state_69.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_70.data(), dfa_state_70.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_64.data(), dfa_state_64.size()}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_12 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_71.data(), dfa_state_71.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 10>Parser::Lexer::dfa_table_13 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_72.data(), dfa_state_72.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_73.data(), dfa_state_73.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_74.data(), dfa_state_74.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_75.data(), dfa_state_75.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_76.data(), dfa_state_76.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_77.data(), dfa_state_77.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_78.data(), dfa_state_78.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_79.data(), dfa_state_79.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_80.data(), dfa_state_80.size()}},
};
const ::Parser::DFA::CharTable<14>Parser::Lexer::dfa_table_14 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_81.data(), dfa_state_81.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_82.data(), dfa_state_82.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_83.data(), dfa_state_83.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_84.data(), dfa_state_84.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_85.data(), dfa_state_85.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_86.data(), dfa_state_86.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_87.data(), dfa_state_87.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_88.data(), dfa_state_88.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_89.data(), dfa_state_89.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_90.data(), dfa_state_90.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_91.data(), dfa_state_91.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_92.data(), dfa_state_92.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_93.data(), dfa_state_93.size()}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_15 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_94.data(), dfa_state_94.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_16 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_95.data(), dfa_state_95.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 13>Parser::Lexer::dfa_table_17 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_96.data(), dfa_state_96.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 7, 0, {dfa_state_97.data(), dfa_state_97.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_98.data(), dfa_state_98.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_99.data(), dfa_state_99.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_100.data(), dfa_state_100.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_101.data(), dfa_state_101.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_102.data(), dfa_state_102.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_103.data(), dfa_state_103.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 2, 0, {dfa_state_104.data(), dfa_state_104.size()}},
};
const ::Parser::DFA::CharTable<13>Parser::Lexer::dfa_table_18 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_105.data(), dfa_state_105.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_106.data(), dfa_state_106.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_107.data(), dfa_state_107.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_108.data(), dfa_state_108.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_109.data(), dfa_state_109.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_110.data(), dfa_state_110.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_111.data(), dfa_state_111.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_112.data(), dfa_state_112.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_113.data(), dfa_state_113.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_107.data(), dfa_state_107.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_107.data(), dfa_state_107.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_107.data(), dfa_state_107.size()}},
};
const ::Parser::DFA::CharTable<5>Parser::Lexer::dfa_table_19 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_114.data(), dfa_state_114.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 5, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_6.data(), dfa_state_6.size()}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_20 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_115.data(), dfa_state_115.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_21 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_116.data(), dfa_state_116.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_22 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_117.data(), dfa_state_117.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 10>Parser::Lexer::dfa_table_23 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_118.data(), dfa_state_118.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 3, 0, {dfa_state_119.data(), dfa_state_119.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_120.data(), dfa_state_120.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_121.data(), dfa_state_121.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_122.data(), dfa_state_122.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_123.data(), dfa_state_123.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_124.data(), dfa_state_124.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_125.data(), dfa_state_125.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 28>Parser::Lexer::dfa_table_24 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_126.data(), dfa_state_126.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_129.data(), dfa_state_129.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_130.data(), dfa_state_130.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 8, 0, {dfa_state_131.data(), dfa_state_131.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_132.data(), dfa_state_132.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_128.data(), dfa_state_128.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_133.data(), dfa_state_133.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_128.data(), dfa_state_128.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_134.data(), dfa_state_134.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_129.data(), dfa_state_129.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_135.data(), dfa_state_135.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_128.data(), dfa_state_128.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_136.data(), dfa_state_136.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_128.data(), dfa_state_128.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_137.data(), dfa_state_137.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_128.data(), dfa_state_128.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_138.data(), dfa_state_138.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_128.data(), dfa_state_128.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_139.data(), dfa_state_139.size()}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 11>Parser::Lexer::dfa_table_25 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_140.data(), dfa_state_140.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_141.data(), dfa_state_141.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_142.data(), dfa_state_142.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_143.data(), dfa_state_143.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_144.data(), dfa_state_144.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_145.data(), dfa_state_145.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_146.data(), dfa_state_146.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_147.data(), dfa_state_147.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_148.data(), dfa_state_148.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 63>Parser::Lexer::dfa_table_26 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_149.data(), dfa_state_149.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_26.data(), dfa_state_26.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_150.data(), dfa_state_150.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_154.data(), dfa_state_154.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_155.data(), dfa_state_155.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_157.data(), dfa_state_157.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_158.data(), dfa_state_158.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_159.data(), dfa_state_159.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_160.data(), dfa_state_160.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_161.data(), dfa_state_161.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_162.data(), dfa_state_162.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_163.data(), dfa_state_163.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 5, {dfa_state_164.data(), dfa_state_164.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_165.data(), dfa_state_165.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_166.data(), dfa_state_166.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_167.data(), dfa_state_167.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_168.data(), dfa_state_168.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_169.data(), dfa_state_169.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_170.data(), dfa_state_170.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_171.data(), dfa_state_171.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_172.data(), dfa_state_172.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_173.data(), dfa_state_173.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_174.data(), dfa_state_174.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_175.data(), dfa_state_175.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_176.data(), dfa_state_176.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_177.data(), dfa_state_177.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_178.data(), dfa_state_178.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_179.data(), dfa_state_179.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_180.data(), dfa_state_180.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_181.data(), dfa_state_181.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_182.data(), dfa_state_182.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_183.data(), dfa_state_183.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_184.data(), dfa_state_184.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_185.data(), dfa_state_185.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_154.data(), dfa_state_154.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_186.data(), dfa_state_186.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_187.data(), dfa_state_187.size()}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 59>Parser::Lexer::dfa_table_27 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_188.data(), dfa_state_188.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_189.data(), dfa_state_189.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_190.data(), dfa_state_190.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_191.data(), dfa_state_191.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_192.data(), dfa_state_192.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_193.data(), dfa_state_193.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_194.data(), dfa_state_194.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_195.data(), dfa_state_195.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_196.data(), dfa_state_196.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_158.data(), dfa_state_158.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_159.data(), dfa_state_159.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_197.data(), dfa_state_197.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_162.data(), dfa_state_162.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 5, {dfa_state_198.data(), dfa_state_198.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_199.data(), dfa_state_199.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_200.data(), dfa_state_200.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_201.data(), dfa_state_201.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_202.data(), dfa_state_202.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_192.data(), dfa_state_192.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_203.data(), dfa_state_203.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_204.data(), dfa_state_204.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_195.data(), dfa_state_195.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_205.data(), dfa_state_205.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_192.data(), dfa_state_192.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_203.data(), dfa_state_203.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_206.data(), dfa_state_206.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_195.data(), dfa_state_195.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_207.data(), dfa_state_207.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_208.data(), dfa_state_208.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_192.data(), dfa_state_192.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_203.data(), dfa_state_203.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_209.data(), dfa_state_209.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_195.data(), dfa_state_195.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_191.data(), dfa_state_191.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_210.data(), dfa_state_210.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_192.data(), dfa_state_192.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_203.data(), dfa_state_203.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_211.data(), dfa_state_211.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_195.data(), dfa_state_195.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_191.data(), dfa_state_191.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_212.data(), dfa_state_212.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_192.data(), dfa_state_192.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_203.data(), dfa_state_203.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_213.data(), dfa_state_213.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_195.data(), dfa_state_195.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_191.data(), dfa_state_191.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_214.data(), dfa_state_214.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_215.data(), dfa_state_215.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_216.data(), dfa_state_216.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_217.data(), dfa_state_217.size()}},
};
const ::Parser::DFA::CharTable<30>Parser::Lexer::dfa_table_28 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_218.data(), dfa_state_218.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_219.data(), dfa_state_219.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_220.data(), dfa_state_220.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_221.data(), dfa_state_221.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_222.data(), dfa_state_222.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_223.data(), dfa_state_223.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_224.data(), dfa_state_224.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_225.data(), dfa_state_225.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_226.data(), dfa_state_226.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_227.data(), dfa_state_227.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_228.data(), dfa_state_228.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_229.data(), dfa_state_229.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_230.data(), dfa_state_230.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_231.data(), dfa_state_231.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_232.data(), dfa_state_232.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_233.data(), dfa_state_233.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_234.data(), dfa_state_234.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_235.data(), dfa_state_235.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_233.data(), dfa_state_233.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::Parser::DFA::null_state, {dfa_state_220.data(), dfa_state_220.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_236.data(), dfa_state_236.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_233.data(), dfa_state_233.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::Parser::DFA::null_state, {dfa_state_220.data(), dfa_state_220.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_237.data(), dfa_state_237.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_233.data(), dfa_state_233.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::Parser::DFA::null_state, {dfa_state_220.data(), dfa_state_220.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_238.data(), dfa_state_238.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_233.data(), dfa_state_233.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::Parser::DFA::null_state, {dfa_state_220.data(), dfa_state_220.size()}},
};
const ::Parser::DFA::CharTable<21>Parser::Lexer::dfa_table_29 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_239.data(), dfa_state_239.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_240.data(), dfa_state_240.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_3.data(), dfa_state_3.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_241.data(), dfa_state_241.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_242.data(), dfa_state_242.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_243.data(), dfa_state_243.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_244.data(), dfa_state_244.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_245.data(), dfa_state_245.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_246.data(), dfa_state_246.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_247.data(), dfa_state_247.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_248.data(), dfa_state_248.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_249.data(), dfa_state_249.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_250.data(), dfa_state_250.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_249.data(), dfa_state_249.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_251.data(), dfa_state_251.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_249.data(), dfa_state_249.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_252.data(), dfa_state_252.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_249.data(), dfa_state_249.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_253.data(), dfa_state_253.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_249.data(), dfa_state_249.size()}},
};
const ::Parser::DFA::CharTable<15>Parser::Lexer::dfa_table_30 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_254.data(), dfa_state_254.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_255.data(), dfa_state_255.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_256.data(), dfa_state_256.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_257.data(), dfa_state_257.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_258.data(), dfa_state_258.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_259.data(), dfa_state_259.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 6, 0, {dfa_state_260.data(), dfa_state_260.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 6, 0, {dfa_state_261.data(), dfa_state_261.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 6, 0, {dfa_state_262.data(), dfa_state_262.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_263.data(), dfa_state_263.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 6, 0, {dfa_state_264.data(), dfa_state_264.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 6, 0, {dfa_state_265.data(), dfa_state_265.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 6, 0, {dfa_state_266.data(), dfa_state_266.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 6, 0, {dfa_state_267.data(), dfa_state_267.size()}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 62>Parser::Lexer::dfa_table_31 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_268.data(), dfa_state_268.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_269.data(), dfa_state_269.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_150.data(), dfa_state_150.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_154.data(), dfa_state_154.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_155.data(), dfa_state_155.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_157.data(), dfa_state_157.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_158.data(), dfa_state_158.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_159.data(), dfa_state_159.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_160.data(), dfa_state_160.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_161.data(), dfa_state_161.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_162.data(), dfa_state_162.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 5, {dfa_state_270.data(), dfa_state_270.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_271.data(), dfa_state_271.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_272.data(), dfa_state_272.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_273.data(), dfa_state_273.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_274.data(), dfa_state_274.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_275.data(), dfa_state_275.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_276.data(), dfa_state_276.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_274.data(), dfa_state_274.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_277.data(), dfa_state_277.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_278.data(), dfa_state_278.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_279.data(), dfa_state_279.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_280.data(), dfa_state_280.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_281.data(), dfa_state_281.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_274.data(), dfa_state_274.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_282.data(), dfa_state_282.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_283.data(), dfa_state_283.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_280.data(), dfa_state_280.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_284.data(), dfa_state_284.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_274.data(), dfa_state_274.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_211.data(), dfa_state_211.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_285.data(), dfa_state_285.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_280.data(), dfa_state_280.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_286.data(), dfa_state_286.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_274.data(), dfa_state_274.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_287.data(), dfa_state_287.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_288.data(), dfa_state_288.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_280.data(), dfa_state_280.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_289.data(), dfa_state_289.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_290.data(), dfa_state_290.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_154.data(), dfa_state_154.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_291.data(), dfa_state_291.size()}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 62>Parser::Lexer::dfa_table_32 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_292.data(), dfa_state_292.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_293.data(), dfa_state_293.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_150.data(), dfa_state_150.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_154.data(), dfa_state_154.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_155.data(), dfa_state_155.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_157.data(), dfa_state_157.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_158.data(), dfa_state_158.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_159.data(), dfa_state_159.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_160.data(), dfa_state_160.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_161.data(), dfa_state_161.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_162.data(), dfa_state_162.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_163.data(), dfa_state_163.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 5, {dfa_state_294.data(), dfa_state_294.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_165.data(), dfa_state_165.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_295.data(), dfa_state_295.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_296.data(), dfa_state_296.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_297.data(), dfa_state_297.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_169.data(), dfa_state_169.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 1, {dfa_state_298.data(), dfa_state_298.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_299.data(), dfa_state_299.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_172.data(), dfa_state_172.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_173.data(), dfa_state_173.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_300.data(), dfa_state_300.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_301.data(), dfa_state_301.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_176.data(), dfa_state_176.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_177.data(), dfa_state_177.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_302.data(), dfa_state_302.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_179.data(), dfa_state_179.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_180.data(), dfa_state_180.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_303.data(), dfa_state_303.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_182.data(), dfa_state_182.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_183.data(), dfa_state_183.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_304.data(), dfa_state_304.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_185.data(), dfa_state_185.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_154.data(), dfa_state_154.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_305.data(), dfa_state_305.size()}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 76>Parser::Lexer::dfa_table_33 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_306.data(), dfa_state_306.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_307.data(), dfa_state_307.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_308.data(), dfa_state_308.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_309.data(), dfa_state_309.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_310.data(), dfa_state_310.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_311.data(), dfa_state_311.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_312.data(), dfa_state_312.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_313.data(), dfa_state_313.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_314.data(), dfa_state_314.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_315.data(), dfa_state_315.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_316.data(), dfa_state_316.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_27.data(), dfa_state_27.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_317.data(), dfa_state_317.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_318.data(), dfa_state_318.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_313.data(), dfa_state_313.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_319.data(), dfa_state_319.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_320.data(), dfa_state_320.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_321.data(), dfa_state_321.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_322.data(), dfa_state_322.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_269.data(), dfa_state_269.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_323.data(), dfa_state_323.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_324.data(), dfa_state_324.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_325.data(), dfa_state_325.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_326.data(), dfa_state_326.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_327.data(), dfa_state_327.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_328.data(), dfa_state_328.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_329.data(), dfa_state_329.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_330.data(), dfa_state_330.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_158.data(), dfa_state_158.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_159.data(), dfa_state_159.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_331.data(), dfa_state_331.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_332.data(), dfa_state_332.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_162.data(), dfa_state_162.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 5, {dfa_state_333.data(), dfa_state_333.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_334.data(), dfa_state_334.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_324.data(), dfa_state_324.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_335.data(), dfa_state_335.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_336.data(), dfa_state_336.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_337.data(), dfa_state_337.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_338.data(), dfa_state_338.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_339.data(), dfa_state_339.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_329.data(), dfa_state_329.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_340.data(), dfa_state_340.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_337.data(), dfa_state_337.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_338.data(), dfa_state_338.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_341.data(), dfa_state_341.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_329.data(), dfa_state_329.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_342.data(), dfa_state_342.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_343.data(), dfa_state_343.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_344.data(), dfa_state_344.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_337.data(), dfa_state_337.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_307.data(), dfa_state_307.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_338.data(), dfa_state_338.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_183.data(), dfa_state_183.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_329.data(), dfa_state_329.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_325.data(), dfa_state_325.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_345.data(), dfa_state_345.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_337.data(), dfa_state_337.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_338.data(), dfa_state_338.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_346.data(), dfa_state_346.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_329.data(), dfa_state_329.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_325.data(), dfa_state_325.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_307.data(), dfa_state_307.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_347.data(), dfa_state_347.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_337.data(), dfa_state_337.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::Parser::DFA::null_state, {dfa_state_307.data(), dfa_state_307.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 1, {dfa_state_338.data(), dfa_state_338.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_348.data(), dfa_state_348.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 5, {dfa_state_329.data(), dfa_state_329.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 4, {dfa_state_325.data(), dfa_state_325.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_349.data(), dfa_state_349.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_350.data(), dfa_state_350.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_327.data(), dfa_state_327.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_351.data(), dfa_state_351.size()}},
};
const ::Parser::DFA::CharTable<17>Parser::Lexer::dfa_table_34 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_352.data(), dfa_state_352.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_353.data(), dfa_state_353.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_354.data(), dfa_state_354.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_355.data(), dfa_state_355.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_356.data(), dfa_state_356.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_357.data(), dfa_state_357.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_129.data(), dfa_state_129.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 7, 0, {dfa_state_245.data(), dfa_state_245.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 7, 0, {dfa_state_358.data(), dfa_state_358.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_359.data(), dfa_state_359.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_360.data(), dfa_state_360.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 7, 0, {dfa_state_361.data(), dfa_state_361.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 7, 0, {dfa_state_362.data(), dfa_state_362.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 7, 0, {dfa_state_363.data(), dfa_state_363.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 7, 0, {dfa_state_364.data(), dfa_state_364.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 7, 0, {dfa_state_365.data(), dfa_state_365.size()}},
};
const ::Parser::DFA::CharTable<12>Parser::Lexer::dfa_table_35 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_366.data(), dfa_state_366.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_367.data(), dfa_state_367.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_368.data(), dfa_state_368.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, 0, {dfa_state_369.data(), dfa_state_369.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, 0, {dfa_state_370.data(), dfa_state_370.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, 0, {dfa_state_371.data(), dfa_state_371.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_372.data(), dfa_state_372.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, 0, {dfa_state_373.data(), dfa_state_373.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, 0, {dfa_state_374.data(), dfa_state_374.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, 0, {dfa_state_375.data(), dfa_state_375.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, 0, {dfa_state_376.data(), dfa_state_376.size()}},
};
const ::Parser::DFA::CharTable<14>Parser::Lexer::dfa_table_36 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_377.data(), dfa_state_377.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_378.data(), dfa_state_378.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_379.data(), dfa_state_379.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_380.data(), dfa_state_380.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_381.data(), dfa_state_381.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_382.data(), dfa_state_382.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_383.data(), dfa_state_383.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_384.data(), dfa_state_384.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_385.data(), dfa_state_385.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_386.data(), dfa_state_386.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_387.data(), dfa_state_387.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_388.data(), dfa_state_388.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, 0, {dfa_state_389.data(), dfa_state_389.size()}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_37 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_390.data(), dfa_state_390.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::MultiTable<::Parser::Tokens, 15>Parser::Lexer::dfa_table_38 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_391.data(), dfa_state_391.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_392.data(), dfa_state_392.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_393.data(), dfa_state_393.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_293.data(), dfa_state_293.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_394.data(), dfa_state_394.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_395.data(), dfa_state_395.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_396.data(), dfa_state_396.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_397.data(), dfa_state_397.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_398.data(), dfa_state_398.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_399.data(), dfa_state_399.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_400.data(), dfa_state_400.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_401.data(), dfa_state_401.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_293.data(), dfa_state_293.size()}},
};
const ::Parser::DFA::CharTable<2>Parser::Lexer::dfa_table_39 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {dfa_state_402.data(), dfa_state_402.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ISPA_STD::fcdt_table Parser::Lexer::first_character_dispatch_table = {
	ISPA_STD::fcdt_variant { std::monostate {} }, // '\0'
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // '\a'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '\b'
	ISPA_STD::fcdt_variant { dfa_span_0, }, // '\t'
	ISPA_STD::fcdt_variant { dfa_span_0, }, // '\n'
	ISPA_STD::fcdt_variant { dfa_span_0, }, // '\v'
	ISPA_STD::fcdt_variant { dfa_span_0, }, // '\f'
	ISPA_STD::fcdt_variant { dfa_span_0, }, // '\r'
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { dfa_span_0, }, // ' '
	ISPA_STD::fcdt_variant { dfa_span_1, }, // '!'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '"'
	ISPA_STD::fcdt_variant { dfa_span_2, }, // '#'
	ISPA_STD::fcdt_variant { dfa_span_3, }, // '$'
	ISPA_STD::fcdt_variant { dfa_span_4, }, // '%'
	ISPA_STD::fcdt_variant { dfa_span_5, }, // '&'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '\''
	ISPA_STD::fcdt_variant { dfa_span_6, }, // '('
	ISPA_STD::fcdt_variant { dfa_span_7, }, // ')'
	ISPA_STD::fcdt_variant { dfa_span_8, }, // '*'
	ISPA_STD::fcdt_variant { dfa_span_9, }, // '+'
	ISPA_STD::fcdt_variant { dfa_span_10, }, // ','
	ISPA_STD::fcdt_variant { dfa_span_11, }, // '-'
	ISPA_STD::fcdt_variant { dfa_span_12, }, // '.'
	ISPA_STD::fcdt_variant { dfa_span_13, }, // '/'
	ISPA_STD::fcdt_variant { dfa_span_14, }, // '0'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '1'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '2'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '3'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '4'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '5'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '6'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '7'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '8'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '9'
	ISPA_STD::fcdt_variant { dfa_span_15, }, // ':'
	ISPA_STD::fcdt_variant { dfa_span_16, }, // ';'
	ISPA_STD::fcdt_variant { dfa_span_17, }, // '<'
	ISPA_STD::fcdt_variant { dfa_span_18, }, // '='
	ISPA_STD::fcdt_variant { dfa_span_19, }, // '>'
	ISPA_STD::fcdt_variant { dfa_span_20, }, // '?'
	ISPA_STD::fcdt_variant { dfa_span_21, }, // '@'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'A'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'B'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'C'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'D'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'E'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'F'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'G'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'H'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'I'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'J'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'K'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'L'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'M'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'N'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'O'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'P'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'Q'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'R'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'S'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'T'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'U'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'V'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'W'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'X'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'Y'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'Z'
	ISPA_STD::fcdt_variant { dfa_span_23, }, // '['
	ISPA_STD::fcdt_variant { dfa_span_24, }, // '\\'
	ISPA_STD::fcdt_variant { dfa_span_25, }, // ']'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '^'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // '_'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '`'
	ISPA_STD::fcdt_variant { dfa_span_26, }, // 'a'
	ISPA_STD::fcdt_variant { dfa_span_27, }, // 'b'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'c'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'd'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'e'
	ISPA_STD::fcdt_variant { dfa_span_28, }, // 'f'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'g'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'h'
	ISPA_STD::fcdt_variant { dfa_span_29, }, // 'i'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'j'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'k'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'l'
	ISPA_STD::fcdt_variant { dfa_span_30, }, // 'm'
	ISPA_STD::fcdt_variant { dfa_span_31, }, // 'n'
	ISPA_STD::fcdt_variant { dfa_span_32, }, // 'o'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'p'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'q'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'r'
	ISPA_STD::fcdt_variant { dfa_span_33, }, // 's'
	ISPA_STD::fcdt_variant { dfa_span_34, }, // 't'
	ISPA_STD::fcdt_variant { dfa_span_35, }, // 'u'
	ISPA_STD::fcdt_variant { dfa_span_27, }, // 'v'
	ISPA_STD::fcdt_variant { dfa_span_36, }, // 'w'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'x'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'y'
	ISPA_STD::fcdt_variant { dfa_span_22, }, // 'z'
	ISPA_STD::fcdt_variant { dfa_span_37, }, // '{'
	ISPA_STD::fcdt_variant { dfa_span_38, }, // '|'
	ISPA_STD::fcdt_variant { dfa_span_39, }, // '}'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '~'
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ä'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Å'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ç'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'É'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ñ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ö'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ü'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'á'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'à'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'â'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ä'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ã'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'å'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ç'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'é'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'è'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ê'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ë'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'í'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ì'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'î'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ï'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ñ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ó'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ò'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ô'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ö'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'õ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ú'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ù'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'û'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ü'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '†'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '°'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '¢'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '£'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '§'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '•'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '¶'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ß'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '®'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '©'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '™'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '´'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '¨'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '≠'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Æ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ø'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '∞'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '±'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '≤'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '≥'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '¥'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'µ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '∂'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '∑'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '∏'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'π'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '∫'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ª'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'º'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ω'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'æ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ø'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '¿'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '¡'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '¬'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '√'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ƒ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '≈'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '∆'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '«'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '»'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '…'
	ISPA_STD::fcdt_variant { std::monostate {} }, // ' '
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'À'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ã'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Õ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Œ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'œ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '–'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '—'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '“'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '”'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '‘'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '’'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '÷'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '◊'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ÿ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ÿ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '⁄'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '€'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '‹'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '›'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ﬁ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ﬂ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '‡'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '·'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '‚'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '„'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '‰'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Â'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ê'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Á'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ë'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'È'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Í'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Î'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ï'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ì'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ó'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ô'
	ISPA_STD::fcdt_variant { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ò'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ú'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Û'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'Ù'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ı'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ˆ'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '˜'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '¯'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '˘'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '˙'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '˚'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '¸'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '˝'
	ISPA_STD::fcdt_variant { std::monostate {} }, // '˛'
	ISPA_STD::fcdt_variant { std::monostate {} }, // 'ˇ'
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_0 = {
	dfa_table_0.data(), dfa_table_0.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_1 = {
	dfa_table_1.data(), dfa_table_1.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_2 = {
	dfa_table_2.data(), dfa_table_2.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_3 = {
	dfa_table_3.data(), dfa_table_3.size()
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_4 = {
	{ 	dfa_table_4.data(), dfa_table_4.size() }
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_5 = {
	{ 	dfa_table_5.data(), dfa_table_5.size() }
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_6 = {
	dfa_table_6.data(), dfa_table_6.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_7 = {
	dfa_table_7.data(), dfa_table_7.size()
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_8 = {
	{ 	dfa_table_8.data(), dfa_table_8.size() }
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_9 = {
	{ 	dfa_table_9.data(), dfa_table_9.size() }
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_10 = {
	dfa_table_10.data(), dfa_table_10.size()
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_11 = {
	{ 	dfa_table_11.data(), dfa_table_11.size() }
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_12 = {
	dfa_table_12.data(), dfa_table_12.size()
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_13 = {
	{ 	dfa_table_13.data(), dfa_table_13.size() }
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_14 = {
	dfa_table_14.data(), dfa_table_14.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_15 = {
	dfa_table_15.data(), dfa_table_15.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_16 = {
	dfa_table_16.data(), dfa_table_16.size()
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_17 = {
	{ 	dfa_table_17.data(), dfa_table_17.size() }
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_18 = {
	dfa_table_18.data(), dfa_table_18.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_19 = {
	dfa_table_19.data(), dfa_table_19.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_20 = {
	dfa_table_20.data(), dfa_table_20.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_21 = {
	dfa_table_21.data(), dfa_table_21.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_22 = {
	dfa_table_22.data(), dfa_table_22.size()
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_23 = {
	{ 	dfa_table_23.data(), dfa_table_23.size() }
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_24 = {
	{ 	dfa_table_24.data(), dfa_table_24.size() }
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_25 = {
	{ 	dfa_table_25.data(), dfa_table_25.size() }
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_26 = {
	{ 	dfa_table_26.data(), dfa_table_26.size() }
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_27 = {
	{ 	dfa_table_27.data(), dfa_table_27.size() }
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_28 = {
	dfa_table_28.data(), dfa_table_28.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_29 = {
	dfa_table_29.data(), dfa_table_29.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_30 = {
	dfa_table_30.data(), dfa_table_30.size()
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_31 = {
	{ 	dfa_table_31.data(), dfa_table_31.size() }
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_32 = {
	{ 	dfa_table_32.data(), dfa_table_32.size() }
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_33 = {
	{ 	dfa_table_33.data(), dfa_table_33.size() }
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_34 = {
	dfa_table_34.data(), dfa_table_34.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_35 = {
	dfa_table_35.data(), dfa_table_35.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_36 = {
	dfa_table_36.data(), dfa_table_36.size()
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_37 = {
	dfa_table_37.data(), dfa_table_37.size()
};
const ::Parser::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_38 = {
	{ 	dfa_table_38.data(), dfa_table_38.size() }
};
const ::Parser::SpanCharTable Parser::Lexer::dfa_span_39 = {
	dfa_table_39.data(), dfa_table_39.size()
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
const ::Parser::DFA::TokenTable<::Parser::Tokens, 36>Parser::Parser::dfa_table_0 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_0.data(), dfa_state_0.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 2, ::Parser::DFA::null_state, {dfa_state_1.data(), dfa_state_1.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_2.data(), dfa_state_2.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_3.data(), dfa_state_3.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 6, ::Parser::DFA::null_state, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 7, ::Parser::DFA::null_state, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_7.data(), dfa_state_7.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_8.data(), dfa_state_8.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {dfa_state_9.data(), dfa_state_9.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_10.data(), dfa_state_10.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_11.data(), dfa_state_11.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_12.data(), dfa_state_12.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 8, 0, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 8, 0, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_13.data(), dfa_state_13.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_14.data(), dfa_state_14.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {dfa_state_15.data(), dfa_state_15.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_16.data(), dfa_state_16.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_17.data(), dfa_state_17.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_18.data(), dfa_state_18.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_19.data(), dfa_state_19.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_20.data(), dfa_state_20.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 8, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 7>Parser::Parser::dfa_table_1 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_21.data(), dfa_state_21.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 2, ::Parser::DFA::null_state, {dfa_state_22.data(), dfa_state_22.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_23.data(), dfa_state_23.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_24.data(), dfa_state_24.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_25.data(), dfa_state_25.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 2, 1, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 4>Parser::Parser::dfa_table_2 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_26.data(), dfa_state_26.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_27.data(), dfa_state_27.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 2, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 41>Parser::Parser::dfa_table_3 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_28.data(), dfa_state_28.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_29.data(), dfa_state_29.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_30.data(), dfa_state_30.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_31.data(), dfa_state_31.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_32.data(), dfa_state_32.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_33.data(), dfa_state_33.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_34.data(), dfa_state_34.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_35.data(), dfa_state_35.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 3, ::Parser::DFA::null_state, {dfa_state_36.data(), dfa_state_36.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_37.data(), dfa_state_37.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_38.data(), dfa_state_38.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_39.data(), dfa_state_39.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_40.data(), dfa_state_40.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_41.data(), dfa_state_41.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_42.data(), dfa_state_42.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 3, 1, {dfa_state_43.data(), dfa_state_43.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 3, 0, {dfa_state_32.data(), dfa_state_32.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 3, 0, {dfa_state_32.data(), dfa_state_32.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_44.data(), dfa_state_44.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 3, ::Parser::DFA::null_state, {dfa_state_45.data(), dfa_state_45.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_46.data(), dfa_state_46.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_47.data(), dfa_state_47.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 3, ::Parser::DFA::null_state, {dfa_state_48.data(), dfa_state_48.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 3, ::Parser::DFA::null_state, {dfa_state_49.data(), dfa_state_49.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 3, ::Parser::DFA::null_state, {dfa_state_50.data(), dfa_state_50.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 3, ::Parser::DFA::null_state, {dfa_state_51.data(), dfa_state_51.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, 1, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 8>Parser::Parser::dfa_table_4 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_53.data(), dfa_state_53.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_54.data(), dfa_state_54.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 3, ::Parser::DFA::null_state, {dfa_state_55.data(), dfa_state_55.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_56.data(), dfa_state_56.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 4, ::Parser::DFA::null_state, {dfa_state_55.data(), dfa_state_55.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_57.data(), dfa_state_57.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 4, 1, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 89>Parser::Parser::dfa_table_5 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_58.data(), dfa_state_58.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_59.data(), dfa_state_59.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_60.data(), dfa_state_60.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_61.data(), dfa_state_61.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_62.data(), dfa_state_62.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_63.data(), dfa_state_63.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_65.data(), dfa_state_65.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_66.data(), dfa_state_66.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_67.data(), dfa_state_67.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_68.data(), dfa_state_68.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_69.data(), dfa_state_69.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_70.data(), dfa_state_70.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_71.data(), dfa_state_71.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_72.data(), dfa_state_72.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_73.data(), dfa_state_73.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_74.data(), dfa_state_74.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_75.data(), dfa_state_75.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_76.data(), dfa_state_76.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_77.data(), dfa_state_77.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_78.data(), dfa_state_78.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_79.data(), dfa_state_79.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_80.data(), dfa_state_80.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_81.data(), dfa_state_81.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_82.data(), dfa_state_82.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_83.data(), dfa_state_83.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_84.data(), dfa_state_84.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_85.data(), dfa_state_85.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_86.data(), dfa_state_86.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_87.data(), dfa_state_87.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_88.data(), dfa_state_88.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 11, {dfa_state_59.data(), dfa_state_59.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_89.data(), dfa_state_89.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 10, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_90.data(), dfa_state_90.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_91.data(), dfa_state_91.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 10, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_65.data(), dfa_state_65.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_63.data(), dfa_state_63.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_92.data(), dfa_state_92.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_93.data(), dfa_state_93.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_63.data(), dfa_state_63.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_94.data(), dfa_state_94.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_95.data(), dfa_state_95.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_96.data(), dfa_state_96.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 10, {dfa_state_97.data(), dfa_state_97.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_98.data(), dfa_state_98.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_82.data(), dfa_state_82.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_99.data(), dfa_state_99.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_100.data(), dfa_state_100.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_101.data(), dfa_state_101.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_102.data(), dfa_state_102.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_103.data(), dfa_state_103.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_104.data(), dfa_state_104.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_105.data(), dfa_state_105.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_106.data(), dfa_state_106.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_107.data(), dfa_state_107.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_108.data(), dfa_state_108.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_109.data(), dfa_state_109.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_110.data(), dfa_state_110.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_98.data(), dfa_state_98.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_111.data(), dfa_state_111.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_112.data(), dfa_state_112.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_113.data(), dfa_state_113.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 11, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_114.data(), dfa_state_114.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 11, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_115.data(), dfa_state_115.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 11, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_116.data(), dfa_state_116.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 11, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 6>Parser::Parser::dfa_table_6 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_117.data(), dfa_state_117.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_118.data(), dfa_state_118.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_119.data(), dfa_state_119.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_120.data(), dfa_state_120.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 3, 3, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 134>Parser::Parser::dfa_table_7 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_121.data(), dfa_state_121.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_122.data(), dfa_state_122.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_123.data(), dfa_state_123.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_124.data(), dfa_state_124.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_125.data(), dfa_state_125.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_126.data(), dfa_state_126.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_129.data(), dfa_state_129.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_130.data(), dfa_state_130.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_131.data(), dfa_state_131.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_132.data(), dfa_state_132.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_133.data(), dfa_state_133.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_134.data(), dfa_state_134.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_135.data(), dfa_state_135.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_136.data(), dfa_state_136.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_137.data(), dfa_state_137.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_138.data(), dfa_state_138.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_139.data(), dfa_state_139.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_140.data(), dfa_state_140.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_141.data(), dfa_state_141.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_142.data(), dfa_state_142.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_143.data(), dfa_state_143.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_144.data(), dfa_state_144.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_145.data(), dfa_state_145.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_146.data(), dfa_state_146.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_147.data(), dfa_state_147.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_148.data(), dfa_state_148.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_149.data(), dfa_state_149.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_150.data(), dfa_state_150.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_154.data(), dfa_state_154.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 1, {dfa_state_124.data(), dfa_state_124.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 4, {dfa_state_122.data(), dfa_state_122.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 3, {dfa_state_155.data(), dfa_state_155.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 4, {dfa_state_122.data(), dfa_state_122.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_157.data(), dfa_state_157.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_158.data(), dfa_state_158.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 3, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_159.data(), dfa_state_159.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 3, {dfa_state_135.data(), dfa_state_135.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_160.data(), dfa_state_160.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_161.data(), dfa_state_161.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_162.data(), dfa_state_162.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_163.data(), dfa_state_163.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_164.data(), dfa_state_164.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_165.data(), dfa_state_165.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_166.data(), dfa_state_166.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_167.data(), dfa_state_167.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_168.data(), dfa_state_168.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_169.data(), dfa_state_169.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_170.data(), dfa_state_170.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_141.data(), dfa_state_141.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_171.data(), dfa_state_171.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_172.data(), dfa_state_172.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_173.data(), dfa_state_173.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_174.data(), dfa_state_174.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_175.data(), dfa_state_175.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_176.data(), dfa_state_176.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_177.data(), dfa_state_177.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_178.data(), dfa_state_178.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_179.data(), dfa_state_179.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_180.data(), dfa_state_180.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_181.data(), dfa_state_181.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_182.data(), dfa_state_182.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_183.data(), dfa_state_183.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_184.data(), dfa_state_184.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_185.data(), dfa_state_185.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_186.data(), dfa_state_186.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_187.data(), dfa_state_187.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_188.data(), dfa_state_188.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_189.data(), dfa_state_189.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_190.data(), dfa_state_190.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_191.data(), dfa_state_191.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_192.data(), dfa_state_192.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_193.data(), dfa_state_193.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_194.data(), dfa_state_194.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_195.data(), dfa_state_195.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_196.data(), dfa_state_196.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_197.data(), dfa_state_197.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_198.data(), dfa_state_198.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_199.data(), dfa_state_199.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_200.data(), dfa_state_200.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_201.data(), dfa_state_201.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_202.data(), dfa_state_202.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_203.data(), dfa_state_203.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 33>Parser::Parser::dfa_table_8 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_204.data(), dfa_state_204.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_205.data(), dfa_state_205.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_206.data(), dfa_state_206.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_207.data(), dfa_state_207.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_208.data(), dfa_state_208.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_209.data(), dfa_state_209.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_210.data(), dfa_state_210.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_211.data(), dfa_state_211.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_212.data(), dfa_state_212.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_213.data(), dfa_state_213.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_214.data(), dfa_state_214.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_215.data(), dfa_state_215.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_216.data(), dfa_state_216.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_217.data(), dfa_state_217.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_218.data(), dfa_state_218.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 6, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_219.data(), dfa_state_219.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_220.data(), dfa_state_220.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_221.data(), dfa_state_221.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_222.data(), dfa_state_222.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_223.data(), dfa_state_223.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_214.data(), dfa_state_214.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_214.data(), dfa_state_214.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_224.data(), dfa_state_224.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_225.data(), dfa_state_225.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 4>Parser::Parser::dfa_table_9 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_226.data(), dfa_state_226.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_227.data(), dfa_state_227.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 1, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 4>Parser::Parser::dfa_table_10 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_226.data(), dfa_state_226.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_227.data(), dfa_state_227.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 1, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 4>Parser::Parser::dfa_table_11 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_228.data(), dfa_state_228.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_229.data(), dfa_state_229.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 1, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 4>Parser::Parser::dfa_table_12 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_228.data(), dfa_state_228.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_229.data(), dfa_state_229.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 1, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 4>Parser::Parser::dfa_table_13 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_230.data(), dfa_state_230.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_231.data(), dfa_state_231.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 2, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 4>Parser::Parser::dfa_table_14 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_232.data(), dfa_state_232.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_233.data(), dfa_state_233.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 1, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 45>Parser::Parser::dfa_table_15 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_234.data(), dfa_state_234.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_235.data(), dfa_state_235.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_236.data(), dfa_state_236.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_237.data(), dfa_state_237.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_238.data(), dfa_state_238.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_239.data(), dfa_state_239.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_240.data(), dfa_state_240.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_241.data(), dfa_state_241.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_242.data(), dfa_state_242.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_243.data(), dfa_state_243.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_244.data(), dfa_state_244.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_245.data(), dfa_state_245.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_246.data(), dfa_state_246.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_247.data(), dfa_state_247.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_248.data(), dfa_state_248.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_249.data(), dfa_state_249.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_250.data(), dfa_state_250.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_251.data(), dfa_state_251.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {dfa_state_252.data(), dfa_state_252.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {dfa_state_240.data(), dfa_state_240.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {dfa_state_240.data(), dfa_state_240.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_253.data(), dfa_state_253.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {dfa_state_254.data(), dfa_state_254.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_255.data(), dfa_state_255.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_256.data(), dfa_state_256.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {dfa_state_257.data(), dfa_state_257.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {dfa_state_258.data(), dfa_state_258.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {dfa_state_259.data(), dfa_state_259.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {dfa_state_260.data(), dfa_state_260.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_261.data(), dfa_state_261.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 5, ::Parser::DFA::null_state, {nullptr, 0}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 37>Parser::Parser::dfa_table_16 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_262.data(), dfa_state_262.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_263.data(), dfa_state_263.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_264.data(), dfa_state_264.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_265.data(), dfa_state_265.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_266.data(), dfa_state_266.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_267.data(), dfa_state_267.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_268.data(), dfa_state_268.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_269.data(), dfa_state_269.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_270.data(), dfa_state_270.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_271.data(), dfa_state_271.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_272.data(), dfa_state_272.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_273.data(), dfa_state_273.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_274.data(), dfa_state_274.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_275.data(), dfa_state_275.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 1, {dfa_state_263.data(), dfa_state_263.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_269.data(), dfa_state_269.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_276.data(), dfa_state_276.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, 0, {dfa_state_269.data(), dfa_state_269.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_277.data(), dfa_state_277.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_278.data(), dfa_state_278.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 0, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_279.data(), dfa_state_279.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_280.data(), dfa_state_280.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_281.data(), dfa_state_281.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 0, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_282.data(), dfa_state_282.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 0, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, 0, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_283.data(), dfa_state_283.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_284.data(), dfa_state_284.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 1, ::Parser::DFA::null_state, {dfa_state_51.data(), dfa_state_51.size()}},
};
const ::Parser::DFA::TokenTable<::Parser::Tokens, 8>Parser::Parser::dfa_table_17 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_285.data(), dfa_state_285.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_286.data(), dfa_state_286.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_287.data(), dfa_state_287.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_288.data(), dfa_state_288.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 2, 0, {dfa_state_289.data(), dfa_state_289.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<Parser::Tokens>{ 0, ::Parser::DFA::null_state, {dfa_state_290.data(), dfa_state_290.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<Parser::Tokens>{ 2, ::Parser::DFA::null_state, {nullptr, 0}},
};

