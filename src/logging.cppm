module;
export module logging;
import cpuf.printf;
import cpuf.color;
import types;
import Tlog.Logger;
import std;
export inline Tlog::Logger logger("Logs");  // <<== IMPORTANT: must be `inline` if defined in module interface
export class Error : public std::exception {
public:
    std::string message;
    template<typename ...Args>
    Error(const char* format, Args&&... args)
        : message( cpuf::sprintf(format, args...) ) {}
    void print() const;
    const char* what() const noexcept override;
};
export template<typename ...Args>
void Assert(bool condition, const char* format, Args&&... args) {
    if (!condition) {
        throw Error(format, std::forward<Args>(args)...);
    }
};
// base user error class
export class UBase : std::exception {
public:
    const std::string message;
    template<typename ...Args>
    UBase(const char* message, Args&&... args) : message( cpuf::sprintf(message, args...) ) {}
    template<typename ...Args>
    UBase(char* message, Args&&... args) : message( cpuf::sprintf(message, args...) ) {}
    template<typename ...Args>
    UBase(std::string message, Args&&... args) : message( cpuf::sprintf(message, args...) ) {}


    void print() const;
    const char* what() const noexcept override;
};
export class UError : public UBase {
public:
    template<typename... Args>
    UError(const char* message, Args&&... args)
        : UBase(message, std::forward<Args>(args)...) {}

    template<typename... Args>
    UError(std::string message, Args&&... args)
        : UBase(std::move(message), std::forward<Args>(args)...) {}

    void print() const;
};
export class UWarning : public UBase {
public:
    template<typename... Args>
    UWarning(const char* message, Args&&... args)
        : UBase(message, std::forward<Args>(args)...) {}

    template<typename... Args>
    UWarning(std::string message, Args&&... args)
        : UBase(std::move(message), std::forward<Args>(args)...) {}

    void print() const;
};


/*
    needed to auto-print into console if not handled with try-catch block
*/
export void custom_terminate_handler();