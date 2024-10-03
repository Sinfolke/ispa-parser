
template<typename ...Args>
void dprintf(const char* format, Args... args) {
#ifdef DEBUG
    tfm::printf(format, args...);
#endif
}
namespace user {
    [[noreturn]] void user_err(const char* msg, ...) {
        va_list args;
        va_start(args, msg);
        printf("%sError: ", color::red);
        vfprintf(stderr, msg, args);
        printf("%s\n", color::reset);
        va_end(args);
        exit(1);
    }
    void warning(const char* msg, ...) {
        va_list args;
        va_start(args, msg);
        printf("%sWarning: ", color::yellow);
        vfprintf(stderr, msg, args);
        printf("%s\n", color::reset);
        va_end(args);
    }
    void info(const char* msg, ...) {
        va_list args;
        va_start(args, msg);
        printf(color::teal);
        vprintf(msg, args);
        printf("%s\n", color::reset);
        va_end(args);
    }
};

void runterr(int LINE, const char* FUNC, const char* FILE, const char* msg, ...) {
    printf("A runtime error occurred. Please contact the developers\n");
    printf("[%d:%s] at %s: ", LINE, FILE, FUNC);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    putchar('\n');
    exit(1);
}
#define runterr(msg, ...) runterr(__LINE__, __FUNCTION__, __FILE__, msg, __VA_ARGS__)
