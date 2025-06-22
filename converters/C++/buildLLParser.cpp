import std;
import LexerConverter;
import LexerBuilder;
import LLConverter;
import LLHeader;
import LLIR;
import AST.Tree;
extern "C" void buildLLParser(const std::filesystem::path name, const LLIR::IR &ir, const LexerBuilder &lexer_data, AST::Tree& ast) {
    std::ofstream cpp(name.string() + ".cpp");
    std::ofstream h(name.string() + ".h");
    if (!cpp) {
        throw std::runtime_error("Unable to open file for writing: " + name.filename().string() + ".cpp");
    }
    if (!h) {
        throw std::runtime_error("Unable to open file for writing: " + name.filename().string() + ".h");
    }
    std::ostringstream cpp_ss, h_ss;
    LexerConverter lexer(ast, cpp_ss, h_ss, lexer_data, name.string());
    LLConverter parser(ir, ast, name.string());
    // print Lexer (into cpp file)
    parser.addHeader(cpp_ss);
    lexer.output();
    parser.addStandardFunctionsLexer(cpp_ss);
    parser.addStandardFunctionsParser(cpp_ss);
    parser.addGetFunctions(cpp_ss, parser.getDataBlockToken(), parser.getDataBlockRules());
    parser.addDFATables(cpp_ss);

    // print header (including Parser)
    parser.createLibrary(h_ss, name.string());
    parser.createIncludes(h_ss);
    parser.createDefaultTypes(h_ss);
    parser.createNamespace(h_ss, name.string());
    parser.createTypes(h_ss, name.string());
    parser.createTokensEnum(h_ss, parser.getTokens());
    parser.createRulesEnum(h_ss, parser.getRules());
    parser.getTypesFromStdlib(h_ss);
    parser.createToStringFunction(parser.getTokens(), parser.getRules(), h_ss);
    parser.createDFATypes(h_ss);
    parser.createTypesNamespace(h_ss, parser.getDataBlockToken(), parser.getDataBlockRules());
    parser.create_get_namespace(h_ss, name.string(), parser.getDataBlockToken(), parser.getDataBlockRules());
    lexer.outputHeader();
    parser.create_parser_header(h_ss, ir.getDfas().getDFAS());
    parser.setIndentLevet(2);
    parser.writeRules(h_ss);
    parser.setIndentLevet(1);
    parser.close_parser_header(h_ss);
    parser.close_library(h_ss, name.string());
    cpp << cpp_ss.str();
    h << h_ss.str();
}
