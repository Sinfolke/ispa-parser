#include <main.h>
int main(int argc, char** argv) {
    init();
#ifdef ENABLE_TRACER
    throw Error("Tracer check. ");
#else
    throw Error("No tracer check.");
#endif
    return EXIT_FAILURE;
}
