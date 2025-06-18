
export module buildLLParser;
import LLIR;
import LexerBuilder;
import AST.Tree;
import std;
export void buildLLParser(const std::filesystem::path name, const LLIR::IR &ir, const LexerBuilder &lexer_data, AST::Tree& ast);