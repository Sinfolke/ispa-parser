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
    // 1. get source dir
    // 2. merge sources
    // 3. separate tokens and rules
    // 4. redirect to generator
    return 0;
}