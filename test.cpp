#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Tokenizator tokenizator;
    Parser::Parser parser;
    std::ifstream file("parser/parser/Rule.isc");
    std::stringstream ss;
    ss << file.rdbuf();
    std::string temp = ss.str();
    const char* str = temp.c_str();
    tokenizator.makeTokens(str);
    parser.main(tokenizator.tokens.begin());
    for (auto token : tokenizator.tokens) {
        std::cout << "name: " << Parser::TokenstoString(token.name) << std::endl;
    }
}