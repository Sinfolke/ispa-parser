module init;
import std;
import logging;
void init() {
#ifndef DEBUG
    std::set_terminate(custom_terminate_handler);
#endif
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
#endif
}