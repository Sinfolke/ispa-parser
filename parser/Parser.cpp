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
    }	else if (data.type() == typeid(Types::_use_unit)) {
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
	else if (data.type() == typeid(Types::rule)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "nested_rules"<< ": ";
		printRule(os, dt.nested_rules, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "data_block"<< ": ";
		printRule(os, dt.data_block, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "rule"<< ": ";
		printRule(os, dt.rule, indentLevel, false);
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
	else if (data.type() == typeid(Types::rule_data_block_regular_datablock_key)) {
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
	else if (data.type() == typeid(Types::cll__variable)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll__variable>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "pos"<< ": ";
		printRule(os, dt.pos, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "brace_expression"<< ": ";
		printRule(os, dt.brace_expression, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "pre"<< ": ";
		printRule(os, dt.pre, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_loop_for)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_loop_for>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "stmt"<< ": ";
		printRule(os, dt.stmt, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "end"<< ": ";
		printRule(os, dt.end, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "cond"<< ": ";
		printRule(os, dt.cond, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "decl"<< ": ";
		printRule(os, dt.decl, indentLevel, false);
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
	else if (data.type() == typeid(Types::rule_member)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule_member>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "quantifier"<< ": ";
		printRule(os, dt.quantifier, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "val"<< ": ";
		printRule(os, dt.val, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "prefix"<< ": ";
		printRule(os, dt.prefix, indentLevel, false);
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
	if (lexer == nullptr) {
		Lexer lexer;
		lexer.setinput(text);
		auto pos = Lexer::lazy_iterator(lexer, text);
		parseFromPos(pos);
	} else {
		auto pos = Lexer::lazy_iterator(lexer, text);
		parseFromPos(pos);
	}
}
const ::Parser::Types::rule_CSEQUENCE& Parser::get::rule_CSEQUENCE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE&>(token.data());
}
::Parser::Types::rule_CSEQUENCE& Parser::get::rule_CSEQUENCE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE&>(token.data());
}
const ::Parser::Types::ID& Parser::get::ID(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::ID) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::ID, "Parser");
	return std::any_cast<const Types::ID&>(token.data());
}
::Parser::Types::ID& Parser::get::ID(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::ID) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::ID, "Parser");
	return std::any_cast<Types::ID&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_DIAPASON& Parser::get::rule_CSEQUENCE_DIAPASON(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_DIAPASON) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_DIAPASON, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_DIAPASON&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_DIAPASON& Parser::get::rule_CSEQUENCE_DIAPASON(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_DIAPASON) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_DIAPASON, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_DIAPASON&>(token.data());
}
const ::Parser::Types::AUTO_13& Parser::get::AUTO_13(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_13) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_13, "Parser");
	return std::any_cast<const Types::AUTO_13&>(token.data());
}
::Parser::Types::AUTO_13& Parser::get::AUTO_13(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_13) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_13, "Parser");
	return std::any_cast<Types::AUTO_13&>(token.data());
}
const ::Parser::Types::SPACEMODE& Parser::get::SPACEMODE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::SPACEMODE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::SPACEMODE, "Parser");
	return std::any_cast<const Types::SPACEMODE&>(token.data());
}
::Parser::Types::SPACEMODE& Parser::get::SPACEMODE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::SPACEMODE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::SPACEMODE, "Parser");
	return std::any_cast<Types::SPACEMODE&>(token.data());
}
const ::Parser::Types::AUTO_16& Parser::get::AUTO_16(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_16) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_16, "Parser");
	return std::any_cast<const Types::AUTO_16&>(token.data());
}
::Parser::Types::AUTO_16& Parser::get::AUTO_16(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_16) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_16, "Parser");
	return std::any_cast<Types::AUTO_16&>(token.data());
}
const ::Parser::Types::NUMBER& Parser::get::NUMBER(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NUMBER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NUMBER, "Parser");
	return std::any_cast<const Types::NUMBER&>(token.data());
}
::Parser::Types::NUMBER& Parser::get::NUMBER(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NUMBER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NUMBER, "Parser");
	return std::any_cast<Types::NUMBER&>(token.data());
}
const ::Parser::Types::AUTO_8& Parser::get::AUTO_8(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_8) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_8, "Parser");
	return std::any_cast<const Types::AUTO_8&>(token.data());
}
::Parser::Types::AUTO_8& Parser::get::AUTO_8(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_8) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_8, "Parser");
	return std::any_cast<Types::AUTO_8&>(token.data());
}
const ::Parser::Types::AUTO_18& Parser::get::AUTO_18(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_18) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_18, "Parser");
	return std::any_cast<const Types::AUTO_18&>(token.data());
}
::Parser::Types::AUTO_18& Parser::get::AUTO_18(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_18) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_18, "Parser");
	return std::any_cast<Types::AUTO_18&>(token.data());
}
const ::Parser::Types::AUTO_14& Parser::get::AUTO_14(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_14) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_14, "Parser");
	return std::any_cast<const Types::AUTO_14&>(token.data());
}
::Parser::Types::AUTO_14& Parser::get::AUTO_14(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_14) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_14, "Parser");
	return std::any_cast<Types::AUTO_14&>(token.data());
}
const ::Parser::Types::rule_HEX& Parser::get::rule_HEX(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_HEX) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_HEX, "Parser");
	return std::any_cast<const Types::rule_HEX&>(token.data());
}
::Parser::Types::rule_HEX& Parser::get::rule_HEX(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_HEX) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_HEX, "Parser");
	return std::any_cast<Types::rule_HEX&>(token.data());
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
const ::Parser::Types::STRING& Parser::get::STRING(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::STRING) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::STRING, "Parser");
	return std::any_cast<const Types::STRING&>(token.data());
}
::Parser::Types::STRING& Parser::get::STRING(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::STRING) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::STRING, "Parser");
	return std::any_cast<Types::STRING&>(token.data());
}
const ::Parser::Types::AUTO_11& Parser::get::AUTO_11(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_11) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_11, "Parser");
	return std::any_cast<const Types::AUTO_11&>(token.data());
}
::Parser::Types::AUTO_11& Parser::get::AUTO_11(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_11) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_11, "Parser");
	return std::any_cast<Types::AUTO_11&>(token.data());
}
const ::Parser::Types::AUTO_0& Parser::get::AUTO_0(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_0) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_0, "Parser");
	return std::any_cast<const Types::AUTO_0&>(token.data());
}
::Parser::Types::AUTO_0& Parser::get::AUTO_0(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_0) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_0, "Parser");
	return std::any_cast<Types::AUTO_0&>(token.data());
}
const ::Parser::Types::BOOLEAN& Parser::get::BOOLEAN(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::BOOLEAN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::BOOLEAN, "Parser");
	return std::any_cast<const Types::BOOLEAN&>(token.data());
}
::Parser::Types::BOOLEAN& Parser::get::BOOLEAN(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::BOOLEAN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::BOOLEAN, "Parser");
	return std::any_cast<Types::BOOLEAN&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_ESCAPE& Parser::get::rule_CSEQUENCE_ESCAPE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_ESCAPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_ESCAPE, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_ESCAPE&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_ESCAPE& Parser::get::rule_CSEQUENCE_ESCAPE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_ESCAPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_ESCAPE, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_ESCAPE&>(token.data());
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
const ::Parser::Types::AUTO_3& Parser::get::AUTO_3(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_3) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_3, "Parser");
	return std::any_cast<const Types::AUTO_3&>(token.data());
}
::Parser::Types::AUTO_3& Parser::get::AUTO_3(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_3) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_3, "Parser");
	return std::any_cast<Types::AUTO_3&>(token.data());
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
const ::Parser::Types::AUTO_1& Parser::get::AUTO_1(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_1) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_1, "Parser");
	return std::any_cast<const Types::AUTO_1&>(token.data());
}
::Parser::Types::AUTO_1& Parser::get::AUTO_1(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_1) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_1, "Parser");
	return std::any_cast<Types::AUTO_1&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_SYMBOL& Parser::get::rule_CSEQUENCE_SYMBOL(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_SYMBOL) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_SYMBOL, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_SYMBOL&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_SYMBOL& Parser::get::rule_CSEQUENCE_SYMBOL(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_SYMBOL) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_SYMBOL, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_SYMBOL&>(token.data());
}
const ::Parser::Types::AUTO_17& Parser::get::AUTO_17(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_17) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_17, "Parser");
	return std::any_cast<const Types::AUTO_17&>(token.data());
}
::Parser::Types::AUTO_17& Parser::get::AUTO_17(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_17) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_17, "Parser");
	return std::any_cast<Types::AUTO_17&>(token.data());
}
const ::Parser::Types::cll_COMPARE_OP& Parser::get::cll_COMPARE_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_COMPARE_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_COMPARE_OP, "Parser");
	return std::any_cast<const Types::cll_COMPARE_OP&>(token.data());
}
::Parser::Types::cll_COMPARE_OP& Parser::get::cll_COMPARE_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_COMPARE_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_COMPARE_OP, "Parser");
	return std::any_cast<Types::cll_COMPARE_OP&>(token.data());
}
const ::Parser::Types::AUTO_12& Parser::get::AUTO_12(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_12) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_12, "Parser");
	return std::any_cast<const Types::AUTO_12&>(token.data());
}
::Parser::Types::AUTO_12& Parser::get::AUTO_12(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_12) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_12, "Parser");
	return std::any_cast<Types::AUTO_12&>(token.data());
}
const ::Parser::Types::cll_TEMPLATE& Parser::get::cll_TEMPLATE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TEMPLATE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TEMPLATE, "Parser");
	return std::any_cast<const Types::cll_TEMPLATE&>(token.data());
}
::Parser::Types::cll_TEMPLATE& Parser::get::cll_TEMPLATE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TEMPLATE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TEMPLATE, "Parser");
	return std::any_cast<Types::cll_TEMPLATE&>(token.data());
}
const ::Parser::Types::AUTO_9& Parser::get::AUTO_9(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_9) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_9, "Parser");
	return std::any_cast<const Types::AUTO_9&>(token.data());
}
::Parser::Types::AUTO_9& Parser::get::AUTO_9(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_9) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_9, "Parser");
	return std::any_cast<Types::AUTO_9&>(token.data());
}
const ::Parser::Types::AUTO_15& Parser::get::AUTO_15(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_15) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_15, "Parser");
	return std::any_cast<const Types::AUTO_15&>(token.data());
}
::Parser::Types::AUTO_15& Parser::get::AUTO_15(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_15) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_15, "Parser");
	return std::any_cast<Types::AUTO_15&>(token.data());
}
const ::Parser::Types::rule_ESCAPED& Parser::get::rule_ESCAPED(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_ESCAPED) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_ESCAPED, "Parser");
	return std::any_cast<const Types::rule_ESCAPED&>(token.data());
}
::Parser::Types::rule_ESCAPED& Parser::get::rule_ESCAPED(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_ESCAPED) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_ESCAPED, "Parser");
	return std::any_cast<Types::rule_ESCAPED&>(token.data());
}
const ::Parser::Types::AUTO_10& Parser::get::AUTO_10(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_10) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_10, "Parser");
	return std::any_cast<const Types::AUTO_10&>(token.data());
}
::Parser::Types::AUTO_10& Parser::get::AUTO_10(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_10) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_10, "Parser");
	return std::any_cast<Types::AUTO_10&>(token.data());
}
const ::Parser::Types::NAME& Parser::get::NAME(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NAME) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NAME, "Parser");
	return std::any_cast<const Types::NAME&>(token.data());
}
::Parser::Types::NAME& Parser::get::NAME(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NAME) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NAME, "Parser");
	return std::any_cast<Types::NAME&>(token.data());
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
const ::Parser::Types::cll_LOGICAL_OP& Parser::get::cll_LOGICAL_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OP, "Parser");
	return std::any_cast<const Types::cll_LOGICAL_OP&>(token.data());
}
::Parser::Types::cll_LOGICAL_OP& Parser::get::cll_LOGICAL_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OP, "Parser");
	return std::any_cast<Types::cll_LOGICAL_OP&>(token.data());
}
const ::Parser::Types::rule_group& Parser::get::rule_group(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_group, "Parser");
	return std::any_cast<const Types::rule_group&>(rule.data());
}
::Parser::Types::rule_group& Parser::get::rule_group(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_group, "Parser");
	return std::any_cast<Types::rule_group&>(rule.data());
}
const ::Parser::Types::_use_unit& Parser::get::_use_unit(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use_unit) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use_unit, "Parser");
	return std::any_cast<const Types::_use_unit&>(rule.data());
}
::Parser::Types::_use_unit& Parser::get::_use_unit(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use_unit) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use_unit, "Parser");
	return std::any_cast<Types::_use_unit&>(rule.data());
}
const ::Parser::Types::rule_nested_rule& Parser::get::rule_nested_rule(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_nested_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_nested_rule, "Parser");
	return std::any_cast<const Types::rule_nested_rule&>(rule.data());
}
::Parser::Types::rule_nested_rule& Parser::get::rule_nested_rule(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_nested_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_nested_rule, "Parser");
	return std::any_cast<Types::rule_nested_rule&>(rule.data());
}
const ::Parser::Types::_use& Parser::get::_use(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use, "Parser");
	return std::any_cast<const Types::_use&>(rule.data());
}
::Parser::Types::_use& Parser::get::_use(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use, "Parser");
	return std::any_cast<Types::_use&>(rule.data());
}
const ::Parser::Types::main& Parser::get::main(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::main) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::main, "Parser");
	return std::any_cast<const Types::main&>(rule.data());
}
::Parser::Types::main& Parser::get::main(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::main) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::main, "Parser");
	return std::any_cast<Types::main&>(rule.data());
}
const ::Parser::Types::rule_quantifier& Parser::get::rule_quantifier(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_quantifier) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_quantifier, "Parser");
	return std::any_cast<const Types::rule_quantifier&>(rule.data());
}
::Parser::Types::rule_quantifier& Parser::get::rule_quantifier(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_quantifier) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_quantifier, "Parser");
	return std::any_cast<Types::rule_quantifier&>(rule.data());
}
const ::Parser::Types::rule_keyvalue& Parser::get::rule_keyvalue(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_keyvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_keyvalue, "Parser");
	return std::any_cast<const Types::rule_keyvalue&>(rule.data());
}
::Parser::Types::rule_keyvalue& Parser::get::rule_keyvalue(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_keyvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_keyvalue, "Parser");
	return std::any_cast<Types::rule_keyvalue&>(rule.data());
}
const ::Parser::Types::cll_expr_term& Parser::get::cll_expr_term(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_term) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_term, "Parser");
	return std::any_cast<const Types::cll_expr_term&>(rule.data());
}
::Parser::Types::cll_expr_term& Parser::get::cll_expr_term(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_term) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_term, "Parser");
	return std::any_cast<Types::cll_expr_term&>(rule.data());
}
const ::Parser::Types::rvalue& Parser::get::rvalue(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rvalue, "Parser");
	return std::any_cast<const Types::rvalue&>(rule.data());
}
::Parser::Types::rvalue& Parser::get::rvalue(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rvalue, "Parser");
	return std::any_cast<Types::rvalue&>(rule.data());
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
const ::Parser::Types::cll__var& Parser::get::cll__var(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__var) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__var, "Parser");
	return std::any_cast<const Types::cll__var&>(rule.data());
}
::Parser::Types::cll__var& Parser::get::cll__var(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__var) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__var, "Parser");
	return std::any_cast<Types::cll__var&>(rule.data());
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
const ::Parser::Types::cll_function_decl& Parser::get::cll_function_decl(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_decl, "Parser");
	return std::any_cast<const Types::cll_function_decl&>(rule.data());
}
::Parser::Types::cll_function_decl& Parser::get::cll_function_decl(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_decl, "Parser");
	return std::any_cast<Types::cll_function_decl&>(rule.data());
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
const ::Parser::Types::cll& Parser::get::cll(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll, "Parser");
	return std::any_cast<const Types::cll&>(rule.data());
}
::Parser::Types::cll& Parser::get::cll(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll, "Parser");
	return std::any_cast<Types::cll&>(rule.data());
}
const ::Parser::Types::cll_expr_compare& Parser::get::cll_expr_compare(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_compare) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_compare, "Parser");
	return std::any_cast<const Types::cll_expr_compare&>(rule.data());
}
::Parser::Types::cll_expr_compare& Parser::get::cll_expr_compare(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_compare) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_compare, "Parser");
	return std::any_cast<Types::cll_expr_compare&>(rule.data());
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
const ::Parser::Types::cll_loop_while& Parser::get::cll_loop_while(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_while) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_while, "Parser");
	return std::any_cast<const Types::cll_loop_while&>(rule.data());
}
::Parser::Types::cll_loop_while& Parser::get::cll_loop_while(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_while) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_while, "Parser");
	return std::any_cast<Types::cll_loop_while&>(rule.data());
}
const ::Parser::Types::cll_method_call& Parser::get::cll_method_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_method_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_method_call, "Parser");
	return std::any_cast<const Types::cll_method_call&>(rule.data());
}
::Parser::Types::cll_method_call& Parser::get::cll_method_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_method_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_method_call, "Parser");
	return std::any_cast<Types::cll_method_call&>(rule.data());
}
const ::Parser::Types::rule_data_block_templated_datablock& Parser::get::rule_data_block_templated_datablock(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_templated_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_templated_datablock, "Parser");
	return std::any_cast<const Types::rule_data_block_templated_datablock&>(rule.data());
}
::Parser::Types::rule_data_block_templated_datablock& Parser::get::rule_data_block_templated_datablock(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_templated_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_templated_datablock, "Parser");
	return std::any_cast<Types::rule_data_block_templated_datablock&>(rule.data());
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
const ::Parser::Types::cll__variable& Parser::get::cll__variable(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__variable) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__variable, "Parser");
	return std::any_cast<const Types::cll__variable&>(rule.data());
}
::Parser::Types::cll__variable& Parser::get::cll__variable(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__variable) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__variable, "Parser");
	return std::any_cast<Types::cll__variable&>(rule.data());
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
const ::Parser::Types::cll_function_body_decl& Parser::get::cll_function_body_decl(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_decl, "Parser");
	return std::any_cast<const Types::cll_function_body_decl&>(rule.data());
}
::Parser::Types::cll_function_body_decl& Parser::get::cll_function_body_decl(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_decl, "Parser");
	return std::any_cast<Types::cll_function_body_decl&>(rule.data());
}
const ::Parser::Types::rule_name& Parser::get::rule_name(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_name) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_name, "Parser");
	return std::any_cast<const Types::rule_name&>(rule.data());
}
::Parser::Types::rule_name& Parser::get::rule_name(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_name) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_name, "Parser");
	return std::any_cast<Types::rule_name&>(rule.data());
}
const ::Parser::Types::array& Parser::get::array(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::array) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::array, "Parser");
	return std::any_cast<const Types::array&>(rule.data());
}
::Parser::Types::array& Parser::get::array(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::array) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::array, "Parser");
	return std::any_cast<Types::array&>(rule.data());
}
const ::Parser::Types::rule_member& Parser::get::rule_member(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_member) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_member, "Parser");
	return std::any_cast<const Types::rule_member&>(rule.data());
}
::Parser::Types::rule_member& Parser::get::rule_member(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_member) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_member, "Parser");
	return std::any_cast<Types::rule_member&>(rule.data());
}
const ::Parser::Types::object& Parser::get::object(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::object) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::object, "Parser");
	return std::any_cast<const Types::object&>(rule.data());
}
::Parser::Types::object& Parser::get::object(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::object) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::object, "Parser");
	return std::any_cast<Types::object&>(rule.data());
}
const ::Parser::Types::cll_expr_logical& Parser::get::cll_expr_logical(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_logical) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_logical, "Parser");
	return std::any_cast<const Types::cll_expr_logical&>(rule.data());
}
::Parser::Types::cll_expr_logical& Parser::get::cll_expr_logical(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_logical) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_logical, "Parser");
	return std::any_cast<Types::cll_expr_logical&>(rule.data());
}
const ::Parser::Types::cll_expr_value& Parser::get::cll_expr_value(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_value, "Parser");
	return std::any_cast<const Types::cll_expr_value&>(rule.data());
}
::Parser::Types::cll_expr_value& Parser::get::cll_expr_value(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_value, "Parser");
	return std::any_cast<Types::cll_expr_value&>(rule.data());
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
	success_1 = false;
	success_3 = false;
	_2 = SPACEMODE(pos);
	if (!(_2.status))
	{
		success_5 = false;
		_4 = AUTO_4(pos);
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
					_10 = cll_TYPE(pos);
					if (!(_10.status))
					{
						success_13 = false;
						_12 = rule_NOSPACE(pos);
						if (!(_12.status))
						{
							success_15 = false;
							_14 = AUTO_18(pos);
							if (!(_14.status))
							{
								success_17 = false;
								_16 = AUTO_19(pos);
								if (!(_16.status))
								{
									success_19 = false;
									_18 = cll_LOGICAL_OP(pos);
									if (!(_18.status))
									{
										success_21 = false;
										_20 = AUTO_9(pos);
										if (!(_20.status))
										{
											success_23 = false;
											_22 = AUTO_10(pos);
											if (!(_22.status))
											{
												success_25 = false;
												_24 = rule_ESCAPED(pos);
												if (!(_24.status))
												{
													success_27 = false;
													_26 = STRING(pos);
													if (!(_26.status))
													{
														success_29 = false;
														_28 = rule_HEX(pos);
														if (!(_28.status))
														{
															success_31 = false;
															_30 = rule_BIN(pos);
															if (!(_30.status))
															{
																success_33 = false;
																_32 = LINEAR_COMMENT(pos);
																if (!(_32.status))
																{
																	success_35 = false;
																	_34 = AUTO_11(pos);
																	if (!(_34.status))
																	{
																		success_37 = false;
																		_36 = AUTO_12(pos);
																		if (!(_36.status))
																		{
																			success_39 = false;
																			_38 = AUTO_2(pos);
																			if (!(_38.status))
																			{
																				success_41 = false;
																				_40 = rule_OP(pos);
																				if (!(_40.status))
																				{
																					success_43 = false;
																					_42 = AUTO_0(pos);
																					if (!(_42.status))
																					{
																						success_45 = false;
																						_44 = AUTO_14(pos);
																						if (!(_44.status))
																						{
																							success_47 = false;
																							_46 = rule_CSEQUENCE(pos);
																							if (!(_46.status))
																							{
																								success_49 = false;
																								_48 = AUTO_13(pos);
																								if (!(_48.status))
																								{
																									success_51 = false;
																									_50 = cll_COMPARE_OP(pos);
																									if (!(_50.status))
																									{
																										success_53 = false;
																										_52 = AT(pos);
																										if (!(_52.status))
																										{
																											success_55 = false;
																											_54 = QUESTION_MARK(pos);
																											if (!(_54.status))
																											{
																												success_57 = false;
																												_56 = AUTO_3(pos);
																												if (!(_56.status))
																												{
																													success_59 = false;
																													_58 = AUTO_8(pos);
																													if (!(_58.status))
																													{
																														success_61 = false;
																														_60 = AUTO_15(pos);
																														if (!(_60.status))
																														{
																															success_63 = false;
																															_62 = DIVIDE(pos);
																															if (!(_62.status))
																															{
																																success_65 = false;
																																_64 = MINUS(pos);
																																if (!(_64.status))
																																{
																																	success_67 = false;
																																	_66 = AUTO_1(pos);
																																	if (!(_66.status))
																																	{
																																		success_69 = false;
																																		_68 = PLUS(pos);
																																		if (!(_68.status))
																																		{
																																			success_71 = false;
																																			_70 = MULTIPLE(pos);
																																			if (!(_70.status))
																																			{
																																				success_73 = false;
																																				_72 = AUTO_6(pos);
																																				if (!(_72.status))
																																				{
																																					success_75 = false;
																																					_74 = AUTO_5(pos);
																																					if (!(_74.status))
																																					{
																																						success_77 = false;
																																						_76 = AUTO_16(pos);
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
																																									_82 = DOT(pos);
																																									if (!(_82.status))
																																									{
																																										success_85 = false;
																																										_84 = AUTO_7(pos);
																																										if (!(_84.status))
																																										{
																																											success_87 = false;
																																											_86 = AUTO_17(pos);
																																											if (!(_86.status))
																																											{
																																												success_89 = false;
																																												_88 = __WHITESPACE(pos);
																																												if (!(_88.status))
																																												{
																																													success_91 = false;
																																													_90 = ID(pos);
																																													if (!(_90.status))
																																													{
																																														success_93 = false;
																																														_92 = NUMBER(pos);
																																														if (!(_92.status))
																																														{
																																															return {};
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
Parser::Token_res Parser::Lexer::__WHITESPACE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_2 = false;
	success_1 = false;
	success_2 = false;
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
Parser::Token_res Parser::Lexer::AUTO_11(const char* pos) {
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
	::Parser::Types::AUTO_11 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_11, data)};
}
Parser::Token_res Parser::Lexer::AUTO_7(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '$'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_7 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_7, data)};
}
Parser::Token_res Parser::Lexer::AUTO_6(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == ')'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_6 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_6, data)};
}
Parser::Token_res Parser::Lexer::AUTO_3(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '='))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_3 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_3, data)};
}
Parser::Token_res Parser::Lexer::AUTO_2(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '}'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_2 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_2, data)};
}
Parser::Token_res Parser::Lexer::AUTO_1(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == ','))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_1 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_1, data)};
}
Parser::Token_res Parser::Lexer::AUTO_0(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '{'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_0 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_0, data)};
}
Parser::Token_res Parser::Lexer::rule_BIN(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_4 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "0b", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	success_3 = false;
	success_4 = false;
	while (*(pos + 0) == '0' || *(pos + 0) == '1')
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		success_4 = true;
	}
	if (!success_4)
	{
		reportError(pos, "0 or 1");
		return {};
	}
	::Parser::Types::rule_BIN data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_BIN, data)};
}
Parser::Token_res Parser::Lexer::rule_HEX(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_4 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "0x", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	success_3 = false;
	success_4 = false;
	while ((*(pos + 0)>='0' && *(pos + 0)<='9') || (*(pos + 0)>='A' && *(pos + 0)<='F') || (*(pos + 0)>='a' && *(pos + 0)<='f'))
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		success_4 = true;
	}
	if (!success_4)
	{
		reportError(pos, "0-9, A-F or a-f");
		return {};
	}
	::Parser::Types::rule_HEX data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_HEX, data)};
}
Parser::Token_res Parser::Lexer::AUTO_14(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == ']'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_14 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_14, data)};
}
Parser::Token_res Parser::Lexer::rule_NOSPACE(const char* pos) {
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
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_NOSPACE)};
}
Parser::Token_res Parser::Lexer::AUTO_8(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == ';'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_8 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_8, data)};
}
Parser::Token_res Parser::Lexer::rule_CSEQUENCE_ESCAPE(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	char _2;
	::Parser::bool_t success_3 = false;
	success_1 = false;
	if (!(*(pos + 0) == '\\'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	success_3 = false;
	if (*(pos + 0) == '\0')
	{
		reportError(pos, "symbol");
		return {};
	}
	_2 = *(pos + 0);
	success_3 = true;
	pos += 1;
	::Parser::Types::rule_CSEQUENCE_ESCAPE data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_CSEQUENCE_ESCAPE, data)};
}
Parser::Token_res Parser::Lexer::rule_CSEQUENCE_SYMBOL(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	char _2;
	::Parser::bool_t success_3 = false;
	char _4;
	::Parser::bool_t success_5 = false;
	success_1 = false;
	success_3 = false;
	if (!(*(pos + 0) == '\\'))
	{
		success_5 = false;
		if (!(!(*(pos + 0) == ']')))
		{
			return {};
		}
		else 
		{
			_4 = *(pos + 0);
			success_5 = true;
			pos += 1;
			_0 = _4;
		}
	}
	else 
	{
		_2 = *(pos + 0);
		success_3 = true;
		pos += 1;
		_0 = _2;
	}
	success_1 = true;
	::Parser::Types::rule_CSEQUENCE_SYMBOL data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_CSEQUENCE_SYMBOL, data)};
}
Parser::Token_res Parser::Lexer::rule_OP(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '|'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_OP)};
}
Parser::Token_res Parser::Lexer::AUTO_17(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '#'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_17 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_17, data)};
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
	char _10;
	::Parser::bool_t success_11 = false;
	char _12;
	::Parser::bool_t success_13 = false;
	success_1 = false;
	success_3 = false;
	if (!(!std::strncmp(pos + 0, ">=", 2)))
	{
		success_5 = false;
		if (!(!std::strncmp(pos + 0, "==", 2)))
		{
			success_7 = false;
			if (!(!std::strncmp(pos + 0, "<=", 2)))
			{
				success_9 = false;
				if (!(!std::strncmp(pos + 0, "!=", 2)))
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
							_12 = *(pos + 0);
							success_13 = true;
							pos += 1;
							_0 = _12;
						}
					}
					else 
					{
						_10 = *(pos + 0);
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
	::Parser::Types::cll_COMPARE_OP data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_COMPARE_OP, data)};
}
Parser::Token_res Parser::Lexer::AUTO_9(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "if", 2) && !(*(pos + 2)>='a' && *(pos + 2)<='z' || *(pos + 2)>='A' && *(pos + 2)<='Z' || *(pos + 2)>='0' && *(pos + 2)<='9' || *(pos + 2) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_9 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_9, data)};
}
Parser::Token_res Parser::Lexer::AUTO_5(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '('))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_5 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_5, data)};
}
Parser::Token_res Parser::Lexer::rule_ESCAPED(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	char _2;
	::Parser::bool_t success_3 = false;
	success_1 = false;
	if (!(*(pos + 0) == '\\'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	success_3 = false;
	if (*(pos + 0) == '\0')
	{
		reportError(pos, "symbol");
		return {};
	}
	_2 = *(pos + 0);
	success_3 = true;
	pos += 1;
	::Parser::Types::rule_ESCAPED data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_ESCAPED, data)};
}
Parser::Token_res Parser::Lexer::cll_OP(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	char _2;
	::Parser::bool_t success_3 = false;
	char _4;
	::Parser::bool_t success_5 = false;
	char _6;
	::Parser::bool_t success_7 = false;
	char _8;
	::Parser::bool_t success_9 = false;
	char _10;
	::Parser::bool_t success_11 = false;
	success_1 = false;
	success_3 = false;
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
						_10 = *(pos + 0);
						success_11 = true;
						pos += 1;
						_0 = _10;
					}
				}
				else 
				{
					_8 = *(pos + 0);
					success_9 = true;
					pos += 1;
					_0 = _8;
				}
			}
			else 
			{
				_6 = *(pos + 0);
				success_7 = true;
				pos += 1;
				_0 = _6;
			}
		}
		else 
		{
			_4 = *(pos + 0);
			success_5 = true;
			pos += 1;
			_0 = _4;
		}
	}
	else 
	{
		_2 = *(pos + 0);
		success_3 = true;
		pos += 1;
		_0 = _2;
	}
	success_1 = true;
	::Parser::Types::cll_OP data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_OP, data)};
}
Parser::Token_res Parser::Lexer::AUTO_10(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "fn", 2) && !(*(pos + 2)>='a' && *(pos + 2)<='z' || *(pos + 2)>='A' && *(pos + 2)<='Z' || *(pos + 2)>='0' && *(pos + 2)<='9' || *(pos + 2) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	::Parser::Types::AUTO_10 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_10, data)};
}
Parser::Token_res Parser::Lexer::cll_ASSIGNMENT_OP(const char* pos) {
	auto in = pos;
	::Parser::Token_res _0;
	::Parser::bool_t success_1 = false;
	char _2;
	::Parser::bool_t success_3 = false;
	success_1 = false;
	_0 = cll_OP(pos);
	if (_0.status)
	{
		success_1 = true;
		pos += _0.node.length();
	}
	skip_spaces(pos);
	success_3 = false;
	if (!(*(pos + 0) == '='))
	{
		reportError(pos, "\"=\"");
		return {};
	}
	_2 = *(pos + 0);
	success_3 = true;
	pos += 1;
	::Parser::Types::cll_ASSIGNMENT_OP data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_ASSIGNMENT_OP, data)};
}
Parser::Token_res Parser::Lexer::AUTO_19(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "for", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	::Parser::Types::AUTO_19 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_19, data)};
}
Parser::Token_res Parser::Lexer::cll_TEMPLATE(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_5 = false;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	char _6;
	::Parser::Token_res _8;
	::Parser::arr_t<::Parser::Token> shadow_10;
	char _12;
	::Parser::bool_t success_13 = false;
	success_1 = false;
	if (!(*(pos + 0) == '<'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	success_3 = false;
	_2 = cll_TYPE(pos);
	if (!(_2.status))
	{
		reportError(pos, "cll type ");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	success_5 = false;
	auto begin_11 = pos;
	success_9 = false;
	success_7 = false;
	while (1)
	{
		if (!(*(begin_11 + 0) == ','))
		{
			reportError(pos, "\",\"");
			break;
		}
		_6 = *(begin_11 + 0);
		success_7 = true;
		begin_11 += 1;
		skip_spaces(begin_11);
		_8 = cll_TYPE(begin_11);
		if (!(_8.status))
		{
			reportError(pos, "cll type ");
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
	success_13 = false;
	if (!(*(pos + 0) == '>'))
	{
		reportError(pos, "\">\"");
		return {};
	}
	_12 = *(pos + 0);
	success_13 = true;
	pos += 1;
	::Parser::Types::cll_TEMPLATE data;
	data.second = shadow_10;
	data.first = _2.node;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_TEMPLATE, data)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_NOT(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	char _4;
	::Parser::bool_t success_5 = false;
	success_1 = false;
	success_3 = false;
	if (!(!std::strncmp(pos + 0, "not", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
	{
		success_5 = false;
		if (!(*(pos + 0) == '!'))
		{
			return {};
		}
		else 
		{
			_4 = *(pos + 0);
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
Parser::Token_res Parser::Lexer::cll_LOGICAL_OP(const char* pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	::Parser::Token_res _4;
	::Parser::bool_t success_5 = false;
	success_1 = false;
	success_3 = false;
	_2 = cll_LOGICAL_AND(pos);
	if (!(_2.status))
	{
		success_5 = false;
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
	::Parser::Types::cll_LOGICAL_OP data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_LOGICAL_OP, data)};
}
Parser::Token_res Parser::Lexer::cll_TYPE(const char* pos) {
	auto in = pos;
	::Parser::any_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::str_t _6;
	::Parser::bool_t success_7 = false;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_13 = false;
	::Parser::bool_t success_11 = false;
	::Parser::str_t _10;
	::Parser::Token_res _12;
	::Parser::str_t _15;
	::Parser::bool_t success_16 = false;
	::Parser::bool_t success_18 = false;
	::Parser::bool_t success_22 = false;
	::Parser::bool_t success_20 = false;
	::Parser::str_t _19;
	::Parser::Token_res _21;
	success_1 = false;
	success_3 = false;
	if (!(!std::strncmp(pos + 0, "bool", 4) && !(*(pos + 4)>='a' && *(pos + 4)<='z' || *(pos + 4)>='A' && *(pos + 4)<='Z' || *(pos + 4)>='0' && *(pos + 4)<='9' || *(pos + 4) == '_')))
	{
		success_5 = false;
		if (!(!std::strncmp(pos + 0, "var", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
		{
			success_7 = false;
			if (!(!std::strncmp(pos + 0, "str", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
			{
				success_9 = false;
				auto begin_14 = pos;
				success_13 = false;
				success_11 = false;
				do
				{
					if (!(!std::strncmp(begin_14 + 0, "obj", 3) && !(*(begin_14 + 3)>='a' && *(begin_14 + 3)<='z' || *(begin_14 + 3)>='A' && *(begin_14 + 3)<='Z' || *(begin_14 + 3)>='0' && *(begin_14 + 3)<='9' || *(begin_14 + 3) == '_')))
					{
						break;
					}
					_10 += ::Parser::str_t(begin_14, 3);
					success_11 = true;
					begin_14 += 3;
					skip_spaces(begin_14);
					_12 = cll_TEMPLATE(begin_14);
					if (!(_12.status))
					{
						reportError(pos, "cll template ");
						break;
					}
					success_13 = true;
					begin_14 += _12.node.length();
				}
				while(0);
				if (success_11 && success_13)
				{
					success_9 = true;
					pos = begin_14;
				}
				;
				if (!success_9)
				{
					success_16 = false;
					if (!(!std::strncmp(pos + 0, "num", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
					{
						success_18 = false;
						auto begin_23 = pos;
						success_22 = false;
						success_20 = false;
						do
						{
							if (!(!std::strncmp(begin_23 + 0, "arr", 3) && !(*(begin_23 + 3)>='a' && *(begin_23 + 3)<='z' || *(begin_23 + 3)>='A' && *(begin_23 + 3)<='Z' || *(begin_23 + 3)>='0' && *(begin_23 + 3)<='9' || *(begin_23 + 3) == '_')))
							{
								break;
							}
							_19 += ::Parser::str_t(begin_23, 3);
							success_20 = true;
							begin_23 += 3;
							skip_spaces(begin_23);
							_21 = cll_TEMPLATE(begin_23);
							if (!(_21.status))
							{
								reportError(pos, "cll template ");
								break;
							}
							success_22 = true;
							begin_23 += _21.node.length();
						}
						while(0);
						if (success_20 && success_22)
						{
							success_18 = true;
							pos = begin_23;
						}
						;
						if (!success_18)
						{
							return {};
						}
					}
					else 
					{
						_15 = ::Parser::str_t(pos, 1);
						success_16 = true;
						pos += 1;
						_0 = _15;
					}
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
	::Parser::Types::cll_TYPE data;
	data.templ = _12.node;
	data.type = _10;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_TYPE, data)};
}
Parser::Token_res Parser::Lexer::AUTO_12(const char* pos) {
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
	::Parser::Types::AUTO_12 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_12, data)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_OR(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	success_1 = false;
	success_3 = false;
	if (!(!std::strncmp(pos + 0, "||", 2)))
	{
		success_5 = false;
		if (!(!std::strncmp(pos + 0, "or", 2) && !(*(pos + 2)>='a' && *(pos + 2)<='z' || *(pos + 2)>='A' && *(pos + 2)<='Z' || *(pos + 2)>='0' && *(pos + 2)<='9' || *(pos + 2) == '_')))
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
Parser::Token_res Parser::Lexer::STRING(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_19 = false;
	::Parser::bool_t success_3 = false;
	char _2;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::bool_t success_7 = false;
	::Parser::str_t _6;
	::Parser::str_t _8;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_13 = false;
	::Parser::bool_t success_11 = false;
	char _10;
	char _12;
	char _15;
	::Parser::bool_t success_16 = false;
	char _18;
	success_1 = false;
	auto begin_20 = pos;
	success_19 = false;
	success_3 = false;
	if (!(*(begin_20 + 0) == '\''))
	{
		return {};
	}
	_2 = *(begin_20 + 0);
	success_3 = true;
	begin_20 += 1;
	skip_spaces(begin_20);
	success_5 = false;
	auto begin_17 = begin_20;
	success_7 = false;
	while (1)
	{
		success_9 = false;
		auto begin_14 = begin_17;
		success_13 = false;
		success_11 = false;
		do
		{
			if (!(*(begin_14 + 0) == '\\'))
			{
				reportError(pos, "\"\\\"");
				break;
			}
			_10 = *(begin_14 + 0);
			success_11 = true;
			begin_14 += 1;
			if (*(begin_14 + 0) == '\0')
			{
				reportError(pos, "symbol");
				break;
			}
			_12 = *(begin_14 + 0);
			success_13 = true;
			begin_14 += 1;
			_8 += _10;
			_8 += _12;
		}
		while(0);
		if (success_11 && success_13)
		{
			success_9 = true;
			begin_17 = begin_14;
		}
		;
		if (!success_9)
		{
			success_16 = false;
			if (!(!(*(begin_17 + 0) == '\'')))
			{
				break;
			}
			else 
			{
				_15 = *(begin_17 + 0);
				success_16 = true;
				begin_17 += 1;
				_6 = _15;
			}
		}
		else 
		{
			_6 = _8;
		}
		success_7 = true;
		_4 += _6;
	}
	if (success_7)
	{
		success_5 = true;
		begin_20 = begin_17;
	}
	skip_spaces(begin_20);
	if (!(*(begin_20 + 0) == '\''))
	{
		reportError(pos, "\"\'\"");
		return {};
	}
	_18 = *(begin_20 + 0);
	success_19 = true;
	begin_20 += 1;
	_0 += _2;
	_0 += _4;
	_0 += _18;
	if (success_3 && success_19)
	{
		success_1 = true;
		pos = begin_20;
	}
	::Parser::Types::STRING data = _4;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::STRING, data)};
}
Parser::Token_res Parser::Lexer::NUMBER(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	char _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	char _6;
	::Parser::str_t _8;
	::Parser::bool_t success_10 = false;
	success_1 = false;
	if (*(pos + 0) == '+' || *(pos + 0) == '-')
	{
		_0 += ::Parser::str_t(pos, 1);
		success_1 = true;
		pos += 1;
	}
	skip_spaces(pos);
	success_3 = false;
	if (!((*(pos + 0)>='0' && *(pos + 0)<='9')))
	{
		reportError(pos, "0-9");
		return {};
	}
	_2 = *(pos + 0);
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	success_5 = false;
	auto begin_11 = pos;
	success_9 = false;
	success_7 = false;
	do
	{
		if (!(*(begin_11 + 0) == '.' || *(begin_11 + 0) == ','))
		{
			reportError(pos, ". or ,");
			break;
		}
		_6 = *(begin_11 + 0);
		success_7 = true;
		begin_11 += 1;
		skip_spaces(begin_11);
		success_10 = false;
		while ((*(begin_11 + 0)>='0' && *(begin_11 + 0)<='9'))
		{
			_8 += ::Parser::str_t(begin_11, 1);
			success_9 = true;
			begin_11 += 1;
			success_10 = true;
		}
		if (!success_10)
		{
			reportError(pos, "0-9");
			break;
		}
		_4 += _6;
		_4 += _8;
	}
	while(0);
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_11;
	}
	::Parser::Types::NUMBER data;
	data.dec = _4;
	data.main = _2;
	data.sign = _0;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::NUMBER, data)};
}
Parser::Token_res Parser::Lexer::AUTO_16(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '&'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_16 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_16, data)};
}
Parser::Token_res Parser::Lexer::AUTO_4(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "while", 5) && !(*(pos + 5)>='a' && *(pos + 5)<='z' || *(pos + 5)>='A' && *(pos + 5)<='Z' || *(pos + 5)>='0' && *(pos + 5)<='9' || *(pos + 5) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 5;
	::Parser::Types::AUTO_4 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_4, data)};
}
Parser::Token_res Parser::Lexer::BOOLEAN(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t d;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	success_1 = false;
	success_3 = false;
	if (!(!std::strncmp(pos + 0, "false", 5) && !(*(pos + 5)>='a' && *(pos + 5)<='z' || *(pos + 5)>='A' && *(pos + 5)<='Z' || *(pos + 5)>='0' && *(pos + 5)<='9' || *(pos + 5) == '_')))
	{
		success_5 = false;
		if (!(!std::strncmp(pos + 0, "true", 4) && !(*(pos + 4)>='a' && *(pos + 4)<='z' || *(pos + 4)>='A' && *(pos + 4)<='Z' || *(pos + 4)>='0' && *(pos + 4)<='9' || *(pos + 4) == '_')))
		{
			return {};
		}
		else 
		{
			_4 = ::Parser::str_t(pos, 4);
			success_5 = true;
			pos += 4;
			_0 = _4;
		}
	}
	else 
	{
		_2 = ::Parser::str_t(pos, 5);
		success_3 = true;
		pos += 5;
		_0 = _2;
	}
	success_1 = true;
	d = _0;
	::Parser::Types::BOOLEAN data = d;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::BOOLEAN, data)};
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
	char _10;
	::Parser::bool_t success_11 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "spacemode", 9) && !(*(pos + 9)>='a' && *(pos + 9)<='z' || *(pos + 9)>='A' && *(pos + 9)<='Z' || *(pos + 9)>='0' && *(pos + 9)<='9' || *(pos + 9) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 9);
	success_1 = true;
	pos += 9;
	skip_spaces(pos);
	success_3 = false;
	success_5 = false;
	if (!(!std::strncmp(pos + 0, "skipped", 7) && !(*(pos + 7)>='a' && *(pos + 7)<='z' || *(pos + 7)>='A' && *(pos + 7)<='Z' || *(pos + 7)>='0' && *(pos + 7)<='9' || *(pos + 7) == '_')))
	{
		success_7 = false;
		if (!(!std::strncmp(pos + 0, "allowed", 7) && !(*(pos + 7)>='a' && *(pos + 7)<='z' || *(pos + 7)>='A' && *(pos + 7)<='Z' || *(pos + 7)>='0' && *(pos + 7)<='9' || *(pos + 7) == '_')))
		{
			success_9 = false;
			if (!(!std::strncmp(pos + 0, "mixed", 5) && !(*(pos + 5)>='a' && *(pos + 5)<='z' || *(pos + 5)>='A' && *(pos + 5)<='Z' || *(pos + 5)>='0' && *(pos + 5)<='9' || *(pos + 5) == '_')))
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
	skip_spaces(pos);
	success_11 = false;
	if (!(*(pos + 0) == ';'))
	{
		reportError(pos, "\";\"");
		return {};
	}
	_10 = *(pos + 0);
	success_11 = true;
	pos += 1;
	::Parser::Types::SPACEMODE data = _2;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::SPACEMODE, data)};
}
Parser::Token_res Parser::Lexer::AUTO_13(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '['))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_13 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_13, data)};
}
Parser::Token_res Parser::Lexer::rule_CSEQUENCE_DIAPASON(const char* pos) {
	auto in = pos;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_7 = false;
	::Parser::bool_t success_5 = false;
	::Parser::bool_t success_3 = false;
	::Parser::Token_res _2;
	char _4;
	::Parser::Token_res _6;
	success_1 = false;
	auto begin_8 = pos;
	success_7 = false;
	success_5 = false;
	success_3 = false;
	_2 = rule_CSEQUENCE_SYMBOL(begin_8);
	if (!(_2.status))
	{
		return {};
	}
	success_3 = true;
	begin_8 += _2.node.length();
	if (!(*(begin_8 + 0) == '-'))
	{
		reportError(pos, "\"-\"");
		return {};
	}
	_4 = *(begin_8 + 0);
	success_5 = true;
	begin_8 += 1;
	_6 = rule_CSEQUENCE_SYMBOL(begin_8);
	if (!(_6.status))
	{
		reportError(pos, "rule csequence symbol ");
		return {};
	}
	success_7 = true;
	begin_8 += _6.node.length();
	if (success_3 && success_5 && success_7)
	{
		success_1 = true;
		pos = begin_8;
	}
	::Parser::Types::rule_CSEQUENCE_DIAPASON data;
	data.to = _6.node;
	data.from = _2.node;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_CSEQUENCE_DIAPASON, data)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_AND(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	success_1 = false;
	success_3 = false;
	if (!(!std::strncmp(pos + 0, "and", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
	{
		success_5 = false;
		if (!(!std::strncmp(pos + 0, "&&", 2)))
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
Parser::Token_res Parser::Lexer::QUESTION_MARK(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '?'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::QUESTION_MARK)};
}
Parser::Token_res Parser::Lexer::PLUS(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '+'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::PLUS)};
}
Parser::Token_res Parser::Lexer::MINUS(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '-'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::MINUS)};
}
Parser::Token_res Parser::Lexer::DIVIDE(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '/'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::DIVIDE)};
}
Parser::Token_res Parser::Lexer::MULTIPLE(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '*'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::MULTIPLE)};
}
Parser::Token_res Parser::Lexer::MODULO(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '%'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::MODULO)};
}
Parser::Token_res Parser::Lexer::AT(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '@'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AT)};
}
Parser::Token_res Parser::Lexer::DOT(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == '.'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::DOT)};
}
Parser::Token_res Parser::Lexer::ID(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_3 = false;
	char _2;
	::Parser::str_t _4;
	::Parser::bool_t success_5 = false;
	success_1 = false;
	auto begin_6 = pos;
	success_3 = false;
	if (!(*(begin_6 + 0) == '_' || (*(begin_6 + 0)>='a' && *(begin_6 + 0)<='z') || (*(begin_6 + 0)>='A' && *(begin_6 + 0)<='Z')))
	{
		return {};
	}
	_2 = *(begin_6 + 0);
	success_3 = true;
	begin_6 += 1;
	skip_spaces(begin_6);
	success_5 = false;
	while (*(begin_6 + 0) == '_' || (*(begin_6 + 0)>='a' && *(begin_6 + 0)<='z') || (*(begin_6 + 0)>='A' && *(begin_6 + 0)<='Z') || (*(begin_6 + 0)>='0' && *(begin_6 + 0)<='9'))
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
	::Parser::Types::ID data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::ID, data)};
}
Parser::Token_res Parser::Lexer::AUTO_15(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(*(pos + 0) == ':'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	::Parser::Types::AUTO_15 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_15, data)};
}
Parser::Token_res Parser::Lexer::rule_CSEQUENCE(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	char _2 = '\0';
	::Parser::bool_t success_3 = false;
	::Parser::arr_t<::Parser::Token> _4;
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
	char _18;
	::Parser::bool_t success_19 = false;
	success_1 = false;
	if (!(*(pos + 0) == '['))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	success_3 = false;
	if (*(pos + 0) == '^')
	{
		_2 = *(pos + 0);
		success_3 = true;
		pos += 1;
	}
	skip_spaces(pos);
	success_5 = false;
	auto begin_17 = pos;
	success_7 = false;
	while (1)
	{
		success_9 = false;
		_8 = rule_CSEQUENCE_DIAPASON(begin_17);
		if (!(_8.status))
		{
			success_12 = false;
			_11 = rule_CSEQUENCE_ESCAPE(begin_17);
			if (!(_11.status))
			{
				success_15 = false;
				_14 = rule_CSEQUENCE_SYMBOL(begin_17);
				if (!(_14.status))
				{
					break;
				}
				else 
				{
					success_15 = true;
					begin_17 += _14.node.length();
					shadow_16.push_back(_14.node);
					_6.push_back(_14.node);
				}
			}
			else 
			{
				success_12 = true;
				begin_17 += _11.node.length();
				shadow_13.push_back(_11.node);
				_6.push_back(_11.node);
			}
		}
		else 
		{
			success_9 = true;
			begin_17 += _8.node.length();
			shadow_10.push_back(_8.node);
			_6.push_back(_8.node);
		}
		success_7 = true;
		_4 = _6;
	}
	if (success_7)
	{
		success_5 = true;
		pos = begin_17;
	}
	skip_spaces(pos);
	success_19 = false;
	if (!(*(pos + 0) == ']'))
	{
		reportError(pos, "\"]\"");
		return {};
	}
	_18 = *(pos + 0);
	success_19 = true;
	pos += 1;
	::Parser::Types::rule_CSEQUENCE data;
	data.val = _4;
	data._not = _2;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_CSEQUENCE, data)};
}
Parser::Token_res Parser::Lexer::LINEAR_COMMENT(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "//", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	success_3 = false;
	while (!(*(pos + 0) == 'n' && *(pos + 0) != '\0'))
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
	}
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::LINEAR_COMMENT)};
}
Parser::Token_res Parser::Lexer::AUTO_18(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "use", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	::Parser::Types::AUTO_18 data = _0;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_18, data)};
}
Parser::Token_res Parser::Lexer::NAME(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::Token_res _2;
	::Parser::bool_t success_3 = false;
	char _4;
	::Parser::bool_t success_5 = false;
	success_1 = false;
	if (!(!std::strncmp(pos + 0, "name", 4) && !(*(pos + 4)>='a' && *(pos + 4)<='z' || *(pos + 4)>='A' && *(pos + 4)<='Z' || *(pos + 4)>='0' && *(pos + 4)<='9' || *(pos + 4) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 4;
	skip_spaces(pos);
	success_3 = false;
	_2 = ID(pos);
	if (!(_2.status))
	{
		reportError(pos, "id ");
		return {};
	}
	success_3 = true;
	pos += _2.node.length();
	skip_spaces(pos);
	success_5 = false;
	if (!(*(pos + 0) == ';'))
	{
		reportError(pos, "\";\"");
		return {};
	}
	_4 = *(pos + 0);
	success_5 = true;
	pos += 1;
	::Parser::Types::NAME data = _2.node;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::NAME, data)};
}
