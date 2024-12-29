#ifdef ENABLE_TRACER
    #define BOOST_STACKTRACE_USE_BACKTRACE
    #include <boost/stacktrace.hpp>
#endif
#include <debug/logging.h>
#include <cpuf/color.h>
#undef Error
const char* Error::what() const noexcept {
    return message.c_str();
}
void Error::print() {
// Capture the stack trace

    cpuf::perror("RTERROR [%s:%d]: %s\n", file, line, message);
#ifdef ENABLE_TRACER
    cpuf::perror("call trace: %$\n", boost::stacktrace::stacktrace());
#endif
    exit(2);
}
const char* UBase::what() const noexcept {
    return message.c_str();
}
void UError::print() {
    cpuf::perror("%sError%s: %$\n", color::red, color::reset, message);
    exit(1);
}
void UWarning::print() {
    cpuf::printf("%$Error%$: %$\n", color::yellow, color::reset, message);
}

/*
    needed to auto-print into console if not handled with try-catch block
*/
void custom_terminate_handler() {
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
        cpuf::printf("Exception: %s\n", e.what());
        exit(1);
    } catch (...) {
        cpuf::printf("Unknown exception\n");
        exit(1);
    }

}