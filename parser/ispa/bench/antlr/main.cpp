#include <iostream>
#include <chrono>
#include "antlr4-runtime.h"
#include "ISPALexer.h"
#include "ISPAParser.h"

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: benchmark <input-file>\n";
        return 1;
    }

    std::ifstream stream(argv[1], std::ios::binary);
    std::string source(
        (std::istreambuf_iterator<char>(stream)),
        std::istreambuf_iterator<char>()
    );

    auto start = std::chrono::steady_clock::now();

    antlr4::ANTLRInputStream input(source);
    ISPALexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();

    ISPAParser parser(&tokens);
    parser.setBuildParseTree(false);
    auto* tree = parser.main();

    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "ANTLR total: " << elapsed.count() << " ms\n";
    std::cout << "Syntax errors: "
              << parser.getNumberOfSyntaxErrors()
              << "\n";

    (void)tree;
}