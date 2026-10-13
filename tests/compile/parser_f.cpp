#include <Parser.h>
#include <iostream>
#include <fstream>
#include <variant>
int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " \"<input>\"\n";
        return 1;
    }
    std::ifstream inputf(argv[1]);
    if (!inputf.is_open()) {
        throw std::runtime_error("Failed to open input file");
    }
    std::string s((std::istreambuf_iterator<char>(inputf)), {});
    Parser::Lexer lexer;
    lexer.makeTokens(s);
    Parser::Parser parser;
    Parser::Types::main &node = parser.parse(lexer);
    std::ofstream of("tree.txt");
    of << node << "\n\n";
}