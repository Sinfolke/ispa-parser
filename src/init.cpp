#include <init.h>
void init(void) {
    std::set_terminate(custom_terminate_handler);
}