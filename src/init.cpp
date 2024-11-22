#include <init.h>
void init(void) {
    std::set_terminate(terminate_handler);
    // init call trace on windows
#if defined(_WIN32) && defined(ENABLE_TRACER)
    stack_trace_t::initSymbolHandler(); // Initialize symbol handler
#endif
}