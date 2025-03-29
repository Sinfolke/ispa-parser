#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Tokenizator tokenizator;
    Parser::Parser parser;
    tokenizator.makeTokensFromFile("parser/parser/Rule.isc");
    for (auto token : tokenizator.getTokens()) {
        std::cout << Parser::TokenstoString(token.name()) << ": ";
        if (token.data().type() == typeid(Parser::str_t)) {
            std::cout << '"' << std::any_cast<Parser::str_t>(token.data()) << '"';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}