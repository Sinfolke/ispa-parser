module;
#include <cpuf/printf.h>
#include <cpuf/color.h>
module logging;
import std;
const char* Error::what() const noexcept {
    return message.c_str();
}
void Error::print() {
// Capture the stack trace

    std::cerr << cpuf::sprintf("ispa: %sinternal error%s: %$\n", color::red, color::reset, message);
    exit(2);
}
const char* UBase::what() const noexcept {
    return message.c_str();
}
void UError::print() {
    std::cerr << cpuf::sprintf("ispa: %serror%s: %$\n", color::red, color::reset, message);
    exit(1);
}
void UWarning::print() {
    cpuf::printf("ispa: %swarning%s: %$\n", color::yellow, color::reset, message);
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
        cpuf::printf("ispa: %sException%s: %s\n", color::red, color::reset, e.what());
        exit(1);
    } catch (...) {
        cpuf::printf("Unknown exception\n");
        exit(1);
    }
#endif
}