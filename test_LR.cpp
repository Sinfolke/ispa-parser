#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Parser parser;
    //Parser::Lexer lexer("x = 5 + 3 * (2 ^ 3) - y && z == 10 || foo(bar, baz) && (x != y)");
    parser.parse("2 + 2 * 3");
}