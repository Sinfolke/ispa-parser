module Tests.AST;
import std;
import Parser;
import AST.Builder;
import AST.Pass;
namespace AST::Test {
    auto get(const char* file) -> AST::Tree {
        // READ FILE
        std::ifstream f(file);
        if (!f) {
            throw std::runtime_error("Failed to open file " + std::string(file));
        }
        std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
        f.close();
        // PARSE CONTENT
        Parser::Parser parser;
        auto AST = parser.parse(content.c_str());
        // GENERATE AST API
        AST::Builder builder(AST);
        builder.build();
        auto tree = builder.get();
        // Do a pass on tree
        TreePass pass(tree);
        return tree;
    }
}