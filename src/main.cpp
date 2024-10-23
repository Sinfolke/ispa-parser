#include "main.h"
int main(int argc, char** argv) {
    std::set_terminate(terminate_handler);

    printf("No code\n");
    return EXIT_FAILURE;
}
