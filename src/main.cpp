#include <main.h>
#include <args/args.h>

void printHelp() {
    cpuf::printf(R"(
usage: 
    [parameters] [individual files]
    Generally you can pass in --dir parameter to make the program parse every file in specified directory.
    Every parameter not being an argument is considered individual file to be parsed.
    %sNote that parameters with one '-' considered without arguments, and with -- considered with arguments%s

    -help show this help message
    -version show version
    --dir specify the directories where to locate sources
    --lang specify target language to build the parser for
    )", color::yellow, color::reset);
    cpuf::printf("\n");
}
std::forward_list<const char*> parameters_required {
    "lang"
};
std::forward_list<const char*> parameters_with_arguments {
    "lang"
};
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
    args.on("help-lang", [](Arg&) {
        cpuf::printf(R"(
        "cpp" - C++
        )");
        cpuf::printf("\n");
    });
    args.on("version", [](Arg&) {
        cpuf::printf("%$\n", PROGRAM_VERSION);
        exit(0);
    });
    args.parse();
    // throw error if required argument missing or not having parameters
    for (auto& el : parameters_required) {
        if (!args.has(el))
            throw UError("Missing parameter '%s'", el);
    }
    for (auto el : parameters_with_arguments) {
        if (args.has(el) && args.get(el).values.empty())
            throw UError("Parameter '%s' must have a parameter", el);
    }
    // get tree from sources
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
    replaceDublications(tree); // replace dublicated tokens (e.g when literal repeats token, replace it to token)
    literalsToToken(tree);    // get tokens from literals (e.g from string, hex or binary)
    
    // begin convertion here
    //dlib converter();
    // tokens must not be repeated. If a specific token already matches current literal, that token should be used in place of literal
    // if no tokens match current literal, a new token should be added that matches that literal and replace every place that kind of literal is used
    // 1. get source dir
    // 2. merge sources
    // 3. separate tokens and rules
    // 4. redirect to generator
    return 0;
}