#include <main.h>
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
    --lang specify target language to generate to. Use --help-lang to see all languages
    )", color::yellow, color::reset);
    cpuf::printf("\n");
}
std::forward_list<const char*> parameters_required {
    "lang"
};
std::forward_list<const char*> parameters_with_arguments {
    "lang"
};
std::unordered_map<const char*, int> parameters_with_fixes_arguments_amount {
    { "lang", 1 }
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
    tree.normalize(); // normalize tree
    tree.literalsToToken();     // get tokens from literals (e.g from string, hex or binary). This ensure proper tokenization process
    tree.sortByPriority();                 // sorts elements to get which should be placed on top. This ensures proper matching
    tree.addSpaceToken();
    tree.replaceDublications();          // replace dublicated tokens (e.g when token content is found somewhere else, replace it to token)
    tree.inlineTokens();                 // inline tokens to make sure that every token is used only once

    auto use = tree.accamulate_use_data_to_map();
    auto use_places = tree.getUsePlacesTable();
    auto [tokens, rules] = tree.getTokenAndRuleNames();

    // convert tree into IR
    IR ir(tree.getRawTree());
    ir.makeIR();
    ir.optimizeIR();
    // Output to file
    ir.outputIRToFile("output_ir.txt");
    /*
        CONVERTION IS GOING HERE

    */
    auto [datablocks_tokens, datablocks_rules] = tree.get_data_blocks(ir);
    auto lexer_code = tree.getCodeForLexer(use_places, ir);
    dlib converter_dlib(std::string("libispa-converter-") + args.get("lang").first());  // get dynamically library for convertion
    auto converter_fun = converter_dlib.loadfun<IR*, IR&, IR&, const IR::node_ret_t &, const std::vector<std::string>&, const std::vector<std::string>&, data_block_t&, data_block_t&, use_prop_t>("getConverter");
    auto converter = converter_fun(ir, lexer_code.code, lexer_code.success_var, tokens, rules, datablocks_tokens, datablocks_rules, use);
    converter->outputIRToFile(std::any_cast<std::string>(use["name"].data));
    // write to file
    // invoke convertion
    //convert(tree, converter);
    // begin convertion here
    // tokens must not be repeated. If a specific token already matches current literal, that token should be used in place of literal
    // if no tokens match current literal, a new token should be added that matches that literal and replace every place that kind of literal is used
    // 1. get source dir
    // 2. merge sources
    // 3. separate tokens and rules
    // 4. redirect to generator
    return 0;
}