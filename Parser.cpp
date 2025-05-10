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
void ::Parser::Parser::printAST(std::ostream &os) {
	size_t indentLevel = 0;
	printRule(os, tree, indentLevel, false);
}
void ::Parser::Parser::printRule(std::ostream &os, const ::Parser::Token &token, size_t &indentLevel, bool addSpaceOnBegin) {
	Lexer::printToken(os, token);
}
void ::Parser::Parser::printRule(std::ostream &os, const ::Parser::Rule &rule, size_t &indentLevel, bool addSpaceOnBegin) {
	printRule(os, rule.data(), indentLevel, addSpaceOnBegin);
}
void ::Parser::Parser::printRule(std::ostream &os, const std::any &data, size_t &indentLevel, bool addSpaceOnBegin) {
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
    }else os << "<UNDEF TYPE>";
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
const ::Parser::Types::AUTO_1& Parser::get::AUTO_1(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_1) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_1, "Parser");
	return std::any_cast<const Types::AUTO_1&>(token.data());
}
::Parser::Types::AUTO_1& Parser::get::AUTO_1(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_1) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_1, "Parser");
	return std::any_cast<Types::AUTO_1&>(token.data());
}
const ::Parser::Types::AUTO_2& Parser::get::AUTO_2(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_2) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_2, "Parser");
	return std::any_cast<const Types::AUTO_2&>(token.data());
}
::Parser::Types::AUTO_2& Parser::get::AUTO_2(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_2) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_2, "Parser");
	return std::any_cast<Types::AUTO_2&>(token.data());
}
const ::Parser::Types::rule_BIN& Parser::get::rule_BIN(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_BIN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_BIN, "Parser");
	return std::any_cast<const Types::rule_BIN&>(token.data());
}
::Parser::Types::rule_BIN& Parser::get::rule_BIN(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_BIN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_BIN, "Parser");
	return std::any_cast<Types::rule_BIN&>(token.data());
}
const ::Parser::Types::rule_NOSPACE& Parser::get::rule_NOSPACE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_NOSPACE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_NOSPACE, "Parser");
	return std::any_cast<const Types::rule_NOSPACE&>(token.data());
}
::Parser::Types::rule_NOSPACE& Parser::get::rule_NOSPACE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_NOSPACE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_NOSPACE, "Parser");
	return std::any_cast<Types::rule_NOSPACE&>(token.data());
}
const ::Parser::Types::rule_ANY& Parser::get::rule_ANY(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_ANY) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_ANY, "Parser");
	return std::any_cast<const Types::rule_ANY&>(token.data());
}
::Parser::Types::rule_ANY& Parser::get::rule_ANY(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_ANY) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_ANY, "Parser");
	return std::any_cast<Types::rule_ANY&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_DIAPASON& Parser::get::rule_CSEQUENCE_DIAPASON(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_DIAPASON) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_DIAPASON, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_DIAPASON&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_DIAPASON& Parser::get::rule_CSEQUENCE_DIAPASON(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_DIAPASON) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_DIAPASON, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_DIAPASON&>(token.data());
}
const ::Parser::Types::cll_LOGICAL_AND& Parser::get::cll_LOGICAL_AND(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_AND) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_AND, "Parser");
	return std::any_cast<const Types::cll_LOGICAL_AND&>(token.data());
}
::Parser::Types::cll_LOGICAL_AND& Parser::get::cll_LOGICAL_AND(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_AND) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_AND, "Parser");
	return std::any_cast<Types::cll_LOGICAL_AND&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE& Parser::get::rule_CSEQUENCE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE&>(token.data());
}
::Parser::Types::rule_CSEQUENCE& Parser::get::rule_CSEQUENCE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE&>(token.data());
}
const ::Parser::Types::rule_OP& Parser::get::rule_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_OP, "Parser");
	return std::any_cast<const Types::rule_OP&>(token.data());
}
::Parser::Types::rule_OP& Parser::get::rule_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_OP, "Parser");
	return std::any_cast<Types::rule_OP&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_SYMBOL& Parser::get::rule_CSEQUENCE_SYMBOL(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_SYMBOL) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_SYMBOL, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_SYMBOL&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_SYMBOL& Parser::get::rule_CSEQUENCE_SYMBOL(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_SYMBOL) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_SYMBOL, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_SYMBOL&>(token.data());
}
const ::Parser::Types::rule_QUANTIFIER& Parser::get::rule_QUANTIFIER(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_QUANTIFIER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_QUANTIFIER, "Parser");
	return std::any_cast<const Types::rule_QUANTIFIER&>(token.data());
}
::Parser::Types::rule_QUANTIFIER& Parser::get::rule_QUANTIFIER(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_QUANTIFIER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_QUANTIFIER, "Parser");
	return std::any_cast<Types::rule_QUANTIFIER&>(token.data());
}
const ::Parser::Types::rule_HEX& Parser::get::rule_HEX(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_HEX) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_HEX, "Parser");
	return std::any_cast<const Types::rule_HEX&>(token.data());
}
::Parser::Types::rule_HEX& Parser::get::rule_HEX(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_HEX) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_HEX, "Parser");
	return std::any_cast<Types::rule_HEX&>(token.data());
}
const ::Parser::Types::AUTO_20& Parser::get::AUTO_20(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_20) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_20, "Parser");
	return std::any_cast<const Types::AUTO_20&>(token.data());
}
::Parser::Types::AUTO_20& Parser::get::AUTO_20(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_20) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_20, "Parser");
	return std::any_cast<Types::AUTO_20&>(token.data());
}
const ::Parser::Types::AUTO_3& Parser::get::AUTO_3(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_3) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_3, "Parser");
	return std::any_cast<const Types::AUTO_3&>(token.data());
}
::Parser::Types::AUTO_3& Parser::get::AUTO_3(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_3) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_3, "Parser");
	return std::any_cast<Types::AUTO_3&>(token.data());
}
const ::Parser::Types::AUTO_8& Parser::get::AUTO_8(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_8) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_8, "Parser");
	return std::any_cast<const Types::AUTO_8&>(token.data());
}
::Parser::Types::AUTO_8& Parser::get::AUTO_8(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_8) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_8, "Parser");
	return std::any_cast<Types::AUTO_8&>(token.data());
}
const ::Parser::Types::AUTO_23& Parser::get::AUTO_23(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_23) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_23, "Parser");
	return std::any_cast<const Types::AUTO_23&>(token.data());
}
::Parser::Types::AUTO_23& Parser::get::AUTO_23(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_23) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_23, "Parser");
	return std::any_cast<Types::AUTO_23&>(token.data());
}
const ::Parser::Types::AUTO_6& Parser::get::AUTO_6(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_6) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_6, "Parser");
	return std::any_cast<const Types::AUTO_6&>(token.data());
}
::Parser::Types::AUTO_6& Parser::get::AUTO_6(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_6) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_6, "Parser");
	return std::any_cast<Types::AUTO_6&>(token.data());
}
const ::Parser::Types::AUTO_7& Parser::get::AUTO_7(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_7) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_7, "Parser");
	return std::any_cast<const Types::AUTO_7&>(token.data());
}
::Parser::Types::AUTO_7& Parser::get::AUTO_7(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_7) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_7, "Parser");
	return std::any_cast<Types::AUTO_7&>(token.data());
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
const ::Parser::Types::AUTO_14& Parser::get::AUTO_14(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_14) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_14, "Parser");
	return std::any_cast<const Types::AUTO_14&>(token.data());
}
::Parser::Types::AUTO_14& Parser::get::AUTO_14(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_14) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_14, "Parser");
	return std::any_cast<Types::AUTO_14&>(token.data());
}
const ::Parser::Types::AUTO_18& Parser::get::AUTO_18(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_18) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_18, "Parser");
	return std::any_cast<const Types::AUTO_18&>(token.data());
}
::Parser::Types::AUTO_18& Parser::get::AUTO_18(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_18) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_18, "Parser");
	return std::any_cast<Types::AUTO_18&>(token.data());
}
const ::Parser::Types::AUTO_9& Parser::get::AUTO_9(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_9) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_9, "Parser");
	return std::any_cast<const Types::AUTO_9&>(token.data());
}
::Parser::Types::AUTO_9& Parser::get::AUTO_9(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_9) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_9, "Parser");
	return std::any_cast<Types::AUTO_9&>(token.data());
}
const ::Parser::Types::AUTO_17& Parser::get::AUTO_17(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_17) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_17, "Parser");
	return std::any_cast<const Types::AUTO_17&>(token.data());
}
::Parser::Types::AUTO_17& Parser::get::AUTO_17(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_17) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_17, "Parser");
	return std::any_cast<Types::AUTO_17&>(token.data());
}
const ::Parser::Types::AUTO_0& Parser::get::AUTO_0(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_0) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_0, "Parser");
	return std::any_cast<const Types::AUTO_0&>(token.data());
}
::Parser::Types::AUTO_0& Parser::get::AUTO_0(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_0) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_0, "Parser");
	return std::any_cast<Types::AUTO_0&>(token.data());
}
const ::Parser::Types::AUTO_21& Parser::get::AUTO_21(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_21) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_21, "Parser");
	return std::any_cast<const Types::AUTO_21&>(token.data());
}
::Parser::Types::AUTO_21& Parser::get::AUTO_21(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_21) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_21, "Parser");
	return std::any_cast<Types::AUTO_21&>(token.data());
}
const ::Parser::Types::cll_COMPARE_OP& Parser::get::cll_COMPARE_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_COMPARE_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_COMPARE_OP, "Parser");
	return std::any_cast<const Types::cll_COMPARE_OP&>(token.data());
}
::Parser::Types::cll_COMPARE_OP& Parser::get::cll_COMPARE_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_COMPARE_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_COMPARE_OP, "Parser");
	return std::any_cast<Types::cll_COMPARE_OP&>(token.data());
}
const ::Parser::Types::AUTO_13& Parser::get::AUTO_13(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_13) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_13, "Parser");
	return std::any_cast<const Types::AUTO_13&>(token.data());
}
::Parser::Types::AUTO_13& Parser::get::AUTO_13(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_13) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_13, "Parser");
	return std::any_cast<Types::AUTO_13&>(token.data());
}
const ::Parser::Types::cll_LOGICAL_OP& Parser::get::cll_LOGICAL_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OP, "Parser");
	return std::any_cast<const Types::cll_LOGICAL_OP&>(token.data());
}
::Parser::Types::cll_LOGICAL_OP& Parser::get::cll_LOGICAL_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OP, "Parser");
	return std::any_cast<Types::cll_LOGICAL_OP&>(token.data());
}
const ::Parser::Types::NUMBER& Parser::get::NUMBER(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NUMBER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NUMBER, "Parser");
	return std::any_cast<const Types::NUMBER&>(token.data());
}
::Parser::Types::NUMBER& Parser::get::NUMBER(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NUMBER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NUMBER, "Parser");
	return std::any_cast<Types::NUMBER&>(token.data());
}
const ::Parser::Types::AUTO_24& Parser::get::AUTO_24(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_24) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_24, "Parser");
	return std::any_cast<const Types::AUTO_24&>(token.data());
}
::Parser::Types::AUTO_24& Parser::get::AUTO_24(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_24) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_24, "Parser");
	return std::any_cast<Types::AUTO_24&>(token.data());
}
const ::Parser::Types::__WHITESPACE& Parser::get::__WHITESPACE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::__WHITESPACE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::__WHITESPACE, "Parser");
	return std::any_cast<const Types::__WHITESPACE&>(token.data());
}
::Parser::Types::__WHITESPACE& Parser::get::__WHITESPACE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::__WHITESPACE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::__WHITESPACE, "Parser");
	return std::any_cast<Types::__WHITESPACE&>(token.data());
}
const ::Parser::Types::AUTO_10& Parser::get::AUTO_10(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_10) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_10, "Parser");
	return std::any_cast<const Types::AUTO_10&>(token.data());
}
::Parser::Types::AUTO_10& Parser::get::AUTO_10(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_10) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_10, "Parser");
	return std::any_cast<Types::AUTO_10&>(token.data());
}
const ::Parser::Types::cll_LOGICAL_NOT& Parser::get::cll_LOGICAL_NOT(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_NOT) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_NOT, "Parser");
	return std::any_cast<const Types::cll_LOGICAL_NOT&>(token.data());
}
::Parser::Types::cll_LOGICAL_NOT& Parser::get::cll_LOGICAL_NOT(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_NOT) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_NOT, "Parser");
	return std::any_cast<Types::cll_LOGICAL_NOT&>(token.data());
}
const ::Parser::Types::AUTO_19& Parser::get::AUTO_19(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_19) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_19, "Parser");
	return std::any_cast<const Types::AUTO_19&>(token.data());
}
::Parser::Types::AUTO_19& Parser::get::AUTO_19(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_19) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_19, "Parser");
	return std::any_cast<Types::AUTO_19&>(token.data());
}
const ::Parser::Types::cll_TYPE& Parser::get::cll_TYPE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TYPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TYPE, "Parser");
	return std::any_cast<const Types::cll_TYPE&>(token.data());
}
::Parser::Types::cll_TYPE& Parser::get::cll_TYPE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TYPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TYPE, "Parser");
	return std::any_cast<Types::cll_TYPE&>(token.data());
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
const ::Parser::Types::AUTO_16& Parser::get::AUTO_16(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_16) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_16, "Parser");
	return std::any_cast<const Types::AUTO_16&>(token.data());
}
::Parser::Types::AUTO_16& Parser::get::AUTO_16(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_16) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_16, "Parser");
	return std::any_cast<Types::AUTO_16&>(token.data());
}
const ::Parser::Types::AUTO_4& Parser::get::AUTO_4(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_4) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_4, "Parser");
	return std::any_cast<const Types::AUTO_4&>(token.data());
}
::Parser::Types::AUTO_4& Parser::get::AUTO_4(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_4) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_4, "Parser");
	return std::any_cast<Types::AUTO_4&>(token.data());
}
const ::Parser::Types::cll_OP& Parser::get::cll_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_OP, "Parser");
	return std::any_cast<const Types::cll_OP&>(token.data());
}
::Parser::Types::cll_OP& Parser::get::cll_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_OP, "Parser");
	return std::any_cast<Types::cll_OP&>(token.data());
}
const ::Parser::Types::AUTO_15& Parser::get::AUTO_15(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_15) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_15, "Parser");
	return std::any_cast<const Types::AUTO_15&>(token.data());
}
::Parser::Types::AUTO_15& Parser::get::AUTO_15(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_15) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_15, "Parser");
	return std::any_cast<Types::AUTO_15&>(token.data());
}
const ::Parser::Types::cll_LOGICAL_OR& Parser::get::cll_LOGICAL_OR(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OR) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OR, "Parser");
	return std::any_cast<const Types::cll_LOGICAL_OR&>(token.data());
}
::Parser::Types::cll_LOGICAL_OR& Parser::get::cll_LOGICAL_OR(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OR) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OR, "Parser");
	return std::any_cast<Types::cll_LOGICAL_OR&>(token.data());
}
const ::Parser::Types::rule_ESCAPED& Parser::get::rule_ESCAPED(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_ESCAPED) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_ESCAPED, "Parser");
	return std::any_cast<const Types::rule_ESCAPED&>(token.data());
}
::Parser::Types::rule_ESCAPED& Parser::get::rule_ESCAPED(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_ESCAPED) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_ESCAPED, "Parser");
	return std::any_cast<Types::rule_ESCAPED&>(token.data());
}
const ::Parser::Types::AUTO_11& Parser::get::AUTO_11(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_11) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_11, "Parser");
	return std::any_cast<const Types::AUTO_11&>(token.data());
}
::Parser::Types::AUTO_11& Parser::get::AUTO_11(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_11) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_11, "Parser");
	return std::any_cast<Types::AUTO_11&>(token.data());
}
const ::Parser::Types::AUTO_22& Parser::get::AUTO_22(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_22) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_22, "Parser");
	return std::any_cast<const Types::AUTO_22&>(token.data());
}
::Parser::Types::AUTO_22& Parser::get::AUTO_22(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_22) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_22, "Parser");
	return std::any_cast<Types::AUTO_22&>(token.data());
}
const ::Parser::Types::STRING& Parser::get::STRING(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::STRING) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::STRING, "Parser");
	return std::any_cast<const Types::STRING&>(token.data());
}
::Parser::Types::STRING& Parser::get::STRING(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::STRING) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::STRING, "Parser");
	return std::any_cast<Types::STRING&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_ESCAPE& Parser::get::rule_CSEQUENCE_ESCAPE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_ESCAPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_ESCAPE, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_ESCAPE&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_ESCAPE& Parser::get::rule_CSEQUENCE_ESCAPE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_ESCAPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_ESCAPE, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_ESCAPE&>(token.data());
}
const ::Parser::Types::BOOLEAN& Parser::get::BOOLEAN(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::BOOLEAN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::BOOLEAN, "Parser");
	return std::any_cast<const Types::BOOLEAN&>(token.data());
}
::Parser::Types::BOOLEAN& Parser::get::BOOLEAN(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::BOOLEAN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::BOOLEAN, "Parser");
	return std::any_cast<Types::BOOLEAN&>(token.data());
}
const ::Parser::Types::rule_data_block_templated_datablock& Parser::get::rule_data_block_templated_datablock(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_templated_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_templated_datablock, "Parser");
	return std::any_cast<const Types::rule_data_block_templated_datablock&>(rule.data());
}
::Parser::Types::rule_data_block_templated_datablock& Parser::get::rule_data_block_templated_datablock(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_templated_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_templated_datablock, "Parser");
	return std::any_cast<Types::rule_data_block_templated_datablock&>(rule.data());
}
const ::Parser::Types::rule_rule& Parser::get::rule_rule(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_rule, "Parser");
	return std::any_cast<const Types::rule_rule&>(rule.data());
}
::Parser::Types::rule_rule& Parser::get::rule_rule(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_rule, "Parser");
	return std::any_cast<Types::rule_rule&>(rule.data());
}
const ::Parser::Types::cll_function_parameters& Parser::get::cll_function_parameters(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_parameters) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_parameters, "Parser");
	return std::any_cast<const Types::cll_function_parameters&>(rule.data());
}
::Parser::Types::cll_function_parameters& Parser::get::cll_function_parameters(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_parameters) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_parameters, "Parser");
	return std::any_cast<Types::cll_function_parameters&>(rule.data());
}
const ::Parser::Types::cll_function_arguments& Parser::get::cll_function_arguments(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_arguments) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_arguments, "Parser");
	return std::any_cast<const Types::cll_function_arguments&>(rule.data());
}
::Parser::Types::cll_function_arguments& Parser::get::cll_function_arguments(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_arguments) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_arguments, "Parser");
	return std::any_cast<Types::cll_function_arguments&>(rule.data());
}
const ::Parser::Types::cll_expr_term& Parser::get::cll_expr_term(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_term) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_term, "Parser");
	return std::any_cast<const Types::cll_expr_term&>(rule.data());
}
::Parser::Types::cll_expr_term& Parser::get::cll_expr_term(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_term) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_term, "Parser");
	return std::any_cast<Types::cll_expr_term&>(rule.data());
}
const ::Parser::Types::cll__variable& Parser::get::cll__variable(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__variable) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__variable, "Parser");
	return std::any_cast<const Types::cll__variable&>(rule.data());
}
::Parser::Types::cll__variable& Parser::get::cll__variable(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__variable) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__variable, "Parser");
	return std::any_cast<Types::cll__variable&>(rule.data());
}
const ::Parser::Types::cll_expr_arithmetic& Parser::get::cll_expr_arithmetic(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_arithmetic) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_arithmetic, "Parser");
	return std::any_cast<const Types::cll_expr_arithmetic&>(rule.data());
}
::Parser::Types::cll_expr_arithmetic& Parser::get::cll_expr_arithmetic(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_arithmetic) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_arithmetic, "Parser");
	return std::any_cast<Types::cll_expr_arithmetic&>(rule.data());
}
const ::Parser::Types::cll__if& Parser::get::cll__if(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__if) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__if, "Parser");
	return std::any_cast<const Types::cll__if&>(rule.data());
}
::Parser::Types::cll__if& Parser::get::cll__if(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__if) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__if, "Parser");
	return std::any_cast<Types::cll__if&>(rule.data());
}
const ::Parser::Types::cll_expr_compare& Parser::get::cll_expr_compare(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_compare) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_compare, "Parser");
	return std::any_cast<const Types::cll_expr_compare&>(rule.data());
}
::Parser::Types::cll_expr_compare& Parser::get::cll_expr_compare(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_compare) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_compare, "Parser");
	return std::any_cast<Types::cll_expr_compare&>(rule.data());
}
const ::Parser::Types::cll& Parser::get::cll(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll, "Parser");
	return std::any_cast<const Types::cll&>(rule.data());
}
::Parser::Types::cll& Parser::get::cll(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll, "Parser");
	return std::any_cast<Types::cll&>(rule.data());
}
const ::Parser::Types::rule& Parser::get::rule(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule, "Parser");
	return std::any_cast<const Types::rule&>(rule.data());
}
::Parser::Types::rule& Parser::get::rule(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule, "Parser");
	return std::any_cast<Types::rule&>(rule.data());
}
const ::Parser::Types::cll_function_call& Parser::get::cll_function_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_call, "Parser");
	return std::any_cast<const Types::cll_function_call&>(rule.data());
}
::Parser::Types::cll_function_call& Parser::get::cll_function_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_call, "Parser");
	return std::any_cast<Types::cll_function_call&>(rule.data());
}
const ::Parser::Types::cll__var& Parser::get::cll__var(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__var) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__var, "Parser");
	return std::any_cast<const Types::cll__var&>(rule.data());
}
::Parser::Types::cll__var& Parser::get::cll__var(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__var) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__var, "Parser");
	return std::any_cast<Types::cll__var&>(rule.data());
}
const ::Parser::Types::cll_function_decl& Parser::get::cll_function_decl(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_decl, "Parser");
	return std::any_cast<const Types::cll_function_decl&>(rule.data());
}
::Parser::Types::cll_function_decl& Parser::get::cll_function_decl(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_decl, "Parser");
	return std::any_cast<Types::cll_function_decl&>(rule.data());
}
const ::Parser::Types::cll_expr_value& Parser::get::cll_expr_value(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_value, "Parser");
	return std::any_cast<const Types::cll_expr_value&>(rule.data());
}
::Parser::Types::cll_expr_value& Parser::get::cll_expr_value(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_value, "Parser");
	return std::any_cast<Types::cll_expr_value&>(rule.data());
}
const ::Parser::Types::cll_expr_logical& Parser::get::cll_expr_logical(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_logical) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_logical, "Parser");
	return std::any_cast<const Types::cll_expr_logical&>(rule.data());
}
::Parser::Types::cll_expr_logical& Parser::get::cll_expr_logical(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_logical) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_logical, "Parser");
	return std::any_cast<Types::cll_expr_logical&>(rule.data());
}
const ::Parser::Types::cll_stmt& Parser::get::cll_stmt(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_stmt) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_stmt, "Parser");
	return std::any_cast<const Types::cll_stmt&>(rule.data());
}
::Parser::Types::cll_stmt& Parser::get::cll_stmt(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_stmt) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_stmt, "Parser");
	return std::any_cast<Types::cll_stmt&>(rule.data());
}
const ::Parser::Types::cll_expr_group& Parser::get::cll_expr_group(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_group, "Parser");
	return std::any_cast<const Types::cll_expr_group&>(rule.data());
}
::Parser::Types::cll_expr_group& Parser::get::cll_expr_group(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_group, "Parser");
	return std::any_cast<Types::cll_expr_group&>(rule.data());
}
const ::Parser::Types::cll_method_call& Parser::get::cll_method_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_method_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_method_call, "Parser");
	return std::any_cast<const Types::cll_method_call&>(rule.data());
}
::Parser::Types::cll_method_call& Parser::get::cll_method_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_method_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_method_call, "Parser");
	return std::any_cast<Types::cll_method_call&>(rule.data());
}
const ::Parser::Types::cll_loop_while& Parser::get::cll_loop_while(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_while) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_while, "Parser");
	return std::any_cast<const Types::cll_loop_while&>(rule.data());
}
::Parser::Types::cll_loop_while& Parser::get::cll_loop_while(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_while) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_while, "Parser");
	return std::any_cast<Types::cll_loop_while&>(rule.data());
}
const ::Parser::Types::cll_expr& Parser::get::cll_expr(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr, "Parser");
	return std::any_cast<const Types::cll_expr&>(rule.data());
}
::Parser::Types::cll_expr& Parser::get::cll_expr(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr, "Parser");
	return std::any_cast<Types::cll_expr&>(rule.data());
}
const ::Parser::Types::cll_loop_for& Parser::get::cll_loop_for(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_for) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_for, "Parser");
	return std::any_cast<const Types::cll_loop_for&>(rule.data());
}
::Parser::Types::cll_loop_for& Parser::get::cll_loop_for(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_for) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_for, "Parser");
	return std::any_cast<Types::cll_loop_for&>(rule.data());
}
const ::Parser::Types::cll_function_body_call& Parser::get::cll_function_body_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_call, "Parser");
	return std::any_cast<const Types::cll_function_body_call&>(rule.data());
}
::Parser::Types::cll_function_body_call& Parser::get::cll_function_body_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_call, "Parser");
	return std::any_cast<Types::cll_function_body_call&>(rule.data());
}
const ::Parser::Types::rule_value& Parser::get::rule_value(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_value, "Parser");
	return std::any_cast<const Types::rule_value&>(rule.data());
}
::Parser::Types::rule_value& Parser::get::rule_value(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_value, "Parser");
	return std::any_cast<Types::rule_value&>(rule.data());
}
const ::Parser::Types::rule_data_block& Parser::get::rule_data_block(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block, "Parser");
	return std::any_cast<const Types::rule_data_block&>(rule.data());
}
::Parser::Types::rule_data_block& Parser::get::rule_data_block(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block, "Parser");
	return std::any_cast<Types::rule_data_block&>(rule.data());
}
const ::Parser::Types::rule_nested_rule& Parser::get::rule_nested_rule(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_nested_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_nested_rule, "Parser");
	return std::any_cast<const Types::rule_nested_rule&>(rule.data());
}
::Parser::Types::rule_nested_rule& Parser::get::rule_nested_rule(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_nested_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_nested_rule, "Parser");
	return std::any_cast<Types::rule_nested_rule&>(rule.data());
}
const ::Parser::Types::cll_function_body_decl& Parser::get::cll_function_body_decl(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_decl, "Parser");
	return std::any_cast<const Types::cll_function_body_decl&>(rule.data());
}
::Parser::Types::cll_function_body_decl& Parser::get::cll_function_body_decl(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_decl, "Parser");
	return std::any_cast<Types::cll_function_body_decl&>(rule.data());
}
const ::Parser::Types::rule_group& Parser::get::rule_group(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_group, "Parser");
	return std::any_cast<const Types::rule_group&>(rule.data());
}
::Parser::Types::rule_group& Parser::get::rule_group(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_group, "Parser");
	return std::any_cast<Types::rule_group&>(rule.data());
}
const ::Parser::Types::rule_name& Parser::get::rule_name(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_name) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_name, "Parser");
	return std::any_cast<const Types::rule_name&>(rule.data());
}
::Parser::Types::rule_name& Parser::get::rule_name(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_name) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_name, "Parser");
	return std::any_cast<Types::rule_name&>(rule.data());
}
const ::Parser::Types::rule_keyvalue& Parser::get::rule_keyvalue(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_keyvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_keyvalue, "Parser");
	return std::any_cast<const Types::rule_keyvalue&>(rule.data());
}
::Parser::Types::rule_keyvalue& Parser::get::rule_keyvalue(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_keyvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_keyvalue, "Parser");
	return std::any_cast<Types::rule_keyvalue&>(rule.data());
}
const ::Parser::Types::rule_data_block_regular_datablock& Parser::get::rule_data_block_regular_datablock(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock, "Parser");
	return std::any_cast<const Types::rule_data_block_regular_datablock&>(rule.data());
}
::Parser::Types::rule_data_block_regular_datablock& Parser::get::rule_data_block_regular_datablock(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock, "Parser");
	return std::any_cast<Types::rule_data_block_regular_datablock&>(rule.data());
}
const ::Parser::Types::rule_data_block_regular_datablock_key& Parser::get::rule_data_block_regular_datablock_key(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock_key) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock_key, "Parser");
	return std::any_cast<const Types::rule_data_block_regular_datablock_key&>(rule.data());
}
::Parser::Types::rule_data_block_regular_datablock_key& Parser::get::rule_data_block_regular_datablock_key(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock_key) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock_key, "Parser");
	return std::any_cast<Types::rule_data_block_regular_datablock_key&>(rule.data());
}

