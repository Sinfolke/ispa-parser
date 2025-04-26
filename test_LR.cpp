#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Parser parser;
    // for LRTest2
    parser.parse("a[10] + b[20] * 4 ? a + 10 * 5 : b + 20 || b && c");

}