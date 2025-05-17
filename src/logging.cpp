module;
#ifdef ENABLE_TRACER
    #include <boost/stacktrace.hpp>
#endif
#include <iostream>
#include <cpuf/color.h>
#include <fmt/printf.h>
#include <fmt/format.h>
module logging;
#undef Error
inline void printCallTrace() {
#ifdef ENABLE_TRACER
    std::cerr << fmt::format("call trace: %$\n", boost::stacktrace::stacktrace());
#endif
}
const char* Error::what() const noexcept {
    return message.c_str();
}
void Error::print() {
// Capture the stack trace

    std::cerr << fmt::format("ispa: %sinternal error%s: %s\n", color::red, color::reset, message);
    printCallTrace();
    exit(2);
}
const char* UBase::what() const noexcept {
    return message.c_str();
}
void UError::print() {
    std::cerr << fmt::format("ispa: %serror%s: %$\n", color::red, color::reset, message);
    exit(1);
}
void UWarning::print() {
    fmt::printf("ispa: %swarning%s: %$\n", color::yellow, color::reset, message);
}

/*
    needed to auto-print into console if not handled with try-catch block
*/
void custom_terminate_handler() {
#ifndef DEBUG
    std::flush(std::cout);
    try {
        // Try to rethrow the last uncaught exception to print it
        if (std::current_exception()) {
            std::rethrow_exception(std::current_exception());
        }
    } catch (Error& e) {
        e.print();
    } catch (UError& e) {
        e.print();
    } catch (UWarning& e) {
        e.print();
    } catch (std::exception& e) {
        fmt::printf("ispa: %sException%s: %s\n", color::red, color::reset, e.what());
        printCallTrace();
        exit(1);
    } catch (...) {
        fmt::printf("Unknown exception\n");
        exit(1);
    }
#endif
}