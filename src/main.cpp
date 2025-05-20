#include <cpuf/color.h>
#include <cpuf/dlib.h>
#include <cpuf/operator.h>
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
import fmt;
import hash;
import Parser;
import TreeAPI;
import std;
void printHelp() {
    fmt::printf(R"(
usage: 
    [parameters] [individual files]
    -help show this help message
    -version show version
    --dir specify the directories where to locate sources
    --lang specify target language to generate to. Use --help-lang to see all languages
    )", color::yellow, color::reset);
    fmt::printf("\n");
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
    init();
    Args args(argc, argv);
    args.parse();

    // Register listener for --help
    if (args.has("help")) {
        printHelp();
        return 0;
    }
    if (args.has("version")) {
        fmt::printf("%$\n", PROGRAM_VERSION);
        return 0;
    }
    // throw error if required argument missing or not having parameters
    for (auto& el : parameters_required) {
        if (!args.has(el))
            throw UError("Missing parameter '%s'", el);
    }
    for (auto el : parameters_with_arguments) {
        if (args.has(el) && args.get(el).values.empty())
            throw UError("Parameter '%s' must have a parameter", el);
    }
    for (auto pair : parameters_with_fixes_arguments_amount) {
        if (args.has(pair.first) && args.get(pair.first).values.size() > pair.second)
            UWarning("Parameter %s expects maximum %d arguments", pair.first, pair.second).print();
    }
    // get tree from sources
    if (!args.unnamed().size() && !args.has("dir"))
        throw UError("No input files");
    for (const auto file : args.unnamed()) {
        fmt::printf("file: %$\n", file);
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
    if (args.has("dir")) {
        for (const auto dirPath : args.get("dir").values) {
            auto files = corelib::file::getFilesRecursively(dirPath, ".isc");
            for (auto file : files) {
                printf("file %s\n", file.c_str());
                //cpuf::printf("file: %s\n", file);
                std::string content = corelib::file::readFile(file);
                Parser::Parser parser;
                auto current_tree = parser.parse(content.c_str());
                for (const auto &err : parser.getErrors()) {
                    printf("Parser error[%zu, %zu]: %s\n", err.line, err.column, err.message.c_str());
                }
                modules.push_back(current_tree);
            }
        }
    }
    if (args.get("lang").values.size() > 1) {
        UWarning("Parameter 'lang' having more than 1 argument. Only first is used.").print();
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
    dlib converter_dlib(std::string("libispa-converter-") + args.get("lang").first());  // get dynamically library for convertion
    auto name = ast.getName();
    std::string algorithm = "LL";
    std::string opath;
    if (!args.get("a").empty()) {
        // if no argument is passed, use default
        algorithm = args.get("a").first();
    }
    if (!args.get("o").empty()) {
        opath = args.get("o").first();
    }
    std::filesystem::path output_path = opath;
    output_path.append(name);
    if (algorithm == "LR") {
        LRParser LRIR(ast);
        // LRIR.printTables("tables");
        LRIR.printCanonicalCollection("canonical_collection.txt");
        // LRIR.printFirstSet("first_set.txt");
        // LRIR.printFollowSet("follow_set.txt");
        auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, AST&>("getLRConverter");
        auto converter = std::unique_ptr<LRConverter_base>(converter_fun(LRIR, ast));
        converter->output(output_path);
    } else if (algorithm == "LALR") {
        LALRParser LALRIR(ast);
        // LALRIR.printTables("tables");
        // LALRIR.printCanonicalCollection("canonical_collection.txt");
        // LALRIR.printFirstSet("first_set.txt");
        // LALRIR.printFollowSet("follow_set.txt");
        auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, AST&>("getLRConverter");
        auto converter = std::unique_ptr<LRConverter_base>(converter_fun(LALRIR, ast));
        converter->output(output_path);
    } else if (algorithm == "ELR") {
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
    } else if (algorithm == "LL") {
        LLIR::Builder builder(ast);
        auto IR = builder.get();
        IR.outputIRToFile("output_ir.txt");
        auto converter_fun = converter_dlib.loadfun<LLConverter_base*, LLIR::IR&, AST&>("getLLConverter");
        auto converter = std::unique_ptr<LLConverter_base>(converter_fun(IR, ast));
        converter->outputIR(output_path);
    } else {
        throw UError("Unknown algorithm '%s'", algorithm);
    }
    return 0;
}