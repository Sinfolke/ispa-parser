#include <main.h>
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
std::forward_list<const char*> parameters_required {
    "lang"
};
std::forward_list<const char*> parameters_with_arguments {
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
    Parser::Tree rawTree;
    init();
    Args args(argc, argv);
    args.parse();

    // Register listener for --help
    if (args.has("help")) {
        printHelp();
        return 0;
    }
    if (args.has("version")) {
        cpuf::printf("%$\n", PROGRAM_VERSION);
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
        cpuf::printf("file: %$\n", file);
        std::string fileContent;
        try {
            fileContent = corelib::file::readFile(std::string(file));
        } catch(std::exception& e) {
            throw UError("Failed read file: %s", e.what());
        }
        // parse 
        Parser::Parser parser(fileContent.c_str());
        auto current_tree = parser.parse();
        // assign tree
        rawTree.insert(rawTree.end(), current_tree.begin(), current_tree.end());
    }
    if (args.has("dir")) {
        for (const auto dirPath : args.get("dir").values) {
            auto files = corelib::file::getFilesRecursively(dirPath, ".isc");
            for (auto file : files) {
                //cpuf::printf("file: %s\n", file);
                std::string content = corelib::file::readFile(file);
                Parser::Parser parser(content.c_str());
                auto current_tree = parser.parse();
                rawTree.push_back(Tokens::make_rule(Parser::Rules::id, file));
                rawTree.insert(rawTree.end(), current_tree.begin(), current_tree.end());
            }
        }
    }
    if (args.get("lang").values.size() > 1) {
        UWarning("Parameter 'lang' having more than 1 argument. Only first is used.").print();
    }
    /*
        LEXICAL CHECKS SHALL GO ABOVE
        TREE CHANGES BELOW
    */
    Tree tree(std::move(rawTree));
    //tree.resolveConflicts();
    auto use = tree.accamulate_use_data_to_map();
    dlib converter_dlib(std::string("libispa-converter-") + args.get("lang").first());  // get dynamically library for convertion
    auto name = std::any_cast<std::string>(use["name"].data);
    std::string algorithm = "LL";
    if (!args.get("a").empty()) {
        // if no argument is passed, use default
        algorithm = args.get("a").first();
    }
    if (algorithm == "LR") {
        LRParser LRIR(tree);
        LRIR.printTables("tables");
        LRIR.printCanonicalCollection("canonical_collection.txt");
        LRIR.printFirstSet("first_set.txt");
        LRIR.printFollowSet("follow_set.txt");
        auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, Tree&>("getLRConverter");
        auto converter = std::unique_ptr<LRConverter_base>(converter_fun(LRIR, tree));
        converter->output(name);
    } else if (algorithm == "LALR") {
        LALRParser LALRIR(tree);
        LALRIR.printTables("tables");
        LALRIR.printCanonicalCollection("canonical_collection.txt");
        LALRIR.printFirstSet("first_set.txt");
        LALRIR.printFollowSet("follow_set.txt");
        auto converter_fun = converter_dlib.loadfun<LRConverter_base*, LRParser&, Tree&>("getLRConverter");
        auto converter = std::unique_ptr<LRConverter_base>(converter_fun(LALRIR, tree));
        converter->output(name);
    } else if (algorithm == "ELR") {
        ELRParser ELRIR(tree);
        ELRIR.printCanonicalCollection("canonical_collection.txt");
        ELRIR.printNfa("nfa");
        ELRIR.printDfa("dfa");
    } else if (algorithm == "LL") {
        LLIR ir(tree.getRawTree());
        ir.makeIR();
        ir.optimizeIR();
        // Output to file
        ir.outputIRToFile("output_ir.txt");
        /*
            CONVERTION IS GOING HERE
    
        */
        auto converter_fun = converter_dlib.loadfun<LLConverter_base*, LLIR&, Tree&>("getLLConverter");
        auto converter = std::unique_ptr<LLConverter_base>(converter_fun(ir, tree));
        converter->outputIR(name);
    
        // IR test
    } else {
        throw UError("Unknown algorithm '%s'", algorithm);
    }
    return 0;
}