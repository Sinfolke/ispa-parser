#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Tokenizator tokenizator;
    Parser::Parser parser;
    tokenizator.makeTokensFromFile("parser/parser/Rule.isc");
    std::ofstream ofile("tokens");
    for (auto token : tokenizator.getTokens()) {
        ofile << Parser::TokensToString(token.name()) << ": ";
        if (token.data().type() == typeid(Parser::str_t)) {
            ofile << '"' << std::any_cast<Parser::str_t>(token.data()) << '"';
        }
        ofile << '\n';
    }
    std::cout << std::endl;
}