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
    if (!args.unnamed().size())
        throw UError("No input files");
    
    for (const auto file : args.unnamed()) {
        cpuf::printf("file: %$\n", file);
        std::ifstream ifs(file);
        // Get the file size
        std::streamsize fileSize = ifs.tellg();
        ifs.seekg(0, std::ios::beg);

        // Read the file content into a string
        std::string fileContent(static_cast<size_t>(fileSize), '\0');
        if (!ifs.read(fileContent.data(), fileSize)) {
            throw Error("Failed to read file %$", file);
        }
        // parse 
        Parser::Parser parser(fileContent.c_str());
        auto current_tree = parser.parse();
        // assign tree
        tree.insert(tree.end(), current_tree.begin(), current_tree.end());
    }
    // 1. get source dir
    // 2. merge sources
    // 3. separate tokens and rules
    // 4. redirect to generator
    return 0;
}