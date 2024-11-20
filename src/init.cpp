#include <init.h>
void init(void) {
    std::set_terminate(terminate_handler);
    // init call trace on windows
#ifdef _WIN32
    stack_trace_t::initSymbolHandler(); // Initialize symbol handler
#endif
}