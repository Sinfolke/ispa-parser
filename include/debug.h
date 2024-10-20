#ifndef __SOURCE_ROOT__
#error "__SOURCE_ROOT__ not defined. It was intended to define root directory of source code what is done via CMAKE"
#endif
// get relative path from full path ommitting source code location differences
static constexpr const char* getRootPath(const char* full) {
    const char* root = __SOURCE_ROOT__;
    // increase until missmatch with root path
    while(*full == *root) {
        full++;
        root++;
    }
    // remove separator if remains
    if (*full == '/' or *full == '\\')
        full++;
    return full;
}

class Error : public std::exception {
public:
    const char* fun;
    const char* file;
    std::string message;
    size_t line;
    template<typename ...Args>
    Error(const char* fun, const char* file, size_t line, const char* format, Args&&... args)
    : fun(fun), file(getRootPath(file)), line(line), message( sprintf(format, ...args) ) {}
    const char* what() const override {
        return message.c_str();
    }
    void print() {

    }
};
void printThrownError(const Error& e) {
    cpuf::printf("[%s:%d] at function %s: %s", e.file, e.line, e.fun, e.message);
}
/*
    needed to auto-print into console if not handled with try-catch block
*/
void terminate_handler() {
    try {
        // Try to rethrow the last uncaught exception to print it
        if (std::current_exception()) {
            std::rethrow_exception(std::current_exception());
        }
    } catch (const Error& e) {
        printThrownError(e);
    } catch (const std::exception& e) {
        cpuf::printf("Unknown std::exception: %s\n", e.what());
    } catch (...) {
        cpuf::printf("Unknown exception")
    }

    // Exit after handling the uncaught exception
    exit(1);
}
#define Error(format, ...) Error(__FUNCTION__, __FILE__, __LINE__, format, __VA_ARGS__)