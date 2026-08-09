#include <Parser.h>
#include <iostream>
#include <ostream>
#include <variant>

int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " \"<input>\"\n";
        return 1;
    }
    Parser::Lexer lexer;
    Parser::Parser parser;
    auto tokens = lexer.makeTokens(argv[1]);
    parser.parse(tokens);
}