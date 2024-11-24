#include <debug/logging.h> // also includes <logging.h>
#include <debug/tracer.h>
#include <cpuf/printf>
#include <cpuf/color>
#undef Error
const char* Error::what() const noexcept {
    return message.c_str();
}
void Error::print() {
#ifdef ENABLE_TRACER
    cpuf::perror("Call trace:\n")
    for (size_t i = 0; i < call_trace.size() - 1; ++i) {
        stack_trace_t e = call_trace[i];
        const char* func_name = e.getFuncInfo();
        cpuf::perror("\t%$ --> ", func_name);
    }
    cpuf::perror("\t%$\n", call_trace.back().getFuncInfo());
#endif
    cpuf::perror("[%s:%d]: %s", file, line, message);
    exit(2);
}
const char* UBase::what() const noexcept {
    return message.c_str();
}
void UError::print() {
    cpuf::perror("%$Error%$: %$", color::red, color::reset, message);
    exit(1);
}
void UWarning::print() {
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
    } catch (Error& e) {
        e.print();
    } catch (UBase& e) {
        e.print();
    } catch (const std::exception& e) {
        printf("Unknown std::exception: %s\n", e.what());
        exit(1);
    } catch (...) {
        printf("Unknown exception\n");
        exit(1);
    }

}