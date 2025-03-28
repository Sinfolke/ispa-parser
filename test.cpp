#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Tokenizator tokenizator;
    Parser::Parser parser;
    tokenizator.makeTokensFromFile("parser/parser/Rule.isc");
    for (auto token : tokenizator.getTokens()) {
        std::cout << Parser::TokenstoString(token.name()) << ", ";
    }
    std::cout << std::endl;
}