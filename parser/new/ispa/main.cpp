#include "parser.h"
#include <iostream>
#include <fstream>
#include <variant>
#include <vector>
#include <queue>
#include <stdexcept>

int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " \"<input>\"\n";
        return 1;
    }

    std::string i;
    if (std::string(argv[1]) == "--file") {
        if (argc < 3) {
            std::cout << "Usage: " << argv[0] << " --file <path>\n";
            return 1;
        }
        std::ifstream inputf(argv[2]);
        if (!inputf.is_open()) {
            throw std::runtime_error("Failed to open input file");
        }
        std::string s((std::istreambuf_iterator<char>(inputf)), {});
        i = std::move(s);
    } else {
        i = argv[1];
    }
    IspaLexer lexer;
    Parser::Parser parser;
    lexer.makeTokens(i.c_str());
    Parser::Types::main node = parser.parse(lexer);
    std::ofstream of("tree.txt");
    of << node << "\n\n";
    std::cout << "Successfully parsed and saved to tree.txt\n";
}