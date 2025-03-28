#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Tokenizator tokenizator;
    Parser::Parser parser;
    tokenizator.makeTokensFromFile("parser/parser/Rule.isc");
    parser.main(tokenizator.tokens.begin());
    for (auto token : tokenizator.tokens) {
        std::cout << Parser::TokenstoString(token.name) << ", ";
    }
    std::cout << std::endl;
}