#ifndef __SOURCE_ROOT__
#error "__SOURCE_ROOT__ not defined. It was intended to define root directory of source code what is done via CMAKE"
#endif
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

class Error : public std::exception {
public:
    const char* fun;
    const char* file;
    std::string message;
    size_t line;
    template<typename ...Args>
    Error(const char* fun, const char* file, size_t line, const char* format, Args&&... args)
    : fun(fun), file(getRelativePath(file)), line(line), message( sprintf(format, ...args) ) {}
    const char* what() const override {
        return message.c_str();
    }
    void print() {
        cpuf::perror("[%s:%d] at function %s: %s", file, line, fun, message);
        exit(2);
    }
};
class UBase : std::exception {
public:
    const std::string message;
    template<typename ...Args>
    UBase(const char* message, Args&&... args) : message( sprintf(message, ...args) ) {}
    template<typename ...Args>
    UBase(char* message, Args&&... args) : message( sprintf(message, ...args) ) {}
    template<typename ...Args>
    UBase(std::string message, Args&&... args) : message( sprintf(message, ...args) ) {}

    const char* what() const override {
        return message.c_str();
    }
    void print();
}
class UError : public UBase {
public:
    void print() {
        cpuf::perror("%$Error%$: %$", color::red, color::reset, message);
        exit(1);
    }
};
class UWarning : public UBase {
public:
    void print() {
        cpuf::printf("%$Error%$: %$", color::yellow, color::reset, message);
    }
};

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
#define Error(format, ...) Error(__FUNCTION__, __FILE__, __LINE__, format, __VA_ARGS__)