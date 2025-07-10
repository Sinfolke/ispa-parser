#include "Parser.h"
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_0 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<6> Parser::Lexer::dfa_state_1 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { ' ', 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::EmptyTableState Parser::Lexer::dfa_state_2 = {
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_3 = {
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<5> Parser::Lexer::dfa_state_4 = {
	ISPA_STD::DFAAPI::CharTransition { 'n', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '!', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '<', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '=', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { '>', 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_5 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_6 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 2, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_7 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_8 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 2, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_9 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 2, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_10 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 2, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_11 = {
	ISPA_STD::DFAAPI::CharTransition { '#', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_12 = {
	ISPA_STD::DFAAPI::CharTransition { '$', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 6> Parser::Lexer::dfa_state_13 = {
	ISPA_STD::DFAAPI::CharTransition { '%', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '-', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '*', 1, 2 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 5> Parser::Lexer::dfa_state_14 = {
	ISPA_STD::DFAAPI::CharTransition { '&', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'a', 2, 1 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 0 },
	ISPA_STD::DFAAPI::CharTableTransition { dfa_span_0, 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_38, 1, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_15 = {
	ISPA_STD::DFAAPI::CharTransition { 'n', 3, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_16 = {
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_17 = {
	ISPA_STD::DFAAPI::CharTransition { '&', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 2> Parser::Lexer::dfa_state_18 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 0 },
	ISPA_STD::DFAAPI::CharTableTransition { dfa_span_0, 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_19 = {
	ISPA_STD::DFAAPI::CharTransition { '(', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_20 = {
	ISPA_STD::DFAAPI::CharTransition { ')', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 6> Parser::Lexer::dfa_state_21 = {
	ISPA_STD::DFAAPI::CharTransition { '%', 1, 4 },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { '*', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '-', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 6> Parser::Lexer::dfa_state_22 = {
	ISPA_STD::DFAAPI::CharTransition { '+', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '-', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '*', 1, 2 },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { '%', 1, 4 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_23 = {
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_24 = {
	ISPA_STD::DFAAPI::CharTransition { ',', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 6> Parser::Lexer::dfa_state_25 = {
	ISPA_STD::DFAAPI::CharTransition { '-', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '*', 1, 2 },
	ISPA_STD::DFAAPI::CharTransition { '+', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '/', 1, 3 },
	ISPA_STD::DFAAPI::CharTransition { '%', 1, 4 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_26 = {
	ISPA_STD::DFAAPI::CharTransition { '-', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_27 = {
	ISPA_STD::DFAAPI::CharTransition { '.', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 6> Parser::Lexer::dfa_state_28 = {
	ISPA_STD::DFAAPI::CharTransition { '/', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '%', 1, 4 },
	ISPA_STD::DFAAPI::CharTransition { '+', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '-', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '*', 1, 2 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_13, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_29 = {
	ISPA_STD::DFAAPI::CharTransition { '/', 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_30 = {
	ISPA_STD::DFAAPI::CharTransition { '0', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_31 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_32 = {
	ISPA_STD::DFAAPI::CharTransition { ':', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_33 = {
	ISPA_STD::DFAAPI::CharTransition { ';', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_34 = {
	ISPA_STD::DFAAPI::CharTransition { '>', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '<', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { '=', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_35 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_36 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_37 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_38 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 1, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_39 = {
	ISPA_STD::DFAAPI::CharTransition { '=', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '!', 2, 1 },
	ISPA_STD::DFAAPI::CharTransition { '<', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '>', 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_40 = {
	ISPA_STD::DFAAPI::CharTransition { '?', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_41 = {
	ISPA_STD::DFAAPI::CharTransition { '@', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<53> Parser::Lexer::dfa_state_42 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_43 = {
	ISPA_STD::DFAAPI::CharTransition { '6', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_44 = {
	ISPA_STD::DFAAPI::CharTransition { '6', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_45 = {
	ISPA_STD::DFAAPI::CharTransition { '[', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 130> Parser::Lexer::dfa_state_46 = {
	ISPA_STD::DFAAPI::CharTransition { 'ã', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '†', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'á', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'â', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ö', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '≠', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'É', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '·', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ç', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ﬂ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ä', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Å', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ñ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ü', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'à', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'œ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¢', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'å', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ä', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ç', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'é', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'è', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ê', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ë', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'í', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ì', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'î', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ñ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ó', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ò', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ô', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ö', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'ï', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'õ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ù', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ü', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '°', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '£', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '§', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '•', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¶', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ß', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '®', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '©', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '™', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '´', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¨', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Æ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ø', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '∞', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '±', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '≤', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '≥', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¥', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'µ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '∂', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '∑', 1, 1 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_25, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '∏', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'π', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '∫', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ª', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'º', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ω', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'æ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ø', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¿', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¡', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¬', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '√', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ƒ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '≈', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '∆', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '«', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '»', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '…', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'À', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ã', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Õ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Œ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '—', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '”', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '‘', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '’', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '÷', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '◊', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ÿ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ÿ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '⁄', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '€', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '‹', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '›', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ﬁ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '‡', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '‚', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '„', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '‰', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Â', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ê', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Á', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ë', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'È', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Î', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ï', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ì', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ó', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ô', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ò', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ú', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Û', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ù', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ı', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˜', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¯', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˘', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˙', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ú', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˚', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '–', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'û', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˝', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˛', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¸', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ˆ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Í', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '“', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ˇ', 1, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_47 = {
	ISPA_STD::DFAAPI::CharTransition { '0', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_48 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_49 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 2, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 131> Parser::Lexer::dfa_state_50 = {
	ISPA_STD::DFAAPI::CharTransition { 'ê', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ã', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '°', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'œ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¢', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'å', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ö', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'â', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '†', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'á', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'É', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '·', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ç', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '≠', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Å', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ﬂ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ä', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ñ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ü', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'à', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ä', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ç', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'é', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'è', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ë', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'í', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ì', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'î', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ñ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ó', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ò', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ô', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'õ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { ']', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'ö', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\\', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'ï', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ù', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ü', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '£', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '§', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '•', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¶', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ß', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '®', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '©', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '™', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '´', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¨', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Æ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ø', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '∞', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '±', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '≤', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '≥', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¥', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'µ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '∂', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '∑', 1, 1 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_25, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '∏', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'π', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '∫', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ª', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'º', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ω', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'æ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ø', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¿', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¡', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¬', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '√', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ƒ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '≈', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '∆', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '«', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '»', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '…', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { ' ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'À', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ã', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Õ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Œ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '—', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '”', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '‘', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '’', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '÷', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '◊', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ÿ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ÿ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '⁄', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '€', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '‹', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '›', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ﬁ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '‡', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '‚', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '„', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '‰', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Â', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ê', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Á', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ë', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'È', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Î', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ï', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ì', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ó', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ô', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ò', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ú', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Û', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Ù', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ı', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˜', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¯', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˘', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˙', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ú', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˚', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '–', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'û', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˝', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '˛', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '¸', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ˆ', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'Í', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { '“', 1, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'ˇ', 1, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_51 = {
	ISPA_STD::DFAAPI::CharTransition { '\\', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 61> Parser::Lexer::dfa_state_52 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, 0 },
	ISPA_STD::DFAAPI::CharTableTransition { dfa_span_0, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 6, 1 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '&', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 7, 2 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_38, 3, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_53 = {
	ISPA_STD::DFAAPI::CharTransition { '&', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_54 = {
	ISPA_STD::DFAAPI::CharTransition { 'd', 3, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_55 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 10, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_56 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 13, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_57 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 14, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_58 = {
	ISPA_STD::DFAAPI::CharTransition { 'j', 15, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_59 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 3, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_60 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 16, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_61 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 3, 3 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_62 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 17, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_63 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 3, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> Parser::Lexer::dfa_state_64 = {
	ISPA_STD::DFAAPI::CharTableTransition { dfa_span_17, 3, 5 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 1> Parser::Lexer::dfa_state_65 = {
	ISPA_STD::DFAAPI::CharTableTransition { dfa_span_17, 3, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_66 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 3, 2 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 2> Parser::Lexer::dfa_state_67 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 3, 0 },
	ISPA_STD::DFAAPI::CharTableTransition { dfa_span_0, 19, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_68 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 12, 3 },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_69 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 5 },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_70 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 11, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<57> Parser::Lexer::dfa_state_71 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 4, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 7, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 5, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 6, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_72 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 9, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_73 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 10, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_74 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 12, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_75 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 13, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_76 = {
	ISPA_STD::DFAAPI::CharTransition { 'j', 14, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_77 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 15, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_78 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 16, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_79 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 11, 3 },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_80 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 5 },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<55> Parser::Lexer::dfa_state_81 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 10, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 10, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_82 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_83 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_84 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_85 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_86 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_87 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_88 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 9, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_89 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_90 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 11, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_91 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 11, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<4> Parser::Lexer::dfa_state_92 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'n', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<53> Parser::Lexer::dfa_state_93 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_94 = {
	ISPA_STD::DFAAPI::CharTransition { 'p', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_95 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_96 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_97 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_98 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_99 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_100 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'f', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<53> Parser::Lexer::dfa_state_101 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 6, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_102 = {
	ISPA_STD::DFAAPI::CharTransition { 'd', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_103 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_104 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_105 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_106 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<58> Parser::Lexer::dfa_state_107 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '!', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 9, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 7, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 8, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_108 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 3, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_109 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_110 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_111 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 12, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_112 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 14, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_113 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 15, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_114 = {
	ISPA_STD::DFAAPI::CharTransition { 'j', 16, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_115 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 17, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_116 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 18, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_117 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 13, 3 },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_118 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 10, 5 },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_119 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 11, 1 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 4, 1 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 61> Parser::Lexer::dfa_state_120 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, 0 },
	ISPA_STD::DFAAPI::CharTableTransition { dfa_span_0, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 5, 1 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '|', 4, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 6, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 7, 2 },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_38, 3, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_121 = {
	ISPA_STD::DFAAPI::CharTransition { '|', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_122 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 11, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_123 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 9, 5 },
	ISPA_STD::DFAAPI::CharTransition { 'r', 3, 1 },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<57> Parser::Lexer::dfa_state_124 = {
	ISPA_STD::DFAAPI::CharTransition { 'Z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'n', 11, 1 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { '_', 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'v', 14, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'a', 12, 4 },
	ISPA_STD::DFAAPI::CharTransition { 'b', 13, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_125 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_126 = {
	ISPA_STD::DFAAPI::CharTransition { 'c', 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_127 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_128 = {
	ISPA_STD::DFAAPI::CharTransition { 'm', 8, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_129 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 9, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_130 = {
	ISPA_STD::DFAAPI::CharTransition { 'd', 10, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_131 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 16, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_132 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 19, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_133 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 20, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_134 = {
	ISPA_STD::DFAAPI::CharTransition { 'j', 21, 5 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_135 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 22, 4 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_136 = {
	ISPA_STD::DFAAPI::CharTransition { 'o', 23, 2 }
};
const ::ISPA_STD::DFAAPI::CharTableState<3> Parser::Lexer::dfa_state_137 = {
	ISPA_STD::DFAAPI::CharTransition { 't', 18, 3 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_138 = {
	ISPA_STD::DFAAPI::CharTransition { 'b', 15, 5 },
	ISPA_STD::DFAAPI::CharTransition { '9', 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<55> Parser::Lexer::dfa_state_139 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 't', 2, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'f', 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 8, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 8, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_140 = {
	ISPA_STD::DFAAPI::CharTransition { 'a', 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_141 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_142 = {
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_143 = {
	ISPA_STD::DFAAPI::CharTransition { 's', 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_144 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 7, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_145 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 9, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_146 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 9, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<53> Parser::Lexer::dfa_state_147 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'c', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 3, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_148 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_149 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_150 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<53> Parser::Lexer::dfa_state_151 = {
	ISPA_STD::DFAAPI::CharTransition { 'c', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'J', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'w', 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '_', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'e', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\t', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'l', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'd', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\b', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'g', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'm', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'j', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\a', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\v', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\n', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'i', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'h', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'k', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\f', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'B', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'p', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { '\r', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'q', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'D', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 's', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'F', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'u', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'H', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'x', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'G', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'y', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'L', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'z', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'I', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'C', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'E', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'K', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'M', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'N', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'O', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'R', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'S', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'T', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'U', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'W', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'X', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'V', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'P', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'A', 5, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 5, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_152 = {
	ISPA_STD::DFAAPI::CharTransition { 'i', 2, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_153 = {
	ISPA_STD::DFAAPI::CharTransition { 'l', 3, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_154 = {
	ISPA_STD::DFAAPI::CharTransition { 'e', 4, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_155 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<63> Parser::Lexer::dfa_state_156 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\0', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'q', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'D', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'c', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'e', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\v', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\b', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'g', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'd', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'l', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\t', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'm', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'j', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\a', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'o', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'B', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'p', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\r', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'k', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\f', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 's', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'F', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'u', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'H', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'w', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'J', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'x', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'G', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'y', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'L', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'z', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'I', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'A', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'C', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'E', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'K', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'O', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Q', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'S', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'T', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'U', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'V', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'W', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'X', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Y', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '1', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '2', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '3', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '4', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'N', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '5', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'Z', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'P', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'i', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '\n', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '7', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'M', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '8', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '6', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'R', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { '9', 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<2> Parser::Lexer::dfa_state_157 = {
	ISPA_STD::DFAAPI::CharTransition { '_', 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::CharTransition { 'h', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_158 = {
	ISPA_STD::DFAAPI::CharTransition { '{', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 5> Parser::Lexer::dfa_state_159 = {
	ISPA_STD::DFAAPI::CharTransition { '|', 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 0 },
	ISPA_STD::DFAAPI::CharTransition { 'o', 2, 1 },
	ISPA_STD::DFAAPI::CharTableTransition { dfa_span_0, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_38, 1, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_160 = {
	ISPA_STD::DFAAPI::CharTransition { 'r', 1, 1 }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_161 = {
	ISPA_STD::DFAAPI::CharTransition { '|', 1, 0 }
};
const ::ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 2> Parser::Lexer::dfa_state_162 = {
	ISPA_STD::DFAAPI::MultiTableTransition<::Parser::Tokens> { dfa_span_26, 1, 0 },
	ISPA_STD::DFAAPI::CharTableTransition { dfa_span_0, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::CharTableState<1> Parser::Lexer::dfa_state_163 = {
	ISPA_STD::DFAAPI::CharTransition { '}', 1, 0 }
};
const ::ISPA_STD::DFAAPI::CharTable<9> Parser::Lexer::dfa_table_0 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_0.data(), dfa_state_0.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_1.data(), dfa_state_1.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_3.data(), dfa_state_3.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_3.data(), dfa_state_3.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_3.data(), dfa_state_3.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_3.data(), dfa_state_3.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_3.data(), dfa_state_3.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_3.data(), dfa_state_3.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<8> Parser::Lexer::dfa_table_1 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_5.data(), dfa_state_5.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_7.data(), dfa_state_7.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 0, {dfa_state_8.data(), dfa_state_8.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 3, {dfa_state_9.data(), dfa_state_9.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, 2, {dfa_state_10.data(), dfa_state_10.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_2 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_11.data(), dfa_state_11.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_3 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_12.data(), dfa_state_12.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_4 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_13.data(), dfa_state_13.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 7> Parser::Lexer::dfa_table_5 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_14.data(), dfa_state_14.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_15.data(), dfa_state_15.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_16.data(), dfa_state_16.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_17.data(), dfa_state_17.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_18.data(), dfa_state_18.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_6 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_19.data(), dfa_state_19.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_7 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_20.data(), dfa_state_20.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_8 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_21.data(), dfa_state_21.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 4> Parser::Lexer::dfa_table_9 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_22.data(), dfa_state_22.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_23.data(), dfa_state_23.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_10 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_24.data(), dfa_state_24.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 4> Parser::Lexer::dfa_table_11 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_25.data(), dfa_state_25.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_26.data(), dfa_state_26.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_12 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_27.data(), dfa_state_27.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_13 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_28.data(), dfa_state_28.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_29.data(), dfa_state_29.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<3> Parser::Lexer::dfa_table_14 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_30.data(), dfa_state_30.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_31.data(), dfa_state_31.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_15 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_32.data(), dfa_state_32.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_16 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_33.data(), dfa_state_33.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::CharTable<6> Parser::Lexer::dfa_table_17 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_34.data(), dfa_state_34.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_35.data(), dfa_state_35.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_36.data(), dfa_state_36.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_37.data(), dfa_state_37.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_38.data(), dfa_state_38.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<6> Parser::Lexer::dfa_table_18 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_39.data(), dfa_state_39.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_35.data(), dfa_state_35.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_36.data(), dfa_state_36.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 3, {dfa_state_38.data(), dfa_state_38.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_37.data(), dfa_state_37.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<6> Parser::Lexer::dfa_table_19 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_34.data(), dfa_state_34.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_35.data(), dfa_state_35.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_36.data(), dfa_state_36.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 2, {dfa_state_37.data(), dfa_state_37.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 3, {dfa_state_38.data(), dfa_state_38.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_20 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_40.data(), dfa_state_40.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_21 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_41.data(), dfa_state_41.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::CharTable<4> Parser::Lexer::dfa_table_22 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_42.data(), dfa_state_42.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_43.data(), dfa_state_43.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_44.data(), dfa_state_44.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::CharTable<3> Parser::Lexer::dfa_table_23 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_45.data(), dfa_state_45.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 5> Parser::Lexer::dfa_table_24 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_46.data(), dfa_state_46.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_47.data(), dfa_state_47.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_48.data(), dfa_state_48.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_49.data(), dfa_state_49.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 3> Parser::Lexer::dfa_table_25 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_50.data(), dfa_state_50.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_51.data(), dfa_state_51.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 23> Parser::Lexer::dfa_table_26 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_43.data(), dfa_state_43.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_44.data(), dfa_state_44.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_53.data(), dfa_state_53.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_54.data(), dfa_state_54.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_55.data(), dfa_state_55.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_56.data(), dfa_state_56.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_57.data(), dfa_state_57.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_58.data(), dfa_state_58.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_59.data(), dfa_state_59.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_60.data(), dfa_state_60.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_61.data(), dfa_state_61.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_62.data(), dfa_state_62.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_63.data(), dfa_state_63.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_65.data(), dfa_state_65.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_66.data(), dfa_state_66.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_67.data(), dfa_state_67.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_68.data(), dfa_state_68.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_69.data(), dfa_state_69.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_70.data(), dfa_state_70.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 19> Parser::Lexer::dfa_table_27 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_71.data(), dfa_state_71.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_43.data(), dfa_state_43.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_44.data(), dfa_state_44.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_72.data(), dfa_state_72.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_73.data(), dfa_state_73.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_74.data(), dfa_state_74.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_75.data(), dfa_state_75.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_76.data(), dfa_state_76.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_59.data(), dfa_state_59.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_77.data(), dfa_state_77.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_61.data(), dfa_state_61.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_78.data(), dfa_state_78.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_63.data(), dfa_state_63.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_65.data(), dfa_state_65.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_66.data(), dfa_state_66.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_79.data(), dfa_state_79.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_80.data(), dfa_state_80.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<13> Parser::Lexer::dfa_table_28 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_81.data(), dfa_state_81.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_82.data(), dfa_state_82.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_83.data(), dfa_state_83.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_84.data(), dfa_state_84.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_85.data(), dfa_state_85.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_86.data(), dfa_state_86.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_87.data(), dfa_state_87.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_88.data(), dfa_state_88.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_89.data(), dfa_state_89.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 11, ::ISPA_STD::DFAAPI::null_state, {dfa_state_90.data(), dfa_state_90.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_91.data(), dfa_state_91.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_92.data(), dfa_state_92.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<9> Parser::Lexer::dfa_table_29 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_93.data(), dfa_state_93.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_94.data(), dfa_state_94.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_95.data(), dfa_state_95.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_96.data(), dfa_state_96.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_97.data(), dfa_state_97.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 7, ::ISPA_STD::DFAAPI::null_state, {dfa_state_98.data(), dfa_state_98.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_99.data(), dfa_state_99.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_100.data(), dfa_state_100.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<9> Parser::Lexer::dfa_table_30 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_101.data(), dfa_state_101.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_102.data(), dfa_state_102.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_103.data(), dfa_state_103.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_104.data(), dfa_state_104.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_105.data(), dfa_state_105.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 7, ::ISPA_STD::DFAAPI::null_state, {dfa_state_98.data(), dfa_state_98.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_99.data(), dfa_state_99.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_106.data(), dfa_state_106.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 22> Parser::Lexer::dfa_table_31 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_107.data(), dfa_state_107.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_43.data(), dfa_state_43.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_44.data(), dfa_state_44.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_108.data(), dfa_state_108.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_109.data(), dfa_state_109.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_110.data(), dfa_state_110.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_111.data(), dfa_state_111.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_112.data(), dfa_state_112.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_113.data(), dfa_state_113.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_114.data(), dfa_state_114.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_59.data(), dfa_state_59.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_115.data(), dfa_state_115.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_61.data(), dfa_state_61.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_116.data(), dfa_state_116.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_63.data(), dfa_state_63.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_65.data(), dfa_state_65.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_66.data(), dfa_state_66.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_117.data(), dfa_state_117.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_118.data(), dfa_state_118.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_119.data(), dfa_state_119.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 22> Parser::Lexer::dfa_table_32 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_120.data(), dfa_state_120.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_43.data(), dfa_state_43.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_44.data(), dfa_state_44.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_121.data(), dfa_state_121.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_55.data(), dfa_state_55.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_122.data(), dfa_state_122.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_56.data(), dfa_state_56.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_57.data(), dfa_state_57.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_58.data(), dfa_state_58.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_59.data(), dfa_state_59.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_60.data(), dfa_state_60.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_61.data(), dfa_state_61.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_62.data(), dfa_state_62.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_63.data(), dfa_state_63.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_65.data(), dfa_state_65.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_66.data(), dfa_state_66.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_67.data(), dfa_state_67.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_68.data(), dfa_state_68.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_123.data(), dfa_state_123.size()}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 26> Parser::Lexer::dfa_table_33 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_124.data(), dfa_state_124.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_43.data(), dfa_state_43.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_44.data(), dfa_state_44.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_125.data(), dfa_state_125.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_126.data(), dfa_state_126.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_129.data(), dfa_state_129.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_130.data(), dfa_state_130.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_110.data(), dfa_state_110.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_131.data(), dfa_state_131.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_115.data(), dfa_state_115.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_132.data(), dfa_state_132.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_133.data(), dfa_state_133.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_134.data(), dfa_state_134.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_59.data(), dfa_state_59.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_135.data(), dfa_state_135.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_61.data(), dfa_state_61.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_136.data(), dfa_state_136.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_63.data(), dfa_state_63.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_65.data(), dfa_state_65.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_66.data(), dfa_state_66.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_137.data(), dfa_state_137.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_138.data(), dfa_state_138.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<10> Parser::Lexer::dfa_table_34 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_139.data(), dfa_state_139.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_140.data(), dfa_state_140.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_96.data(), dfa_state_96.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_141.data(), dfa_state_141.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_142.data(), dfa_state_142.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_143.data(), dfa_state_143.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_144.data(), dfa_state_144.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 9, ::ISPA_STD::DFAAPI::null_state, {dfa_state_145.data(), dfa_state_145.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 7, ::ISPA_STD::DFAAPI::null_state, {dfa_state_146.data(), dfa_state_146.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<6> Parser::Lexer::dfa_table_35 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_147.data(), dfa_state_147.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_87.data(), dfa_state_87.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_148.data(), dfa_state_148.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_149.data(), dfa_state_149.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_150.data(), dfa_state_150.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<8> Parser::Lexer::dfa_table_36 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_154.data(), dfa_state_154.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 6, ::ISPA_STD::DFAAPI::null_state, {dfa_state_155.data(), dfa_state_155.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_157.data(), dfa_state_157.size()}},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_37 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_158.data(), dfa_state_158.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 6> Parser::Lexer::dfa_table_38 = {
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_159.data(), dfa_state_159.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_160.data(), dfa_state_160.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 1, 0, {dfa_state_161.data(), dfa_state_161.size()}},
	ISPA_STD::DFAAPI::SpanMultiTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_162.data(), dfa_state_162.size()}},
	ISPA_STD::DFAAPI::SpanEmptyTableState{},
};
const ::ISPA_STD::DFAAPI::CharTable<2> Parser::Lexer::dfa_table_39 = {
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_163.data(), dfa_state_163.size()}},
	ISPA_STD::DFAAPI::SpanCharTableState{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ISPA_STD::fcdt_table<::Parser::Tokens> Parser::Lexer::first_character_dispatch_table = {
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\0'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\a'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\b'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_0, }, // '\t'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_0, }, // '\n'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_0, }, // '\v'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_0, }, // '\f'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_0, }, // '\r'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_0, }, // ' '
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_1, }, // '!'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '"'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_2, }, // '#'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_3, }, // '$'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_4, }, // '%'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_5, }, // '&'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '\''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_6, }, // '('
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_7, }, // ')'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_8, }, // '*'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_9, }, // '+'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_10, }, // ','
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_11, }, // '-'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_12, }, // '.'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_13, }, // '/'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_14, }, // '0'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '1'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '2'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '3'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '4'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '5'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '6'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '7'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '8'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '9'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_15, }, // ':'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_16, }, // ';'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_17, }, // '<'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_18, }, // '='
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_19, }, // '>'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_20, }, // '?'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_21, }, // '@'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'A'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'B'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'C'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'D'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'E'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'F'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'G'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'H'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'I'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'J'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'K'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'L'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'M'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'N'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'O'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'P'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'Q'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'R'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'S'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'T'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'U'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'V'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'W'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'X'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'Y'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'Z'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_23, }, // '['
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_24, }, // '\\'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_25, }, // ']'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '^'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // '_'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '`'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_26, }, // 'a'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_27, }, // 'b'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'c'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'd'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'e'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_28, }, // 'f'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'g'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'h'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_29, }, // 'i'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'j'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'k'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'l'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_30, }, // 'm'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_31, }, // 'n'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_32, }, // 'o'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'p'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'q'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'r'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_33, }, // 's'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_34, }, // 't'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_35, }, // 'u'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_27, }, // 'v'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_36, }, // 'w'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'x'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'y'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_22, }, // 'z'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_37, }, // '{'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_38, }, // '|'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { dfa_span_39, }, // '}'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '~'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ä'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Å'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ç'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'É'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ñ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ö'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ü'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'á'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'à'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'â'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ä'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ã'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'å'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ç'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'é'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'è'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ê'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ë'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'í'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ì'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'î'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ï'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ñ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ó'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ò'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ô'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ö'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'õ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ú'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ù'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'û'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ü'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '†'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '°'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '¢'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '£'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '§'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '•'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '¶'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ß'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '®'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '©'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '™'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '´'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '¨'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '≠'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Æ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ø'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '∞'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '±'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '≤'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '≥'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '¥'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'µ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '∂'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '∑'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '∏'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'π'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '∫'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ª'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'º'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ω'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'æ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ø'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '¿'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '¡'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '¬'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '√'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ƒ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '≈'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '∆'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '«'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '»'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '…'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ' '
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'À'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ã'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Õ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Œ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'œ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '–'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '—'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '“'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '”'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '‘'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '’'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '÷'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '◊'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ÿ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ÿ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '⁄'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '€'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '‹'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '›'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ﬁ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ﬂ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '‡'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '·'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '‚'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '„'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '‰'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Â'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ê'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Á'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ë'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'È'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Í'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Î'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ï'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ì'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ó'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ô'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // ''
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ò'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ú'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Û'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'Ù'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ı'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ˆ'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '˜'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '¯'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '˘'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '˙'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '˚'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '¸'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '˝'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // '˛'
	ISPA_STD::fcdt_variant<::Parser::Tokens> { std::monostate {} }, // 'ˇ'
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_0 = {
	dfa_table_0.data(), dfa_table_0.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_1 = {
	dfa_table_1.data(), dfa_table_1.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_2 = {
	dfa_table_2.data(), dfa_table_2.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_3 = {
	dfa_table_3.data(), dfa_table_3.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_4 = {
	{ 	dfa_table_4.data(), dfa_table_4.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_5 = {
	{ 	dfa_table_5.data(), dfa_table_5.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_6 = {
	dfa_table_6.data(), dfa_table_6.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_7 = {
	dfa_table_7.data(), dfa_table_7.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_8 = {
	{ 	dfa_table_8.data(), dfa_table_8.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_9 = {
	{ 	dfa_table_9.data(), dfa_table_9.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_10 = {
	dfa_table_10.data(), dfa_table_10.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_11 = {
	{ 	dfa_table_11.data(), dfa_table_11.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_12 = {
	dfa_table_12.data(), dfa_table_12.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_13 = {
	{ 	dfa_table_13.data(), dfa_table_13.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_14 = {
	dfa_table_14.data(), dfa_table_14.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_15 = {
	dfa_table_15.data(), dfa_table_15.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_16 = {
	dfa_table_16.data(), dfa_table_16.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_17 = {
	dfa_table_17.data(), dfa_table_17.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_18 = {
	dfa_table_18.data(), dfa_table_18.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_19 = {
	dfa_table_19.data(), dfa_table_19.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_20 = {
	dfa_table_20.data(), dfa_table_20.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_21 = {
	dfa_table_21.data(), dfa_table_21.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_22 = {
	dfa_table_22.data(), dfa_table_22.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_23 = {
	dfa_table_23.data(), dfa_table_23.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_24 = {
	{ 	dfa_table_24.data(), dfa_table_24.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_25 = {
	{ 	dfa_table_25.data(), dfa_table_25.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_26 = {
	{ 	dfa_table_26.data(), dfa_table_26.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_27 = {
	{ 	dfa_table_27.data(), dfa_table_27.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_28 = {
	dfa_table_28.data(), dfa_table_28.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_29 = {
	dfa_table_29.data(), dfa_table_29.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_30 = {
	dfa_table_30.data(), dfa_table_30.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_31 = {
	{ 	dfa_table_31.data(), dfa_table_31.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_32 = {
	{ 	dfa_table_32.data(), dfa_table_32.size() }
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_33 = {
	{ 	dfa_table_33.data(), dfa_table_33.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_34 = {
	dfa_table_34.data(), dfa_table_34.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_35 = {
	dfa_table_35.data(), dfa_table_35.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_36 = {
	dfa_table_36.data(), dfa_table_36.size()
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_37 = {
	dfa_table_37.data(), dfa_table_37.size()
};
const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> Parser::Lexer::dfa_span_38 = {
	{ 	dfa_table_38.data(), dfa_table_38.size() }
};
const ::ISPA_STD::DFAAPI::SpanCharTable Parser::Lexer::dfa_span_39 = {
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
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_0 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 4, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 5, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_1 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 11, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_2 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_3 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 7, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_4 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 7, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::EmptyTableState Parser::Parser::dfa_state_5 = {
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_6 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 7, 3 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_7 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 7, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_8 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_9 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> Parser::Parser::dfa_state_10 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 8, 3 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 4, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 5, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_11 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 7, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_12 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_13 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_14 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 7, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_15 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 7, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_16 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_17 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_18 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_19 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_20 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 2, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_21 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_22 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_23 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_24 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 2, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_25 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 1, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 1, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_26 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_27 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 6, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_28 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 8, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_29 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 9, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_30 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_21, 3, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_31 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_32 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 3, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_33 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_34 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_35 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_36 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 6, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_37 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_38 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_39 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_40 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_41 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_42 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_43 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 3, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_44 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_45 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_46 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_47 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 3, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_48 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 3, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_49 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 3, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_50 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 40, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> Parser::Parser::dfa_state_51 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 32, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_52 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 2, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 1, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_53 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_54 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_55 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 4, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_56 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 4, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> Parser::Parser::dfa_state_57 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 1, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 1, 3 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 1, 5 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 1, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 1, 6 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 1, 7 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 1, 9 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 1, 8 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 1, 10 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_58 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_59 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 1, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 15> Parser::Parser::dfa_state_60 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 50, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_18, 48, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_17, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 47, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 46, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 45, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 43, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_15, 41, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_61 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_62 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_63 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_64 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 19> Parser::Parser::dfa_state_65 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 68, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 66, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 64, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 62, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 56, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 54, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 52, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 60, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 58, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_66 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_67 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 70, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_68 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 17> Parser::Parser::dfa_state_69 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 85, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 83, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 81, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 79, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 77, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 75, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 73, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 71, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_70 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_71 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_72 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 89, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 87, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 18, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_73 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_74 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 94, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 93, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 91, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_75 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 96, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 31, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_76 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 100, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 98, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_77 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_78 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 19> Parser::Parser::dfa_state_79 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> Parser::Parser::dfa_state_80 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_81 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 23, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_82 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 102, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 19, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 19> Parser::Parser::dfa_state_83 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_84 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_85 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_86 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 1, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_87 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_88 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 27, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_89 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_90 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_91 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_92 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 39, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_93 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 13, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_94 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_95 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 32, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 27, 11 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_96 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 49, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_97 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 20, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_98 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 53, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_99 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 55, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_100 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 57, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_101 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 59, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_102 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 61, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_103 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 63, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_104 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 65, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_105 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 67, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_106 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 69, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_107 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 10, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_108 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 72, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_109 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 74, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_110 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 76, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_111 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 78, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_112 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 80, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_113 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 82, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_114 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 84, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_115 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 86, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_116 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 88, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_117 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 90, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> Parser::Parser::dfa_state_118 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 92, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 10, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_119 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 8, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_120 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 95, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_121 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 97, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> Parser::Parser::dfa_state_122 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 99, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 4, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 5, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 10, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_123 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 101, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_124 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 103, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 27, 11 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 29, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_125 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_8, 3, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NAME, 1, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::SPACEMODE, 1, 3 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_126 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 1, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_127 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_128 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_8, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 15> Parser::Parser::dfa_state_129 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 47, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_18, 45, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_17, 11, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 43, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 40, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 5, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_15, 38, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_130 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_131 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_132 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 51, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 49, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_133 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_134 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 57, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 13, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 13, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 13, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 13, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 13, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 56, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 13, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 13, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 53, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_135 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 59, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 17, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_136 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 64, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 13, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 61, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_137 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 1, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_138 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_139 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, 4 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_140 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_17, 1, 4 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_141 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 5, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 66, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 7, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 20> Parser::Parser::dfa_state_142 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 98, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 96, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 94, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 92, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 90, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 89, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 86, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 84, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 82, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 80, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 78, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 76, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 72, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 74, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 70, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 68, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_143 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 17> Parser::Parser::dfa_state_144 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 106, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 104, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 102, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 100, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_145 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_146 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 14, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_147 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_148 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_149 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_150 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> Parser::Parser::dfa_state_151 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_18, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_17, 11, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 9, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 5, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_152 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_153 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_154 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_155 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_156 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_157 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> Parser::Parser::dfa_state_158 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 125, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 123, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 121, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 119, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 117, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 115, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 113, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 111, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 109, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 18> Parser::Parser::dfa_state_159 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 153, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 151, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 149, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 147, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 144, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 142, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 140, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 138, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 136, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 134, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 130, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 132, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 128, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 126, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> Parser::Parser::dfa_state_160 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 22, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_161 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_162 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 161, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 159, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 157, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 155, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> Parser::Parser::dfa_state_163 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_164 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_165 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> Parser::Parser::dfa_state_166 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 41, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 19, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 13, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 14, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_167 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 46, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_168 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 48, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 10, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 8, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_169 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 50, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_170 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 52, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 13> Parser::Parser::dfa_state_171 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 55, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 54, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_172 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 58, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_173 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 60, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 13> Parser::Parser::dfa_state_174 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 63, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 62, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_175 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 65, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 1, 4 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_176 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 67, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_7, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 13, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 16, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_177 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 69, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_178 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 71, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_179 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 73, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_180 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 75, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_181 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 77, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_182 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 79, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_183 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 81, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_184 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 83, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_185 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 85, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_186 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 88, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 87, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_187 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 35, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_188 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 91, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_189 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 93, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_190 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 95, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_191 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 97, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_192 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 99, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_193 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 101, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_194 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 103, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_195 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 105, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_196 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 107, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_197 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 32, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_198 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 110, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_199 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 112, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_200 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 114, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_201 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 116, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_202 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 118, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_203 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 120, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_204 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 122, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_205 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 124, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_206 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_207 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 127, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_208 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 129, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_209 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 131, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_210 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 133, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_211 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 135, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_212 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 137, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_213 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 139, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_214 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 141, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> Parser::Parser::dfa_state_215 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 121, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 125, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 123, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 115, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 113, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 119, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 117, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 111, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 109, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_216 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 143, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 19> Parser::Parser::dfa_state_217 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 146, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_CSEQUENCE, 96, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 89, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_BIN, 94, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 90, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 145, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_23, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 86, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 82, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 84, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_ESCAPED, 80, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_OP, 78, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 76, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::QUESTION_MARK, 72, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_NOSPACE, 74, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::rule_HEX, 70, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 68, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_218 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 93, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 21, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> Parser::Parser::dfa_state_219 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 99, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_220 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 148, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_221 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 150, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_222 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 152, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 108, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_223 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 154, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> Parser::Parser::dfa_state_224 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 156, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> Parser::Parser::dfa_state_225 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 158, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> Parser::Parser::dfa_state_226 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_12, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_5, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::LINEAR_COMMENT, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 160, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_227 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 162, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> Parser::Parser::dfa_state_228 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 3, 2 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 3, 4 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, 3 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 3, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 3, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, 6 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_229 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, 6 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_230 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, 6 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 3, 6 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_231 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_232 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 9> Parser::Parser::dfa_state_233 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_234 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DOT, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_235 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_236 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_237 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 3, 5 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_238 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 3, 5 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, 6 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> Parser::Parser::dfa_state_239 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, 6 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, 6 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_240 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_241 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_242 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 3, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_243 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_244 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_245 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 1, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 1, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_246 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_247 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 1, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_248 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_249 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 1, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 1, 2 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_250 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_251 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 1, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 1, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_252 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_253 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 2, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_254 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 26, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_255 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 5, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_256 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 30, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 10, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_257 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 32, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 11, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_258 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_21, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_259 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_260 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_261 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_262 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 10, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> Parser::Parser::dfa_state_263 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 41, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_264 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 43, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 11, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 3, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_265 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_266 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 15, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 5, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_267 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_268 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_269 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_270 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_271 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_272 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_273 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_274 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_275 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_276 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 38, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_277 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 40, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_278 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 42, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> Parser::Parser::dfa_state_279 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 39, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 37, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 44, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 5, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 12, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 6, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> Parser::Parser::dfa_state_280 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 36, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> Parser::Parser::dfa_state_281 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 20, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 19, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 7, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 17, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 16, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 15, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_282 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 2, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 1, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_283 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> Parser::Parser::dfa_state_284 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 27, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_COMPARE_OP, 11, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 11, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MODULO, 11, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::PLUS, 11, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::DIVIDE, 11, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MINUS, 11, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 11, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_285 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 29, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_2, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 14, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_286 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 33, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 31, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_287 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_4, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_288 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_289 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 11, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> Parser::Parser::dfa_state_290 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 9, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 7, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 8, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 35, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::BOOLEAN, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::STRING, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AT, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::NUMBER, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_0, 5, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_291 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 12, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_292 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_14, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_293 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 14, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_6, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> Parser::Parser::dfa_state_294 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 18, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_ASSIGNMENT_OP, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 11, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 12, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> Parser::Parser::dfa_state_295 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 21, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_TYPE, 2, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 10, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_296 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 23, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_297 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 25, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_298 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 28, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_299 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 32, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_300 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 34, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> Parser::Parser::dfa_state_301 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_13, 13, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_20, 22, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 36, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::cll_LOGICAL_OP, 11, 0 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_19, 24, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_3, 1, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> Parser::Parser::dfa_state_302 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 26, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_303 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 6, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 5, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::MULTIPLE, 1, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_304 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_9, 2, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_305 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 3, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, 1 }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_306 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 4, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> Parser::Parser::dfa_state_307 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 1, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_9, 3, 1 },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::AUTO_1, 4, ::ISPA_STD::DFAAPI::null_state }
};
const ::ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> Parser::Parser::dfa_state_308 = {
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::__WHITESPACE, 7, ::ISPA_STD::DFAAPI::null_state },
	ISPA_STD::DFAAPI::TokenTransition<::Parser::Tokens> { Tokens::ID, 2, 0 }
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 31> Parser::Parser::dfa_table_0 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_0.data(), dfa_state_0.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_1.data(), dfa_state_1.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_2.data(), dfa_state_2.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_3.data(), dfa_state_3.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 6, ::ISPA_STD::DFAAPI::null_state, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, ::ISPA_STD::DFAAPI::null_state, {dfa_state_4.data(), dfa_state_4.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_6.data(), dfa_state_6.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_7.data(), dfa_state_7.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_8.data(), dfa_state_8.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_9.data(), dfa_state_9.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_10.data(), dfa_state_10.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_11.data(), dfa_state_11.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_12.data(), dfa_state_12.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, 4, {dfa_state_13.data(), dfa_state_13.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, 1, {dfa_state_7.data(), dfa_state_7.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, 1, {dfa_state_7.data(), dfa_state_7.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, 0, {dfa_state_14.data(), dfa_state_14.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_15.data(), dfa_state_15.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_16.data(), dfa_state_16.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, ::ISPA_STD::DFAAPI::null_state, {dfa_state_17.data(), dfa_state_17.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_18.data(), dfa_state_18.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_19.data(), dfa_state_19.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 7, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 7> Parser::Parser::dfa_table_1 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_20.data(), dfa_state_20.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 2, ::ISPA_STD::DFAAPI::null_state, {dfa_state_21.data(), dfa_state_21.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_22.data(), dfa_state_22.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_23.data(), dfa_state_23.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_24.data(), dfa_state_24.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 2, 1, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_2 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_25.data(), dfa_state_25.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_26.data(), dfa_state_26.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 2, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 41> Parser::Parser::dfa_table_3 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_27.data(), dfa_state_27.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_28.data(), dfa_state_28.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_29.data(), dfa_state_29.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_30.data(), dfa_state_30.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_31.data(), dfa_state_31.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_32.data(), dfa_state_32.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_33.data(), dfa_state_33.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_34.data(), dfa_state_34.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_35.data(), dfa_state_35.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_36.data(), dfa_state_36.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_37.data(), dfa_state_37.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_38.data(), dfa_state_38.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_39.data(), dfa_state_39.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_40.data(), dfa_state_40.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_41.data(), dfa_state_41.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 1, {dfa_state_42.data(), dfa_state_42.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_31.data(), dfa_state_31.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_31.data(), dfa_state_31.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_43.data(), dfa_state_43.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_44.data(), dfa_state_44.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_45.data(), dfa_state_45.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_46.data(), dfa_state_46.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_47.data(), dfa_state_47.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_48.data(), dfa_state_48.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_49.data(), dfa_state_49.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_50.data(), dfa_state_50.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_51.data(), dfa_state_51.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 8> Parser::Parser::dfa_table_4 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_52.data(), dfa_state_52.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_53.data(), dfa_state_53.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_54.data(), dfa_state_54.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_55.data(), dfa_state_55.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 4, ::ISPA_STD::DFAAPI::null_state, {dfa_state_54.data(), dfa_state_54.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_56.data(), dfa_state_56.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 4, 1, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 104> Parser::Parser::dfa_table_5 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_57.data(), dfa_state_57.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_58.data(), dfa_state_58.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_59.data(), dfa_state_59.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_60.data(), dfa_state_60.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_61.data(), dfa_state_61.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_62.data(), dfa_state_62.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_63.data(), dfa_state_63.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_65.data(), dfa_state_65.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_66.data(), dfa_state_66.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_67.data(), dfa_state_67.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_68.data(), dfa_state_68.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_69.data(), dfa_state_69.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_70.data(), dfa_state_70.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_71.data(), dfa_state_71.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_72.data(), dfa_state_72.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_73.data(), dfa_state_73.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_74.data(), dfa_state_74.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_75.data(), dfa_state_75.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_76.data(), dfa_state_76.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_77.data(), dfa_state_77.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_78.data(), dfa_state_78.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_79.data(), dfa_state_79.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_80.data(), dfa_state_80.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_81.data(), dfa_state_81.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_82.data(), dfa_state_82.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_83.data(), dfa_state_83.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_84.data(), dfa_state_84.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_85.data(), dfa_state_85.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_86.data(), dfa_state_86.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_87.data(), dfa_state_87.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_88.data(), dfa_state_88.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_89.data(), dfa_state_89.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_90.data(), dfa_state_90.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 11, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_91.data(), dfa_state_91.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 0, {dfa_state_61.data(), dfa_state_61.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_92.data(), dfa_state_92.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 10, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_93.data(), dfa_state_93.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_94.data(), dfa_state_94.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_95.data(), dfa_state_95.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_70.data(), dfa_state_70.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_77.data(), dfa_state_77.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_70.data(), dfa_state_70.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_96.data(), dfa_state_96.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_97.data(), dfa_state_97.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_98.data(), dfa_state_98.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_99.data(), dfa_state_99.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_100.data(), dfa_state_100.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_101.data(), dfa_state_101.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_102.data(), dfa_state_102.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_103.data(), dfa_state_103.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_104.data(), dfa_state_104.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_105.data(), dfa_state_105.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_106.data(), dfa_state_106.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_107.data(), dfa_state_107.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_108.data(), dfa_state_108.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_109.data(), dfa_state_109.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_110.data(), dfa_state_110.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_111.data(), dfa_state_111.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_112.data(), dfa_state_112.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_113.data(), dfa_state_113.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_114.data(), dfa_state_114.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_115.data(), dfa_state_115.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_116.data(), dfa_state_116.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_117.data(), dfa_state_117.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 11, {dfa_state_118.data(), dfa_state_118.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_119.data(), dfa_state_119.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_84.data(), dfa_state_84.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_120.data(), dfa_state_120.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_121.data(), dfa_state_121.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_122.data(), dfa_state_122.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_119.data(), dfa_state_119.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_123.data(), dfa_state_123.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_124.data(), dfa_state_124.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 6> Parser::Parser::dfa_table_6 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_125.data(), dfa_state_125.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_126.data(), dfa_state_126.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_127.data(), dfa_state_127.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_128.data(), dfa_state_128.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 3, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 163> Parser::Parser::dfa_table_7 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_129.data(), dfa_state_129.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_130.data(), dfa_state_130.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_131.data(), dfa_state_131.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_132.data(), dfa_state_132.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_133.data(), dfa_state_133.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_134.data(), dfa_state_134.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_135.data(), dfa_state_135.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_136.data(), dfa_state_136.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_137.data(), dfa_state_137.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_138.data(), dfa_state_138.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_139.data(), dfa_state_139.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_140.data(), dfa_state_140.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_141.data(), dfa_state_141.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_142.data(), dfa_state_142.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_143.data(), dfa_state_143.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_144.data(), dfa_state_144.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_145.data(), dfa_state_145.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_146.data(), dfa_state_146.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_146.data(), dfa_state_146.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_147.data(), dfa_state_147.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_148.data(), dfa_state_148.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_149.data(), dfa_state_149.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_150.data(), dfa_state_150.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_151.data(), dfa_state_151.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_152.data(), dfa_state_152.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_153.data(), dfa_state_153.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_154.data(), dfa_state_154.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_155.data(), dfa_state_155.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_156.data(), dfa_state_156.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_157.data(), dfa_state_157.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_158.data(), dfa_state_158.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_159.data(), dfa_state_159.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_160.data(), dfa_state_160.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_161.data(), dfa_state_161.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_162.data(), dfa_state_162.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_163.data(), dfa_state_163.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_164.data(), dfa_state_164.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 4, {dfa_state_165.data(), dfa_state_165.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_166.data(), dfa_state_166.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_130.data(), dfa_state_130.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 0, {dfa_state_138.data(), dfa_state_138.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_130.data(), dfa_state_130.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 4, {dfa_state_167.data(), dfa_state_167.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_168.data(), dfa_state_168.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 4, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_169.data(), dfa_state_169.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_170.data(), dfa_state_170.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_171.data(), dfa_state_171.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 4, {dfa_state_143.data(), dfa_state_143.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_172.data(), dfa_state_172.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_173.data(), dfa_state_173.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_174.data(), dfa_state_174.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_175.data(), dfa_state_175.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_176.data(), dfa_state_176.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_177.data(), dfa_state_177.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_178.data(), dfa_state_178.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_179.data(), dfa_state_179.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_180.data(), dfa_state_180.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_181.data(), dfa_state_181.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_182.data(), dfa_state_182.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_183.data(), dfa_state_183.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_184.data(), dfa_state_184.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_185.data(), dfa_state_185.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_186.data(), dfa_state_186.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_187.data(), dfa_state_187.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_155.data(), dfa_state_155.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_188.data(), dfa_state_188.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_189.data(), dfa_state_189.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_190.data(), dfa_state_190.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_191.data(), dfa_state_191.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_192.data(), dfa_state_192.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_193.data(), dfa_state_193.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_194.data(), dfa_state_194.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_195.data(), dfa_state_195.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_196.data(), dfa_state_196.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_197.data(), dfa_state_197.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_198.data(), dfa_state_198.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_199.data(), dfa_state_199.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_200.data(), dfa_state_200.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_201.data(), dfa_state_201.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_202.data(), dfa_state_202.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_203.data(), dfa_state_203.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_204.data(), dfa_state_204.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_205.data(), dfa_state_205.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_206.data(), dfa_state_206.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_207.data(), dfa_state_207.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_208.data(), dfa_state_208.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_209.data(), dfa_state_209.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_210.data(), dfa_state_210.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_211.data(), dfa_state_211.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_212.data(), dfa_state_212.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_213.data(), dfa_state_213.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_214.data(), dfa_state_214.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_215.data(), dfa_state_215.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_216.data(), dfa_state_216.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_217.data(), dfa_state_217.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_218.data(), dfa_state_218.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_219.data(), dfa_state_219.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_220.data(), dfa_state_220.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_221.data(), dfa_state_221.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_222.data(), dfa_state_222.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_223.data(), dfa_state_223.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_224.data(), dfa_state_224.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_225.data(), dfa_state_225.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_226.data(), dfa_state_226.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_227.data(), dfa_state_227.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 22> Parser::Parser::dfa_table_8 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_228.data(), dfa_state_228.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_229.data(), dfa_state_229.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_230.data(), dfa_state_230.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_231.data(), dfa_state_231.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {dfa_state_232.data(), dfa_state_232.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_233.data(), dfa_state_233.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_234.data(), dfa_state_234.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_235.data(), dfa_state_235.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_236.data(), dfa_state_236.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_237.data(), dfa_state_237.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_238.data(), dfa_state_238.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_239.data(), dfa_state_239.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_240.data(), dfa_state_240.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_241.data(), dfa_state_241.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 6, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_242.data(), dfa_state_242.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, 6, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_243.data(), dfa_state_243.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_244.data(), dfa_state_244.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 3, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_9 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_245.data(), dfa_state_245.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_246.data(), dfa_state_246.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 1, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_10 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_245.data(), dfa_state_245.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_246.data(), dfa_state_246.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 1, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_11 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_247.data(), dfa_state_247.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_248.data(), dfa_state_248.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 1, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_12 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_247.data(), dfa_state_247.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_248.data(), dfa_state_248.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 1, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_13 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_249.data(), dfa_state_249.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_250.data(), dfa_state_250.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 2, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> Parser::Parser::dfa_table_14 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_251.data(), dfa_state_251.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_252.data(), dfa_state_252.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 1, {nullptr, 0}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 45> Parser::Parser::dfa_table_15 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_253.data(), dfa_state_253.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_254.data(), dfa_state_254.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_255.data(), dfa_state_255.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_256.data(), dfa_state_256.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_257.data(), dfa_state_257.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_258.data(), dfa_state_258.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_259.data(), dfa_state_259.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_260.data(), dfa_state_260.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_261.data(), dfa_state_261.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_262.data(), dfa_state_262.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_263.data(), dfa_state_263.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_264.data(), dfa_state_264.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_265.data(), dfa_state_265.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_266.data(), dfa_state_266.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_267.data(), dfa_state_267.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_268.data(), dfa_state_268.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_269.data(), dfa_state_269.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_270.data(), dfa_state_270.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_271.data(), dfa_state_271.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_259.data(), dfa_state_259.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_259.data(), dfa_state_259.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_272.data(), dfa_state_272.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_273.data(), dfa_state_273.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_274.data(), dfa_state_274.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_275.data(), dfa_state_275.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_276.data(), dfa_state_276.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_277.data(), dfa_state_277.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_278.data(), dfa_state_278.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_279.data(), dfa_state_279.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 5, ::ISPA_STD::DFAAPI::null_state, {dfa_state_280.data(), dfa_state_280.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 37> Parser::Parser::dfa_table_16 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_281.data(), dfa_state_281.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_282.data(), dfa_state_282.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_283.data(), dfa_state_283.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_284.data(), dfa_state_284.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_285.data(), dfa_state_285.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_286.data(), dfa_state_286.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_287.data(), dfa_state_287.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_288.data(), dfa_state_288.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_289.data(), dfa_state_289.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_290.data(), dfa_state_290.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_291.data(), dfa_state_291.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_292.data(), dfa_state_292.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_293.data(), dfa_state_293.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 1, {dfa_state_282.data(), dfa_state_282.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_294.data(), dfa_state_294.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_64.data(), dfa_state_64.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_295.data(), dfa_state_295.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 1, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_296.data(), dfa_state_296.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 0, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_297.data(), dfa_state_297.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 0, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 0, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_298.data(), dfa_state_298.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, 0, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_157.data(), dfa_state_157.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_299.data(), dfa_state_299.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_300.data(), dfa_state_300.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_301.data(), dfa_state_301.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 1, ::ISPA_STD::DFAAPI::null_state, {dfa_state_302.data(), dfa_state_302.size()}},
};
const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 8> Parser::Parser::dfa_table_17 = {
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_303.data(), dfa_state_303.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_304.data(), dfa_state_304.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_305.data(), dfa_state_305.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_306.data(), dfa_state_306.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 2, 0, {dfa_state_307.data(), dfa_state_307.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 0, ::ISPA_STD::DFAAPI::null_state, {dfa_state_308.data(), dfa_state_308.size()}},
	ISPA_STD::DFAAPI::SpanTokenTableState<::Parser::Tokens>{ 2, ::ISPA_STD::DFAAPI::null_state, {nullptr, 0}},
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

