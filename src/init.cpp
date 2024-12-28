#include <init.h>
void init(void) {
    std::set_terminate(custom_terminate_handler);
    std::ios::sync_with_stdio(false);
}