#include <logging.h>
#undef Error
// get relative path from full path ommitting source code location differences
static constexpr const char* getRelativePath(const char* full) {
    const char* root = __SOURCE_ROOT__;

    // Skip the common prefix between root and full
    while (*root && *full && (*root == *full)) {
        root++;
        full++;
    }

    // If we've reached a separator after the root path in full path, skip it
    if ((*full == '/' || *full == '\\') && (*root == '\0')) {
        full++;
    }

    return full;
}
Error::what() const override {
    return message.c_str();
}
Error::print() {
    cpuf::perror("[%s:%d] at function %s: %s", file, line, fun, message);
    exit(2);
}

UError::print() {
    cpuf::perror("%$Error%$: %$", color::red, color::reset, message);
    exit(1);
}
UWarning::print() {
    cpuf::printf("%$Error%$: %$", color::yellow, color::reset, message);
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
        e.print();
    } catch (const UBase& e) {
        e.print();
    } catch (const std::exception& e) {
        printf("Unknown std::exception: %s\n", e.what());
        exit(1);
    } catch (...) {
        printf("Unknown exception\n");
        exit(1);
    }

}