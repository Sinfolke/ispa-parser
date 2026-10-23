#include "parser.hpp"
int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " \"<input>\"\n";
        return 1;
    }

    std::string i;
    PyLexer lexer;
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
    PyRawParser::Parser parser;
    PyRawParser::Types::main node = parser.parse(i.c_str());
    for (const auto &e : parser.getErrors()) {
        std::cout << "Error: " << e.message << std::endl;
    }
    std::ofstream of("tree.txt");
    of << node << "\n\n";
    std::cout << "Successfully parsed and saved to tree.txt\n";
}