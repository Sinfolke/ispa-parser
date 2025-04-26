#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Parser parser;
    parser.parse("1 + 2 * 3");
}