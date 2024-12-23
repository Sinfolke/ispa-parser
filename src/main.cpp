#include <main.h>
int main(int argc, char** argv) {
    init();
    throw Error("No code!");
    return EXIT_FAILURE;
}