Parser::Token Parser::Lexer::makeToken(const char*& pos) {
	::Parser::UNDEF _0;
	::Parser::bool_t success_1 = false;
	return {};
	success_1 = true;
	return ;
}
Parser::Token_res Parser::Lexer::cll_loop_while(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_24))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = expr(pos);
	if (!(_2.status))
	{
		reportError(pos, "expr");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	_4 = stmt(pos);
	if (!(_4.status))
	{
		reportError(pos, "stmt");
		return {};
	}
	success_5 = true;
	pos += _4.node.length();
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_loop_while)};
}
Parser::Token_res Parser::Lexer::cll_method_call(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::ID))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_23))
	{
		reportError(pos, "AUTO_23");
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	_4 = function_call(pos);
	if (!(_4.status))
	{
		reportError(pos, "function_call");
		return {};
	}
	success_5 = true;
	pos += _4.node.length();
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_method_call)};
}
Parser::Token_res Parser::Lexer::cll_expr_group(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_7))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = expr(pos);
	if (!(_2.status))
	{
		reportError(pos, "expr");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_8))
	{
		reportError(pos, "AUTO_8");
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 1;
	::Parser::Types::cll_expr_group_data data = _2.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_expr_group, data)};
}
Parser::Token_res Parser::Lexer::cll_expr_logical(const char* pos) {
	auto in = pos	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	_0 = compare(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	pos += _0.node.length();
	skip_spaces(pos);
	::Parser::bool_t success_3 = false;
	auto begin_4 = pos;
	::Parser::bool_t success_7 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _4;
	if (!(begin_4->name() == ::Parser::Tokens::LOGICAL_OP))
	{
		reportError(pos, "LOGICAL_OP");
		return {};
	}
	_4 = *begin_4;
	success_5 = true;
	begin_4 += 1;
	skip_spaces(begin_4);
	::Parser::Rule_res _6;
	_6 = compare(begin_4);
	if (!(_6.status))
	{
		reportError(pos, "compare");
		return {};
	}
	success_7 = true;
	begin_4 += _6.node.length();
	if (success_5 && success_7)
	{
		success_3 = true;
		pos = begin_4;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_expr_logical)};
}
Parser::Token_res Parser::Lexer::cll__var(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::TYPE))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == ::Parser::Tokens::ID))
	{
		reportError(pos, "ID");
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::bool_t success_5 = false;
	auto begin_6 = pos;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	::Parser::Token _6;
	if (!(begin_6->name() == ::Parser::Tokens::ASSIGNMENT_OP))
	{
		reportError(pos, "ASSIGNMENT_OP");
		return {};
	}
	_6 = *begin_6;
	success_7 = true;
	begin_6 += 1;
	skip_spaces(begin_6);
	::Parser::Rule_res _8;
	_8 = expr(begin_6);
	if (!(_8.status))
	{
		reportError(pos, "expr");
		return {};
	}
	success_9 = true;
	begin_6 += _8.node.length();
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_6;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll__var)};
}
Parser::Token_res Parser::Lexer::cll_function_call(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::ID))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = function_body_call(pos);
	if (!(_2.status))
	{
		reportError(pos, "function_body_call");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_function_call)};
}
Parser::Token_res Parser::Lexer::cll(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_20))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = cll__var(pos);
	if (!(_2.status))
	{
		reportError(pos, "_var");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	_4 = cll__if(pos);
	if (!(_4.status))
	{
		reportError(pos, "_if");
		return {};
	}
	success_5 = true;
	pos += _4.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	_6 = cll_expr(pos);
	if (!(_6.status))
	{
		reportError(pos, "expr");
		return {};
	}
	success_7 = true;
	pos += _6.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	_8 = cll_loop_while(pos);
	if (!(_8.status))
	{
		reportError(pos, "loop_while");
		return {};
	}
	success_9 = true;
	pos += _8.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _10;
	::Parser::bool_t success_11 = false;
	_10 = cll_loop_for(pos);
	if (!(_10.status))
	{
		reportError(pos, "loop_for");
		return {};
	}
	success_11 = true;
	pos += _10.node.length();
	skip_spaces(pos);
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	if (!(pos->name() == ::Parser::Tokens::END))
	{
		reportError(pos, "END");
		return {};
	}
	_12 = *pos;
	success_13 = true;
	pos += 1;
	::Parser::Types::cll_data data = _2.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll, data)};
}
Parser::Token_res Parser::Lexer::cll_expr_compare(const char* pos) {
	auto in = pos	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	_0 = arithmetic(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	pos += _0.node.length();
	skip_spaces(pos);
	::Parser::bool_t success_3 = false;
	auto begin_4 = pos;
	::Parser::bool_t success_7 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _4;
	if (!(begin_4->name() == ::Parser::Tokens::COMPARE_OP))
	{
		reportError(pos, "COMPARE_OP");
		return {};
	}
	_4 = *begin_4;
	success_5 = true;
	begin_4 += 1;
	skip_spaces(begin_4);
	::Parser::Rule_res _6;
	_6 = arithmetic(begin_4);
	if (!(_6.status))
	{
		reportError(pos, "arithmetic");
		return {};
	}
	success_7 = true;
	begin_4 += _6.node.length();
	if (success_5 && success_7)
	{
		success_3 = true;
		pos = begin_4;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_expr_compare)};
}
Parser::Token_res Parser::Lexer::cll_expr_arithmetic(const char* pos) {
	auto in = pos	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	_0 = term(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	pos += _0.node.length();
	skip_spaces(pos);
	::Parser::bool_t success_3 = false;
	auto begin_4 = pos;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _4;
	if (!(begin_4->name() == ::Parser::Tokens::PLUS))
	{
		reportError(pos, "PLUS");
		return {};
	}
	_4 = *begin_4;
	success_5 = true;
	begin_4 += 1;
	skip_spaces(begin_4);
	::Parser::Token _6;
	if (!(begin_4->name() == ::Parser::Tokens::MINUS))
	{
		reportError(pos, "MINUS");
		return {};
	}
	_6 = *begin_4;
	success_7 = true;
	begin_4 += 1;
	skip_spaces(begin_4);
	::Parser::Rule_res _8;
	_8 = term(begin_4);
	if (!(_8.status))
	{
		reportError(pos, "term");
		return {};
	}
	success_9 = true;
	begin_4 += _8.node.length();
	if (success_5 && success_7 && success_9)
	{
		success_3 = true;
		pos = begin_4;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_expr_arithmetic)};
}
Parser::Token_res Parser::Lexer::cll__if(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_19))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = expr(pos);
	if (!(_2.status))
	{
		reportError(pos, "expr");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	_4 = stmt(pos);
	if (!(_4.status))
	{
		reportError(pos, "stmt");
		return {};
	}
	success_5 = true;
	pos += _4.node.length();
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll__if)};
}
Parser::Token_res Parser::Lexer::cll_function_parameters(const char* pos) {
	auto in = pos	::Parser::bool_t success_1 = false;
	success_1 = false;
	auto begin_2 = pos;
	::Parser::bool_t success_5 = false;
	::Parser::bool_t success_3 = false;
	::Parser::Token _2;
	if (!(begin_2->name() == ::Parser::Tokens::ID))
	{
		return {};
	}
	_2 = *begin_2;
	success_3 = true;
	begin_2 += 1;
	skip_spaces(begin_2);
	auto begin_6 = begin_2;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	::Parser::Token _6;
	if (!(begin_6->name() == ::Parser::Tokens::AUTO_2))
	{
		reportError(pos, "AUTO_2");
		return {};
	}
	_6 = *begin_6;
	success_7 = true;
	begin_6 += 1;
	skip_spaces(begin_6);
	::Parser::Token _8;
	if (!(begin_6->name() == ::Parser::Tokens::ID))
	{
		reportError(pos, "ID");
		return {};
	}
	_8 = *begin_6;
	success_9 = true;
	begin_6 += 1;
	if (success_7 && success_9)
	{
		success_5 = true;
		begin_2 = begin_6;
	}
	if (success_3 && success_5)
	{
		success_1 = true;
		pos = begin_2;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_function_parameters)};
}
Parser::Token_res Parser::Lexer::cll_function_arguments(const char* pos) {
	auto in = pos	::Parser::bool_t success_1 = false;
	success_1 = false;
	auto begin_2 = pos;
	::Parser::bool_t success_5 = false;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _2;
	_2 = expr(begin_2);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	begin_2 += _2.node.length();
	skip_spaces(begin_2);
	auto begin_6 = begin_2;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	::Parser::Token _6;
	if (!(begin_6->name() == ::Parser::Tokens::AUTO_2))
	{
		reportError(pos, "AUTO_2");
		return {};
	}
	_6 = *begin_6;
	success_7 = true;
	begin_6 += 1;
	skip_spaces(begin_6);
	::Parser::Rule_res _8;
	_8 = expr(begin_6);
	if (!(_8.status))
	{
		reportError(pos, "expr");
		return {};
	}
	success_9 = true;
	begin_6 += _8.node.length();
	if (success_7 && success_9)
	{
		success_5 = true;
		begin_2 = begin_6;
	}
	if (success_3 && success_5)
	{
		success_1 = true;
		pos = begin_2;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_function_arguments)};
}
Parser::Token_res Parser::Lexer::cll_expr_term(const char* pos) {
	auto in = pos	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	_0 = value(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	pos += _0.node.length();
	skip_spaces(pos);
	::Parser::bool_t success_3 = false;
	auto begin_4 = pos;
	::Parser::bool_t success_11 = false;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	::Parser::bool_t success_5 = false;
	::Parser::Token _4;
	if (!(begin_4->name() == ::Parser::Tokens::MULTIPLE))
	{
		reportError(pos, "MULTIPLE");
		return {};
	}
	_4 = *begin_4;
	success_5 = true;
	begin_4 += 1;
	skip_spaces(begin_4);
	::Parser::Token _6;
	if (!(begin_4->name() == ::Parser::Tokens::DIVIDE))
	{
		reportError(pos, "DIVIDE");
		return {};
	}
	_6 = *begin_4;
	success_7 = true;
	begin_4 += 1;
	skip_spaces(begin_4);
	::Parser::Token _8;
	if (!(begin_4->name() == ::Parser::Tokens::MODULO))
	{
		reportError(pos, "MODULO");
		return {};
	}
	_8 = *begin_4;
	success_9 = true;
	begin_4 += 1;
	skip_spaces(begin_4);
	::Parser::Rule_res _10;
	_10 = value(begin_4);
	if (!(_10.status))
	{
		reportError(pos, "value");
		return {};
	}
	success_11 = true;
	begin_4 += _10.node.length();
	if (success_5 && success_7 && success_9 && success_11)
	{
		success_3 = true;
		pos = begin_4;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_expr_term)};
}
Parser::Token_res Parser::Lexer::cll_function_decl(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_22))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == ::Parser::Tokens::ID))
	{
		reportError(pos, "ID");
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	_4 = function_body_decl(pos);
	if (!(_4.status))
	{
		reportError(pos, "function_body_decl");
		return {};
	}
	success_5 = true;
	pos += _4.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	_6 = stmt(pos);
	if (!(_6.status))
	{
		reportError(pos, "stmt");
		return {};
	}
	success_7 = true;
	pos += _6.node.length();
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_function_decl)};
}
Parser::Token_res Parser::Lexer::cll__variable(const char* pos) {
	auto in = pos	::Parser::bool_t success_1 = false;
	success_1 = false;
	auto begin_2 = pos;
	::Parser::bool_t success_5 = false;
	::Parser::bool_t success_3 = false;
	::Parser::Token _2;
	if (!(begin_2->name() == ::Parser::Tokens::AUTO_15))
	{
		return {};
	}
	_2 = *begin_2;
	success_3 = true;
	begin_2 += 1;
	skip_spaces(begin_2);
	::Parser::Token _4;
	if (!(begin_2->name() == ::Parser::Tokens::AUTO_16))
	{
		reportError(pos, "AUTO_16");
		return {};
	}
	_4 = *begin_2;
	success_5 = true;
	begin_2 += 1;
	if (success_3 && success_5)
	{
		success_1 = true;
		pos = begin_2;
	}
	skip_spaces(pos);
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	if (!(pos->name() == ::Parser::Tokens::ID))
	{
		reportError(pos, "ID");
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::bool_t success_9 = false;
	auto begin_10 = pos;
	::Parser::bool_t success_15 = false;
	::Parser::bool_t success_13 = false;
	::Parser::bool_t success_11 = false;
	::Parser::Token _10;
	if (!(begin_10->name() == ::Parser::Tokens::AUTO_17))
	{
		reportError(pos, "AUTO_17");
		return {};
	}
	_10 = *begin_10;
	success_11 = true;
	begin_10 += 1;
	skip_spaces(begin_10);
	::Parser::Rule_res _12;
	_12 = expr(begin_10);
	if (!(_12.status))
	{
		reportError(pos, "expr");
		return {};
	}
	success_13 = true;
	begin_10 += _12.node.length();
	skip_spaces(begin_10);
	::Parser::Token _14;
	if (!(begin_10->name() == ::Parser::Tokens::AUTO_18))
	{
		reportError(pos, "AUTO_18");
		return {};
	}
	_14 = *begin_10;
	success_15 = true;
	begin_10 += 1;
	if (success_11 && success_13 && success_15)
	{
		success_9 = true;
		pos = begin_10;
	}
	skip_spaces(pos);
	::Parser::bool_t success_17 = false;
	auto begin_18 = pos;
	::Parser::bool_t success_21 = false;
	::Parser::bool_t success_19 = false;
	::Parser::Token _18;
	if (!(begin_18->name() == ::Parser::Tokens::AUTO_15))
	{
		reportError(pos, "AUTO_15");
		return {};
	}
	_18 = *begin_18;
	success_19 = true;
	begin_18 += 1;
	skip_spaces(begin_18);
	::Parser::Token _20;
	if (!(begin_18->name() == ::Parser::Tokens::AUTO_16))
	{
		reportError(pos, "AUTO_16");
		return {};
	}
	_20 = *begin_18;
	success_21 = true;
	begin_18 += 1;
	if (success_19 && success_21)
	{
		success_17 = true;
		pos = begin_18;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll__variable)};
}
Parser::Token_res Parser::Lexer::cll_expr(const char* pos) {
	auto in = pos	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	_0 = cll_expr_logical(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	pos += _0.node.length();
	::Parser::Types::cll_expr_data data = _0.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_expr, data)};
}
Parser::Token_res Parser::Lexer::cll_function_body_call(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_7))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = function_arguments(pos);
	if (!(_2.status))
	{
		reportError(pos, "function_arguments");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_8))
	{
		reportError(pos, "AUTO_8");
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 1;
	::Parser::Types::cll_function_body_call_data data = _2.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_function_body_call, data)};
}
Parser::Token_res Parser::Lexer::cll_stmt(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_5))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = rule_rule(pos);
	if (!(_2.status))
	{
		reportError(pos, "rule");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_3))
	{
		reportError(pos, "AUTO_3");
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 1;
	::Parser::Types::cll_stmt_data data = _2.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_stmt, data)};
}
Parser::Token_res Parser::Lexer::rule(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::ID))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_21))
	{
		reportError(pos, "AUTO_21");
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	_4 = rule_rule(pos);
	if (!(_4.status))
	{
		reportError(pos, "rule");
		return {};
	}
	success_5 = true;
	pos += _4.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	_6 = rule_data_block(pos);
	if (!(_6.status))
	{
		reportError(pos, "data_block");
		return {};
	}
	success_7 = true;
	pos += _6.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	_8 = rule_nested_rule(pos);
	if (!(_8.status))
	{
		reportError(pos, "nested_rule");
		return {};
	}
	success_9 = true;
	pos += _8.node.length();
	skip_spaces(pos);
	::Parser::Token _10;
	::Parser::bool_t success_11 = false;
	if (!(pos->name() == ::Parser::Tokens::STRICT_END))
	{
		reportError(pos, "STRICT_END");
		return {};
	}
	_10 = *pos;
	success_11 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule)};
}
Parser::Token_res Parser::Lexer::rule_value(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_11))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == ::Parser::Tokens::ID))
	{
		reportError(pos, "ID");
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 1;
	::Parser::Types::rule_value_data data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_value, data)};
}
Parser::Token_res Parser::Lexer::rule_data_block(const char* pos) {
	auto in = pos	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	_0 = rule_data_block_templated_datablock(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	pos += _0.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = rule_data_block_regular_datablock(pos);
	if (!(_2.status))
	{
		reportError(pos, "regular_datablock");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	::Parser::Types::rule_data_block_data data = _0.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_data_block, data)};
}
Parser::Token_res Parser::Lexer::cll_function_body_decl(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_7))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = function_parameters(pos);
	if (!(_2.status))
	{
		reportError(pos, "function_parameters");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_8))
	{
		reportError(pos, "AUTO_8");
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 1;
	::Parser::Types::cll_function_body_decl_data data = _2.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_function_body_decl, data)};
}
Parser::Token_res Parser::Lexer::rule_name(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_9))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == ::Parser::Tokens::ID))
	{
		reportError(pos, "ID");
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::bool_t success_5 = false;
	auto begin_6 = pos;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	::Parser::Token _6;
	if (!(begin_6->name() == ::Parser::Tokens::AUTO_10))
	{
		reportError(pos, "AUTO_10");
		return {};
	}
	_6 = *begin_6;
	success_7 = true;
	begin_6 += 1;
	skip_spaces(begin_6);
	::Parser::Token _8;
	if (!(begin_6->name() == ::Parser::Tokens::ID))
	{
		reportError(pos, "ID");
		return {};
	}
	_8 = *begin_6;
	success_9 = true;
	begin_6 += 1;
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_6;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_name)};
}
Parser::Token_res Parser::Lexer::rule_group(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_7))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = rule(pos);
	if (!(_2.status))
	{
		reportError(pos, "rule");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_8))
	{
		reportError(pos, "AUTO_8");
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 1;
	::Parser::Types::rule_group_data data = _2.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_group, data)};
}
Parser::Token_res Parser::Lexer::rule_keyvalue(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_0))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::bool_t success_3 = false;
	auto begin_4 = pos;
	::Parser::bool_t success_5 = false;
	::Parser::Token _4;
	if (!(begin_4->name() == ::Parser::Tokens::ID))
	{
		reportError(pos, "ID");
		return {};
	}
	_4 = *begin_4;
	success_5 = true;
	begin_4 += 1;
	if (success_5)
	{
		success_3 = true;
		pos = begin_4;
	}
	::Parser::Types::rule_keyvalue_data data = _4;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_keyvalue, data)};
}
Parser::Token_res Parser::Lexer::cll_loop_for(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_12))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_13))
	{
		reportError(pos, "AUTO_13");
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::bool_t success_5 = false;
	auto begin_6 = pos;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	::Parser::Rule_res _6;
	_6 = expr(begin_6);
	if (!(_6.status))
	{
		reportError(pos, "expr");
		return {};
	}
	success_7 = true;
	begin_6 += _6.node.length();
	skip_spaces(begin_6);
	::Parser::Rule_res _8;
	_8 = _var(begin_6);
	if (!(_8.status))
	{
		reportError(pos, "_var");
		return {};
	}
	success_9 = true;
	begin_6 += _8.node.length();
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_6;
	}
	skip_spaces(pos);
	::Parser::Token _10;
	::Parser::bool_t success_11 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_14))
	{
		reportError(pos, "AUTO_14");
		return {};
	}
	_10 = *pos;
	success_11 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _12;
	::Parser::bool_t success_13 = false;
	_12 = expr(pos);
	if (!(_12.status))
	{
		reportError(pos, "expr");
		return {};
	}
	success_13 = true;
	pos += _12.node.length();
	skip_spaces(pos);
	::Parser::Token _14;
	::Parser::bool_t success_15 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_14))
	{
		reportError(pos, "AUTO_14");
		return {};
	}
	_14 = *pos;
	success_15 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _16;
	::Parser::bool_t success_17 = false;
	_16 = expr(pos);
	if (!(_16.status))
	{
		reportError(pos, "expr");
		return {};
	}
	success_17 = true;
	pos += _16.node.length();
	skip_spaces(pos);
	::Parser::Token _18;
	::Parser::bool_t success_19 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_8))
	{
		reportError(pos, "AUTO_8");
		return {};
	}
	_18 = *pos;
	success_19 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _20;
	::Parser::bool_t success_21 = false;
	_20 = stmt(pos);
	if (!(_20.status))
	{
		reportError(pos, "stmt");
		return {};
	}
	success_21 = true;
	pos += _20.node.length();
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_loop_for)};
}
Parser::Token_res Parser::Lexer::rule_nested_rule(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_6))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = Rule(pos);
	if (!(_2.status))
	{
		reportError(pos, "Rule");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	::Parser::Types::rule_nested_rule_data data = ;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_nested_rule, data)};
}
Parser::Token_res Parser::Lexer::rule_data_block_regular_datablock(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_5))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = any_data(pos);
	if (!(_2.status))
	{
		reportError(pos, "any_data");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	_4 = rule_data_block_regular_datablock_key(pos);
	if (!(_4.status))
	{
		reportError(pos, "key");
		return {};
	}
	success_5 = true;
	pos += _4.node.length();
	skip_spaces(pos);
	::Parser::Token _6;
	::Parser::bool_t success_7 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_3))
	{
		reportError(pos, "AUTO_3");
		return {};
	}
	_6 = *pos;
	success_7 = true;
	pos += 1;
	::Parser::Types::rule_data_block_regular_datablock_data data = _2.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_data_block_regular_datablock, data)};
}
Parser::Token_res Parser::Lexer::rule_data_block_regular_datablock_key(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::ID))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_4))
	{
		reportError(pos, "AUTO_4");
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	_4 = cll_expr(pos);
	if (!(_4.status))
	{
		reportError(pos, "expr");
		return {};
	}
	success_5 = true;
	pos += _4.node.length();
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_data_block_regular_datablock_key)};
}
Parser::Token_res Parser::Lexer::rule_data_block_templated_datablock(const char* pos) {
	auto in = pos	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_0))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_1))
	{
		reportError(pos, "AUTO_1");
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::bool_t success_5 = false;
	auto begin_6 = pos;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	::Parser::Token _6;
	if (!(begin_6->name() == ::Parser::Tokens::ID))
	{
		reportError(pos, "ID");
		return {};
	}
	_6 = *begin_6;
	success_7 = true;
	begin_6 += 1;
	skip_spaces(begin_6);
	auto begin_10 = begin_6;
	::Parser::bool_t success_13 = false;
	::Parser::bool_t success_11 = false;
	::Parser::Token _10;
	if (!(begin_10->name() == ::Parser::Tokens::AUTO_2))
	{
		reportError(pos, "AUTO_2");
		return {};
	}
	_10 = *begin_10;
	success_11 = true;
	begin_10 += 1;
	skip_spaces(begin_10);
	::Parser::Token _12;
	if (!(begin_10->name() == ::Parser::Tokens::ID))
	{
		reportError(pos, "ID");
		return {};
	}
	_12 = *begin_10;
	success_13 = true;
	begin_10 += 1;
	if (success_11 && success_13)
	{
		success_9 = true;
		begin_6 = begin_10;
	}
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_6;
	}
	skip_spaces(pos);
	::Parser::Token _14;
	::Parser::bool_t success_15 = false;
	if (!(pos->name() == ::Parser::Tokens::AUTO_3))
	{
		reportError(pos, "AUTO_3");
		return {};
	}
	_14 = *pos;
	success_15 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_data_block_templated_datablock)};
}
Parser::Token_res Parser::Lexer::rule_rule(const char* pos) {
	auto in = pos	::Parser::bool_t success_1 = false;
	success_1 = false;
	auto begin_2 = pos;
	::Parser::bool_t success_5 = false;
	::Parser::bool_t success_3 = false;
	::Parser::Rule_res _2;
	_2 = keyvalue(begin_2);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	begin_2 += _2.node.length();
	skip_spaces(begin_2);
	::Parser::Rule_res _4;
	_4 = value(begin_2);
	if (!(_4.status))
	{
		reportError(pos, "value");
		return {};
	}
	success_5 = true;
	begin_2 += _4.node.length();
	if (success_3 && success_5)
	{
		success_1 = true;
		pos = begin_2;
	}
	skip_spaces(pos);
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	_6 = name(pos);
	if (!(_6.status))
	{
		reportError(pos, "name");
		return {};
	}
	success_7 = true;
	pos += _6.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	_8 = group(pos);
	if (!(_8.status))
	{
		reportError(pos, "group");
		return {};
	}
	success_9 = true;
	pos += _8.node.length();
	skip_spaces(pos);
	::Parser::Token _10;
	::Parser::bool_t success_11 = false;
	if (!(pos->name() == ::Parser::Tokens::CSEQUENCE))
	{
		reportError(pos, "CSEQUENCE");
		return {};
	}
	_10 = *pos;
	success_11 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _12;
	::Parser::bool_t success_13 = false;
	if (!(pos->name() == ::Parser::Tokens::STRING))
	{
		reportError(pos, "STRING");
		return {};
	}
	_12 = *pos;
	success_13 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _14;
	::Parser::bool_t success_15 = false;
	if (!(pos->name() == ::Parser::Tokens::HEX))
	{
		reportError(pos, "HEX");
		return {};
	}
	_14 = *pos;
	success_15 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _16;
	::Parser::bool_t success_17 = false;
	if (!(pos->name() == ::Parser::Tokens::BIN))
	{
		reportError(pos, "BIN");
		return {};
	}
	_16 = *pos;
	success_17 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _18;
	::Parser::bool_t success_19 = false;
	if (!(pos->name() == ::Parser::Tokens::NOSPACE))
	{
		reportError(pos, "NOSPACE");
		return {};
	}
	_18 = *pos;
	success_19 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _20;
	::Parser::bool_t success_21 = false;
	if (!(pos->name() == ::Parser::Tokens::ESCAPED))
	{
		reportError(pos, "ESCAPED");
		return {};
	}
	_20 = *pos;
	success_21 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _22;
	::Parser::bool_t success_23 = false;
	if (!(pos->name() == ::Parser::Tokens::ANY))
	{
		reportError(pos, "ANY");
		return {};
	}
	_22 = *pos;
	success_23 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _24;
	::Parser::bool_t success_25 = false;
	if (!(pos->name() == ::Parser::Tokens::OP))
	{
		reportError(pos, "OP");
		return {};
	}
	_24 = *pos;
	success_25 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _26;
	::Parser::bool_t success_27 = false;
	if (!(pos->name() == ::Parser::Tokens::LINEAR_COMMENT))
	{
		reportError(pos, "LINEAR_COMMENT");
		return {};
	}
	_26 = *pos;
	success_27 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Rule_res _28;
	::Parser::bool_t success_29 = false;
	_28 = cll(pos);
	if (!(_28.status))
	{
		reportError(pos, "cll");
		return {};
	}
	success_29 = true;
	pos += _28.node.length();
	skip_spaces(pos);
	::Parser::Token _30;
	::Parser::bool_t success_31 = false;
	if (!(pos->name() == ::Parser::Tokens::QUANTIFIER))
	{
		reportError(pos, "QUANTIFIER");
		return {};
	}
	_30 = *pos;
	success_31 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_rule)};
}
Parser::Token_res Parser::Lexer::cll_expr_value(const char* pos) {
	auto in = pos	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = false;
	_0 = group(pos);
	if (!(_0.status))
	{
		return {};
	}
	success_1 = true;
	pos += _0.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = false;
	_2 = _variable(pos);
	if (!(_2.status))
	{
		reportError(pos, "_variable");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _4;
	::Parser::bool_t success_5 = false;
	_4 = cll_function_call(pos);
	if (!(_4.status))
	{
		reportError(pos, "cll_function_call");
		return {};
	}
	success_5 = true;
	pos += _4.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _6;
	::Parser::bool_t success_7 = false;
	_6 = method_call(pos);
	if (!(_6.status))
	{
		reportError(pos, "method_call");
		return {};
	}
	success_7 = true;
	pos += _6.node.length();
	skip_spaces(pos);
	::Parser::Rule_res _8;
	::Parser::bool_t success_9 = false;
	_8 = any_data(pos);
	if (!(_8.status))
	{
		reportError(pos, "any_data");
		return {};
	}
	success_9 = true;
	pos += _8.node.length();
	::Parser::Types::cll_expr_value_data data = _0.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_expr_value, data)};
}
