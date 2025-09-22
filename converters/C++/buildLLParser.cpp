import std;
import LexerConverter;
import LexerBuilder;
import LLConverter;
import LLHeader;
import LLIR.IR;
import StateArrayBuilder;
import AST.Tree;
extern "C" void buildLLParser(const std::string &name, const LLIR::IR &ir, const LexerBuilder &lexer_data, AST::Tree& ast) {
    std::ofstream cpp(name + ".cpp");
    std::ofstream h(name + ".h");
    if (!cpp) {
        throw std::runtime_error("Unable to open file for writing: " + name + ".cpp");
    }
    if (!h) {
        throw std::runtime_error("Unable to open file for writing: " + name + ".h");
    }
    std::ostringstream cpp_ss, h_ss;
    auto states_pair = ir.getDfas().getStateSet();
    LexerConverter lexer(ast, cpp_ss, h_ss, lexer_data, name);
    LLConverter parser(ir, ast, name);
    auto data_block_token = lexer_data.getDataBlocks();
    // print Lexer (into cpp file)
    parser.addHeader(cpp_ss);
    lexer.output();
    parser.addStandardFunctionsLexer(cpp_ss);
    parser.addStandardFunctionsParser(cpp_ss);
    parser.addGetFunctions(cpp_ss, data_block_token, parser.getDataBlockRules());
    parser.addDFATables(cpp_ss, states_pair);

    // print header (including Parser)
    parser.createLibrary(h_ss, name);
    parser.createIncludes(h_ss);
    parser.createDefaultTypes(h_ss);
    parser.createNamespace(h_ss, name);
    parser.createTypes(h_ss, name);
    parser.createTokensEnum(h_ss, parser.getTokens());
    parser.createRulesEnum(h_ss, parser.getRules());
    parser.getTypesFromStdlib(h_ss);
    parser.createToStringFunction(parser.getTokens(), parser.getRules(), h_ss);
    parser.createDFATypes(h_ss);
    parser.createTypesNamespace(h_ss, data_block_token, parser.getDataBlockRules());
    parser.create_get_namespace(h_ss, name, data_block_token, parser.getDataBlockRules());
    lexer.outputHeader();
    parser.create_parser_header(h_ss, ir.getDfas(), states_pair);
    parser.setIndentLevet(2);
    parser.writeRules(h_ss);
    parser.setIndentLevet(1);
    parser.close_parser_header(h_ss);
    parser.close_library(h_ss, name);
    cpp << cpp_ss.str();
    h << h_ss.str();
}
