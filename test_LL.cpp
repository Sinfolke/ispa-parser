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
        printf("Lexer: %zu:%zu: %s\n", error.line, error.column, error.message.c_str());
    }
    std::cout << std::endl;
    auto tree = parser.parse(lexer);
    for (auto &el : tree) {
        std::cout << Parser::RulesToString(el.name()) << std::endl;\
    }
    auto parser_errors = parser.getErrors();
    printf("errors size(): %zu, tree size: %zu\n", parser_errors.size(), tree.size());
    for (auto error : parser_errors) {
        printf("Parser: %zu:%zu: %s\n", error.line, error.column, error.message.c_str());
    }
    for (auto member : tree) {
        printf("name: %s\n", Parser::RulesToString(member.name()).c_str());
    }
}