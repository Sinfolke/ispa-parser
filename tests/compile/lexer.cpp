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
    auto tokens = lexer.makeTokens(argv[1]);
    // for (auto token : tokens) {
    //     std::cout << token.index() << "\n";
    //     if (std::holds_alternative<Parser::Types::TEMPLATED_TYPE>(token)) {
    //         const auto tt = std::get<Parser::Types::TEMPLATED_TYPE>(token);
    //         std::cout << "op: " <<  tt.op << "type: " << tt.type << "\n";
    //     }
    // }
}
// int main() {
//     Parser::Lexer lexer;
//     Parser::Parser parser;
//     lexer.makeTokensFromFile("parser/parser/rule.isc");
//     std::ofstream ofile("tokens");
//     if (!ofile) {
//         std::cerr << "could not open token file\n";
//         exit(1);
//     }
//     lexer.printTokens(ofile);
//     auto errors = lexer.getErrors();
//     for (auto error : errors) {
//         printf("Lexer: %zu:%zu: %s\n", error.line, error.column, error.message.c_str());
//     }
//     std::cout << std::endl;
//     auto tree = parser.parse(lexer);
//     auto parser_errors = parser.getErrors();
//     printf("errors size(): %zu\n", parser_errors.size());
//     for (auto error : parser_errors) {
//         printf("Parser: %zu:%zu(%zu): %s\n", error.line, error.column, error.pos, error.message.c_str());
//     }
//     std::ofstream file("AST");
//     parser.printAST(file);
// }