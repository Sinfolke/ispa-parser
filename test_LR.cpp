#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Parser parser;
    // parser.parse("a[10] + b[20] * 4 ? a + 10 * 5 : b + 20 || b && c");
    //parser.parse("10 + 20 * 5");
    //parser.parse("int a = 10;");
    // parser.parse("int a = 10;");
    std::ifstream file("parser/parser/new/Rule.isc");
    std::stringstream oss;
    oss << file.rdbuf();
    auto str = oss.str();
    parser.parse(str.c_str());
}