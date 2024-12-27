#include <main.h>
#include <args/args.h>

void printHelp() {
    std::cout << "Usage: ./program [options]\n"
              << "Options:\n"
              << "  --help      Show this help message\n";
}

int main(int argc, char** argv) {
    init();
    Args args(argc, argv);

    // Register listener for --help
    args.on("help", [](Arg&) {
        printHelp();
        exit(0);
    });

    // Parse arguments
    args.parse();
    return 0;
}