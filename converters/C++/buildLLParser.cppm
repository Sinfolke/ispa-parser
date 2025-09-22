
export module buildLLParser;
import LLIR.IR;
import LexerBuilder;
import AST.Tree;
import std;
extern "C" {
    export void buildLLParser(const std::string &name, const LLIR::IR &ir, const LexerBuilder &lexer_data, AST::Tree& ast);
}