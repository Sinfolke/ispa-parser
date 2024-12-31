#include <main.h>
#include <args/args.h>

void printHelp() {
    cpuf::printf(R"(
usage: 
    [parameters] [individual files]
    Generally you can pass in --dir parameter to make the program parse every file in specified directory.
    Every parameter not being an argument is considered individual file to be parsed.
    %sNote that parameters with one '-' considered without arguments, and with -- considered with arguments until next parameter encountered %s

    --help show this help message
    --version show version
    --dir specify the directories where to locate sources
    )", color::yellow, color::reset);
    cpuf::printf("\n");
}

// void printData(const char* data, int tabs);
// void printData(const std::string data, int tabs);
// void printData(const ::Parser::Rule data, int tabs);
// void printData(const std::unordered_map<const char*, std::any> data, int tabs);
// void printData(const std::unordered_map<std::string, std::any> data, int tabs);
int main(int argc, char** argv) {
    init();
    Args args(argc, argv);

    // Register listener for --help
    args.on("help", [](Arg&) {
        printHelp();
        exit(0);
    });
    args.on("version", [](Arg&) {
        cpuf::printf("%$\n", PROGRAM_VERSION);
        exit(0);
    });
    args.parse();
    Parser::Tree tree;
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
        tree.insert(tree.end(), current_tree.begin(), current_tree.end());
    }
    if (args.has("dir")) {
        for (const auto dirPath : args.get("dir").values) {
            auto files = corelib::file::getFilesRecursively(dirPath, ".isc");
            for (auto file : files) {
                cpuf::printf("Parsing file %$\n", file);
                std::string content = corelib::file::readFile(file);
                Parser::Parser parser(content.c_str());
                auto current_tree = parser.parse();
                tree.insert(tree.end(), current_tree.begin(), current_tree.end());
            }
        }
    }
    /*
        LEXICAL CHECKS SHALL GO ABOVE
        CONVERTION IS STARTING HERE

    */
    literalsToToken(tree);    // get tokens from literals (e.g from string, hex or binary)

    // now we have tree of all files
    // 1. get source dir
    // 2. merge sources
    // 3. separate tokens and rules
    // 4. redirect to generator
    return 0;
}