#include <main.h>
#include <args/args.h>

void printHelp() {
    cpuf::printf("usage\n");
}


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
        auto fileContent = readFile(std::string(file));
        // parse 
        Parser::Parser parser(fileContent.c_str());
        auto current_tree = parser.parse();
        // assign tree
        tree.insert(tree.end(), current_tree.begin(), current_tree.end());
    }
    if (args.has("dir")) {
        cpuf::printf("Parsing all files in dir\n");
        for (const auto dirPath : args.get("dir").values) {
            cpuf::printf("dir: %$\n", dirPath);
            auto files = getFilesRecursively(dirPath, ".isc");
            for (auto file : files) {
                std::string content = readFile(file);
                Parser::Parser parser(content.c_str());
                auto current_tree = parser.parse();
                tree.insert(tree.end(), current_tree.begin(), current_tree.end());
            }
        }
    }
    // 1. get source dir
    // 2. merge sources
    // 3. separate tokens and rules
    // 4. redirect to generator
    return 0;
}