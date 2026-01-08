import cpuf.color;
import cpuf.dlib;
import cpuf.printf;
import cpuf.op;
import Parser;
import CLI;
import init;
import args;
import corelib;
import logging;
import Dump;
import AST.Tree;
import AST.Pass;
import LRParser;
import ELRParser;
import LALRParser;
import LLIR.Builder;
import LLIR.IR;
import LangRepr.Construct;
import LangRepr.Converter;
import hash;
import AST.Builder;
import fcdt;
import LexerBuilder;
import dstd;
import std;

void printHelp() {
    cpuf::printf(R"(
usage: 
    [parameters] [individual files]
    -help show this help message
    -version show version
    --dir specify the directories where to locate sources
    --lang specify target language to generate to. Use --help-lang to see all languages
    )", color::yellow, color::reset);
    cpuf::printf("\n");
}
stdu::vector<const char*> parameters_required {
    "lang"
};
stdu::vector<const char*> parameters_with_arguments {
    "lang", "a"
};
std::unordered_map<const char*, int> parameters_with_fixes_arguments_amount {
    { "lang", 1 },
    { "a", 1 }
};
// void printData(const char* data, int tabs);
// void printData(const std::string data, int tabs);
// void printData(const ::Parser::Rule data, int tabs);
// void printData(const std::unordered_map<const char*, std::any> data, int tabs);
// void printData(const std::unordered_map<std::string, std::any> data, int tabs);
int main(int argc, char** argv) {
    stdu::vector<Parser::Rule> modules;
    auto args = init(argc, argv);
    dumper.setArgsPointer(&args);
    dumper.setDumpDirectory(args.dump_dir);
    dumper.initDumpDirectory();
    logger.clearLogDirectory();
    if (args.version) {
        cpuf::printf("%$\n", PROGRAM_VERSION);
        return 0;
    }
    // get tree from sources
    if (args.files.empty() && args.dir.empty())
        throw UError("No input files");
    for (const auto file : args.files) {
        cpuf::printf("file: {}\n", file);
        std::string fileContent;
        try {
            fileContent = corelib::file::readFile(std::string(file));
        } catch(std::exception& e) {
            throw UError("Failed read file: %s", e.what());
        }
        // parse
        Parser::Parser parser;
        auto current_tree = parser.parse(fileContent.c_str());
        // assign tree
        modules.push_back(current_tree);
    }
    if (!args.dir.empty()) {
        for (const auto &dirPath : args.dir) {
            auto files = corelib::file::getFilesRecursively(dirPath, ".isc");
            for (auto file : files) {
                cpuf::printf("file {}", file.c_str());
                //cpuf::printf("file: %s\n", file);
                std::string content = corelib::file::readFile(file);
                Parser::Parser parser;
                auto current_tree = parser.parse(content.c_str());
                for (const auto &err : parser.getErrors()) {
                    cpuf::printf("Parser error[{}, {}]: {}", err.line, err.column, err.message.c_str());
                }
                modules.push_back(current_tree);
            }
        }
    }
    // init DFA and NFA files if dump DFA and NFA
    if (dumper.shouldDump("NFA"))
        std::ofstream dumpFile(dumper.makeDumpPath("NFA"), std::ios::trunc);
    if (dumper.shouldDump("DFA"))
        std::ofstream dumpFile(dumper.makeDumpPath("DFA"), std::ios::trunc);
    AST::Builder ast_builder(modules);
    ast_builder.build();
    auto ast = ast_builder.get();
    std::ofstream treeAPIO("treeAPI.txt");
    std::ofstream initialItemSet("tree.txt");
    for (const auto &[name, value] : ast.getTreeMap()) {
        treeAPIO << "name<" << name << "> : " << value;
    }
    treeAPIO.close();
    /*
        LEXICAL CHECKS SHOULD GO ABOVE
        TREE CHANGES BELOW
    */
    AST::TreePass pass(ast);
    for (const auto &[name, value] : ast.getInitialItemSet()) {
        initialItemSet << "name<" << name << "> : " << value;
    }
    initialItemSet.close();
    if (dumper.shouldDump("first"))
        ast.printFirstSet(dumper.makeDumpPath("first"));
    if (dumper.shouldDump("follow"))
        ast.printFollowSet(dumper.makeDumpPath("follow"));
    dlib converter_dlib(std::string("libispa-converter-") + args.language_str);  // get dynamically library for conversion
    std::string opath;
    if (!args.output.empty()) {
        opath = args.output;
    }
    std::filesystem::path output_path = opath;
    output_path.append(ast.getName());
    LexerBuilder lexer_data(ast);
    lexer_data.build();
    lexer_data.getFCDT().print();
    std::ofstream dumpDFAFile(dumper.makeDumpPath("DFA"));
    if (!dumpDFAFile.is_open())
        throw Error("failed to open DFA for dump");
    for (const auto &dfa : lexer_data.getDFAS()) {
        dumpDFAFile << dfa;
    }
    dumpDFAFile.close();
    // if (args.algorithm == Args::Algorithm::LR0) {
    //     LRParser LRIR(ast);
    //     // LRIR.printTables("tables");
    //     LRIR.printCanonicalCollection("canonical_collection.txt");
    //     // LRIR.printFirstSet("first_set.txt");
    //     // LRIR.printFollowSet("follow_set.txt");
    //     auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, AST::Tree&>("getLRConverter");
    //     auto converter = std::unique_ptr<LRConverter_base>(converter_fun(LRIR, ast));
    //     converter->output(output_path);
    // } else if (args.algorithm == Args::Algorithm::LALR) {
    //     LALRParser LALRIR(ast);
    //     // LALRIR.printTables("tables");
    //     // LALRIR.printCanonicalCollection("canonical_collection.txt");
    //     // LALRIR.printFirstSet("first_set.txt");
    //     // LALRIR.printFollowSet("follow_set.txt");
    //     auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, AST::Tree&>("getLRConverter");
    //     auto converter = std::unique_ptr<LRConverter_base>(converter_fun(LALRIR, ast));
    //     converter->output(output_path);
    // } else if (args.algorithm == Args::Algorithm::ELR) {
    //     ELRParser ELRIR(ast);
    //     ELRIR.printTables("tables");
    //     ELRIR.printCanonicalCollection("canonical_collection.txt");
    //     ELRIR.printNfa("nfa");
    //     ELRIR.printDfa("dfa");
    //     auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, AST::Tree&>("getLRConverter");
    //     auto converter = std::unique_ptr<LRConverter_base>(converter_fun(ELRIR, ast));
    //     converter->output(output_path);
    if (args.algorithm == Args::Algorithm::LL) {
        LLIR::Builder builder(ast, false);
        auto IR = builder.get();
        auto repr = LangRepr::Construct::construct(std::move(lexer_data), std::move(IR), args.language, ast.getName());
        LangRepr::Converter converter(repr, args.language_str, ast.getName());
        converter.build();
        std::ofstream out("Parser.h");
        out << converter.get().get();
    }
    // } else {
    //     throw Error("Unknown algorithm");
    // }
    return 0;
}