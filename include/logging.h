#ifndef __SOURCE_ROOT__
#error "__SOURCE_ROOT__ not defined. It was intended to define root directory of source code what is done via CMAKE"
#endif

class Error : public std::exception {
public:
    const char* fun;
    const char* file;
    std::string message;
    size_t line;
    template<typename ...Args>
    Error(const char* fun, const char* file, size_t line, const char* format, Args&&... args);
    void print();
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
    void print();
};
class UWarning : public UBase {
public:
    void print();
};

/*
    needed to auto-print into console if not handled with try-catch block
*/
void terminate_handler();
#define Error(format, ...) Error(__FUNCTION__, __FILE__, __LINE__, format, __VA_ARGS__)