#include "Parser.h"
#include <fstream>
#include <sstream>
int main() {
    Parser::Tokenizator tokenizator;
    Parser::Parser parser;
    std::ifstream file("parser/parser/Rule.isc");
    std::stringstream ss;
    ss << file.rdbuf();
    std::string temp = ss.str();  // ✅ Store the string first
    const char* str = temp.c_str(); // Safe, as temp lives long enough
    tokenizator.makeTokens(str);
    parser.main(tokenizator.tokens.begin());
}