#include "Parser.h"
Parser::Rule_res Parser::Parser::getRule(Lexer::lazy_iterator &pos) {
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
const ::Parser::Types::ID_data& Parser::get::ID(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::ID) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::ID, "Parser");
	return std::any_cast<const Types::ID_data&>(token.data());
}
::Parser::Types::ID_data& Parser::get::ID(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::ID) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::ID, "Parser");
	return std::any_cast<Types::ID_data&>(token.data());
}
const ::Parser::Types::SPACEMODE_data& Parser::get::SPACEMODE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::SPACEMODE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::SPACEMODE, "Parser");
	return std::any_cast<const Types::SPACEMODE_data&>(token.data());
}
::Parser::Types::SPACEMODE_data& Parser::get::SPACEMODE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::SPACEMODE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::SPACEMODE, "Parser");
	return std::any_cast<Types::SPACEMODE_data&>(token.data());
}
const ::Parser::Types::NAME_data& Parser::get::NAME(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NAME) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NAME, "Parser");
	return std::any_cast<const Types::NAME_data&>(token.data());
}
::Parser::Types::NAME_data& Parser::get::NAME(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NAME) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NAME, "Parser");
	return std::any_cast<Types::NAME_data&>(token.data());
}
const ::Parser::Types::STRING_data& Parser::get::STRING(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::STRING) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::STRING, "Parser");
	return std::any_cast<const Types::STRING_data&>(token.data());
}
::Parser::Types::STRING_data& Parser::get::STRING(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::STRING) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::STRING, "Parser");
	return std::any_cast<Types::STRING_data&>(token.data());
}
const ::Parser::Types::NUMBER_data& Parser::get::NUMBER(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NUMBER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NUMBER, "Parser");
	return std::any_cast<const Types::NUMBER_data&>(token.data());
}
::Parser::Types::NUMBER_data& Parser::get::NUMBER(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NUMBER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NUMBER, "Parser");
	return std::any_cast<Types::NUMBER_data&>(token.data());
}
const ::Parser::Types::BOOLEAN_data& Parser::get::BOOLEAN(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::BOOLEAN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::BOOLEAN, "Parser");
	return std::any_cast<const Types::BOOLEAN_data&>(token.data());
}
::Parser::Types::BOOLEAN_data& Parser::get::BOOLEAN(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::BOOLEAN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::BOOLEAN, "Parser");
	return std::any_cast<Types::BOOLEAN_data&>(token.data());
}
const ::Parser::Types::cll_OP_data& Parser::get::cll_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_OP, "Parser");
	return std::any_cast<const Types::cll_OP_data&>(token.data());
}
::Parser::Types::cll_OP_data& Parser::get::cll_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_OP, "Parser");
	return std::any_cast<Types::cll_OP_data&>(token.data());
}
const ::Parser::Types::cll_ASSIGNMENT_OP_data& Parser::get::cll_ASSIGNMENT_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_ASSIGNMENT_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_ASSIGNMENT_OP, "Parser");
	return std::any_cast<const Types::cll_ASSIGNMENT_OP_data&>(token.data());
}
::Parser::Types::cll_ASSIGNMENT_OP_data& Parser::get::cll_ASSIGNMENT_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_ASSIGNMENT_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_ASSIGNMENT_OP, "Parser");
	return std::any_cast<Types::cll_ASSIGNMENT_OP_data&>(token.data());
}
const ::Parser::Types::cll_COMPARE_OP_data& Parser::get::cll_COMPARE_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_COMPARE_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_COMPARE_OP, "Parser");
	return std::any_cast<const Types::cll_COMPARE_OP_data&>(token.data());
}
::Parser::Types::cll_COMPARE_OP_data& Parser::get::cll_COMPARE_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_COMPARE_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_COMPARE_OP, "Parser");
	return std::any_cast<Types::cll_COMPARE_OP_data&>(token.data());
}
const ::Parser::Types::cll_LOGICAL_OP_data& Parser::get::cll_LOGICAL_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OP, "Parser");
	return std::any_cast<const Types::cll_LOGICAL_OP_data&>(token.data());
}
::Parser::Types::cll_LOGICAL_OP_data& Parser::get::cll_LOGICAL_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OP, "Parser");
	return std::any_cast<Types::cll_LOGICAL_OP_data&>(token.data());
}
const ::Parser::Types::cll_TYPE_data& Parser::get::cll_TYPE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TYPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TYPE, "Parser");
	return std::any_cast<const Types::cll_TYPE_data&>(token.data());
}
::Parser::Types::cll_TYPE_data& Parser::get::cll_TYPE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TYPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TYPE, "Parser");
	return std::any_cast<Types::cll_TYPE_data&>(token.data());
}
const ::Parser::Types::cll_TEMPLATE_data& Parser::get::cll_TEMPLATE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TEMPLATE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TEMPLATE, "Parser");
	return std::any_cast<const Types::cll_TEMPLATE_data&>(token.data());
}
::Parser::Types::cll_TEMPLATE_data& Parser::get::cll_TEMPLATE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TEMPLATE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TEMPLATE, "Parser");
	return std::any_cast<Types::cll_TEMPLATE_data&>(token.data());
}
const ::Parser::Types::Rule_CSEQUENCE_SYMBOL_data& Parser::get::Rule_CSEQUENCE_SYMBOL(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_CSEQUENCE_SYMBOL) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_CSEQUENCE_SYMBOL, "Parser");
	return std::any_cast<const Types::Rule_CSEQUENCE_SYMBOL_data&>(token.data());
}
::Parser::Types::Rule_CSEQUENCE_SYMBOL_data& Parser::get::Rule_CSEQUENCE_SYMBOL(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_CSEQUENCE_SYMBOL) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_CSEQUENCE_SYMBOL, "Parser");
	return std::any_cast<Types::Rule_CSEQUENCE_SYMBOL_data&>(token.data());
}
const ::Parser::Types::Rule_CSEQUENCE_ESCAPE_data& Parser::get::Rule_CSEQUENCE_ESCAPE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_CSEQUENCE_ESCAPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_CSEQUENCE_ESCAPE, "Parser");
	return std::any_cast<const Types::Rule_CSEQUENCE_ESCAPE_data&>(token.data());
}
::Parser::Types::Rule_CSEQUENCE_ESCAPE_data& Parser::get::Rule_CSEQUENCE_ESCAPE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_CSEQUENCE_ESCAPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_CSEQUENCE_ESCAPE, "Parser");
	return std::any_cast<Types::Rule_CSEQUENCE_ESCAPE_data&>(token.data());
}
const ::Parser::Types::Rule_CSEQUENCE_DIAPASON_data& Parser::get::Rule_CSEQUENCE_DIAPASON(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_CSEQUENCE_DIAPASON) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_CSEQUENCE_DIAPASON, "Parser");
	return std::any_cast<const Types::Rule_CSEQUENCE_DIAPASON_data&>(token.data());
}
::Parser::Types::Rule_CSEQUENCE_DIAPASON_data& Parser::get::Rule_CSEQUENCE_DIAPASON(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_CSEQUENCE_DIAPASON) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_CSEQUENCE_DIAPASON, "Parser");
	return std::any_cast<Types::Rule_CSEQUENCE_DIAPASON_data&>(token.data());
}
const ::Parser::Types::Rule_CSEQUENCE_data& Parser::get::Rule_CSEQUENCE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_CSEQUENCE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_CSEQUENCE, "Parser");
	return std::any_cast<const Types::Rule_CSEQUENCE_data&>(token.data());
}
::Parser::Types::Rule_CSEQUENCE_data& Parser::get::Rule_CSEQUENCE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_CSEQUENCE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_CSEQUENCE, "Parser");
	return std::any_cast<Types::Rule_CSEQUENCE_data&>(token.data());
}
const ::Parser::Types::Rule_ESCAPED_data& Parser::get::Rule_ESCAPED(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_ESCAPED) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_ESCAPED, "Parser");
	return std::any_cast<const Types::Rule_ESCAPED_data&>(token.data());
}
::Parser::Types::Rule_ESCAPED_data& Parser::get::Rule_ESCAPED(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_ESCAPED) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_ESCAPED, "Parser");
	return std::any_cast<Types::Rule_ESCAPED_data&>(token.data());
}
const ::Parser::Types::Rule_HEX_data& Parser::get::Rule_HEX(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_HEX) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_HEX, "Parser");
	return std::any_cast<const Types::Rule_HEX_data&>(token.data());
}
::Parser::Types::Rule_HEX_data& Parser::get::Rule_HEX(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_HEX) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_HEX, "Parser");
	return std::any_cast<Types::Rule_HEX_data&>(token.data());
}
const ::Parser::Types::Rule_BIN_data& Parser::get::Rule_BIN(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_BIN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_BIN, "Parser");
	return std::any_cast<const Types::Rule_BIN_data&>(token.data());
}
::Parser::Types::Rule_BIN_data& Parser::get::Rule_BIN(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::Rule_BIN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::Rule_BIN, "Parser");
	return std::any_cast<Types::Rule_BIN_data&>(token.data());
}
const ::Parser::Types::AUTO_0_data& Parser::get::AUTO_0(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_0) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_0, "Parser");
	return std::any_cast<const Types::AUTO_0_data&>(token.data());
}
::Parser::Types::AUTO_0_data& Parser::get::AUTO_0(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_0) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_0, "Parser");
	return std::any_cast<Types::AUTO_0_data&>(token.data());
}
const ::Parser::Types::AUTO_1_data& Parser::get::AUTO_1(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_1) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_1, "Parser");
	return std::any_cast<const Types::AUTO_1_data&>(token.data());
}
::Parser::Types::AUTO_1_data& Parser::get::AUTO_1(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_1) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_1, "Parser");
	return std::any_cast<Types::AUTO_1_data&>(token.data());
}
const ::Parser::Types::AUTO_2_data& Parser::get::AUTO_2(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_2) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_2, "Parser");
	return std::any_cast<const Types::AUTO_2_data&>(token.data());
}
::Parser::Types::AUTO_2_data& Parser::get::AUTO_2(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_2) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_2, "Parser");
	return std::any_cast<Types::AUTO_2_data&>(token.data());
}
const ::Parser::Types::AUTO_3_data& Parser::get::AUTO_3(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_3) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_3, "Parser");
	return std::any_cast<const Types::AUTO_3_data&>(token.data());
}
::Parser::Types::AUTO_3_data& Parser::get::AUTO_3(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_3) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_3, "Parser");
	return std::any_cast<Types::AUTO_3_data&>(token.data());
}
const ::Parser::Types::AUTO_4_data& Parser::get::AUTO_4(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_4) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_4, "Parser");
	return std::any_cast<const Types::AUTO_4_data&>(token.data());
}
::Parser::Types::AUTO_4_data& Parser::get::AUTO_4(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_4) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_4, "Parser");
	return std::any_cast<Types::AUTO_4_data&>(token.data());
}
const ::Parser::Types::AUTO_5_data& Parser::get::AUTO_5(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_5) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_5, "Parser");
	return std::any_cast<const Types::AUTO_5_data&>(token.data());
}
::Parser::Types::AUTO_5_data& Parser::get::AUTO_5(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_5) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_5, "Parser");
	return std::any_cast<Types::AUTO_5_data&>(token.data());
}
const ::Parser::Types::AUTO_6_data& Parser::get::AUTO_6(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_6) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_6, "Parser");
	return std::any_cast<const Types::AUTO_6_data&>(token.data());
}
::Parser::Types::AUTO_6_data& Parser::get::AUTO_6(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_6) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_6, "Parser");
	return std::any_cast<Types::AUTO_6_data&>(token.data());
}
const ::Parser::Types::AUTO_7_data& Parser::get::AUTO_7(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_7) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_7, "Parser");
	return std::any_cast<const Types::AUTO_7_data&>(token.data());
}
::Parser::Types::AUTO_7_data& Parser::get::AUTO_7(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_7) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_7, "Parser");
	return std::any_cast<Types::AUTO_7_data&>(token.data());
}
const ::Parser::Types::AUTO_8_data& Parser::get::AUTO_8(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_8) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_8, "Parser");
	return std::any_cast<const Types::AUTO_8_data&>(token.data());
}
::Parser::Types::AUTO_8_data& Parser::get::AUTO_8(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_8) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_8, "Parser");
	return std::any_cast<Types::AUTO_8_data&>(token.data());
}
const ::Parser::Types::AUTO_9_data& Parser::get::AUTO_9(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_9) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_9, "Parser");
	return std::any_cast<const Types::AUTO_9_data&>(token.data());
}
::Parser::Types::AUTO_9_data& Parser::get::AUTO_9(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_9) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_9, "Parser");
	return std::any_cast<Types::AUTO_9_data&>(token.data());
}
const ::Parser::Types::AUTO_10_data& Parser::get::AUTO_10(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_10) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_10, "Parser");
	return std::any_cast<const Types::AUTO_10_data&>(token.data());
}
::Parser::Types::AUTO_10_data& Parser::get::AUTO_10(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_10) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_10, "Parser");
	return std::any_cast<Types::AUTO_10_data&>(token.data());
}
const ::Parser::Types::AUTO_11_data& Parser::get::AUTO_11(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_11) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_11, "Parser");
	return std::any_cast<const Types::AUTO_11_data&>(token.data());
}
::Parser::Types::AUTO_11_data& Parser::get::AUTO_11(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_11) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_11, "Parser");
	return std::any_cast<Types::AUTO_11_data&>(token.data());
}
const ::Parser::Types::AUTO_12_data& Parser::get::AUTO_12(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_12) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_12, "Parser");
	return std::any_cast<const Types::AUTO_12_data&>(token.data());
}
::Parser::Types::AUTO_12_data& Parser::get::AUTO_12(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_12) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_12, "Parser");
	return std::any_cast<Types::AUTO_12_data&>(token.data());
}
const ::Parser::Types::AUTO_13_data& Parser::get::AUTO_13(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_13) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_13, "Parser");
	return std::any_cast<const Types::AUTO_13_data&>(token.data());
}
::Parser::Types::AUTO_13_data& Parser::get::AUTO_13(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_13) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_13, "Parser");
	return std::any_cast<Types::AUTO_13_data&>(token.data());
}
const ::Parser::Types::AUTO_14_data& Parser::get::AUTO_14(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_14) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_14, "Parser");
	return std::any_cast<const Types::AUTO_14_data&>(token.data());
}
::Parser::Types::AUTO_14_data& Parser::get::AUTO_14(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_14) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_14, "Parser");
	return std::any_cast<Types::AUTO_14_data&>(token.data());
}
const ::Parser::Types::AUTO_15_data& Parser::get::AUTO_15(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_15) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_15, "Parser");
	return std::any_cast<const Types::AUTO_15_data&>(token.data());
}
::Parser::Types::AUTO_15_data& Parser::get::AUTO_15(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_15) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_15, "Parser");
	return std::any_cast<Types::AUTO_15_data&>(token.data());
}
const ::Parser::Types::AUTO_16_data& Parser::get::AUTO_16(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_16) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_16, "Parser");
	return std::any_cast<const Types::AUTO_16_data&>(token.data());
}
::Parser::Types::AUTO_16_data& Parser::get::AUTO_16(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_16) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_16, "Parser");
	return std::any_cast<Types::AUTO_16_data&>(token.data());
}
const ::Parser::Types::AUTO_17_data& Parser::get::AUTO_17(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_17) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_17, "Parser");
	return std::any_cast<const Types::AUTO_17_data&>(token.data());
}
::Parser::Types::AUTO_17_data& Parser::get::AUTO_17(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_17) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_17, "Parser");
	return std::any_cast<Types::AUTO_17_data&>(token.data());
}
const ::Parser::Types::AUTO_18_data& Parser::get::AUTO_18(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_18) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_18, "Parser");
	return std::any_cast<const Types::AUTO_18_data&>(token.data());
}
::Parser::Types::AUTO_18_data& Parser::get::AUTO_18(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_18) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_18, "Parser");
	return std::any_cast<Types::AUTO_18_data&>(token.data());
}
const ::Parser::Types::AUTO_19_data& Parser::get::AUTO_19(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_19) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_19, "Parser");
	return std::any_cast<const Types::AUTO_19_data&>(token.data());
}
::Parser::Types::AUTO_19_data& Parser::get::AUTO_19(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_19) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_19, "Parser");
	return std::any_cast<Types::AUTO_19_data&>(token.data());
}
const ::Parser::Types::AUTO_20_data& Parser::get::AUTO_20(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_20) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_20, "Parser");
	return std::any_cast<const Types::AUTO_20_data&>(token.data());
}
::Parser::Types::AUTO_20_data& Parser::get::AUTO_20(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_20) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_20, "Parser");
	return std::any_cast<Types::AUTO_20_data&>(token.data());
}
const ::Parser::Types::main_data& Parser::get::main(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::main) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::main, "Parser");
	return std::any_cast<const Types::main_data&>(rule.data());
}
::Parser::Types::main_data& Parser::get::main(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::main) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::main, "Parser");
	return std::any_cast<Types::main_data&>(rule.data());
}
const ::Parser::Types::use_unit_data& Parser::get::use_unit(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::use_unit) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::use_unit, "Parser");
	return std::any_cast<const Types::use_unit_data&>(rule.data());
}
::Parser::Types::use_unit_data& Parser::get::use_unit(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::use_unit) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::use_unit, "Parser");
	return std::any_cast<Types::use_unit_data&>(rule.data());
}
const ::Parser::Types::use_data& Parser::get::use(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::use) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::use, "Parser");
	return std::any_cast<const Types::use_data&>(rule.data());
}
::Parser::Types::use_data& Parser::get::use(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::use) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::use, "Parser");
	return std::any_cast<Types::use_data&>(rule.data());
}
const ::Parser::Types::array_data& Parser::get::array(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::array) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::array, "Parser");
	return std::any_cast<const Types::array_data&>(rule.data());
}
::Parser::Types::array_data& Parser::get::array(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::array) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::array, "Parser");
	return std::any_cast<Types::array_data&>(rule.data());
}
const ::Parser::Types::object_data& Parser::get::object(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::object) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::object, "Parser");
	return std::any_cast<const Types::object_data&>(rule.data());
}
::Parser::Types::object_data& Parser::get::object(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::object) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::object, "Parser");
	return std::any_cast<Types::object_data&>(rule.data());
}
const ::Parser::Types::any_data_data& Parser::get::any_data(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::any_data) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::any_data, "Parser");
	return std::any_cast<const Types::any_data_data&>(rule.data());
}
::Parser::Types::any_data_data& Parser::get::any_data(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::any_data) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::any_data, "Parser");
	return std::any_cast<Types::any_data_data&>(rule.data());
}
const ::Parser::Types::cll_if_data& Parser::get::cll_if(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_if) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_if, "Parser");
	return std::any_cast<const Types::cll_if_data&>(rule.data());
}
::Parser::Types::cll_if_data& Parser::get::cll_if(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_if) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_if, "Parser");
	return std::any_cast<Types::cll_if_data&>(rule.data());
}
const ::Parser::Types::cll_variable_data& Parser::get::cll_variable(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_variable) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_variable, "Parser");
	return std::any_cast<const Types::cll_variable_data&>(rule.data());
}
::Parser::Types::cll_variable_data& Parser::get::cll_variable(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_variable) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_variable, "Parser");
	return std::any_cast<Types::cll_variable_data&>(rule.data());
}
const ::Parser::Types::cll_function_body_call_data& Parser::get::cll_function_body_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_call, "Parser");
	return std::any_cast<const Types::cll_function_body_call_data&>(rule.data());
}
::Parser::Types::cll_function_body_call_data& Parser::get::cll_function_body_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_call, "Parser");
	return std::any_cast<Types::cll_function_body_call_data&>(rule.data());
}
const ::Parser::Types::cll_function_body_decl_data& Parser::get::cll_function_body_decl(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_decl, "Parser");
	return std::any_cast<const Types::cll_function_body_decl_data&>(rule.data());
}
::Parser::Types::cll_function_body_decl_data& Parser::get::cll_function_body_decl(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_decl, "Parser");
	return std::any_cast<Types::cll_function_body_decl_data&>(rule.data());
}
const ::Parser::Types::cll_function_arguments_data& Parser::get::cll_function_arguments(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_arguments) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_arguments, "Parser");
	return std::any_cast<const Types::cll_function_arguments_data&>(rule.data());
}
::Parser::Types::cll_function_arguments_data& Parser::get::cll_function_arguments(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_arguments) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_arguments, "Parser");
	return std::any_cast<Types::cll_function_arguments_data&>(rule.data());
}
const ::Parser::Types::cll_function_parameters_data& Parser::get::cll_function_parameters(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_parameters) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_parameters, "Parser");
	return std::any_cast<const Types::cll_function_parameters_data&>(rule.data());
}
::Parser::Types::cll_function_parameters_data& Parser::get::cll_function_parameters(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_parameters) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_parameters, "Parser");
	return std::any_cast<Types::cll_function_parameters_data&>(rule.data());
}
const ::Parser::Types::cll_cll_function_call_data& Parser::get::cll_cll_function_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_cll_function_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_cll_function_call, "Parser");
	return std::any_cast<const Types::cll_cll_function_call_data&>(rule.data());
}
::Parser::Types::cll_cll_function_call_data& Parser::get::cll_cll_function_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_cll_function_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_cll_function_call, "Parser");
	return std::any_cast<Types::cll_cll_function_call_data&>(rule.data());
}
const ::Parser::Types::cll_function_decl_data& Parser::get::cll_function_decl(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_decl, "Parser");
	return std::any_cast<const Types::cll_function_decl_data&>(rule.data());
}
::Parser::Types::cll_function_decl_data& Parser::get::cll_function_decl(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_decl, "Parser");
	return std::any_cast<Types::cll_function_decl_data&>(rule.data());
}
const ::Parser::Types::cll_expr_logical_data& Parser::get::cll_expr_logical(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_logical) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_logical, "Parser");
	return std::any_cast<const Types::cll_expr_logical_data&>(rule.data());
}
::Parser::Types::cll_expr_logical_data& Parser::get::cll_expr_logical(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_logical) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_logical, "Parser");
	return std::any_cast<Types::cll_expr_logical_data&>(rule.data());
}
const ::Parser::Types::cll_expr_compare_data& Parser::get::cll_expr_compare(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_compare) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_compare, "Parser");
	return std::any_cast<const Types::cll_expr_compare_data&>(rule.data());
}
::Parser::Types::cll_expr_compare_data& Parser::get::cll_expr_compare(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_compare) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_compare, "Parser");
	return std::any_cast<Types::cll_expr_compare_data&>(rule.data());
}
const ::Parser::Types::cll_expr_arithmetic_data& Parser::get::cll_expr_arithmetic(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_arithmetic) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_arithmetic, "Parser");
	return std::any_cast<const Types::cll_expr_arithmetic_data&>(rule.data());
}
::Parser::Types::cll_expr_arithmetic_data& Parser::get::cll_expr_arithmetic(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_arithmetic) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_arithmetic, "Parser");
	return std::any_cast<Types::cll_expr_arithmetic_data&>(rule.data());
}
const ::Parser::Types::cll_expr_term_data& Parser::get::cll_expr_term(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_term) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_term, "Parser");
	return std::any_cast<const Types::cll_expr_term_data&>(rule.data());
}
::Parser::Types::cll_expr_term_data& Parser::get::cll_expr_term(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_term) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_term, "Parser");
	return std::any_cast<Types::cll_expr_term_data&>(rule.data());
}
const ::Parser::Types::cll_expr_value_data& Parser::get::cll_expr_value(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_value, "Parser");
	return std::any_cast<const Types::cll_expr_value_data&>(rule.data());
}
::Parser::Types::cll_expr_value_data& Parser::get::cll_expr_value(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_value, "Parser");
	return std::any_cast<Types::cll_expr_value_data&>(rule.data());
}
const ::Parser::Types::cll_expr_group_data& Parser::get::cll_expr_group(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_group, "Parser");
	return std::any_cast<const Types::cll_expr_group_data&>(rule.data());
}
::Parser::Types::cll_expr_group_data& Parser::get::cll_expr_group(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_group, "Parser");
	return std::any_cast<Types::cll_expr_group_data&>(rule.data());
}
const ::Parser::Types::cll_expr_data& Parser::get::cll_expr(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr, "Parser");
	return std::any_cast<const Types::cll_expr_data&>(rule.data());
}
::Parser::Types::cll_expr_data& Parser::get::cll_expr(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr, "Parser");
	return std::any_cast<Types::cll_expr_data&>(rule.data());
}
const ::Parser::Types::cll_var_data& Parser::get::cll_var(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_var) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_var, "Parser");
	return std::any_cast<const Types::cll_var_data&>(rule.data());
}
::Parser::Types::cll_var_data& Parser::get::cll_var(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_var) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_var, "Parser");
	return std::any_cast<Types::cll_var_data&>(rule.data());
}
const ::Parser::Types::cll_block_data& Parser::get::cll_block(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_block) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_block, "Parser");
	return std::any_cast<const Types::cll_block_data&>(rule.data());
}
::Parser::Types::cll_block_data& Parser::get::cll_block(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_block) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_block, "Parser");
	return std::any_cast<Types::cll_block_data&>(rule.data());
}
const ::Parser::Types::cll_loop_while_data& Parser::get::cll_loop_while(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_while) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_while, "Parser");
	return std::any_cast<const Types::cll_loop_while_data&>(rule.data());
}
::Parser::Types::cll_loop_while_data& Parser::get::cll_loop_while(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_while) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_while, "Parser");
	return std::any_cast<Types::cll_loop_while_data&>(rule.data());
}
const ::Parser::Types::cll_loop_for_data& Parser::get::cll_loop_for(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_for) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_for, "Parser");
	return std::any_cast<const Types::cll_loop_for_data&>(rule.data());
}
::Parser::Types::cll_loop_for_data& Parser::get::cll_loop_for(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_for) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_for, "Parser");
	return std::any_cast<Types::cll_loop_for_data&>(rule.data());
}
const ::Parser::Types::cll_data& Parser::get::cll(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll, "Parser");
	return std::any_cast<const Types::cll_data&>(rule.data());
}
::Parser::Types::cll_data& Parser::get::cll(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll, "Parser");
	return std::any_cast<Types::cll_data&>(rule.data());
}
const ::Parser::Types::Rule_rule_data& Parser::get::Rule_rule(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_rule, "Parser");
	return std::any_cast<const Types::Rule_rule_data&>(rule.data());
}
::Parser::Types::Rule_rule_data& Parser::get::Rule_rule(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_rule, "Parser");
	return std::any_cast<Types::Rule_rule_data&>(rule.data());
}
const ::Parser::Types::Rule_name_data& Parser::get::Rule_name(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_name) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_name, "Parser");
	return std::any_cast<const Types::Rule_name_data&>(rule.data());
}
::Parser::Types::Rule_name_data& Parser::get::Rule_name(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_name) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_name, "Parser");
	return std::any_cast<Types::Rule_name_data&>(rule.data());
}
const ::Parser::Types::Rule_group_data& Parser::get::Rule_group(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_group, "Parser");
	return std::any_cast<const Types::Rule_group_data&>(rule.data());
}
::Parser::Types::Rule_group_data& Parser::get::Rule_group(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_group, "Parser");
	return std::any_cast<Types::Rule_group_data&>(rule.data());
}
const ::Parser::Types::Rule_keyvalue_data& Parser::get::Rule_keyvalue(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_keyvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_keyvalue, "Parser");
	return std::any_cast<const Types::Rule_keyvalue_data&>(rule.data());
}
::Parser::Types::Rule_keyvalue_data& Parser::get::Rule_keyvalue(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_keyvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_keyvalue, "Parser");
	return std::any_cast<Types::Rule_keyvalue_data&>(rule.data());
}
const ::Parser::Types::Rule_value_data& Parser::get::Rule_value(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_value, "Parser");
	return std::any_cast<const Types::Rule_value_data&>(rule.data());
}
::Parser::Types::Rule_value_data& Parser::get::Rule_value(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_value, "Parser");
	return std::any_cast<Types::Rule_value_data&>(rule.data());
}
const ::Parser::Types::Rule_nested_rule_data& Parser::get::Rule_nested_rule(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_nested_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_nested_rule, "Parser");
	return std::any_cast<const Types::Rule_nested_rule_data&>(rule.data());
}
::Parser::Types::Rule_nested_rule_data& Parser::get::Rule_nested_rule(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_nested_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_nested_rule, "Parser");
	return std::any_cast<Types::Rule_nested_rule_data&>(rule.data());
}
const ::Parser::Types::Rule_data_block_regular_datablock_key_data& Parser::get::Rule_data_block_regular_datablock_key(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_data_block_regular_datablock_key) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_data_block_regular_datablock_key, "Parser");
	return std::any_cast<const Types::Rule_data_block_regular_datablock_key_data&>(rule.data());
}
::Parser::Types::Rule_data_block_regular_datablock_key_data& Parser::get::Rule_data_block_regular_datablock_key(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_data_block_regular_datablock_key) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_data_block_regular_datablock_key, "Parser");
	return std::any_cast<Types::Rule_data_block_regular_datablock_key_data&>(rule.data());
}
const ::Parser::Types::Rule_data_block_regular_datablock_data& Parser::get::Rule_data_block_regular_datablock(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_data_block_regular_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_data_block_regular_datablock, "Parser");
	return std::any_cast<const Types::Rule_data_block_regular_datablock_data&>(rule.data());
}
::Parser::Types::Rule_data_block_regular_datablock_data& Parser::get::Rule_data_block_regular_datablock(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_data_block_regular_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_data_block_regular_datablock, "Parser");
	return std::any_cast<Types::Rule_data_block_regular_datablock_data&>(rule.data());
}
const ::Parser::Types::Rule_data_block_templated_datablock_data& Parser::get::Rule_data_block_templated_datablock(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_data_block_templated_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_data_block_templated_datablock, "Parser");
	return std::any_cast<const Types::Rule_data_block_templated_datablock_data&>(rule.data());
}
::Parser::Types::Rule_data_block_templated_datablock_data& Parser::get::Rule_data_block_templated_datablock(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_data_block_templated_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_data_block_templated_datablock, "Parser");
	return std::any_cast<Types::Rule_data_block_templated_datablock_data&>(rule.data());
}
const ::Parser::Types::Rule_data_block_data& Parser::get::Rule_data_block(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_data_block) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_data_block, "Parser");
	return std::any_cast<const Types::Rule_data_block_data&>(rule.data());
}
::Parser::Types::Rule_data_block_data& Parser::get::Rule_data_block(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_data_block) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_data_block, "Parser");
	return std::any_cast<Types::Rule_data_block_data&>(rule.data());
}
const ::Parser::Types::Rule_quantifier_data& Parser::get::Rule_quantifier(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_quantifier) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_quantifier, "Parser");
	return std::any_cast<const Types::Rule_quantifier_data&>(rule.data());
}
::Parser::Types::Rule_quantifier_data& Parser::get::Rule_quantifier(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule_quantifier) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule_quantifier, "Parser");
	return std::any_cast<Types::Rule_quantifier_data&>(rule.data());
}
const ::Parser::Types::Rule_data& Parser::get::Rule(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule, "Parser");
	return std::any_cast<const Types::Rule_data&>(rule.data());
}
::Parser::Types::Rule_data& Parser::get::Rule(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::Rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::Rule, "Parser");
	return std::any_cast<Types::Rule_data&>(rule.data());
}

