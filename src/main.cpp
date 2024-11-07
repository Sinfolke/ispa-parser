#include "main.h"
int main(int argc, char** argv) {
    std::set_terminate(terminate_handler);

    throw Error("No code!");
    return EXIT_FAILURE;
}
