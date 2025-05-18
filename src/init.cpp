module;
#include <iostream>
module init;
void init() {
    //std::set_terminate(custom_terminate_handler);
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
#endif
}