#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Parser parser;
    Parser::Lexer lexer("2 + 2 * 3");
    lexer.makeTokens();
    parser.parse(lexer);
}