Parser::Token Parser::Lexer::makeToken(const char*& pos) {
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
	success_3 = false;
	success_1 = false;
	_2 = SPACEMODE(pos);
	if (!(_2.status))
	{
		success_5 = false;
		_4 = AUTO_15(pos);
		if (!(_4.status))
		{
			success_7 = false;
			_6 = BOOLEAN(pos);
			if (!(_6.status))
			{
				success_9 = false;
				_8 = NAME(pos);
				if (!(_8.status))
				{
					success_11 = false;
					_10 = Rule_NOSPACE(pos);
					if (!(_10.status))
					{
						success_13 = false;
						_12 = AUTO_0(pos);
						if (!(_12.status))
						{
							success_15 = false;
							_14 = AUTO_16(pos);
							if (!(_14.status))
							{
								success_17 = false;
								_16 = AUTO_9(pos);
								if (!(_16.status))
								{
									success_19 = false;
									_18 = AUTO_14(pos);
									if (!(_18.status))
									{
										success_21 = false;
										_20 = Rule_ESCAPED(pos);
										if (!(_20.status))
										{
											success_23 = false;
											_22 = Rule_HEX(pos);
											if (!(_22.status))
											{
												success_25 = false;
												_24 = Rule_BIN(pos);
												if (!(_24.status))
												{
													success_27 = false;
													_26 = LINEAR_COMMENT(pos);
													if (!(_26.status))
													{
														success_29 = false;
														_28 = AUTO_10(pos);
														if (!(_28.status))
														{
															success_31 = false;
															_30 = AUTO_11(pos);
															if (!(_30.status))
															{
																success_33 = false;
																_32 = cll_LOGICAL_OP(pos);
																if (!(_32.status))
																{
																	success_35 = false;
																	_34 = AUTO_7(pos);
																	if (!(_34.status))
																	{
																		success_37 = false;
																		_36 = Rule_OP(pos);
																		if (!(_36.status))
																		{
																			success_39 = false;
																			_38 = AUTO_4(pos);
																			if (!(_38.status))
																			{
																				success_41 = false;
																				_40 = AUTO_3(pos);
																				if (!(_40.status))
																				{
																					success_43 = false;
																					_42 = Rule_CSEQUENCE(pos);
																					if (!(_42.status))
																					{
																						success_45 = false;
																						_44 = AUTO_2(pos);
																						if (!(_44.status))
																						{
																							success_47 = false;
																							_46 = AT(pos);
																							if (!(_46.status))
																							{
																								success_49 = false;
																								_48 = QUESTION_MARK(pos);
																								if (!(_48.status))
																								{
																									success_51 = false;
																									_50 = AUTO_20(pos);
																									if (!(_50.status))
																									{
																										success_53 = false;
																										_52 = cll_COMPARE_OP(pos);
																										if (!(_52.status))
																										{
																											success_55 = false;
																											_54 = AUTO_6(pos);
																											if (!(_54.status))
																											{
																												success_57 = false;
																												_56 = AUTO_5(pos);
																												if (!(_56.status))
																												{
																													success_59 = false;
																													_58 = DIVIDE(pos);
																													if (!(_58.status))
																													{
																														success_61 = false;
																														_60 = AUTO_18(pos);
																														if (!(_60.status))
																														{
																															success_63 = false;
																															_62 = MINUS(pos);
																															if (!(_62.status))
																															{
																																success_65 = false;
																																_64 = AUTO_1(pos);
																																if (!(_64.status))
																																{
																																	success_67 = false;
																																	_66 = PLUS(pos);
																																	if (!(_66.status))
																																	{
																																		success_69 = false;
																																		_68 = MULTIPLE(pos);
																																		if (!(_68.status))
																																		{
																																			success_71 = false;
																																			_70 = AUTO_13(pos);
																																			if (!(_70.status))
																																			{
																																				success_73 = false;
																																				_72 = AUTO_12(pos);
																																				if (!(_72.status))
																																				{
																																					success_75 = false;
																																					_74 = STRING(pos);
																																					if (!(_74.status))
																																					{
																																						success_77 = false;
																																						_76 = AUTO_19(pos);
																																						if (!(_76.status))
																																						{
																																							success_79 = false;
																																							_78 = MODULO(pos);
																																							if (!(_78.status))
																																							{
																																								success_81 = false;
																																								_80 = cll_ASSIGNMENT_OP(pos);
																																								if (!(_80.status))
																																								{
																																									success_83 = false;
																																									_82 = AUTO_8(pos);
																																									if (!(_82.status))
																																									{
																																										success_85 = false;
																																										_84 = AUTO_17(pos);
																																										if (!(_84.status))
																																										{
																																											success_87 = false;
																																											_86 = __WHITESPACE(pos);
																																											if (!(_86.status))
																																											{
																																												success_89 = false;
																																												_88 = cll_TYPE(pos);
																																												if (!(_88.status))
																																												{
																																													success_91 = false;
																																													_90 = NUMBER(pos);
																																													if (!(_90.status))
																																													{
																																														success_93 = false;
																																														_92 = ID(pos);
																																														if (!(_92.status))
																																														{
																																															success_95 = false;
																																															_94 = END(pos);
																																															if (!(_94.status))
																																															{
																																																success_97 = false;
																																																_96 = NEWLINE(pos);
																																																if (!(_96.status))
																																																{
																																																	return {};
																																																}
																																																else 
																																																{
																																																	success_97 = true;
																																																	pos += _96.node.length();
																																																	_0 = _96.node;
																																																}
																																															}
																																															else 
																																															{
																																																success_95 = true;
																																																pos += _94.node.length();
																																																_0 = _94.node;
																																															}
																																														}
																																														else 
																																														{
																																															success_93 = true;
																																															pos += _92.node.length();
																																															_0 = _92.node;
																																														}
																																													}
																																													else 
																																													{
																																														success_91 = true;
																																														pos += _90.node.length();
																																														_0 = _90.node;
																																													}
																																												}
																																												else 
																																												{
																																													success_89 = true;
																																													pos += _88.node.length();
																																													_0 = _88.node;
																																												}
																																											}
																																											else 
																																											{
																																												success_87 = true;
																																												pos += _86.node.length();
																																												_0 = _86.node;
																																											}
																																										}
																																										else 
																																										{
																																											success_85 = true;
																																											pos += _84.node.length();
																																											_0 = _84.node;
																																										}
																																									}
																																									else 
																																									{
																																										success_83 = true;
																																										pos += _82.node.length();
																																										_0 = _82.node;
																																									}
																																								}
																																								else 
																																								{
																																									success_81 = true;
																																									pos += _80.node.length();
																																									_0 = _80.node;
																																								}
																																							}
																																							else 
																																							{
																																								success_79 = true;
																																								pos += _78.node.length();
																																								_0 = _78.node;
																																							}
																																						}
																																						else 
																																						{
																																							success_77 = true;
																																							pos += _76.node.length();
																																							_0 = _76.node;
																																						}
																																					}
																																					else 
																																					{
																																						success_75 = true;
																																						pos += _74.node.length();
																																						_0 = _74.node;
																																					}
																																				}
																																				else 
																																				{
																																					success_73 = true;
																																					pos += _72.node.length();
																																					_0 = _72.node;
																																				}
																																			}
																																			else 
																																			{
																																				success_71 = true;
																																				pos += _70.node.length();
																																				_0 = _70.node;
																																			}
																																		}
																																		else 
																																		{
																																			success_69 = true;
																																			pos += _68.node.length();
																																			_0 = _68.node;
																																		}
																																	}
																																	else 
																																	{
																																		success_67 = true;
																																		pos += _66.node.length();
																																		_0 = _66.node;
																																	}
																																}
																																else 
																																{
																																	success_65 = true;
																																	pos += _64.node.length();
																																	_0 = _64.node;
																																}
																															}
																															else 
																															{
																																success_63 = true;
																																pos += _62.node.length();
																																_0 = _62.node;
																															}
																														}
																														else 
																														{
																															success_61 = true;
																															pos += _60.node.length();
																															_0 = _60.node;
																														}
																													}
																													else 
																													{
																														success_59 = true;
																														pos += _58.node.length();
																														_0 = _58.node;
																													}
																												}
																												else 
																												{
																													success_57 = true;
																													pos += _56.node.length();
																													_0 = _56.node;
																												}
																											}
																											else 
																											{
																												success_55 = true;
																												pos += _54.node.length();
																												_0 = _54.node;
																											}
																										}
																										else 
																										{
																											success_53 = true;
																											pos += _52.node.length();
																											_0 = _52.node;
																										}
																									}
																									else 
																									{
																										success_51 = true;
																										pos += _50.node.length();
																										_0 = _50.node;
																									}
																								}
																								else 
																								{
																									success_49 = true;
																									pos += _48.node.length();
																									_0 = _48.node;
																								}
																							}
																							else 
																							{
																								success_47 = true;
																								pos += _46.node.length();
																								_0 = _46.node;
																							}
																						}
																						else 
																						{
																							success_45 = true;
																							pos += _44.node.length();
																							_0 = _44.node;
																						}
																					}
																					else 
																					{
																						success_43 = true;
																						pos += _42.node.length();
																						_0 = _42.node;
																					}
																				}
																				else 
																				{
																					success_41 = true;
																					pos += _40.node.length();
																					_0 = _40.node;
																				}
																			}
																			else 
																			{
																				success_39 = true;
																				pos += _38.node.length();
																				_0 = _38.node;
																			}
																		}
																		else 
																		{
																			success_37 = true;
																			pos += _36.node.length();
																			_0 = _36.node;
																		}
																	}
																	else 
																	{
																		success_35 = true;
																		pos += _34.node.length();
																		_0 = _34.node;
																	}
																}
																else 
																{
																	success_33 = true;
																	pos += _32.node.length();
																	_0 = _32.node;
																}
															}
															else 
															{
																success_31 = true;
																pos += _30.node.length();
																_0 = _30.node;
															}
														}
														else 
														{
															success_29 = true;
															pos += _28.node.length();
															_0 = _28.node;
														}
													}
													else 
													{
														success_27 = true;
														pos += _26.node.length();
														_0 = _26.node;
													}
												}
												else 
												{
													success_25 = true;
													pos += _24.node.length();
													_0 = _24.node;
												}
											}
											else 
											{
												success_23 = true;
												pos += _22.node.length();
												_0 = _22.node;
											}
										}
										else 
										{
											success_21 = true;
											pos += _20.node.length();
											_0 = _20.node;
										}
									}
									else 
									{
										success_19 = true;
										pos += _18.node.length();
										_0 = _18.node;
									}
								}
								else 
								{
									success_17 = true;
									pos += _16.node.length();
									_0 = _16.node;
								}
							}
							else 
							{
								success_15 = true;
								pos += _14.node.length();
								_0 = _14.node;
							}
						}
						else 
						{
							success_13 = true;
							pos += _12.node.length();
							_0 = _12.node;
						}
					}
					else 
					{
						success_11 = true;
						pos += _10.node.length();
						_0 = _10.node;
					}
				}
				else 
				{
					success_9 = true;
					pos += _8.node.length();
					_0 = _8.node;
				}
			}
			else 
			{
				success_7 = true;
				pos += _6.node.length();
				_0 = _6.node;
			}
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
	return _0;
}
Parser::Token_res Parser::Lexer::END(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == ';' || *(pos + 0) == '\n'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::END)};
}
Parser::Token_res Parser::Lexer::NEWLINE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '\n'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::NEWLINE)};
}
Parser::Token_res Parser::Lexer::QUESTION_MARK(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '?'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::QUESTION_MARK)};
}
Parser::Token_res Parser::Lexer::PLUS(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '+'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::PLUS)};
}
Parser::Token_res Parser::Lexer::MINUS(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '-'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::MINUS)};
}
Parser::Token_res Parser::Lexer::DIVIDE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '/'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::DIVIDE)};
}
Parser::Token_res Parser::Lexer::MULTIPLE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '*'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::MULTIPLE)};
}
Parser::Token_res Parser::Lexer::MODULO(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '%'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::MODULO)};
}
Parser::Token_res Parser::Lexer::LINEAR_COMMENT(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "//", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	while (!(*(pos + 0) == '\n' && *(pos + 0) != '\0'))
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::LINEAR_COMMENT)};
}
Parser::Token_res Parser::Lexer::ID(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _2;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	success_5 = false;
	success_3 = false;
	success_1 = false;
	auto begin_2 = pos;
	if (!((*(begin_2 + 0)>='a' && *(begin_2 + 0)<='z') || (*(begin_2 + 0)>='A' && *(begin_2 + 0)<='Z') || *(begin_2 + 0) == '_'))
	{
		return {};
	}
	_2 += ::Parser::str_t(begin_2, 1);
	success_3 = true;
	begin_2 += 1;
	skip_spaces(begin_2);
	while ((*(begin_2 + 0)>='a' && *(begin_2 + 0)<='z') || (*(begin_2 + 0)>='A' && *(begin_2 + 0)<='Z') || (*(begin_2 + 0)>='0' && *(begin_2 + 0)<='9') || *(begin_2 + 0) == '_')
	{
		_4 += ::Parser::str_t(begin_2, 1);
		success_5 = true;
		begin_2 += 1;
	}
	_0 += _2;
	_0 += _4;
	if (success_3)
	{
		success_1 = true;
		pos = begin_2;
	}
	::Parser::Types::ID_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::ID, data)};
}
Parser::Token_res Parser::Lexer::SPACEMODE(const char* pos) {
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
	success_5 = false;
	success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "spacemode", 9)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 9);
	success_1 = true;
	pos += 9;
	skip_spaces(pos);
	if (!(!std::strncmp(pos, "skipped", 7)))
	{
		success_7 = false;
		if (!(!std::strncmp(pos, "allowed", 7)))
		{
			success_9 = false;
			if (!(!std::strncmp(pos, "mixed", 5)))
			{
				return {};
			}
			else 
			{
				_8 = ::Parser::str_t(pos, 5);
				success_9 = true;
				pos += 5;
				_2 = _8;
			}
		}
		else 
		{
			_6 = ::Parser::str_t(pos, 7);
			success_7 = true;
			pos += 7;
			_2 = _6;
		}
	}
	else 
	{
		_4 = ::Parser::str_t(pos, 7);
		success_5 = true;
		pos += 7;
		_2 = _4;
	}
	success_3 = true;
	::Parser::Types::SPACEMODE_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::SPACEMODE, data)};
}
Parser::Token_res Parser::Lexer::NAME(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "name", 4)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 4;
	skip_spaces(pos);
	_2 = ID(pos);
	if (!(_2.status))
	{
		reportError(pos, "id");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	::Parser::Types::NAME_data data = _2.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::NAME, data)};
}
Parser::Token_res Parser::Lexer::AT(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '@'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AT)};
}
Parser::Token_res Parser::Lexer::STRING(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _4;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::bool_t success_11 = false;
	::Parser::bool_t success_9 = false;
	::Parser::str_t _8;
	::Parser::str_t _10;
	::Parser::str_t _12;
	::Parser::bool_t success_13 = false;
	::Parser::str_t _14;
	::Parser::bool_t success_15 = false;
	success_15 = false;
	success_5 = false;
	success_3 = false;
	success_1 = false;
	if (!(*(pos + 0) == '\''))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	auto begin_4 = pos;
	while (1)
	{
		success_9 = false;
		success_11 = false;
		success_7 = false;
		auto begin_8 = begin_4;
		do
		{
			if (!(!std::strncmp(begin_8 + 0, "\\", 1)))
			{
				reportError(pos, "\"\\\"");
				break;
			}
			_8 += ::Parser::str_t(begin_8, 1);
			success_9 = true;
			begin_8 += 1;
			if (*(begin_8 + 0) == '\0')
			{
				reportError(pos, "any symbol");
				break;
			}
			_10 += ::Parser::str_t(begin_8, 1);
			success_11 = true;
			begin_8 += 1;
			_6 += _8;
			_6 += _10;
		}
		while(0);
		if (success_9 && success_11)
		{
			success_7 = true;
			begin_4 = begin_8;
		}
		;
		if (!success_7)
		{
			success_13 = false;
			if (!(!(*(begin_4 + 0) == '\'')))
			{
				break;
			}
			else 
			{
				_12 = ::Parser::str_t(begin_4, 1);
				success_13 = true;
				begin_4 += 1;
				_4 = _12;
			}
		}
		else 
		{
			_4 = _6;
		}
		success_5 = true;
		_2 += _4;
	}
	if (success_5)
	{
		success_3 = true;
		pos = begin_4;
	}
	skip_spaces(pos);
	if (!(*(pos + 0) == '\''))
	{
		reportError(pos, "\"'\"");
		return {};
	}
	_14 += ::Parser::str_t(pos, 1);
	success_15 = true;
	pos += 1;
	::Parser::Types::STRING_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::STRING, data)};
}
Parser::Token_res Parser::Lexer::NUMBER(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_6 = false;
	::Parser::str_t _7;
	::Parser::bool_t success_8 = false;
	::Parser::bool_t success_12 = false;
	::Parser::bool_t success_10 = false;
	::Parser::str_t _9;
	::Parser::str_t _11;
	::Parser::bool_t success_13 = false;
	success_10 = false;
	success_12 = false;
	success_8 = false;
	success_6 = false;
	success_5 = false;
	success_3 = false;
	success_1 = false;
	if (*(pos + 0) == '+' || *(pos + 0) == '-')
	{
		_0 += ::Parser::str_t(pos, 1);
		success_1 = true;
		pos += 1;
	}
	skip_spaces(pos);
	auto begin_4 = pos;
	while ((*(begin_4 + 0)>='0' && *(begin_4 + 0)<='9'))
	{
		_4 += ::Parser::str_t(begin_4, 1);
		success_5 = true;
		begin_4 += 1;
		success_6 = true;
	}
	if (!success_6)
	{
		reportError(pos, "0-9 or ");
		return {};
	}
	_2 += _4;
	if (success_5)
	{
		success_3 = true;
		pos = begin_4;
	}
	skip_spaces(pos);
	auto begin_9 = pos;
	do
	{
		success_13 = false;
		if (!(*(begin_9 + 0) == '.' || *(begin_9 + 0) == ','))
		{
			reportError(pos, ".,");
			break;
		}
		_9 += ::Parser::str_t(begin_9, 1);
		success_10 = true;
		begin_9 += 1;
		skip_spaces(begin_9);
		while ((*(begin_9 + 0)>='0' && *(begin_9 + 0)<='9'))
		{
			_11 += ::Parser::str_t(begin_9, 1);
			success_12 = true;
			begin_9 += 1;
			success_13 = true;
		}
		if (!success_13)
		{
			reportError(pos, "0-9 or ");
			break;
		}
		_7 += _9;
		_7 += _11;
	}
	while(0);
	if (success_10 && success_12)
	{
		success_8 = true;
		pos = begin_9;
	}
	::Parser::Types::NUMBER_data data;
	data.dec = _9;
	data.main = _4;
	data.sign = _0;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::NUMBER, data)};
}
Parser::Token_res Parser::Lexer::BOOLEAN(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::str_t d;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _2;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	success_5 = false;
	success_3 = false;
	success_1 = false;
	auto begin_2 = pos;
	if (!(!std::strncmp(begin_2, "false", 5)))
	{
		success_7 = false;
		if (!(!std::strncmp(begin_2, "true", 4)))
		{
			return {};
		}
		else 
		{
			_6 = ::Parser::str_t(begin_2, 4);
			success_7 = true;
			begin_2 += 4;
			_2 = _6;
		}
	}
	else 
	{
		_4 = ::Parser::str_t(begin_2, 5);
		success_5 = true;
		begin_2 += 5;
		_2 = _4;
	}
	success_3 = true;
	_0 += _2;
	if (success_3)
	{
		success_1 = true;
		d = _0;
		pos = begin_2;
	}
	::Parser::Types::BOOLEAN_data data = d;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::BOOLEAN, data)};
}
Parser::Token_res Parser::Lexer::cll_OP(const char* pos) {
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
	success_3 = false;
	success_1 = false;
	if (!(*(pos + 0) == '/'))
	{
		success_5 = false;
		if (!(*(pos + 0) == '-'))
		{
			success_7 = false;
			if (!(*(pos + 0) == '+'))
			{
				success_9 = false;
				if (!(*(pos + 0) == '*'))
				{
					success_11 = false;
					if (!(*(pos + 0) == '%'))
					{
						return {};
					}
					else 
					{
						_10 = ::Parser::str_t(pos, 1);
						success_11 = true;
						pos += 1;
						_0 = _10;
					}
				}
				else 
				{
					_8 = ::Parser::str_t(pos, 1);
					success_9 = true;
					pos += 1;
					_0 = _8;
				}
			}
			else 
			{
				_6 = ::Parser::str_t(pos, 1);
				success_7 = true;
				pos += 1;
				_0 = _6;
			}
		}
		else 
		{
			_4 = ::Parser::str_t(pos, 1);
			success_5 = true;
			pos += 1;
			_0 = _4;
		}
	}
	else 
	{
		_2 = ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		_0 = _2;
	}
	success_1 = true;
	::Parser::Types::cll_OP_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_OP, data)};
}
Parser::Token_res Parser::Lexer::cll_ASSIGNMENT_OP(const char* pos) {
	auto in = pos;
	::Parser::Token_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	success_3 = false;
	success_1 = false;
	_0 = cll_OP(pos);
	if (_0.status)
	{
		success_1 = true;
		pos += _0.node.length();
	}
	skip_spaces(pos);
	_2 = AUTO_20(pos);
	if (!(_2.status))
	{
		reportError(pos, "\"=\"");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	::Parser::Types::cll_ASSIGNMENT_OP_data data = _0.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_ASSIGNMENT_OP, data)};
}
Parser::Token_res Parser::Lexer::cll_COMPARE_OP(const char* pos) {
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
	success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos, ">=", 2)))
	{
		success_5 = false;
		if (!(!std::strncmp(pos, "==", 2)))
		{
			success_7 = false;
			if (!(!std::strncmp(pos, "<=", 2)))
			{
				success_9 = false;
				if (!(!std::strncmp(pos, "!=", 2)))
				{
					success_11 = false;
					if (!(*(pos + 0) == '>'))
					{
						success_13 = false;
						if (!(*(pos + 0) == '<'))
						{
							return {};
						}
						else 
						{
							_12 = ::Parser::str_t(pos, 1);
							success_13 = true;
							pos += 1;
							_0 = _12;
						}
					}
					else 
					{
						_10 = ::Parser::str_t(pos, 1);
						success_11 = true;
						pos += 1;
						_0 = _10;
					}
				}
				else 
				{
					_8 = ::Parser::str_t(pos, 2);
					success_9 = true;
					pos += 2;
					_0 = _8;
				}
			}
			else 
			{
				_6 = ::Parser::str_t(pos, 2);
				success_7 = true;
				pos += 2;
				_0 = _6;
			}
		}
		else 
		{
			_4 = ::Parser::str_t(pos, 2);
			success_5 = true;
			pos += 2;
			_0 = _4;
		}
	}
	else 
	{
		_2 = ::Parser::str_t(pos, 2);
		success_3 = true;
		pos += 2;
		_0 = _2;
	}
	success_1 = true;
	::Parser::Types::cll_COMPARE_OP_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_COMPARE_OP, data)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_OP(const char* pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token_res _4;
	::Parser::bool_t success_5 = false;
	success_3 = false;
	success_1 = false;
	_2 = cll_LOGICAL_OR(pos);
	if (!(_2.status))
	{
		success_5 = false;
		_4 = cll_LOGICAL_AND(pos);
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
	::Parser::Types::cll_LOGICAL_OP_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_LOGICAL_OP, data)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_NOT(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos, "not", 3)))
	{
		success_5 = false;
		if (!(*(pos + 0) == '!'))
		{
			return {};
		}
		else 
		{
			_4 = ::Parser::str_t(pos, 1);
			success_5 = true;
			pos += 1;
			_0 = _4;
		}
	}
	else 
	{
		_2 = ::Parser::str_t(pos, 3);
		success_3 = true;
		pos += 3;
		_0 = _2;
	}
	success_1 = true;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_LOGICAL_NOT)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_AND(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos, "and", 3)))
	{
		success_5 = false;
		if (!(!std::strncmp(pos, "&&", 2)))
		{
			return {};
		}
		else 
		{
			_4 = ::Parser::str_t(pos, 2);
			success_5 = true;
			pos += 2;
			_0 = _4;
		}
	}
	else 
	{
		_2 = ::Parser::str_t(pos, 3);
		success_3 = true;
		pos += 3;
		_0 = _2;
	}
	success_1 = true;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_LOGICAL_AND)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_OR(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos, "||", 2)))
	{
		success_5 = false;
		if (!(!std::strncmp(pos, "or", 2)))
		{
			return {};
		}
		else 
		{
			_4 = ::Parser::str_t(pos, 2);
			success_5 = true;
			pos += 2;
			_0 = _4;
		}
	}
	else 
	{
		_2 = ::Parser::str_t(pos, 2);
		success_3 = true;
		pos += 2;
		_0 = _2;
	}
	success_1 = true;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_LOGICAL_OR)};
}
Parser::Token_res Parser::Lexer::cll_TYPE(const char* pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::any_t _2;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::str_t _8;
	::Parser::bool_t success_9 = false;
	::Parser::str_t _10;
	::Parser::bool_t success_11 = false;
	::Parser::bool_t success_13 = false;
	::Parser::bool_t success_17 = false;
	::Parser::bool_t success_15 = false;
	::Parser::str_t _14;
	::Parser::Token_res _16;
	::Parser::bool_t success_19 = false;
	::Parser::bool_t success_23 = false;
	::Parser::bool_t success_21 = false;
	::Parser::str_t _20;
	::Parser::Token_res _22;
	success_5 = false;
	success_3 = false;
	success_1 = false;
	auto begin_2 = pos;
	if (!(!std::strncmp(begin_2, "bool", 4)))
	{
		success_7 = false;
		if (!(!std::strncmp(begin_2, "var", 3)))
		{
			success_9 = false;
			if (!(!std::strncmp(begin_2, "str", 3)))
			{
				success_11 = false;
				if (!(!std::strncmp(begin_2, "num", 3)))
				{
					success_15 = false;
					success_17 = false;
					success_13 = false;
					auto begin_14 = begin_2;
					do
					{
						if (!(!std::strncmp(begin_14 + 0, "obj", 3)))
						{
							break;
						}
						_14 += ::Parser::str_t(begin_14, 3);
						success_15 = true;
						begin_14 += 3;
						skip_spaces(begin_14);
						_16 = cll_TEMPLATE(begin_14);
						if (!(_16.status))
						{
							reportError(pos, "template");
							break;
						}
						success_17 = true;
						begin_14 += _16.node.length();
					}
					while(0);
					if (success_15 && success_17)
					{
						success_13 = true;
						begin_2 = begin_14;
					}
					;
					if (!success_13)
					{
						success_21 = false;
						success_23 = false;
						success_19 = false;
						auto begin_20 = begin_2;
						do
						{
							if (!(!std::strncmp(begin_20 + 0, "arr", 3)))
							{
								break;
							}
							_20 += ::Parser::str_t(begin_20, 3);
							success_21 = true;
							begin_20 += 3;
							skip_spaces(begin_20);
							_22 = cll_TEMPLATE(begin_20);
							if (!(_22.status))
							{
								reportError(pos, "template");
								break;
							}
							success_23 = true;
							begin_20 += _22.node.length();
						}
						while(0);
						if (success_21 && success_23)
						{
							success_19 = true;
							begin_2 = begin_20;
						}
						;
						if (!success_19)
						{
							return {};
						}
					}
				}
				else 
				{
					_10 = ::Parser::str_t(begin_2, 1);
					success_11 = true;
					begin_2 += 1;
					_2 = _10;
				}
			}
			else 
			{
				_8 = ::Parser::str_t(begin_2, 1);
				success_9 = true;
				begin_2 += 1;
				_2 = _8;
			}
		}
		else 
		{
			_6 = ::Parser::str_t(begin_2, 1);
			success_7 = true;
			begin_2 += 1;
			_2 = _6;
		}
	}
	else 
	{
		_4 = ::Parser::str_t(begin_2, 1);
		success_5 = true;
		begin_2 += 1;
		_2 = _4;
	}
	success_3 = true;
	if (success_3)
	{
		success_1 = true;
		pos = begin_2;
	}
	::Parser::Types::cll_TYPE_data data;
	data.templ = _20;
	data.type = _14;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_TYPE, data)};
}
Parser::Token_res Parser::Lexer::cll_TEMPLATE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	::Parser::str_t _6;
	::Parser::Token_res _8;
	::Parser::arr_t<::Parser::Token> shadow_10;
	::Parser::str_t _11;
	::Parser::bool_t success_12 = false;
	success_12 = false;
	success_7 = false;
	success_9 = false;
	success_5 = false;
	success_3 = false;
	success_1 = false;
	if (!(*(pos + 0) == '<'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	_2 = cll_TYPE(pos);
	if (!(_2.status))
	{
		reportError(pos, "type");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	auto begin_6 = pos;
	while (1)
	{
		if (!(*(begin_6 + 0) == ','))
		{
			reportError(pos, "\",\"");
			break;
		}
		_6 += ::Parser::str_t(begin_6, 1);
		success_7 = true;
		begin_6 += 1;
		skip_spaces(begin_6);
		_8 = cll_TYPE(begin_6);
		if (!(_8.status))
		{
			reportError(pos, "type");
			break;
		}
		success_9 = true;
		begin_6 += _8.node.length();
		shadow_10.push_back(_8.node);
	}
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_6;
	}
	skip_spaces(pos);
	if (!(*(pos + 0) == '>'))
	{
		reportError(pos, "\">\"");
		return {};
	}
	_11 += ::Parser::str_t(pos, 1);
	success_12 = true;
	pos += 1;
	::Parser::Types::cll_TEMPLATE_data data;
	data.second = shadow_10;
	data.first = _2.node;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_TEMPLATE, data)};
}
Parser::Token_res Parser::Lexer::Rule_OP(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '|'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_OP)};
}
Parser::Token_res Parser::Lexer::Rule_CSEQUENCE_SYMBOL(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _2;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::str_t _8;
	::Parser::bool_t success_9 = false;
	success_5 = false;
	success_3 = false;
	success_1 = false;
	auto begin_2 = pos;
	if (!(!std::strncmp(begin_2, "\\]", 2)))
	{
		success_7 = false;
		if (!(!std::strncmp(begin_2, "\\", 1)))
		{
			success_9 = false;
			if (!(!(*(begin_2 + 0) == ']')))
			{
				return {};
			}
			else 
			{
				_8 = ::Parser::str_t(begin_2, 1);
				success_9 = true;
				begin_2 += 1;
				_2 = _8;
			}
		}
		else 
		{
			_6 = ::Parser::str_t(begin_2, 1);
			success_7 = true;
			begin_2 += 1;
			_2 = _6;
		}
	}
	else 
	{
		_4 = ::Parser::str_t(begin_2, 2);
		success_5 = true;
		begin_2 += 2;
		_2 = _4;
	}
	success_3 = true;
	_0 += _2;
	if (success_3)
	{
		success_1 = true;
		pos = begin_2;
	}
	::Parser::Types::Rule_CSEQUENCE_SYMBOL_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_CSEQUENCE_SYMBOL, data)};
}
Parser::Token_res Parser::Lexer::Rule_CSEQUENCE_ESCAPE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _4;
	success_5 = false;
	success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "\\", 1)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	auto begin_4 = pos;
	if (*(begin_4 + 0) == '\0')
	{
		reportError(pos, "any symbol");
		return {};
	}
	_4 += ::Parser::str_t(begin_4, 1);
	success_5 = true;
	begin_4 += 1;
	_2 += _4;
	if (success_5)
	{
		success_3 = true;
		pos = begin_4;
	}
	::Parser::Types::Rule_CSEQUENCE_ESCAPE_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_CSEQUENCE_ESCAPE, data)};
}
Parser::Token_res Parser::Lexer::Rule_CSEQUENCE_DIAPASON(const char* pos) {
	auto in = pos;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	::Parser::bool_t success_3 = false;
	::Parser::Token _2;
	::Parser::Token from;
	::Parser::bool_t success_5 = false;
	::Parser::Token_res _4;
	::Parser::str_t _6;
	::Parser::Token _8;
	::Parser::Token to;
	::Parser::bool_t success_11 = false;
	::Parser::Token_res _10;
	success_11 = false;
	success_5 = false;
	success_3 = false;
	success_7 = false;
	success_9 = false;
	success_1 = false;
	auto begin_2 = pos;
	auto begin_4 = begin_2;
	_4 = Rule_CSEQUENCE_SYMBOL(begin_4);
	if (!(_4.status))
	{
		return {};
	}
	success_5 = true;
	begin_4 += _4.node.length();
	_2 = _4.node;
	if (success_5)
	{
		success_3 = true;
		from = _2;
		begin_2 = begin_4;
	}
	if (!(*(begin_2 + 0) == '-'))
	{
		reportError(pos, "\"-\"");
		return {};
	}
	_6 += ::Parser::str_t(begin_2, 1);
	success_7 = true;
	begin_2 += 1;
	auto begin_10 = begin_2;
	_10 = Rule_CSEQUENCE_SYMBOL(begin_10);
	if (!(_10.status))
	{
		reportError(pos, "symbol");
		return {};
	}
	success_11 = true;
	begin_10 += _10.node.length();
	_8 = _10.node;
	if (success_11)
	{
		success_9 = true;
		to = _8;
		begin_2 = begin_10;
	}
	if (success_3 && success_7 && success_9)
	{
		success_1 = true;
		pos = begin_2;
	}
	::Parser::Types::Rule_CSEQUENCE_DIAPASON_data data = {from,to};
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_CSEQUENCE_DIAPASON, data)};
}
Parser::Token_res Parser::Lexer::Rule_CSEQUENCE(const char* pos) {
	auto in = pos;
	::Parser::Token_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::Token> _4;
	::Parser::arr_t<::Parser::arr_t<::Parser::Token>> dt;
	::Parser::bool_t success_5 = false;
	::Parser::bool_t success_7 = false;
	::Parser::arr_t<::Parser::Token> _6;
	::Parser::Token_res _8;
	::Parser::bool_t success_9 = false;
	::Parser::arr_t<::Parser::Token> shadow_10;
	::Parser::Token_res _11;
	::Parser::bool_t success_12 = false;
	::Parser::arr_t<::Parser::Token> shadow_13;
	::Parser::Token_res _14;
	::Parser::bool_t success_15 = false;
	::Parser::arr_t<::Parser::Token> shadow_16;
	::Parser::arr_t<::Parser::arr_t<::Parser::Token>> shadow_17;
	::Parser::Token_res _18;
	::Parser::bool_t success_19 = false;
	success_19 = false;
	success_7 = false;
	success_5 = false;
	success_3 = false;
	success_1 = false;
	_0 = AUTO_2(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	pos += _0.node.length();
	skip_spaces(pos);
	if (*(pos + 0) == '^')
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
	}
	skip_spaces(pos);
	auto begin_6 = pos;
	while (1)
	{
		success_9 = false;
		_8 = Rule_CSEQUENCE_DIAPASON(begin_6);
		if (!(_8.status))
		{
			success_12 = false;
			_11 = Rule_CSEQUENCE_SYMBOL(begin_6);
			if (!(_11.status))
			{
				success_15 = false;
				_14 = Rule_CSEQUENCE_ESCAPE(begin_6);
				if (!(_14.status))
				{
					break;
				}
				else 
				{
					success_15 = true;
					begin_6 += _14.node.length();
					shadow_16.push_back(_14.node);
					_6.push_back(_14.node);
				}
			}
			else 
			{
				success_12 = true;
				begin_6 += _11.node.length();
				shadow_13.push_back(_11.node);
				_6.push_back(_11.node);
			}
		}
		else 
		{
			success_9 = true;
			begin_6 += _8.node.length();
			shadow_10.push_back(_8.node);
			_6.push_back(_8.node);
		}
		success_7 = true;
		_4 = _6;
		shadow_17.push_back(_4);
	}
	if (success_7)
	{
		success_5 = true;
		dt = shadow_17;
		pos = begin_6;
	}
	skip_spaces(pos);
	_18 = AUTO_3(pos);
	if (!(_18.status))
	{
		reportError(pos, "\"]\"");
		return {};
	}
	success_19 = true;
	pos += _18.node.length();
	::Parser::Types::Rule_CSEQUENCE_data data;
	data.val = dt;
	data._not = _2;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_CSEQUENCE, data)};
}
Parser::Token_res Parser::Lexer::Rule_NOSPACE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "\\s0", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_NOSPACE)};
}
Parser::Token_res Parser::Lexer::Rule_ESCAPED(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _4;
	success_5 = false;
	success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "\\", 1)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	auto begin_4 = pos;
	if (*(begin_4 + 0) == '\0')
	{
		reportError(pos, "any symbol");
		return {};
	}
	_4 += ::Parser::str_t(begin_4, 1);
	success_5 = true;
	begin_4 += 1;
	_2 += _4;
	if (success_5)
	{
		success_3 = true;
		pos = begin_4;
	}
	::Parser::Types::Rule_ESCAPED_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_ESCAPED, data)};
}
Parser::Token_res Parser::Lexer::Rule_HEX(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_4 = false;
	success_4 = false;
	success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "0x", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	while ((*(pos + 0)>='0' && *(pos + 0)<='9') || (*(pos + 0)>='A' && *(pos + 0)<='F') || (*(pos + 0)>='a' && *(pos + 0)<='f'))
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		success_4 = true;
	}
	if (!success_4)
	{
		reportError(pos, "0-9 or A-Fa-f");
		return {};
	}
	::Parser::Types::Rule_HEX_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_HEX, data)};
}
Parser::Token_res Parser::Lexer::Rule_BIN(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_4 = false;
	success_4 = false;
	success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "0b", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	while (*(pos + 0) == '0' || *(pos + 0) == '1')
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		success_4 = true;
	}
	if (!success_4)
	{
		reportError(pos, "01");
		return {};
	}
	::Parser::Types::Rule_BIN_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_BIN, data)};
}
Parser::Token_res Parser::Lexer::AUTO_0(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "use", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	::Parser::Types::AUTO_0_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_0, data)};
}
Parser::Token_res Parser::Lexer::AUTO_1(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == ','))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_1_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_1, data)};
}
Parser::Token_res Parser::Lexer::AUTO_2(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '['))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_2_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_2, data)};
}
Parser::Token_res Parser::Lexer::AUTO_3(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == ']'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_3_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_3, data)};
}
Parser::Token_res Parser::Lexer::AUTO_4(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '{'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_4_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_4, data)};
}
Parser::Token_res Parser::Lexer::AUTO_5(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == ':'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_5_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_5, data)};
}
Parser::Token_res Parser::Lexer::AUTO_6(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == ';'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_6_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_6, data)};
}
Parser::Token_res Parser::Lexer::AUTO_7(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '}'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_7_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_7, data)};
}
Parser::Token_res Parser::Lexer::AUTO_8(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '$'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_8_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_8, data)};
}
Parser::Token_res Parser::Lexer::AUTO_9(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "if", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_9_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_9, data)};
}
Parser::Token_res Parser::Lexer::AUTO_10(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "--", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_10_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_10, data)};
}
Parser::Token_res Parser::Lexer::AUTO_11(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "++", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_11_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_11, data)};
}
Parser::Token_res Parser::Lexer::AUTO_12(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '('))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_12_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_12, data)};
}
Parser::Token_res Parser::Lexer::AUTO_13(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == ')'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_13_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_13, data)};
}
Parser::Token_res Parser::Lexer::AUTO_14(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "fn", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_14_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_14, data)};
}
Parser::Token_res Parser::Lexer::AUTO_15(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "while", 5)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 5;
	::Parser::Types::AUTO_15_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_15, data)};
}
Parser::Token_res Parser::Lexer::AUTO_16(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "for", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	::Parser::Types::AUTO_16_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_16, data)};
}
Parser::Token_res Parser::Lexer::AUTO_17(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '#'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_17_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_17, data)};
}
Parser::Token_res Parser::Lexer::AUTO_18(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '.'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_18_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_18, data)};
}
Parser::Token_res Parser::Lexer::AUTO_19(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '&'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_19_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_19, data)};
}
Parser::Token_res Parser::Lexer::AUTO_20(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '='))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_20_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_20, data)};
}
Parser::Token_res Parser::Lexer::__WHITESPACE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_2 = false;
	success_2 = false;
	success_1 = false;
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::__WHITESPACE)};
}
