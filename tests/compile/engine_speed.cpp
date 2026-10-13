#include <Parser.h>
#include <iostream>
#include <fstream>
int main(int argc, const char** argv) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " \"<input>\" <number of iterations>\n";
        return 1;
    }
    for (std::size_t i = 0; i < std::stoi(argv[2]); ++i) {
        Parser::Lexer lexer;
        lexer.makeTokens(argv[1]);
        Parser::Parser parser;
        parser.parse(lexer);
    }
}
