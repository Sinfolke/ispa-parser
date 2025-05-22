module init;
import args;
import logging;
import CLI;
import std;

Args init(int argc, char** argv) {
#ifndef DEBUG
    std::set_terminate(custom_terminate_handler);
#endif
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
#endif
    return parse_args(argc, argv);
}
