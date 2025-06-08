import cpuf.color;
import cpuf.dlib;
import cpuf.printf;
import cpuf.op;
import cpuf.dlib;
import CLI;
import init;
import args;
import corelib;
import logging;
import AST.Tree;
import ASTPass;
import LRParser;
import ELRParser;
import LALRParser;
import Converter;
import LLIR.Builder;
import LLIR;
import hash;
import Parser;
import AST.Builder;
import NFA;
import DFA;
import dstd;
import std;
import std.compat;
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
    args.initDumpDirectory();
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
        LEXICAL CHECKS SHALL GO ABOVE
        TREE CHANGES BELOW
    */
    AST::TreePass pass(ast);
    for (const auto &[name, value] : ast.getInitialItemSet()) {
        initialItemSet << "name<" << name << "> : " << value;
    }
    initialItemSet.close();
    cpuf::printf("dumps: {}", args.dump);
    if (args.shouldDump(args.dump_dir + "/first"))
        ast.printFirstSet(args.makeDumpPath("first"));
    if (args.shouldDump("follow"))
        ast.printFollowSet(args.makeDumpPath("follow"));
    if (args.dump_nfa_from_rule) {
        std::stringstream nfa_ss, dfa_ss;
        for (const auto &[name, value] : ast.getTreeMap()) {
            // if (corelib::text::isUpper(name.back()))
            //     continue;
            for (const auto &el : value.rule_members) {
                if (el.isOp()) {
                    NFA nfa(ast, el);
                    nfa.build();
                    nfa_ss << "\n-------rule \"" << name << "\"----------\n";
                    nfa_ss << nfa;
                    dfa_ss << "\n-------rule \"" << name << "\"----------\n";
                    DFA dfa(nfa);
                    dfa.build();
                    dfa_ss << dfa;
                }
            }

        }
        std::ofstream NFA_file(args.makeDumpPath("NFA"));
        std::ofstream DFA_file(args.makeDumpPath("DFA"));
        NFA_file << nfa_ss.str();
        DFA_file << dfa_ss.str();
        NFA_file.close();
        DFA_file.close();
    }
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
        auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, AST::Tree&>("getLRConverter");
        auto converter = std::unique_ptr<LRConverter_base>(converter_fun(LRIR, ast));
        converter->output(output_path);
    } else if (args.algorithm == Args::Algorithm::LALR) {
        LALRParser LALRIR(ast);
        // LALRIR.printTables("tables");
        // LALRIR.printCanonicalCollection("canonical_collection.txt");
        // LALRIR.printFirstSet("first_set.txt");
        // LALRIR.printFollowSet("follow_set.txt");
        auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, AST::Tree&>("getLRConverter");
        auto converter = std::unique_ptr<LRConverter_base>(converter_fun(LALRIR, ast));
        converter->output(output_path);
    } else if (args.algorithm == Args::Algorithm::ELR) {
        ELRParser ELRIR(ast);
        ELRIR.printTables("tables");
        ELRIR.printCanonicalCollection("canonical_collection.txt");
        ELRIR.printNfa("nfa");
        ELRIR.printDfa("dfa");
        auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, AST::Tree&>("getLRConverter");
        auto converter = std::unique_ptr<LRConverter_base>(converter_fun(ELRIR, ast));
        converter->output(output_path);
    } else if (args.algorithm == Args::Algorithm::LL) {
        LLIR::Builder builder(ast);
        auto IR = builder.get();
        if (args.shouldDump("IR"))
            IR.outputIRToFile(args.makeDumpPath("output_ir.txt"));
        auto converter_fun = converter_dlib.loadfun<LLConverter_base*, LLIR::IR&, AST::Tree&>("getLLConverter");
        auto converter = std::unique_ptr<LLConverter_base>(converter_fun(IR, ast));
        converter->outputIR(output_path);
    } else {
        throw Error("Unknown algorithm");
    }
    return 0;
}