#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Lexer lexer;
    Parser::Parser parser;
    lexer.makeTokensFromFile("parser/parser/Rule.isc");
    std::ofstream ofile("tokens");
    if (!ofile) {
        std::cerr << "could not open token file\n";
        exit(1);
    }
    lexer.printTokens(ofile);
    std::cout << std::endl;
    std::ifstream file("parser/parser/Rule.isc");
    if (!file.is_open()) {
        std::cerr << "could not open input file\n";
        exit(1);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    auto tree = parser.parse(buffer.str());
}