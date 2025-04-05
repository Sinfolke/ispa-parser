#include "Parser.h"
void Parser::Lexer::printTokens(std::ostream& os, bool sensitiveInfo) {
    for (const auto& token : tokens)
        printToken(os, token, sensitiveInfo);
}
void Parser::Lexer::printToken(std::ostream& os, const Token& token, bool sensitiveInfo) {
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
    if (sensitiveInfo)
        os << ", line " << token.line() << ", pos " << token.positionInLine();
    os << '\n';
}
Parser::Rule_res Parser::Parser::getRule() {
    return main(pos);
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
		case Tokens::LINEAR_COMMENT: return "LINEAR_COMMENT";
		case Tokens::ID: return "ID";
		case Tokens::NAME: return "NAME";
		case Tokens::AT: return "AT";
		case Tokens::Rule_OP: return "Rule_OP";
		case Tokens::Rule_QUANTIFIER: return "Rule_QUANTIFIER";
		case Tokens::Rule_CSEQUENCE: return "Rule_CSEQUENCE";
		case Tokens::Rule_CSEQUENCE_SYMBOL: return "Rule_CSEQUENCE_SYMBOL";
		case Tokens::Rule_CSEQUENCE_ESCAPE: return "Rule_CSEQUENCE_ESCAPE";
		case Tokens::Rule_CSEQUENCE_DIAPASON: return "Rule_CSEQUENCE_DIAPASON";
		case Tokens::Rule_ANY: return "Rule_ANY";
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
		case Tokens::AUTO_35: return "AUTO_35";
		case Tokens::AUTO_36: return "AUTO_36";
		case Tokens::AUTO_37: return "AUTO_37";
		case Tokens::AUTO_38: return "AUTO_38";
		case Tokens::AUTO_40: return "AUTO_40";
		case Tokens::AUTO_42: return "AUTO_42";
		case Tokens::AUTO_43: return "AUTO_43";
		case Tokens::AUTO_44: return "AUTO_44";
		case Tokens::AUTO_45: return "AUTO_45";
		case Tokens::AUTO_46: return "AUTO_46";
		case Tokens::AUTO_49: return "AUTO_49";
		case Tokens::AUTO_50: return "AUTO_50";
		case Tokens::AUTO_51: return "AUTO_51";
		case Tokens::AUTO_52: return "AUTO_52";
		case Tokens::AUTO_53: return "AUTO_53";
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
		case Rules::cll_expr_value: return "cll_expr_value";
		case Rules::cll_expr_group: return "cll_expr_group";
		case Rules::cll_var: return "cll_var";
		case Rules::cll_block: return "cll_block";
		case Rules::cll_loop_while: return "cll_loop_while";
		case Rules::cll_loop_for: return "cll_loop_for";
		case Rules::array: return "array";
		case Rules::object: return "object";
		case Rules::any_data: return "any_data";
		case Rules::spacemode: return "spacemode";
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
::Parser::Types::NAME_data Parser::get::NAME(::Parser::Token &token) {
	return std::any_cast<Types::NAME_data>(token.data());
}
::Parser::Types::Rule_QUANTIFIER_data Parser::get::Rule_QUANTIFIER(::Parser::Token &token) {
	return std::any_cast<Types::Rule_QUANTIFIER_data>(token.data());
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
::Parser::Types::AUTO_35_data Parser::get::AUTO_35(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_35_data>(token.data());
}
::Parser::Types::AUTO_36_data Parser::get::AUTO_36(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_36_data>(token.data());
}
::Parser::Types::AUTO_37_data Parser::get::AUTO_37(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_37_data>(token.data());
}
::Parser::Types::AUTO_38_data Parser::get::AUTO_38(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_38_data>(token.data());
}
::Parser::Types::AUTO_40_data Parser::get::AUTO_40(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_40_data>(token.data());
}
::Parser::Types::AUTO_42_data Parser::get::AUTO_42(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_42_data>(token.data());
}
::Parser::Types::AUTO_43_data Parser::get::AUTO_43(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_43_data>(token.data());
}
::Parser::Types::AUTO_44_data Parser::get::AUTO_44(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_44_data>(token.data());
}
::Parser::Types::AUTO_45_data Parser::get::AUTO_45(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_45_data>(token.data());
}
::Parser::Types::AUTO_46_data Parser::get::AUTO_46(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_46_data>(token.data());
}
::Parser::Types::AUTO_49_data Parser::get::AUTO_49(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_49_data>(token.data());
}
::Parser::Types::AUTO_50_data Parser::get::AUTO_50(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_50_data>(token.data());
}
::Parser::Types::AUTO_51_data Parser::get::AUTO_51(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_51_data>(token.data());
}
::Parser::Types::AUTO_52_data Parser::get::AUTO_52(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_52_data>(token.data());
}
::Parser::Types::AUTO_53_data Parser::get::AUTO_53(::Parser::Token &token) {
	return std::any_cast<Types::AUTO_53_data>(token.data());
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
::Parser::Types::spacemode_data Parser::get::spacemode(::Parser::Rule &rule) {
	return std::any_cast<Types::spacemode_data>(rule.data());
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
	::Parser::Token_res _100;
	::Parser::bool_t success_101 = false;
	_2 = Rule_ESCAPED(pos);
	if (!(_2.status))
	{
		_4 = Rule_CSEQUENCE(pos);
		if (!(_4.status))
		{
			_6 = NUMBER(pos);
			if (!(_6.status))
			{
				_8 = cll_ASSIGNMENT_OP(pos);
				if (!(_8.status))
				{
					_10 = NAME(pos);
					if (!(_10.status))
					{
						_12 = LINEAR_COMMENT(pos);
						if (!(_12.status))
						{
							_14 = Rule_BIN(pos);
							if (!(_14.status))
							{
								_16 = Rule_HEX(pos);
								if (!(_16.status))
								{
									_18 = AUTO_19(pos);
									if (!(_18.status))
									{
										_20 = AUTO_20(pos);
										if (!(_20.status))
										{
											_22 = cll_OP(pos);
											if (!(_22.status))
											{
												_24 = AUTO_34(pos);
												if (!(_24.status))
												{
													_26 = AUTO_35(pos);
													if (!(_26.status))
													{
														_28 = AUTO_36(pos);
														if (!(_28.status))
														{
															_30 = AUTO_37(pos);
															if (!(_30.status))
															{
																_32 = Rule_NOSPACE(pos);
																if (!(_32.status))
																{
																	_34 = AUTO_38(pos);
																	if (!(_34.status))
																	{
																		_36 = AUTO_6(pos);
																		if (!(_36.status))
																		{
																			_38 = AUTO_7(pos);
																			if (!(_38.status))
																			{
																				_40 = AUTO_14(pos);
																				if (!(_40.status))
																				{
																					_42 = AUTO_1(pos);
																					if (!(_42.status))
																					{
																						_44 = AUTO_46(pos);
																						if (!(_44.status))
																						{
																							_46 = AUTO_0(pos);
																							if (!(_46.status))
																							{
																								_48 = AUTO_45(pos);
																								if (!(_48.status))
																								{
																									_50 = AUTO_43(pos);
																									if (!(_50.status))
																									{
																										_52 = AUTO_44(pos);
																										if (!(_52.status))
																										{
																											_54 = AUTO_52(pos);
																											if (!(_54.status))
																											{
																												_56 = AUTO_42(pos);
																												if (!(_56.status))
																												{
																													_58 = Rule_ANY(pos);
																													if (!(_58.status))
																													{
																														_60 = AUTO_40(pos);
																														if (!(_60.status))
																														{
																															_62 = AUTO_32(pos);
																															if (!(_62.status))
																															{
																																_64 = AUTO_50(pos);
																																if (!(_64.status))
																																{
																																	_66 = AT(pos);
																																	if (!(_66.status))
																																	{
																																		_68 = AUTO_25(pos);
																																		if (!(_68.status))
																																		{
																																			_70 = AUTO_27(pos);
																																			if (!(_70.status))
																																			{
																																				_72 = AUTO_51(pos);
																																				if (!(_72.status))
																																				{
																																					_74 = Rule_OP(pos);
																																					if (!(_74.status))
																																					{
																																						_76 = AUTO_53(pos);
																																						if (!(_76.status))
																																						{
																																							_78 = __WHITESPACE(pos);
																																							if (!(_78.status))
																																							{
																																								_80 = END(pos);
																																								if (!(_80.status))
																																								{
																																									_82 = AUTO_49(pos);
																																									if (!(_82.status))
																																									{
																																										_84 = NEWLINE(pos);
																																										if (!(_84.status))
																																										{
																																											_86 = STRING(pos);
																																											if (!(_86.status))
																																											{
																																												_88 = ID(pos);
																																												if (!(_88.status))
																																												{
																																													_90 = cll_TYPE(pos);
																																													if (!(_90.status))
																																													{
																																														_92 = cll_COMPARE_OP(pos);
																																														if (!(_92.status))
																																														{
																																															_94 = cll_LOGICAL_OP(pos);
																																															if (!(_94.status))
																																															{
																																																_96 = cll_LOGICAL_NOT(pos);
																																																if (!(_96.status))
																																																{
																																																	_98 = BOOLEAN(pos);
																																																	if (!(_98.status))
																																																	{
																																																		_100 = Rule_QUANTIFIER(pos);
																																																		if (!(_100.status))
																																																		{
																																																			return {};
																																																		}
																																																		else 
																																																		{
																																																			success_101 = true;
																																																			pos += _100.node.length();
																																																			_0 = _100.node;
																																																		}
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
	if (!(*(pos + 0) == '%'))
	{
		if (!(*(pos + 0) == '*'))
		{
			if (!(*(pos + 0) == '+'))
			{
				if (!(*(pos + 0) == '-'))
				{
					if (!(*(pos + 0) == '/'))
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
	Types::cll_OP_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::cll_OP, data)};
}
Parser::Token_res Parser::Lexer::cll_ASSIGNMENT_OP(const char* pos) {
	auto in = pos;
	::Parser::Token_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	_0 = cll_OP(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	pos += _0.node.length();
	skip_spaces(pos);
	if (!(*(pos + 0) == '='))
	{
		return {};
	}
	_2 += ::Parser::str_t(pos, 1);
	success_3 = true;
	pos += 1;
	Types::cll_ASSIGNMENT_OP_data data = _0.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::cll_ASSIGNMENT_OP, data)};
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
	if (!(!std::strncmp(pos, "!=", 2)))
	{
		if (!(!std::strncmp(pos, "<=", 2)))
		{
			if (!(!std::strncmp(pos, "==", 2)))
			{
				if (!(!std::strncmp(pos, ">=", 2)))
				{
					if (!(*(pos + 0) == '<'))
					{
						if (!(*(pos + 0) == '>'))
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
	Types::cll_COMPARE_OP_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::cll_COMPARE_OP, data)};
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
	Types::cll_LOGICAL_OP_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::cll_LOGICAL_OP, data)};
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::cll_LOGICAL_NOT)};
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::cll_LOGICAL_AND)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_OR(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	if (!(!std::strncmp(pos, "or", 2)))
	{
		if (!(!std::strncmp(pos, "||", 2)))
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::cll_LOGICAL_OR)};
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
		if (!(!std::strncmp(begin_28, "any", 3)))
		{
			if (!(!std::strncmp(begin_28, "num", 3)))
			{
				if (!(!std::strncmp(begin_28, "str", 3)))
				{
					if (!(!std::strncmp(begin_28, "var", 3)))
					{
						auto begin_20 = begin_28;
						if (!(!std::strncmp(begin_20 + 0, "arr", 3)))
						{
							return {};
						}
						_16 += ::Parser::str_t(begin_20, 3);
						success_17 = true;
						begin_20 += 3;
						skip_spaces(begin_20);
						_18 = cll_TEMPLATE(begin_20);
						if (!(_18.status))
						{
							return {};
						}
						success_19 = true;
						begin_20 += _18.node.length();
						if (success_17 && success_19)
						{
							success_15 = true;
							begin_28 = begin_20;
						}
						;
						if (!success_15)
						{
							auto begin_27 = begin_28;
							if (!(!std::strncmp(begin_27 + 0, "obj", 3)))
							{
								return {};
							}
							_23 += ::Parser::str_t(begin_27, 3);
							success_24 = true;
							begin_27 += 3;
							skip_spaces(begin_27);
							_25 = cll_TEMPLATE(begin_27);
							if (!(_25.status))
							{
								return {};
							}
							success_26 = true;
							begin_27 += _25.node.length();
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
		_4 = ::Parser::str_t(begin_28, 3);
		success_5 = true;
		begin_28 += 3;
		_2 = _4;
	}
	success_3 = true;
	if (success_3)
	{
		success_1 = true;
		pos = begin_28;
	}
	Types::cll_TYPE_data data;
	data.templ = _23;
	data.type = _16;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::cll_TYPE, data)};
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
	::Parser::str_t _11;
	::Parser::bool_t success_12 = false;
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
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	auto begin_10 = pos;
	if (!(*(begin_10 + 0) == ','))
	{
		return {};
	}
	_6 += ::Parser::str_t(begin_10, 1);
	success_7 = true;
	begin_10 += 1;
	skip_spaces(begin_10);
	_8 = cll_TYPE(begin_10);
	if (!(_8.status))
	{
		return {};
	}
	success_9 = true;
	begin_10 += _8.node.length();
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_10;
	}
	skip_spaces(pos);
	if (!(*(pos + 0) == '>'))
	{
		return {};
	}
	_11 += ::Parser::str_t(pos, 1);
	success_12 = true;
	pos += 1;
	Types::cll_TEMPLATE_data data;
	data.second = _8.node;
	data.first = _2.node;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::cll_TEMPLATE, data)};
}
Parser::Rule_res Parser::Parser::cll_if(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_1))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_2 = cll_expr(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_4 = cll_block(pos);
	if (!(_4.status))
	{
		return {};
	}
	success_5 = true;
	std::advance(pos, _4.node.length());
	Types::cll_if_data data;
	data.block = _4.node;
	data.expr = _2.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_if, data)};
}
Parser::Rule_res Parser::Parser::cll_variable(::Parser::TokenFlow::iterator pos) {
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
	if (!(begin_8->name() == Tokens::AUTO_6))
	{
		if (!(begin_8->name() == Tokens::AUTO_7))
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
	if (success_3)
	{
		success_1 = true;
		pos = begin_8;
	}
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::ID))
	{
		return {};
	}
	_9 = *pos;
	success_10 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_19 = pos;
	if (!(begin_19->name() == Tokens::AUTO_25))
	{
		return {};
	}
	_13 = *begin_19;
	success_14 = true;
	begin_19++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_15 = cll_expr(begin_19);
	if (!(_15.status))
	{
		return {};
	}
	success_16 = true;
	std::advance(begin_19, _15.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(begin_19->name() == Tokens::AUTO_27))
	{
		return {};
	}
	_17 = *begin_19;
	success_18 = true;
	begin_19++;
	if (success_14 && success_16 && success_18)
	{
		success_12 = true;
		pos = begin_19;
	}
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_28 = pos;
	if (!(begin_28->name() == Tokens::AUTO_6))
	{
		if (!(begin_28->name() == Tokens::AUTO_7))
		{
			return {};
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
	if (success_23)
	{
		success_21 = true;
		pos = begin_28;
	}
	Types::cll_variable_data data;
	data.post = _20;
	data.pre = _0;
	data.brace_expression = _15.node;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_variable, data)};
}
Parser::Rule_res Parser::Parser::cll_function_body_call(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_43))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_2 = cll_function_arguments(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_44))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	Types::cll_function_body_call_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_function_body_call, data)};
}
Parser::Rule_res Parser::Parser::cll_function_body_decl(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_43))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_2 = cll_function_parameters(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_44))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	Types::cll_function_body_decl_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_function_body_decl, data)};
}
Parser::Rule_res Parser::Parser::cll_function_arguments(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::bool_t success_1 = false;
	::Parser::any_t _2;
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
	auto begin_15 = pos;
	_4 = any_data(begin_15);
	if (!(_4.status))
	{
		if (!(begin_15->name() == Tokens::ID))
		{
			return {};
		}
		else 
		{
			_6 = *begin_15;
			success_7 = true;
			begin_15++;
			_2 = _6;
		}
	}
	else 
	{
		success_5 = true;
		std::advance(begin_15, _4.node.length());
		_2 = _4.node;
	}
	success_3 = true;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_14 = begin_15;
	if (!(begin_14->name() == Tokens::AUTO_52))
	{
		return {};
	}
	else 
	{
		_12 = *begin_14;
		success_13 = true;
		begin_14++;
		_10 = _12;
	}
	success_11 = true;
	_8 = _10;
	if (success_11)
	{
		success_9 = true;
		begin_15 = begin_14;
	}
	if (success_3 && success_9)
	{
		success_1 = true;
		pos = begin_15;
	}
	Types::cll_function_arguments_data data;
	data.second = _8;
	data.first = _2;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_function_arguments, data)};
}
Parser::Rule_res Parser::Parser::cll_function_parameters(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token _8;
	::Parser::bool_t success_9 = false;
	auto begin_11 = pos;
	if (!(begin_11->name() == Tokens::ID))
	{
		return {};
	}
	_2 = *begin_11;
	success_3 = true;
	begin_11++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = begin_11;
	if (!(begin_10->name() == Tokens::AUTO_52))
	{
		return {};
	}
	_6 = *begin_10;
	success_7 = true;
	begin_10++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(begin_10->name() == Tokens::ID))
	{
		return {};
	}
	_8 = *begin_10;
	success_9 = true;
	begin_10++;
	if (success_7 && success_9)
	{
		success_5 = true;
		begin_11 = begin_10;
	}
	if (success_3 && success_5)
	{
		success_1 = true;
		pos = begin_11;
	}
	Types::cll_function_parameters_data data;
	data.second = _8;
	data.first = _2;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_function_parameters, data)};
}
Parser::Rule_res Parser::Parser::cll_cll_function_call(::Parser::TokenFlow::iterator pos) {
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
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_2 = cll_function_body_call(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	Types::cll_cll_function_call_data data;
	data.body = _2.node;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_cll_function_call, data)};
}
Parser::Rule_res Parser::Parser::cll_function_decl(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::Rule val;
	::Parser::bool_t success_9 = false;
	::Parser::Rule_res _10;
	::Parser::bool_t success_11 = false;
	if (!(pos->name() == Tokens::AUTO_14))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_6 = pos;
	if (!(begin_6->name() == Tokens::ID))
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
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_7 = cll_function_body_decl(pos);
	if (!(_7.status))
	{
		return {};
	}
	success_8 = true;
	std::advance(pos, _7.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_12 = pos;
	_10 = cll_block(begin_12);
	if (!(_10.status))
	{
		return {};
	}
	success_11 = true;
	std::advance(begin_12, _10.node.length());
	val = _10.node;
	if (success_11)
	{
		success_9 = true;
		pos = begin_12;
	}
	Types::cll_function_decl_data data;
	data.value = val;
	data.name = _2;
	data.type = _4;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_function_decl, data)};
}
Parser::Rule_res Parser::Parser::cll_expr_logical(::Parser::TokenFlow::iterator pos) {
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
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::cll_LOGICAL_OP))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
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
	Types::cll_expr_logical_data data;
	data.right = _10;
	data.op = _8;
	data.left = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_expr_logical, data)};
}
Parser::Rule_res Parser::Parser::cll_expr_compare(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	_0 = cll_expr_arithmetic(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	std::advance(pos, _0.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_8 = pos;
	if (!(begin_8->name() == Tokens::cll_COMPARE_OP))
	{
		return {};
	}
	_4 = *begin_8;
	success_5 = true;
	begin_8++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_6 = cll_expr_arithmetic(begin_8);
	if (!(_6.status))
	{
		return {};
	}
	success_7 = true;
	std::advance(begin_8, _6.node.length());
	if (success_5 && success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	Types::cll_expr_compare_data data;
	data.sequence = _6.node;
	data.operators = _4;
	data.first = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_expr_compare, data)};
}
Parser::Rule_res Parser::Parser::cll_expr_arithmetic(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	_0 = cll_expr_value(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	std::advance(pos, _0.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_8 = pos;
	if (!(begin_8->name() == Tokens::cll_OP))
	{
		return {};
	}
	_4 = *begin_8;
	success_5 = true;
	begin_8++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_6 = cll_expr_value(begin_8);
	if (!(_6.status))
	{
		return {};
	}
	success_7 = true;
	std::advance(begin_8, _6.node.length());
	if (success_5 && success_7)
	{
		success_3 = true;
		pos = begin_8;
	}
	Types::cll_expr_arithmetic_data data;
	data.sequence = _6.node;
	data.operators = _4;
	data.first = _0.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_expr_arithmetic, data)};
}
Parser::Rule_res Parser::Parser::cll_expr_value(::Parser::TokenFlow::iterator pos) {
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
	_2 = cll_variable(pos);
	if (!(_2.status))
	{
		_4 = cll_expr_group(pos);
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
	Types::cll_expr_value_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_expr_value, data)};
}
Parser::Rule_res Parser::Parser::cll_expr_group(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_43))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_2 = cll_expr(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_44))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	Types::cll_expr_group_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_expr_group, data)};
}
Parser::Rule_res Parser::Parser::cll_expr(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::any_t _0;
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
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	_2 = cll_expr_logical(pos);
	if (!(_2.status))
	{
		_4 = cll_expr_group(pos);
		if (!(_4.status))
		{
			_6 = cll_expr_compare(pos);
			if (!(_6.status))
			{
				_8 = cll_expr_arithmetic(pos);
				if (!(_8.status))
				{
					_10 = cll_expr_value(pos);
					if (!(_10.status))
					{
						if (!(pos->name() == Tokens::AT))
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
	Types::cll_expr_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_expr, data)};
}
Parser::Rule_res Parser::Parser::cll_var(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	if (!(pos->name() == Tokens::cll_TYPE))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	if (!(begin_10->name() == Tokens::cll_ASSIGNMENT_OP))
	{
		return {};
	}
	_6 = *begin_10;
	success_7 = true;
	begin_10++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_8 = cll_expr(begin_10);
	if (!(_8.status))
	{
		return {};
	}
	success_9 = true;
	std::advance(begin_10, _8.node.length());
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_10;
	}
	Types::cll_var_data data;
	data.value = _8.node;
	data.op = _6;
	data.id = _2;
	data.type = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_var, data)};
}
Parser::Rule_res Parser::Parser::cll_block(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_51))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_2 = Rule_rule(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_53))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	Types::cll_block_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_block, data)};
}
Parser::Rule_res Parser::Parser::cll_loop_while(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_19))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_2 = cll_expr(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_4 = cll_block(pos);
	if (!(_4.status))
	{
		return {};
	}
	success_5 = true;
	std::advance(pos, _4.node.length());
	Types::cll_loop_while_data data;
	data.block = _4.node;
	data.expr = _2.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_loop_while, data)};
}
Parser::Rule_res Parser::Parser::cll_loop_for(::Parser::TokenFlow::iterator pos) {
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
	if (!(pos->name() == Tokens::AUTO_20))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_43))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_12 = pos;
	_8 = cll_var(begin_12);
	if (!(_8.status))
	{
		_10 = cll_expr(begin_12);
		if (!(_10.status))
		{
			return {};
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
	if (success_7)
	{
		success_5 = true;
		pos = begin_12;
	}
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_32))
	{
		return {};
	}
	_13 = *pos;
	success_14 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_15 = cll_expr(pos);
	if (!(_15.status))
	{
		return {};
	}
	success_16 = true;
	std::advance(pos, _15.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_32))
	{
		return {};
	}
	_17 = *pos;
	success_18 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_19 = cll_expr(pos);
	if (!(_19.status))
	{
		return {};
	}
	success_20 = true;
	std::advance(pos, _19.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_44))
	{
		return {};
	}
	_21 = *pos;
	success_22 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_23 = cll_block(pos);
	if (!(_23.status))
	{
		return {};
	}
	success_24 = true;
	std::advance(pos, _23.node.length());
	Types::cll_loop_for_data data;
	data.block = _21;
	data.end = _17;
	data.cond = _13;
	data.decl = _6;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll_loop_for, data)};
}
Parser::Rule_res Parser::Parser::cll(::Parser::TokenFlow::iterator pos) {
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
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_4 = cll_loop_for(pos);
	if (!(_4.status))
	{
		_6 = cll_loop_while(pos);
		if (!(_6.status))
		{
			_8 = cll_if(pos);
			if (!(_8.status))
			{
				_10 = cll_var(pos);
				if (!(_10.status))
				{
					_12 = cll_expr(pos);
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
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::END))
	{
		return {};
	}
	_14 = *pos;
	success_15 = true;
	pos++;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::cll)};
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
	::Parser::str_t _10;
	::Parser::bool_t success_11 = false;
	::Parser::str_t _12;
	::Parser::bool_t success_13 = false;
	::Parser::str_t _14;
	::Parser::bool_t success_15 = false;
	::Parser::str_t _18;
	::Parser::bool_t success_19 = false;
	auto begin_20 = pos;
	if (!(*(begin_20 + 0) == '\''))
	{
		return {};
	}
	_2 += ::Parser::str_t(begin_20, 1);
	success_3 = true;
	begin_20 += 1;
	skip_spaces(begin_20);
	auto begin_17 = begin_20;
	if (!(!(*(begin_17 + 0) == '\'' || *(begin_17 + 0) == '\0')))
	{
		auto begin_16 = begin_17;
		if (!(!std::strncmp(begin_16 + 0, "\\", 1)))
		{
			return {};
		}
		_12 += ::Parser::str_t(begin_16, 1);
		success_13 = true;
		begin_16 += 1;
		skip_spaces(begin_16);
		if (*(begin_16 + 0) == '\0')
		{
			return {};
		}
		_14 += ::Parser::str_t(begin_16, 1);
		success_15 = true;
		begin_16 += 1;
		_10 += _12;
		_10 += _14;
		if (success_13 && success_15)
		{
			success_11 = true;
			begin_17 = begin_16;
		}
		;
		if (!success_11)
		{
			return {};
		}
		else 
		{
			_6 = _10;
		}
	}
	else 
	{
		_8 = ::Parser::str_t(begin_17, 1);
		success_9 = true;
		begin_17 += 1;
		_6 = _8;
	}
	success_7 = true;
	_4 += _6;
	if (success_7)
	{
		success_5 = true;
		begin_20 = begin_17;
	}
	skip_spaces(begin_20);
	if (!(*(begin_20 + 0) == '\''))
	{
		return {};
	}
	_18 += ::Parser::str_t(begin_20, 1);
	success_19 = true;
	begin_20 += 1;
	_0 += _2;
	_0 += _4;
	_0 += _18;
	if (success_3 && success_5 && success_19)
	{
		success_1 = true;
		pos = begin_20;
	}
	Types::STRING_data data = _4;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::STRING, data)};
}
Parser::Token_res Parser::Lexer::NUMBER(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _7;
	::Parser::bool_t success_8 = false;
	::Parser::str_t _9;
	::Parser::bool_t success_10 = false;
	::Parser::str_t _11;
	::Parser::bool_t success_12 = false;
	if (!(*(pos + 0) == '+' || *(pos + 0) == '-'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	auto begin_6 = pos;
	if (!((*(begin_6 + 0)>='0' && *(begin_6 + 0)<='9')))
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
	skip_spaces(pos);
	auto begin_13 = pos;
	if (!(*(begin_13 + 0) == '.' || *(begin_13 + 0) == ','))
	{
		return {};
	}
	_9 += ::Parser::str_t(begin_13, 1);
	success_10 = true;
	begin_13 += 1;
	skip_spaces(begin_13);
	if (!((*(begin_13 + 0)>='0' && *(begin_13 + 0)<='9')))
	{
		return {};
	}
	_11 += ::Parser::str_t(begin_13, 1);
	success_12 = true;
	begin_13 += 1;
	_7 += _9;
	_7 += _11;
	if (success_10 && success_12)
	{
		success_8 = true;
		pos = begin_13;
	}
	Types::NUMBER_data data;
	data.dec = _9;
	data.main = _4;
	data.sign = _0;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::NUMBER, data)};
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
	Types::BOOLEAN_data data = d;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::BOOLEAN, data)};
}
Parser::Rule_res Parser::Parser::array(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token _8;
	::Parser::bool_t success_9 = false;
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	if (!(pos->name() == Tokens::AUTO_25))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_11 = pos;
	auto begin_10 = begin_11;
	_6 = any_data(begin_10);
	if (!(_6.status))
	{
		return {};
	}
	success_7 = true;
	std::advance(begin_10, _6.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(begin_10->name() == Tokens::AUTO_52))
	{
		return {};
	}
	_8 = *begin_10;
	success_9 = true;
	begin_10++;
	if (success_7 && success_9)
	{
		success_5 = true;
		begin_11 = begin_10;
	}
	if (success_5)
	{
		success_3 = true;
		pos = begin_11;
	}
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_27))
	{
		return {};
	}
	_12 = *pos;
	success_13 = true;
	pos++;
	Types::array_data data = _6.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::array, data)};
}
Parser::Rule_res Parser::Parser::object(::Parser::TokenFlow::iterator pos) {
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
	::Parser::Token _14;
	::Parser::bool_t success_15 = false;
	::Parser::Token _16;
	::Parser::bool_t success_17 = false;
	::Parser::Rule_res _18;
	::Parser::bool_t success_19 = false;
	::Parser::Token _21;
	::Parser::bool_t success_22 = false;
	::Parser::Token _24;
	::Parser::bool_t success_25 = false;
	if (!(pos->name() == Tokens::AUTO_51))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_23 = pos;
	_4 = any_data(begin_23);
	if (!(_4.status))
	{
		return {};
	}
	success_5 = true;
	std::advance(begin_23, _4.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(begin_23->name() == Tokens::AUTO_40))
	{
		return {};
	}
	_6 = *begin_23;
	success_7 = true;
	begin_23++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_8 = any_data(begin_23);
	if (!(_8.status))
	{
		return {};
	}
	success_9 = true;
	std::advance(begin_23, _8.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_20 = begin_23;
	if (!(begin_20->name() == Tokens::AUTO_52))
	{
		return {};
	}
	_12 = *begin_20;
	success_13 = true;
	begin_20++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(begin_20->name() == Tokens::ID))
	{
		return {};
	}
	_14 = *begin_20;
	success_15 = true;
	begin_20++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(begin_20->name() == Tokens::AUTO_40))
	{
		return {};
	}
	_16 = *begin_20;
	success_17 = true;
	begin_20++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_18 = any_data(begin_20);
	if (!(_18.status))
	{
		return {};
	}
	success_19 = true;
	std::advance(begin_20, _18.node.length());
	if (success_13 && success_15 && success_17 && success_19)
	{
		success_11 = true;
		begin_23 = begin_20;
	}
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(begin_23->name() == Tokens::AUTO_32))
	{
		return {};
	}
	_21 = *begin_23;
	success_22 = true;
	begin_23++;
	if (success_5 && success_7 && success_9 && success_11 && success_22)
	{
		success_3 = true;
		pos = begin_23;
	}
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_53))
	{
		return {};
	}
	_24 = *pos;
	success_25 = true;
	pos++;
	Types::object_data data;
	data.values = _16;
	data.keys = _12;
	data.value = _8.node;
	data.key = _4.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::object, data)};
}
Parser::Rule_res Parser::Parser::any_data(::Parser::TokenFlow::iterator pos) {
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
				if (!(pos->name() == Tokens::STRING))
				{
					if (!(pos->name() == Tokens::ID))
					{
						if (!(pos->name() == Tokens::BOOLEAN))
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
	Types::any_data_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::any_data, data)};
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::END)};
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::NEWLINE)};
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
	if (!(!(*(pos + 0) == '\n' || *(pos + 0) == '\0')))
	{
		return {};
	}
	_2 += ::Parser::str_t(pos, 1);
	success_3 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::LINEAR_COMMENT)};
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
	if (!((*(begin_6 + 0)>='a' && *(begin_6 + 0)<='z') || (*(begin_6 + 0)>='A' && *(begin_6 + 0)<='Z') || (*(begin_6 + 0)>='0' && *(begin_6 + 0)<='9') || *(begin_6 + 0) == '_'))
	{
		return {};
	}
	_4 += ::Parser::str_t(begin_6, 1);
	success_5 = true;
	begin_6 += 1;
	_0 += _2;
	_0 += _4;
	if (success_3 && success_5)
	{
		success_1 = true;
		pos = begin_6;
	}
	Types::ID_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::ID, data)};
}
Parser::Rule_res Parser::Parser::spacemode(::Parser::TokenFlow::iterator pos) {
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
	if (!(pos->name() == Tokens::AUTO_34))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_35))
	{
		if (!(pos->name() == Tokens::AUTO_36))
		{
			if (!(pos->name() == Tokens::AUTO_37))
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
	Types::spacemode_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::spacemode, data)};
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
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	Types::NAME_data data = _2.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::NAME, data)};
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AT)};
}
Parser::Rule_res Parser::Parser::main(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token _8;
	::Parser::bool_t success_9 = false;
	_2 = Rule(pos);
	if (!(_2.status))
	{
		_4 = use(pos);
		if (!(_4.status))
		{
			_6 = spacemode(pos);
			if (!(_6.status))
			{
				if (!(pos->name() == Tokens::NAME))
				{
					return {};
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
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::main)};
}
Parser::Rule_res Parser::Parser::use_unit(::Parser::TokenFlow::iterator pos) {
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
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_2 = any_data(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	Types::use_unit_data data;
	data.value = _2.node;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::use_unit, data)};
}
Parser::Rule_res Parser::Parser::use(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	if (!(pos->name() == Tokens::AUTO_38))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_2 = use_unit(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	if (!(begin_10->name() == Tokens::AUTO_52))
	{
		return {};
	}
	_6 = *begin_10;
	success_7 = true;
	begin_10++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_8 = use_unit(begin_10);
	if (!(_8.status))
	{
		return {};
	}
	success_9 = true;
	std::advance(begin_10, _8.node.length());
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_10;
	}
	Types::use_data data;
	data.second = _8.node;
	data.first = _2.node;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::use, data)};
}
Parser::Rule_res Parser::Parser::Rule_rule(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Rule _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	::Parser::any_t _9;
	::Parser::bool_t success_10 = false;
	::Parser::Token _11;
	::Parser::bool_t success_12 = false;
	::Parser::Token _13;
	::Parser::bool_t success_14 = false;
	::Parser::Rule_res _15;
	::Parser::bool_t success_16 = false;
	::Parser::Rule_res _17;
	::Parser::bool_t success_18 = false;
	::Parser::Rule_res _19;
	::Parser::bool_t success_20 = false;
	::Parser::Token _21;
	::Parser::bool_t success_22 = false;
	::Parser::Token _23;
	::Parser::bool_t success_24 = false;
	::Parser::Token _25;
	::Parser::bool_t success_26 = false;
	::Parser::Token _27;
	::Parser::bool_t success_28 = false;
	::Parser::Token _29;
	::Parser::bool_t success_30 = false;
	::Parser::Token _31;
	::Parser::bool_t success_32 = false;
	::Parser::Token _33;
	::Parser::bool_t success_34 = false;
	::Parser::Token _35;
	::Parser::bool_t success_36 = false;
	auto begin_8 = pos;
	_4 = Rule_value(begin_8);
	if (!(_4.status))
	{
		_6 = Rule_keyvalue(begin_8);
		if (!(_6.status))
		{
			return {};
		}
		else 
		{
			success_7 = true;
			std::advance(begin_8, _6.node.length());
			_2 = _6.node;
		}
	}
	else 
	{
		success_5 = true;
		std::advance(begin_8, _4.node.length());
		_2 = _4.node;
	}
	success_3 = true;
	_0 = _2;
	if (success_3)
	{
		success_1 = true;
		pos = begin_8;
	}
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::Rule_ESCAPED))
	{
		if (!(pos->name() == Tokens::Rule_CSEQUENCE))
		{
			_15 = Rule_name(pos);
			if (!(_15.status))
			{
				_17 = cll(pos);
				if (!(_17.status))
				{
					_19 = Rule_group(pos);
					if (!(_19.status))
					{
						if (!(pos->name() == Tokens::LINEAR_COMMENT))
						{
							if (!(pos->name() == Tokens::Rule_BIN))
							{
								if (!(pos->name() == Tokens::Rule_HEX))
								{
									if (!(pos->name() == Tokens::Rule_NOSPACE))
									{
										if (!(pos->name() == Tokens::Rule_ANY))
										{
											if (!(pos->name() == Tokens::Rule_OP))
											{
												if (!(pos->name() == Tokens::STRING))
												{
													return {};
												}
												else 
												{
													_33 = *pos;
													success_34 = true;
													pos++;
													_9 = _33;
												}
											}
											else 
											{
												_31 = *pos;
												success_32 = true;
												pos++;
												_9 = _31;
											}
										}
										else 
										{
											_29 = *pos;
											success_30 = true;
											pos++;
											_9 = _29;
										}
									}
									else 
									{
										_27 = *pos;
										success_28 = true;
										pos++;
										_9 = _27;
									}
								}
								else 
								{
									_25 = *pos;
									success_26 = true;
									pos++;
									_9 = _25;
								}
							}
							else 
							{
								_23 = *pos;
								success_24 = true;
								pos++;
								_9 = _23;
							}
						}
						else 
						{
							_21 = *pos;
							success_22 = true;
							pos++;
							_9 = _21;
						}
					}
					else 
					{
						success_20 = true;
						std::advance(pos, _19.node.length());
						_9 = _19.node;
					}
				}
				else 
				{
					success_18 = true;
					std::advance(pos, _17.node.length());
					_9 = _17.node;
				}
			}
			else 
			{
				success_16 = true;
				std::advance(pos, _15.node.length());
				_9 = _15.node;
			}
		}
		else 
		{
			_13 = *pos;
			success_14 = true;
			std::advance(pos, 1);
			_9 = _13;
		}
	}
	else 
	{
		_11 = *pos;
		success_12 = true;
		std::advance(pos, 1);
		_9 = _11;
	}
	success_10 = true;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::Rule_QUANTIFIER))
	{
		return {};
	}
	_35 = *pos;
	success_36 = true;
	pos++;
	Types::Rule_rule_data data;
	data.quantifier = _9;
	data.val = _0;
	data.prefix = _2;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::Rule_rule, data)};
}
Parser::Rule_res Parser::Parser::Rule_name(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Token _8;
	::Parser::bool_t success_9 = false;
	if (!(pos->name() == Tokens::AUTO_46))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_10 = pos;
	if (!(begin_10->name() == Tokens::AUTO_42))
	{
		return {};
	}
	_6 = *begin_10;
	success_7 = true;
	begin_10++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(begin_10->name() == Tokens::ID))
	{
		return {};
	}
	_8 = *begin_10;
	success_9 = true;
	begin_10++;
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_10;
	}
	Types::Rule_name_data data;
	data.nested_name = _8;
	data.name = _2;
	data.is_nested = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::Rule_name, data)};
}
Parser::Rule_res Parser::Parser::Rule_group(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_43))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_2 = Rule_rule(pos);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	std::advance(pos, _2.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_44))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos++;
	Types::Rule_group_data data = _2.node;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::Rule_group, data)};
}
Parser::Rule_res Parser::Parser::Rule_keyvalue(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AT))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_6 = pos;
	if (!(begin_6->name() == Tokens::ID))
	{
		return {};
	}
	_4 = *begin_6;
	success_5 = true;
	begin_6++;
	if (success_5)
	{
		success_3 = true;
		pos = begin_6;
	}
	Types::Rule_keyvalue_data data = _4;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::Rule_keyvalue, data)};
}
Parser::Rule_res Parser::Parser::Rule_value(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == Tokens::AUTO_45))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	Types::Rule_value_data data = _2;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::Rule_value, data)};
}
Parser::Rule_res Parser::Parser::Rule_nested_rule(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == Tokens::AUTO_46))
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
	Types::Rule_nested_rule_data data = _2;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::Rule_nested_rule, data)};
}
Parser::Rule_res Parser::Parser::Rule_data_block_regular_datablock_key(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token name;
	::Parser::bool_t success_2 = false;
	::Parser::Token _3;
	::Parser::bool_t success_4 = false;
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	::Parser::Rule dt;
	::Parser::bool_t success_8 = false;
	::Parser::Rule_res _9;
	::Parser::bool_t success_10 = false;
	if (!(pos->name() == Tokens::AUTO_49))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_5 = pos;
	if (!(begin_5->name() == Tokens::ID))
	{
		return {};
	}
	_3 = *begin_5;
	success_4 = true;
	begin_5++;
	name = _3;
	if (success_4)
	{
		success_2 = true;
		pos = begin_5;
	}
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_50))
	{
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_11 = pos;
	_9 = cll_expr(begin_11);
	if (!(_9.status))
	{
		return {};
	}
	success_10 = true;
	std::advance(begin_11, _9.node.length());
	dt = _9.node;
	if (success_10)
	{
		success_8 = true;
		pos = begin_11;
	}
	Types::Rule_data_block_regular_datablock_key_data data;
	data.val = dt;
	data.name = name;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::Rule_data_block_regular_datablock_key, data)};
}
Parser::Rule_res Parser::Parser::Rule_data_block_regular_datablock(::Parser::TokenFlow::iterator pos) {
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
	if (!(pos->name() == Tokens::AUTO_51))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_4 = Rule_data_block_regular_datablock_key(pos);
	if (!(_4.status))
	{
		_6 = any_data(pos);
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
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_53))
	{
		return {};
	}
	_8 = *pos;
	success_9 = true;
	pos++;
	Types::Rule_data_block_regular_datablock_data data = _2;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::Rule_data_block_regular_datablock, data)};
}
Parser::Rule_res Parser::Parser::Rule_data_block_templated_datablock(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token first_name;
	::Parser::bool_t success_6 = false;
	::Parser::Token _7;
	::Parser::bool_t success_8 = false;
	::Parser::bool_t success_11 = false;
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	::Parser::Token second_name;
	::Parser::bool_t success_14 = false;
	::Parser::Token _15;
	::Parser::bool_t success_16 = false;
	::Parser::Token _20;
	::Parser::bool_t success_21 = false;
	if (!(pos->name() == Tokens::AT))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_51))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_19 = pos;
	auto begin_9 = begin_19;
	if (!(begin_9->name() == Tokens::ID))
	{
		return {};
	}
	_7 = *begin_9;
	success_8 = true;
	begin_9++;
	first_name = _7;
	if (success_8)
	{
		success_6 = true;
		begin_19 = begin_9;
	}
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_18 = begin_19;
	if (!(begin_18->name() == Tokens::AUTO_52))
	{
		return {};
	}
	_12 = *begin_18;
	success_13 = true;
	begin_18++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	auto begin_17 = begin_18;
	if (!(begin_17->name() == Tokens::ID))
	{
		return {};
	}
	_15 = *begin_17;
	success_16 = true;
	begin_17++;
	second_name = _15;
	if (success_16)
	{
		success_14 = true;
		begin_18 = begin_17;
	}
	if (success_13 && success_14)
	{
		success_11 = true;
		begin_19 = begin_18;
	}
	if (success_6 && success_11)
	{
		success_5 = true;
		pos = begin_19;
	}
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_53))
	{
		return {};
	}
	_20 = *pos;
	success_21 = true;
	pos++;
	Types::Rule_data_block_templated_datablock_data data;
	data.second_name = second_name;
	data.first_name = first_name;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::Rule_data_block_templated_datablock, data)};
}
Parser::Rule_res Parser::Parser::Rule_data_block(::Parser::TokenFlow::iterator pos) {
	auto in = pos;
	::Parser::Rule _0;
	::Parser::bool_t success_1 = false;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	_2 = Rule_data_block_templated_datablock(pos);
	if (!(_2.status))
	{
		_4 = Rule_data_block_regular_datablock(pos);
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
	Types::Rule_data_block_data data = _0;
	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::Rule_data_block, data)};
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::Rule_OP)};
}
Parser::Token_res Parser::Lexer::Rule_QUANTIFIER(const char* pos) {
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
	if (!(*(begin_10 + 0) == '*'))
	{
		if (!(*(begin_10 + 0) == '+'))
		{
			if (!(*(begin_10 + 0) == '?'))
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
		_4 = ::Parser::str_t(begin_10, 1);
		success_5 = true;
		begin_10 += 1;
		_2 = _4;
	}
	success_3 = true;
	_0 += _2;
	if (success_3)
	{
		success_1 = true;
		pos = begin_10;
	}
	Types::Rule_QUANTIFIER_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::Rule_QUANTIFIER, data)};
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
			if (!(!(*(begin_10 + 0) == ']' || *(begin_10 + 0) == '\0')))
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
	Types::Rule_CSEQUENCE_SYMBOL_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::Rule_CSEQUENCE_SYMBOL, data)};
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
	Types::Rule_CSEQUENCE_ESCAPE_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::Rule_CSEQUENCE_ESCAPE, data)};
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
	Types::Rule_CSEQUENCE_DIAPASON_data data = {from,to};
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::Rule_CSEQUENCE_DIAPASON, data)};
}
Parser::Token_res Parser::Lexer::Rule_CSEQUENCE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token dt;
	::Parser::bool_t success_4 = false;
	::Parser::Token _5;
	::Parser::bool_t success_6 = false;
	::Parser::Token_res _7;
	::Parser::bool_t success_8 = false;
	::Parser::Token_res _9;
	::Parser::bool_t success_10 = false;
	::Parser::Token_res _11;
	::Parser::bool_t success_12 = false;
	::Parser::str_t _14;
	::Parser::bool_t success_15 = false;
	if (!(*(pos + 0) == '['))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	if (!(*(pos + 0) == '^'))
	{
		return {};
	}
	_2 += ::Parser::str_t(pos, 1);
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	auto begin_13 = pos;
	_7 = Rule_CSEQUENCE_ESCAPE(begin_13);
	if (!(_7.status))
	{
		_9 = Rule_CSEQUENCE_DIAPASON(begin_13);
		if (!(_9.status))
		{
			_11 = Rule_CSEQUENCE_SYMBOL(begin_13);
			if (!(_11.status))
			{
				return {};
			}
			else 
			{
				success_12 = true;
				begin_13 += _11.node.length();
				_5 = _11.node;
			}
		}
		else 
		{
			success_10 = true;
			begin_13 += _9.node.length();
			_5 = _9.node;
		}
	}
	else 
	{
		success_8 = true;
		begin_13 += _7.node.length();
		_5 = _7.node;
	}
	success_6 = true;
	dt = _5;
	if (success_6)
	{
		success_4 = true;
		pos = begin_13;
	}
	skip_spaces(pos);
	if (!(*(pos + 0) == ']'))
	{
		return {};
	}
	_14 += ::Parser::str_t(pos, 1);
	success_15 = true;
	pos += 1;
	Types::Rule_CSEQUENCE_data data;
	data.val = dt;
	data._not = _2;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::Rule_CSEQUENCE, data)};
}
Parser::Token_res Parser::Lexer::Rule_ANY(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::Rule_ANY)};
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::Rule_NOSPACE)};
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
	Types::Rule_ESCAPED_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::Rule_ESCAPED, data)};
}
Parser::Token_res Parser::Lexer::Rule_HEX(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	if (!(!std::strncmp(pos + 0, "0x", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	if (!((*(pos + 0)>='0' && *(pos + 0)<='9') || (*(pos + 0)>='A' && *(pos + 0)<='F') || (*(pos + 0)>='a' && *(pos + 0)<='f')))
	{
		return {};
	}
	_2 += ::Parser::str_t(pos, 1);
	success_3 = true;
	pos += 1;
	Types::Rule_HEX_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::Rule_HEX, data)};
}
Parser::Token_res Parser::Lexer::Rule_BIN(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	if (!(!std::strncmp(pos + 0, "0b", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	if (!(*(pos + 0) == '0' || *(pos + 0) == '1'))
	{
		return {};
	}
	_2 += ::Parser::str_t(pos, 1);
	success_3 = true;
	pos += 1;
	Types::Rule_BIN_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::Rule_BIN, data)};
}
Parser::Rule_res Parser::Parser::Rule(::Parser::TokenFlow::iterator pos) {
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
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_40))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos++;
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_4 = Rule_rule(pos);
	if (!(_4.status))
	{
		return {};
	}
	success_5 = true;
	std::advance(pos, _4.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_6 = Rule_data_block(pos);
	if (!(_6.status))
	{
		return {};
	}
	success_7 = true;
	std::advance(pos, _6.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	_8 = Rule_nested_rule(pos);
	if (!(_8.status))
	{
		return {};
	}
	success_9 = true;
	std::advance(pos, _8.node.length());
	skip_spaces<::Parser::TokenFlow::iterator, ::Parser::Tokens>(pos);
	if (!(pos->name() == Tokens::AUTO_32))
	{
		return {};
	}
	_10 = *pos;
	success_11 = true;
	pos++;
	Types::Rule_data data;
	data.nested_rules = _8.node;
	data.data_block = _6.node;
	data.rule = _4.node;
	data.name = _0;

	return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), std::distance(in, pos), Rules::Rule, data)};
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
	Types::AUTO_0_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_0, data)};
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
	Types::AUTO_1_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_1, data)};
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
	Types::AUTO_6_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_6, data)};
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
	Types::AUTO_7_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_7, data)};
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
	Types::AUTO_14_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_14, data)};
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
	Types::AUTO_19_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_19, data)};
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
	Types::AUTO_20_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_20, data)};
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
	Types::AUTO_25_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_25, data)};
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
	Types::AUTO_27_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_27, data)};
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
	Types::AUTO_32_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_32, data)};
}
Parser::Token_res Parser::Lexer::AUTO_34(const char* pos) {
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
	Types::AUTO_34_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_34, data)};
}
Parser::Token_res Parser::Lexer::AUTO_35(const char* pos) {
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
	Types::AUTO_35_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_35, data)};
}
Parser::Token_res Parser::Lexer::AUTO_36(const char* pos) {
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
	Types::AUTO_36_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_36, data)};
}
Parser::Token_res Parser::Lexer::AUTO_37(const char* pos) {
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
	Types::AUTO_37_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_37, data)};
}
Parser::Token_res Parser::Lexer::AUTO_38(const char* pos) {
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
	Types::AUTO_38_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_38, data)};
}
Parser::Token_res Parser::Lexer::AUTO_40(const char* pos) {
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
	Types::AUTO_40_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_40, data)};
}
Parser::Token_res Parser::Lexer::AUTO_42(const char* pos) {
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
	Types::AUTO_42_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_42, data)};
}
Parser::Token_res Parser::Lexer::AUTO_43(const char* pos) {
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
	Types::AUTO_43_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_43, data)};
}
Parser::Token_res Parser::Lexer::AUTO_44(const char* pos) {
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
	Types::AUTO_44_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_44, data)};
}
Parser::Token_res Parser::Lexer::AUTO_45(const char* pos) {
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
	Types::AUTO_45_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_45, data)};
}
Parser::Token_res Parser::Lexer::AUTO_46(const char* pos) {
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
	Types::AUTO_46_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_46, data)};
}
Parser::Token_res Parser::Lexer::AUTO_49(const char* pos) {
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
	Types::AUTO_49_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_49, data)};
}
Parser::Token_res Parser::Lexer::AUTO_50(const char* pos) {
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
	Types::AUTO_50_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_50, data)};
}
Parser::Token_res Parser::Lexer::AUTO_51(const char* pos) {
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
	Types::AUTO_51_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_51, data)};
}
Parser::Token_res Parser::Lexer::AUTO_52(const char* pos) {
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
	Types::AUTO_52_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_52, data)};
}
Parser::Token_res Parser::Lexer::AUTO_53(const char* pos) {
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
	Types::AUTO_53_data data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::AUTO_53, data)};
}
Parser::Token_res Parser::Lexer::__WHITESPACE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ' ' || *(pos + 0) == '\t' || *(pos + 0) == '\n' || *(pos + 0) == '\r' || *(pos + 0) == '\v' || *(pos + 0) == '\f'))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 1);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, Tokens::__WHITESPACE)};
}
