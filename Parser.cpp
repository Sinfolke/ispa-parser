#include "Parser.h"
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
		case Tokens::cll_TYPE: return "cll_TYPE";
		case Tokens::cll_TEMPLATE: return "cll_TEMPLATE";
		case Tokens::STRING: return "STRING";
		case Tokens::NUMBER: return "NUMBER";
		case Tokens::BOOLEAN: return "BOOLEAN";
		case Tokens::END: return "END";
		case Tokens::NEWLINE: return "NEWLINE";
		case Tokens::PLUS: return "PLUS";
		case Tokens::MINUS: return "MINUS";
		case Tokens::DIVIDE: return "DIVIDE";
		case Tokens::MULTIPLE: return "MULTIPLE";
		case Tokens::MODULO: return "MODULO";
		case Tokens::LINEAR_COMMENT: return "LINEAR_COMMENT";
		case Tokens::ID: return "ID";
		case Tokens::SPACEMODE: return "SPACEMODE";
		case Tokens::NAME: return "NAME";
		case Tokens::AT: return "AT";
		case Tokens::Rule_OP: return "Rule_OP";
		case Tokens::Rule_CSEQUENCE: return "Rule_CSEQUENCE";
		case Tokens::Rule_CSEQUENCE_SYMBOL: return "Rule_CSEQUENCE_SYMBOL";
		case Tokens::Rule_CSEQUENCE_ESCAPE: return "Rule_CSEQUENCE_ESCAPE";
		case Tokens::Rule_CSEQUENCE_DIAPASON: return "Rule_CSEQUENCE_DIAPASON";
		case Tokens::Rule_NOSPACE: return "Rule_NOSPACE";
		case Tokens::Rule_ESCAPED: return "Rule_ESCAPED";
		case Tokens::Rule_HEX: return "Rule_HEX";
		case Tokens::Rule_BIN: return "Rule_BIN";
		case Tokens::AUTO_0: return "AUTO_0";
		case Tokens::AUTO_1: return "AUTO_1";
		case Tokens::AUTO_6: return "AUTO_6";
		case Tokens::AUTO_7: return "AUTO_7";
		case Tokens::AUTO_14: return "AUTO_14";
		case Tokens::AUTO_19: return "AUTO_19";
		case Tokens::AUTO_20: return "AUTO_20";
		case Tokens::AUTO_25: return "AUTO_25";
		case Tokens::AUTO_27: return "AUTO_27";
		case Tokens::AUTO_32: return "AUTO_32";
		case Tokens::AUTO_34: return "AUTO_34";
		case Tokens::AUTO_36: return "AUTO_36";
		case Tokens::AUTO_38: return "AUTO_38";
		case Tokens::AUTO_39: return "AUTO_39";
		case Tokens::AUTO_40: return "AUTO_40";
		case Tokens::AUTO_41: return "AUTO_41";
		case Tokens::AUTO_42: return "AUTO_42";
		case Tokens::AUTO_45: return "AUTO_45";
		case Tokens::AUTO_46: return "AUTO_46";
		case Tokens::AUTO_47: return "AUTO_47";
		case Tokens::AUTO_48: return "AUTO_48";
		case Tokens::AUTO_49: return "AUTO_49";
		case Tokens::AUTO_50: return "AUTO_50";
		case Tokens::__WHITESPACE: return "__WHITESPACE";
	}
	return "NONE";
}
std::string Parser::RulesToString(Rules rule) {
	switch (rule) {
		case Rules::NONE: return "NONE";
		case Rules::cll: return "cll";
		case Rules::cll_if: return "cll_if";
		case Rules::cll_variable: return "cll_variable";
		case Rules::cll_function_body_call: return "cll_function_body_call";
		case Rules::cll_function_body_decl: return "cll_function_body_decl";
		case Rules::cll_function_arguments: return "cll_function_arguments";
		case Rules::cll_function_parameters: return "cll_function_parameters";
		case Rules::cll_cll_function_call: return "cll_cll_function_call";
		case Rules::cll_function_decl: return "cll_function_decl";
		case Rules::cll_expr: return "cll_expr";
		case Rules::cll_expr_logical: return "cll_expr_logical";
		case Rules::cll_expr_compare: return "cll_expr_compare";
		case Rules::cll_expr_arithmetic: return "cll_expr_arithmetic";
		case Rules::cll_expr_term: return "cll_expr_term";
		case Rules::cll_expr_value: return "cll_expr_value";
		case Rules::cll_expr_group: return "cll_expr_group";
		case Rules::cll_var: return "cll_var";
		case Rules::cll_block: return "cll_block";
		case Rules::cll_loop_while: return "cll_loop_while";
		case Rules::cll_loop_for: return "cll_loop_for";
		case Rules::array: return "array";
		case Rules::object: return "object";
		case Rules::any_data: return "any_data";
		case Rules::main: return "main";
		case Rules::use: return "use";
		case Rules::use_unit: return "use_unit";
		case Rules::Rule: return "Rule";
		case Rules::Rule_rule: return "Rule_rule";
		case Rules::Rule_name: return "Rule_name";
		case Rules::Rule_group: return "Rule_group";
		case Rules::Rule_keyvalue: return "Rule_keyvalue";
		case Rules::Rule_value: return "Rule_value";
		case Rules::Rule_nested_rule: return "Rule_nested_rule";
		case Rules::Rule_data_block: return "Rule_data_block";
		case Rules::Rule_data_block_regular_datablock: return "Rule_data_block_regular_datablock";
		case Rules::Rule_data_block_regular_datablock_key: return "Rule_data_block_regular_datablock_key";
		case Rules::Rule_data_block_templated_datablock: return "Rule_data_block_templated_datablock";
		case Rules::Rule_quantifier: return "Rule_quantifier";
	}
	return "NONE";
}
::Parser::Types::cll_OP_data Parser::get::cll_OP(::Parser::Token &token) {
	return std::any_cast<Types::cll_OP_data>(token.data());
}
::Parser::Types::cll_ASSIGNMENT_OP_data Parser::get::cll_ASSIGNMENT_OP(::Parser::Token &token) {
	return std::any_cast<Types::cll_ASSIGNMENT_OP_data>(token.data());
}
::Parser::Types::cll_COMPARE_OP_data Parser::get::cll_COMPARE_OP(::Parser::Token &token) {
	return std::any_cast<Types::cll_COMPARE_OP_data>(token.data());
}
::Parser::Types::cll_LOGICAL_OP_data Parser::get::cll_LOGICAL_OP(::Parser::Token &token) {
	return std::any_cast<Types::cll_LOGICAL_OP_data>(token.data());
}
::Parser::Types::cll_TYPE_data Parser::get::cll_TYPE(::Parser::Token &token) {
	return std::any_cast<Types::cll_TYPE_data>(token.data());
}
::Parser::Types::cll_TEMPLATE_data Parser::get::cll_TEMPLATE(::Parser::Token &token) {
	return std::any_cast<Types::cll_TEMPLATE_data>(token.data());
}
::Parser::Types::STRING_data Parser::get::STRING(::Parser::Token &token) {
	return std::any_cast<Types::STRING_data>(token.data());
}
::Parser::Types::NUMBER_data Parser::get::NUMBER(::Parser::Token &token) {
	return std::any_cast<Types::NUMBER_data>(token.data());
}
::Parser::Types::BOOLEAN_data Parser::get::BOOLEAN(::Parser::Token &token) {
	return std::any_cast<Types::BOOLEAN_data>(token.data());
}
::Parser::Types::ID_data Parser::get::ID(::Parser::Token &token) {
	return std::any_cast<Types::ID_data>(token.data());
}
::Parser::Types::SPACEMODE_data Parser::get::SPACEMODE(::Parser::Token &token) {
	return std::any_cast<Types::SPACEMODE_data>(token.data());
}
::Parser::Types::NAME_data Parser::get::NAME(::Parser::Token &token) {
	return std::any_cast<Types::NAME_data>(token.data());
}
::Parser::Types::Rule_CSEQUENCE_SYMBOL_data Parser::get::Rule_CSEQUENCE_SYMBOL(::Parser::Token &token) {
	return std::any_cast<Types::Rule_CSEQUENCE_SYMBOL_data>(token.data());
}
::Parser::Types::Rule_CSEQUENCE_ESCAPE_data Parser::get::Rule_CSEQUENCE_ESCAPE(::Parser::Token &token) {
	return std::any_cast<Types::Rule_CSEQUENCE_ESCAPE_data>(token.data());
}
::Parser::Types::Rule_CSEQUENCE_DIAPASON_data Parser::get::Rule_CSEQUENCE_DIAPASON(::Parser::Token &token) {
	return std::any_cast<Types::Rule_CSEQUENCE_DIAPASON_data>(token.data());
}
::Parser::Types::Rule_CSEQUENCE_data Parser::get::Rule_CSEQUENCE(::Parser::Token &token) {
	return std::any_cast<Types::Rule_CSEQUENCE_data>(token.data());
}
::Parser::Types::Rule_ESCAPED_data Parser::get::Rule_ESCAPED(::Parser::Token &token) {
	return std::any_cast<Types::Rule_ESCAPED_data>(token.data());
}
::Parser::Types::Rule_HEX_data Parser::get::Rule_HEX(::Parser::Token &token) {
	return std::any_cast<Types::Rule_HEX_data>(token.data());
}
::Parser::Types::Rule_BIN_data Parser::get::Rule_BIN(::Parser::Token &token) {
	return std::any_cast<Types::Rule_BIN_data>(token.data());
}
::Parser::Types::AUTO_0_data Parser::get::AUTO_0(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_0_data>(token.data());
}
::Parser::Types::AUTO_1_data Parser::get::AUTO_1(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_1_data>(token.data());
}
::Parser::Types::AUTO_6_data Parser::get::AUTO_6(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_6_data>(token.data());
}
::Parser::Types::AUTO_7_data Parser::get::AUTO_7(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_7_data>(token.data());
}
::Parser::Types::AUTO_14_data Parser::get::AUTO_14(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_14_data>(token.data());
}
::Parser::Types::AUTO_19_data Parser::get::AUTO_19(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_19_data>(token.data());
}
::Parser::Types::AUTO_20_data Parser::get::AUTO_20(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_20_data>(token.data());
}
::Parser::Types::AUTO_25_data Parser::get::AUTO_25(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_25_data>(token.data());
}
::Parser::Types::AUTO_27_data Parser::get::AUTO_27(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_27_data>(token.data());
}
::Parser::Types::AUTO_32_data Parser::get::AUTO_32(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_32_data>(token.data());
}
::Parser::Types::AUTO_34_data Parser::get::AUTO_34(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_34_data>(token.data());
}
::Parser::Types::AUTO_36_data Parser::get::AUTO_36(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_36_data>(token.data());
}
::Parser::Types::AUTO_38_data Parser::get::AUTO_38(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_38_data>(token.data());
}
::Parser::Types::AUTO_39_data Parser::get::AUTO_39(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_39_data>(token.data());
}
::Parser::Types::AUTO_40_data Parser::get::AUTO_40(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_40_data>(token.data());
}
::Parser::Types::AUTO_41_data Parser::get::AUTO_41(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_41_data>(token.data());
}
::Parser::Types::AUTO_42_data Parser::get::AUTO_42(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_42_data>(token.data());
}
::Parser::Types::AUTO_45_data Parser::get::AUTO_45(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_45_data>(token.data());
}
::Parser::Types::AUTO_46_data Parser::get::AUTO_46(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_46_data>(token.data());
}
::Parser::Types::AUTO_47_data Parser::get::AUTO_47(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_47_data>(token.data());
}
::Parser::Types::AUTO_48_data Parser::get::AUTO_48(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_48_data>(token.data());
}
::Parser::Types::AUTO_49_data Parser::get::AUTO_49(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_49_data>(token.data());
}
::Parser::Types::AUTO_50_data Parser::get::AUTO_50(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_50_data>(token.data());
}
::Parser::Types::cll_if_data Parser::get::cll_if(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_if_data>(rule.data());
}
::Parser::Types::cll_variable_data Parser::get::cll_variable(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_variable_data>(rule.data());
}
::Parser::Types::cll_function_body_call_data Parser::get::cll_function_body_call(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_function_body_call_data>(rule.data());
}
::Parser::Types::cll_function_body_decl_data Parser::get::cll_function_body_decl(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_function_body_decl_data>(rule.data());
}
::Parser::Types::cll_function_arguments_data Parser::get::cll_function_arguments(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_function_arguments_data>(rule.data());
}
::Parser::Types::cll_function_parameters_data Parser::get::cll_function_parameters(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_function_parameters_data>(rule.data());
}
::Parser::Types::cll_cll_function_call_data Parser::get::cll_cll_function_call(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_cll_function_call_data>(rule.data());
}
::Parser::Types::cll_function_decl_data Parser::get::cll_function_decl(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_function_decl_data>(rule.data());
}
::Parser::Types::cll_expr_logical_data Parser::get::cll_expr_logical(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_expr_logical_data>(rule.data());
}
::Parser::Types::cll_expr_compare_data Parser::get::cll_expr_compare(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_expr_compare_data>(rule.data());
}
::Parser::Types::cll_expr_arithmetic_data Parser::get::cll_expr_arithmetic(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_expr_arithmetic_data>(rule.data());
}
::Parser::Types::cll_expr_term_data Parser::get::cll_expr_term(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_expr_term_data>(rule.data());
}
::Parser::Types::cll_expr_value_data Parser::get::cll_expr_value(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_expr_value_data>(rule.data());
}
::Parser::Types::cll_expr_group_data Parser::get::cll_expr_group(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_expr_group_data>(rule.data());
}
::Parser::Types::cll_expr_data Parser::get::cll_expr(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_expr_data>(rule.data());
}
::Parser::Types::cll_var_data Parser::get::cll_var(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_var_data>(rule.data());
}
::Parser::Types::cll_block_data Parser::get::cll_block(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_block_data>(rule.data());
}
::Parser::Types::cll_loop_while_data Parser::get::cll_loop_while(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_loop_while_data>(rule.data());
}
::Parser::Types::cll_loop_for_data Parser::get::cll_loop_for(::Parser::Rule &rule) {
	return std::any_cast<Types::cll_loop_for_data>(rule.data());
}
::Parser::Types::array_data Parser::get::array(::Parser::Rule &rule) {
	return std::any_cast<Types::array_data>(rule.data());
}
::Parser::Types::object_data Parser::get::object(::Parser::Rule &rule) {
	return std::any_cast<Types::object_data>(rule.data());
}
::Parser::Types::any_data_data Parser::get::any_data(::Parser::Rule &rule) {
	return std::any_cast<Types::any_data_data>(rule.data());
}
::Parser::Types::use_unit_data Parser::get::use_unit(::Parser::Rule &rule) {
	return std::any_cast<Types::use_unit_data>(rule.data());
}
::Parser::Types::use_data Parser::get::use(::Parser::Rule &rule) {
	return std::any_cast<Types::use_data>(rule.data());
}
::Parser::Types::Rule_rule_data Parser::get::Rule_rule(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_rule_data>(rule.data());
}
::Parser::Types::Rule_name_data Parser::get::Rule_name(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_name_data>(rule.data());
}
::Parser::Types::Rule_group_data Parser::get::Rule_group(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_group_data>(rule.data());
}
::Parser::Types::Rule_keyvalue_data Parser::get::Rule_keyvalue(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_keyvalue_data>(rule.data());
}
::Parser::Types::Rule_value_data Parser::get::Rule_value(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_value_data>(rule.data());
}
::Parser::Types::Rule_nested_rule_data Parser::get::Rule_nested_rule(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_nested_rule_data>(rule.data());
}
::Parser::Types::Rule_data_block_regular_datablock_key_data Parser::get::Rule_data_block_regular_datablock_key(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_data_block_regular_datablock_key_data>(rule.data());
}
::Parser::Types::Rule_data_block_regular_datablock_data Parser::get::Rule_data_block_regular_datablock(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_data_block_regular_datablock_data>(rule.data());
}
::Parser::Types::Rule_data_block_templated_datablock_data Parser::get::Rule_data_block_templated_datablock(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_data_block_templated_datablock_data>(rule.data());
}
::Parser::Types::Rule_data_block_data Parser::get::Rule_data_block(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_data_block_data>(rule.data());
}
::Parser::Types::Rule_quantifier_data Parser::get::Rule_quantifier(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_quantifier_data>(rule.data());
}
::Parser::Types::Rule_data Parser::get::Rule(::Parser::Rule &rule) {
	return std::any_cast<Types::Rule_data>(rule.data());
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
	::Parser::Token_res _98;
	::Parser::bool_t success_99 = false;
	_2 = Rule_CSEQUENCE(pos);
	if (!(_2.status))
	{
		_4 = Rule_ESCAPED(pos);
		if (!(_4.status))
		{
			_6 = STRING(pos);
			if (!(_6.status))
			{
				_8 = NUMBER(pos);
				if (!(_8.status))
				{
					_10 = cll_ASSIGNMENT_OP(pos);
					if (!(_10.status))
					{
						_12 = SPACEMODE(pos);
						if (!(_12.status))
						{
							_14 = NAME(pos);
							if (!(_14.status))
							{
								_16 = Rule_BIN(pos);
								if (!(_16.status))
								{
									_18 = Rule_HEX(pos);
									if (!(_18.status))
									{
										_20 = LINEAR_COMMENT(pos);
										if (!(_20.status))
										{
											_22 = AUTO_19(pos);
											if (!(_22.status))
											{
												_24 = Rule_NOSPACE(pos);
												if (!(_24.status))
												{
													_26 = AUTO_34(pos);
													if (!(_26.status))
													{
														_28 = AUTO_20(pos);
														if (!(_28.status))
														{
															_30 = AUTO_1(pos);
															if (!(_30.status))
															{
																_32 = AUTO_6(pos);
																if (!(_32.status))
																{
																	_34 = AUTO_7(pos);
																	if (!(_34.status))
																	{
																		_36 = AUTO_14(pos);
																		if (!(_36.status))
																		{
																			_38 = AUTO_27(pos);
																			if (!(_38.status))
																			{
																				_40 = AUTO_25(pos);
																				if (!(_40.status))
																				{
																					_42 = AUTO_0(pos);
																					if (!(_42.status))
																					{
																						_44 = AUTO_32(pos);
																						if (!(_44.status))
																						{
																							_46 = AUTO_36(pos);
																							if (!(_46.status))
																							{
																								_48 = AUTO_38(pos);
																								if (!(_48.status))
																								{
																									_50 = AUTO_39(pos);
																									if (!(_50.status))
																									{
																										_52 = AUTO_40(pos);
																										if (!(_52.status))
																										{
																											_54 = AUTO_41(pos);
																											if (!(_54.status))
																											{
																												_56 = MINUS(pos);
																												if (!(_56.status))
																												{
																													_58 = AUTO_50(pos);
																													if (!(_58.status))
																													{
																														_60 = AUTO_49(pos);
																														if (!(_60.status))
																														{
																															_62 = AUTO_48(pos);
																															if (!(_62.status))
																															{
																																_64 = Rule_OP(pos);
																																if (!(_64.status))
																																{
																																	_66 = AT(pos);
																																	if (!(_66.status))
																																	{
																																		_68 = AUTO_47(pos);
																																		if (!(_68.status))
																																		{
																																			_70 = AUTO_46(pos);
																																			if (!(_70.status))
																																			{
																																				_72 = AUTO_42(pos);
																																				if (!(_72.status))
																																				{
																																					_74 = PLUS(pos);
																																					if (!(_74.status))
																																					{
																																						_76 = MODULO(pos);
																																						if (!(_76.status))
																																						{
																																							_78 = MULTIPLE(pos);
																																							if (!(_78.status))
																																							{
																																								_80 = DIVIDE(pos);
																																								if (!(_80.status))
																																								{
																																									_82 = __WHITESPACE(pos);
																																									if (!(_82.status))
																																									{
																																										_84 = AUTO_45(pos);
																																										if (!(_84.status))
																																										{
																																											_86 = END(pos);
																																											if (!(_86.status))
																																											{
																																												_88 = NEWLINE(pos);
																																												if (!(_88.status))
																																												{
																																													_90 = ID(pos);
																																													if (!(_90.status))
																																													{
																																														_92 = BOOLEAN(pos);
																																														if (!(_92.status))
																																														{
																																															_94 = cll_TYPE(pos);
																																															if (!(_94.status))
																																															{
																																																_96 = cll_LOGICAL_OP(pos);
																																																if (!(_96.status))
																																																{
																																																	_98 = cll_COMPARE_OP(pos);
																																																	if (!(_98.status))
																																																	{
																																																		return {};
																																																	}
																																																	else 
																																																	{
																																																		success_99 = true;
																																																		pos += _98.node.length();
																																																		_0 = _98.node;
																																																	}
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
	skip_spaces(pos);
	return _0;
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
	_0 = cll_OP(pos);
	if (_0.status)
	{
		success_1 = true;
		pos += _0.node.length();
	}
	skip_spaces(pos);
	_2 = AUTO_46(pos);
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
	if (!(!std::strncmp(pos, "not", 3)))
	{
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
	if (!(!std::strncmp(pos, "and", 3)))
	{
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
	if (!(!std::strncmp(pos, "||", 2)))
	{
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
	::Parser::any_t _2;
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
	::Parser::bool_t success_15 = false;
	::Parser::str_t _16;
	::Parser::bool_t success_17 = false;
	::Parser::Token_res _18;
	::Parser::bool_t success_19 = false;
	::Parser::bool_t success_22 = false;
	::Parser::str_t _23;
	::Parser::bool_t success_24 = false;
	::Parser::Token_res _25;
	::Parser::bool_t success_26 = false;
	auto begin_28 = pos;
	if (!(!std::strncmp(begin_28, "bool", 4)))
	{
		if (!(!std::strncmp(begin_28, "var", 3)))
		{
			if (!(!std::strncmp(begin_28, "any", 3)))
			{
				if (!(!std::strncmp(begin_28, "num", 3)))
				{
					if (!(!std::strncmp(begin_28, "str", 3)))
					{
						auto begin_20 = begin_28;
						do
						{
							if (!(!std::strncmp(begin_20 + 0, "arr", 3)))
							{
								break;
							}
							_16 += ::Parser::str_t(begin_20, 3);
							success_17 = true;
							begin_20 += 3;
							skip_spaces(begin_20);
							_18 = cll_TEMPLATE(begin_20);
							if (!(_18.status))
							{
								reportError(pos, "template");
								break;
							}
							success_19 = true;
							begin_20 += _18.node.length();
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
								if (!(!std::strncmp(begin_27 + 0, "obj", 3)))
								{
									break;
								}
								_23 += ::Parser::str_t(begin_27, 3);
								success_24 = true;
								begin_27 += 3;
								skip_spaces(begin_27);
								_25 = cll_TEMPLATE(begin_27);
								if (!(_25.status))
								{
									reportError(pos, "template");
									break;
								}
								success_26 = true;
								begin_27 += _25.node.length();
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
						_12 = ::Parser::str_t(begin_28, 1);
						success_13 = true;
						begin_28 += 1;
						_2 = _12;
					}
				}
				else 
				{
					_10 = ::Parser::str_t(begin_28, 1);
					success_11 = true;
					begin_28 += 1;
					_2 = _10;
				}
			}
			else 
			{
				_8 = ::Parser::str_t(begin_28, 1);
				success_9 = true;
				begin_28 += 1;
				_2 = _8;
			}
		}
		else 
		{
			_6 = ::Parser::str_t(begin_28, 1);
			success_7 = true;
			begin_28 += 1;
			_2 = _6;
		}
	}
	else 
	{
		_4 = ::Parser::str_t(begin_28, 1);
		success_5 = true;
		begin_28 += 1;
		_2 = _4;
	}
	success_3 = true;
	if (success_3)
	{
		success_1 = true;
		pos = begin_28;
	}
	::Parser::Types::cll_TYPE_data data;
	data.templ = _23;
	data.type = _16;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_TYPE, data)};
}
Parser::Token_res Parser::Lexer::cll_TEMPLATE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token_res _8;
	::Parser::bool_t success_9 = false;
	::Parser::arr_t<::Parser::Token> shadow_10;
	::Parser::str_t _12;
	::Parser::bool_t success_13 = false;
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
	auto begin_11 = pos;
	while (1)
	{
		if (!(*(begin_11 + 0) == ','))
		{
			reportError(pos, "\",\"");
			break;
		}
		_6 += ::Parser::str_t(begin_11, 1);
		success_7 = true;
		begin_11 += 1;
		skip_spaces(begin_11);
		_8 = cll_TYPE(begin_11);
		if (!(_8.status))
		{
			reportError(pos, "type");
			break;
		}
		success_9 = true;
		begin_11 += _8.node.length();
		shadow_10.push_back(_8.node);
	}
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_11;
	}
	skip_spaces(pos);
	if (!(*(pos + 0) == '>'))
	{
		reportError(pos, "\">\"");
		return {};
	}
	_12 += ::Parser::str_t(pos, 1);
	success_13 = true;
	pos += 1;
	::Parser::Types::cll_TEMPLATE_data data;
	data.second = shadow_10;
	data.first = _2.node;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_TEMPLATE, data)};
}
Parser::Token_res Parser::Lexer::STRING(const char* pos) {
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
	::Parser::arr_t<::Parser::str_t> shadow_14;
	::Parser::str_t _10;
	::Parser::bool_t success_11 = false;
	::Parser::str_t _12;
	::Parser::bool_t success_13 = false;
	::Parser::str_t _16;
	::Parser::bool_t success_17 = false;
	if (!(*(pos + 0) == '\''))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	auto begin_15 = pos;
	while (1)
	{
		if (!(!(*(begin_15 + 0) == '\'')))
		{
			auto begin_14 = begin_15;
			do
			{
				if (!(!std::strncmp(begin_14 + 0, "\\", 1)))
				{
					reportError(pos, "\"\\\"");
					break;
				}
				_10 += ::Parser::str_t(begin_14, 1);
				success_11 = true;
				begin_14 += 1;
				skip_spaces(begin_14);
				if (*(begin_14 + 0) == '\0')
				{
					reportError(pos, "any symbol");
					break;
				}
				_12 += ::Parser::str_t(begin_14, 1);
				success_13 = true;
				begin_14 += 1;
				_8 += _10;
				_8 += _12;
				shadow_14.push_back(_8);
			}
			while(0)
;
			if (success_11 && success_13)
			{
				success_9 = true;
				begin_15 = begin_14;
			}
			;
			if (!success_9)
			{
				break;
			}
			else 
			{
				_4 = _8;
			}
		}
		else 
		{
			_6 = ::Parser::str_t(begin_15, 1);
			success_7 = true;
			begin_15 += 1;
			_4 = _6;
		}
		success_5 = true;
		_2 += _4;
	}
	if (success_5)
	{
		success_3 = true;
		pos = begin_15;
	}
	skip_spaces(pos);
	if (!(*(pos + 0) == '\''))
	{
		reportError(pos, "\"'\"");
		return {};
	}
	_16 += ::Parser::str_t(pos, 1);
	success_17 = true;
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
	if (*(pos + 0) == '+' || *(pos + 0) == '-')
	{
		_0 += ::Parser::str_t(pos, 1);
		success_1 = true;
		pos += 1;
	}
	skip_spaces(pos);
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
		reportError(pos, "0-9 or ");
		return {};
	}
	_2 += _4;
	if (success_5)
	{
		success_3 = true;
		pos = begin_7;
	}
	skip_spaces(pos);
	auto begin_15 = pos;
	do
	{
		if (!(*(begin_15 + 0) == '.' || *(begin_15 + 0) == ','))
		{
			reportError(pos, ".,");
			break;
		}
		_10 += ::Parser::str_t(begin_15, 1);
		success_11 = true;
		begin_15 += 1;
		skip_spaces(begin_15);
		while ((*(begin_15 + 0)>='0' && *(begin_15 + 0)<='9'))
		{
			_12 += ::Parser::str_t(begin_15, 1);
			success_13 = true;
			begin_15 += 1;
			success_14 = true;
		}
		if (!success_14)
		{
			reportError(pos, "0-9 or ");
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
	::Parser::Types::NUMBER_data data;
	data.dec = _10;
	data.main = _4;
	data.sign = _0;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::NUMBER, data)};
}
Parser::Token_res Parser::Lexer::BOOLEAN(const char* pos) {
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
			_5 = ::Parser::str_t(begin_7, 4);
			success_6 = true;
			begin_7 += 4;
			_1 = _5;
		}
	}
	else 
	{
		_3 = ::Parser::str_t(begin_7, 5);
		success_4 = true;
		begin_7 += 5;
		_1 = _3;
	}
	success_2 = true;
	d += _1;
	if (success_2)
	{
		success_0 = true;
		pos = begin_7;
	}
	::Parser::Types::BOOLEAN_data data = d;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::BOOLEAN, data)};
}
Parser::Token_res Parser::Lexer::END(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::END)};
}
Parser::Token_res Parser::Lexer::NEWLINE(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::NEWLINE)};
}
Parser::Token_res Parser::Lexer::PLUS(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::PLUS)};
}
Parser::Token_res Parser::Lexer::MINUS(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::MINUS)};
}
Parser::Token_res Parser::Lexer::DIVIDE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
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
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	auto begin_6 = pos;
	if (!((*(begin_6 + 0)>='a' && *(begin_6 + 0)<='z') || (*(begin_6 + 0)>='A' && *(begin_6 + 0)<='Z') || *(begin_6 + 0) == '_'))
	{
		return {};
	}
	_2 += ::Parser::str_t(begin_6, 1);
	success_3 = true;
	begin_6 += 1;
	skip_spaces(begin_6);
	while ((*(begin_6 + 0)>='a' && *(begin_6 + 0)<='z') || (*(begin_6 + 0)>='A' && *(begin_6 + 0)<='Z') || (*(begin_6 + 0)>='0' && *(begin_6 + 0)<='9') || *(begin_6 + 0) == '_')
	{
		_4 += ::Parser::str_t(begin_6, 1);
		success_5 = true;
		begin_6 += 1;
	}
	_0 += _2;
	_0 += _4;
	if (success_3)
	{
		success_1 = true;
		pos = begin_6;
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
		if (!(!std::strncmp(pos, "allowed", 7)))
		{
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
	if (!(*(pos + 0) == '@'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AT)};
}
Parser::Token_res Parser::Lexer::Rule_OP(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_OP)};
}
Parser::Token_res Parser::Lexer::Rule_CSEQUENCE_SYMBOL(const char* pos) {
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
			if (!(!(*(begin_10 + 0) == ']')))
			{
				return {};
			}
			else 
			{
				_8 = ::Parser::str_t(begin_10, 1);
				success_9 = true;
				begin_10 += 1;
				_2 = _8;
			}
		}
		else 
		{
			_6 = ::Parser::str_t(begin_10, 1);
			success_7 = true;
			begin_10 += 1;
			_2 = _6;
		}
	}
	else 
	{
		_4 = ::Parser::str_t(begin_10, 2);
		success_5 = true;
		begin_10 += 2;
		_2 = _4;
	}
	success_3 = true;
	_0 += _2;
	if (success_3)
	{
		success_1 = true;
		pos = begin_10;
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
		reportError(pos, "any symbol");
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
	::Parser::Types::Rule_CSEQUENCE_ESCAPE_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_CSEQUENCE_ESCAPE, data)};
}
Parser::Token_res Parser::Lexer::Rule_CSEQUENCE_DIAPASON(const char* pos) {
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
		reportError(pos, "\"-\"");
		return {};
	}
	_6 += ::Parser::str_t(begin_12, 1);
	success_7 = true;
	begin_12 += 1;
	auto begin_11 = begin_12;
	_9 = Rule_CSEQUENCE_SYMBOL(begin_11);
	if (!(_9.status))
	{
		reportError(pos, "symbol");
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
	::Parser::Types::Rule_CSEQUENCE_DIAPASON_data data = {from,to};
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_CSEQUENCE_DIAPASON, data)};
}
Parser::Token_res Parser::Lexer::Rule_CSEQUENCE(const char* pos) {
	auto in = pos;
	::Parser::Token_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::Token> dt;
	::Parser::bool_t success_4 = false;
	::Parser::arr_t<::Parser::arr_t<::Parser::Token>> shadow_16;
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
	::Parser::Token_res _17;
	::Parser::bool_t success_18 = false;
	::Parser::arr_t<::Parser::Token> shadow_19;
	_0 = AUTO_25(pos);
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
	auto begin_16 = pos;
	while (1)
	{
		_7 = Rule_CSEQUENCE_ESCAPE(begin_16);
		if (!(_7.status))
		{
			_10 = Rule_CSEQUENCE_DIAPASON(begin_16);
			if (!(_10.status))
			{
				_13 = Rule_CSEQUENCE_SYMBOL(begin_16);
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
		shadow_16.push_back(dt);
	}
	if (success_6)
	{
		success_4 = true;
		pos = begin_16;
	}
	skip_spaces(pos);
	_17 = AUTO_27(pos);
	if (!(_17.status))
	{
		reportError(pos, "\"]\"");
		return {};
	}
	success_18 = true;
	pos += _17.node.length();
	shadow_19.push_back(_17.node);
	::Parser::Types::Rule_CSEQUENCE_data data;
	data.val = dt;
	data._not = _2;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::Rule_CSEQUENCE, data)};
}
Parser::Token_res Parser::Lexer::Rule_NOSPACE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
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
		reportError(pos, "any symbol");
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
	if (!(*(pos + 0) == '$'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_0_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_0, data)};
}
Parser::Token_res Parser::Lexer::AUTO_1(const char* pos) {
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
	::Parser::Types::AUTO_1_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_1, data)};
}
Parser::Token_res Parser::Lexer::AUTO_6(const char* pos) {
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
	::Parser::Types::AUTO_6_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_6, data)};
}
Parser::Token_res Parser::Lexer::AUTO_7(const char* pos) {
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
	::Parser::Types::AUTO_7_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_7, data)};
}
Parser::Token_res Parser::Lexer::AUTO_14(const char* pos) {
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
	::Parser::Types::AUTO_14_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_14, data)};
}
Parser::Token_res Parser::Lexer::AUTO_19(const char* pos) {
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
	::Parser::Types::AUTO_19_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_19, data)};
}
Parser::Token_res Parser::Lexer::AUTO_20(const char* pos) {
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
	::Parser::Types::AUTO_20_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_20, data)};
}
Parser::Token_res Parser::Lexer::AUTO_25(const char* pos) {
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
	::Parser::Types::AUTO_25_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_25, data)};
}
Parser::Token_res Parser::Lexer::AUTO_27(const char* pos) {
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
	::Parser::Types::AUTO_27_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_27, data)};
}
Parser::Token_res Parser::Lexer::AUTO_32(const char* pos) {
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
	::Parser::Types::AUTO_32_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_32, data)};
}
Parser::Token_res Parser::Lexer::AUTO_34(const char* pos) {
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
	::Parser::Types::AUTO_34_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_34, data)};
}
Parser::Token_res Parser::Lexer::AUTO_36(const char* pos) {
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
	::Parser::Types::AUTO_36_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_36, data)};
}
Parser::Token_res Parser::Lexer::AUTO_38(const char* pos) {
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
	::Parser::Types::AUTO_38_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_38, data)};
}
Parser::Token_res Parser::Lexer::AUTO_39(const char* pos) {
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
	::Parser::Types::AUTO_39_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_39, data)};
}
Parser::Token_res Parser::Lexer::AUTO_40(const char* pos) {
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
	::Parser::Types::AUTO_40_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_40, data)};
}
Parser::Token_res Parser::Lexer::AUTO_41(const char* pos) {
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
	::Parser::Types::AUTO_41_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_41, data)};
}
Parser::Token_res Parser::Lexer::AUTO_42(const char* pos) {
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
	::Parser::Types::AUTO_42_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_42, data)};
}
Parser::Token_res Parser::Lexer::AUTO_45(const char* pos) {
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
	::Parser::Types::AUTO_45_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_45, data)};
}
Parser::Token_res Parser::Lexer::AUTO_46(const char* pos) {
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
	::Parser::Types::AUTO_46_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_46, data)};
}
Parser::Token_res Parser::Lexer::AUTO_47(const char* pos) {
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
	::Parser::Types::AUTO_47_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_47, data)};
}
Parser::Token_res Parser::Lexer::AUTO_48(const char* pos) {
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
	::Parser::Types::AUTO_48_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_48, data)};
}
Parser::Token_res Parser::Lexer::AUTO_49(const char* pos) {
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
	::Parser::Types::AUTO_49_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_49, data)};
}
Parser::Token_res Parser::Lexer::AUTO_50(const char* pos) {
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
	::Parser::Types::AUTO_50_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_50, data)};
}
Parser::Token_res Parser::Lexer::__WHITESPACE(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::__WHITESPACE)};
}
