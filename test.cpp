#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Lexer lexer;
    Parser::Parser parser;
    lexer.makeTokensFromFile("parser/parser/new/Rule.isc");
    std::ofstream ofile("tokens");
    if (!ofile) {
        std::cerr << "could not open token file\n";
        exit(1);
    }
    lexer.printTokens(ofile);
    std::cout << std::endl;
    auto tree = parser.parse(lexer);
    for (auto &el : tree) {
        std::cout << Parser::RulesToString(el.name()) << std::endl;
    }
}