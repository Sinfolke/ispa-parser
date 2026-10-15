#include <Parser.h>
#include <iostream>
#include <ostream>
#include <variant>
int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " \"<input>\"\n";
        return 1;
    }
    Parser::Parser parser;
    Parser::Types::main &node = parser.parse(argv[1]);
    std::cout << node.to_string() << std::endl;
}