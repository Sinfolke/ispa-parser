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
    auto errors = lexer.getErrors();
    for (auto error : errors) {
        printf("%zu:%zu: %s\n", error.line, error.column, error.message.c_str());
    }
    std::cout << std::endl;
    auto tree = parser.parse(lexer);
    for (auto &el : tree) {
        std::cout << Parser::RulesToString(el.name()) << std::endl;\
    }
}