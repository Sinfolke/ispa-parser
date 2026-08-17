module;
export module logging;
import cpuf.printf;
import cpuf.color;
import dstd;
export import Tlog.Logger;
import std;
export inline Tlog::Logger logger("Logs");  // <<== IMPORTANT: must be `inline` if defined in module interface
export class Error : public std::exception {
public:
    std::string msg;
    template<typename ...Args>
    Error(const char* format, Args&&... args)
        : msg( cpuf::sprintf(format, args...) ) {}
    void print() const;
    const char* what() const noexcept override;
};
export template<typename ...Args>
void Assert(bool condition, const char* format, Args&&... args) {
    if (!condition) {
        throw Error(format, std::forward<Args>(args)...);
    }
};
export template<typename ...Args>
void AssertNe(bool condition, const char* format, Args&&... args) {
    if (condition) {
        throw Error(format, std::forward<Args>(args)...);
    }
};
// base user error class
export class UBase : public std::exception {
public:
    const std::string msg;
    template<typename ...Args>
    UBase(const char* msg, Args&&... args) : msg( cpuf::sprintf(msg, args...) ) {}
    template<typename ...Args>
    UBase(char* msg, Args&&... args) : msg( cpuf::sprintf(msg, args...) ) {}
    template<typename ...Args>
    UBase(std::string msg, Args&&... args) : msg( cpuf::sprintf(msg, args...) ) {}


    void print() const;
    const char* what() const noexcept override;
};
export class UError : public UBase {
public:
    template<typename... Args>
    UError(const char* msg, Args&&... args)
        : UBase(msg, std::forward<Args>(args)...) {}

    template<typename... Args>
    UError(std::string msg, Args&&... args)
        : UBase(std::move(msg), std::forward<Args>(args)...) {}

    void print() const;
};
export class UWarning : public UBase {
public:
    template<typename... Args>
    UWarning(const char* msg, Args&&... args)
        : UBase(msg, std::forward<Args>(args)...) {}

    template<typename... Args>
    UWarning(std::string msg, Args&&... args)
        : UBase(std::move(msg), std::forward<Args>(args)...) {}

    void print() const;
};


/*
    needed to auto-print into console if not handled with try-catch block
*/
export void custom_terminate_handler();