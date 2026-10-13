#include <Parser.h>
#include <iostream>
#include <fstream>
#include <variant>
int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " \"<input>\"\n";
        return 1;
    }
    Parser::Lexer lexer;
    lexer.makeTokens(argv[1]);
    Parser::Parser parser;
    Parser::Types::main &node = parser.parse(lexer);
    std::ofstream of("tree.txt");
    of << node << "\n\n";
    for (const auto &token : lexer.getTokens()) {
        std::cout << token << std::endl;
    }
}