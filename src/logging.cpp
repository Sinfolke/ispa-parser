module logging;
import cpuf.printf;
import cpuf.color;
import std;
import std.compat;
const char* Error::what() const noexcept {
    return message.c_str();
}
void Error::print() const {
// Capture the stack trace

    std::cerr << cpuf::sprintf("ispa: %sinternal error%s: %$\n", color::red, color::reset, message);
    exit(2);
}
const char* UBase::what() const noexcept {
    return message.c_str();
}
void UError::print() const {
    std::cerr << cpuf::sprintf("ispa: %serror%s: %$\n", color::red, color::reset, message);
    exit(1);
}
void UWarning::print() const {
    cpuf::printf("ispa: %swarning%s: %$\n", color::yellow, color::reset, message);
}

/*
    needed to auto-print into console if not handled with try-catch block
*/
void custom_terminate_handler() {
    std::flush(std::cout);
    std::flush(std::cerr);
    try {
        // Try to rethrow active exception
        if (auto eptr = std::current_exception()) {
            std::rethrow_exception(eptr);
        }
    } catch (const Error& e) {
        e.print();
    } catch (const UError& e) {
        e.print();
    } catch (const UWarning& e) {
        e.print();
    } catch (const std::exception& e) {
        cpuf::printf("ispa: %sException%s: %s\n", color::red, color::reset, e.what());
    } catch (...) {
        cpuf::printf("Unknown exception\n");
    }

    // Now crash deliberately to trigger debugger
#if defined(_MSC_VER)
    __debugbreak(); // MSVC-specific
#elif defined(__GNUC__) || defined(__clang__)
    __builtin_trap(); // GCC/Clang
#else
    std::abort();
#endif
}