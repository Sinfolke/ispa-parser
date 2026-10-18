#include <Parser.h>
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
    Parser::Parser parser;
    Parser::Types::main node = parser.parse(i.c_str());
    std::ofstream of("tree.txt");
    of << node << "\n\n";
    std::cout << "Successfully parsed and saved to tree.txt\n";
    // IspaLexer hand;           // with the overrides
    // Parser::Lexer dfa;        // generated DFA only
    // auto a = IspaLexer::lazy_iterator(hand, i.c_str());
    // auto b = Parser::Lexer::lazy_iterator(dfa, i.c_str());
    //
    // for (size_t i = 0;; ++i, ++a, ++b) {
    //     auto ta = *a;
    //     auto tb = *b;
    //     if (ta.index() != tb.index() || ta.meta().length() != tb.meta().length() || (!ta.empty() && !tb.empty() && ta.to_string() != tb.to_string())) {
    //         std::cerr << "first diff at token " << i << "\n"
    //                   << " hand: type=" << ta.index() << " len=" << ta.meta().length() << " val=[" << (ta.empty() ? "<empty>" : ta.to_string()) << "]\n"
    //                   << " dfa : type=" << tb.index() << " len=" << tb.meta().length() << " val=[" << (tb.empty() ? "<empty>" : tb.to_string()) << "]\n";
    //         break;
    //     }
    //     if (a.isEnd() || b.isEnd()) break;
    // }
}
