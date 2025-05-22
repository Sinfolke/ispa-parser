import cpuf.color;
import cpuf.dlib;
import cpuf.printf;
import cpuf.dlib;
import CLI;
import init;
import args;
import corelib;
import logging;
import AST;
import ASTPass;
import LRParser;
import ELRParser;
import LALRParser;
import Converter;
import LLIRBuilder;
import LLIR;
import hash;
import Parser;
import TreeAPI;
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
std::vector<const char*> parameters_required {
    "lang"
};
std::vector<const char*> parameters_with_arguments {
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
    std::vector<Parser::Rule> modules;
    auto args = init(argc, argv);

    if (args.version) {
        cpuf::printf("%$\n", PROGRAM_VERSION);
        return 0;
    }
    // get tree from sources
    if (args.files.empty() && args.dir.empty())
        throw UError("No input files");
    for (const auto file : args.files) {
        cpuf::printf("file: %$\n", file);
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
            std::string dir = dirPath;
            auto files = corelib::file::getFilesRecursively(dir, ".isc");
            for (auto file : files) {
                cpuf::printf("file {}\n", file.c_str());
                //cpuf::printf("file: %s\n", file);
                std::string content = corelib::file::readFile(file);
                Parser::Parser parser;
                auto current_tree = parser.parse(content.c_str());
                for (const auto &err : parser.getErrors()) {
                    cpuf::printf("Parser error[{}, {}]: %s\n", err.line, err.column, err.message.c_str());
                }
                modules.push_back(current_tree);
            }
        }
    }
    AST ast(modules);
    std::ofstream treeAPIOutput("treeAPI.txt");
    for (const auto &[name, value] : ast.getTreeMap()) {
        treeAPIOutput << "name<" << name << "> : " << value;
    }
    treeAPIOutput.close();
    /*
        LEXICAL CHECKS SHALL GO ABOVE
        TREE CHANGES BELOW
    */
    ASTPass treePass(ast);

    //tree.resolveConflicts();
    dlib converter_dlib(std::string("libispa-converter-") + args.language);  // get dynamically library for convertion
    auto name = ast.getName();
    std::string opath;
    if (!args.output.empty()) {
        opath = args.output;
    }
    std::filesystem::path output_path = opath;
    output_path.append(name);
    if (args.algorithm == Args::Algorithm::LR0) {
        LRParser LRIR(ast);
        // LRIR.printTables("tables");
        LRIR.printCanonicalCollection("canonical_collection.txt");
        // LRIR.printFirstSet("first_set.txt");
        // LRIR.printFollowSet("follow_set.txt");
        auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, AST&>("getLRConverter");
        auto converter = std::unique_ptr<LRConverter_base>(converter_fun(LRIR, ast));
        converter->output(output_path);
    } else if (args.algorithm == Args::Algorithm::LALR) {
        LALRParser LALRIR(ast);
        // LALRIR.printTables("tables");
        // LALRIR.printCanonicalCollection("canonical_collection.txt");
        // LALRIR.printFirstSet("first_set.txt");
        // LALRIR.printFollowSet("follow_set.txt");
        auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, AST&>("getLRConverter");
        auto converter = std::unique_ptr<LRConverter_base>(converter_fun(LALRIR, ast));
        converter->output(output_path);
    } else if (args.algorithm == Args::Algorithm::ELR) {
        ELRParser ELRIR(ast);
        ELRIR.printTables("tables");
        ELRIR.printCanonicalCollection("canonical_collection.txt");
        ELRIR.printFirstSet("first_set.txt");
        ELRIR.printFollowSet("follow_set.txt");
        ELRIR.printNfa("nfa");
        ELRIR.printDfa("dfa");
        auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, AST&>("getLRConverter");
        auto converter = std::unique_ptr<LRConverter_base>(converter_fun(ELRIR, ast));
        converter->output(output_path);
    } else if (args.algorithm == Args::Algorithm::LL) {
        LLIR::Builder builder(ast);
        auto IR = builder.get();
        IR.outputIRToFile("output_ir.txt");
        auto converter_fun = converter_dlib.loadfun<LLConverter_base*, LLIR::IR&, AST&>("getLLConverter");
        auto converter = std::unique_ptr<LLConverter_base>(converter_fun(IR, ast));
        converter->outputIR(output_path);
    } else {
        throw Error("Unknown algorithm");
    }
    return 0;
}