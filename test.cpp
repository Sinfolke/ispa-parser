#include "Parser.h"
#include <fstream>
#include <sstream>
int main() {
    Parser::Tokenizator tokens;
    std::ifstream file("parser/parser/Rule.isc");
    std::stringstream ss;
    ss << file.rdbuf();
    const char* str = ss.str().c_str();
    tokens.makeTokens(str);
}