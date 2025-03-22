#include "Parser.h"
#include <fstream>
#include <sstream>
int main() {
    Parser::Tokenizator tokenizator;
    Parser::Parser parser;
    std::ifstream file("parser/parser/Rule.isc");
    std::stringstream ss;
    ss << file.rdbuf();
    const char* str = ss.str().c_str();
    tokenizator.makeTokens(str);
    parser.main(tokenizator.tokens.begin());
}