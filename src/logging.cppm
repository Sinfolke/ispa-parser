module;
#ifndef __SOURCE_ROOT__
#error "__SOURCE_ROOT__ not defined. It was intended to define root directory of source code what is done via CMAKE"
#endif
#include <cpuf/printf.h>
export module logging;
export class Error : public std::exception {
public:
    std::string message;
    template<typename ...Args>
    Error(const char* format, Args&&... args)
        : message( cpuf::sprintf(format, args...) ) {}
    void print();
    const char* what() const noexcept override;
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


    void print();
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

    void print();
};
export class UWarning : public UBase {
public:
    template<typename... Args>
    UWarning(const char* message, Args&&... args)
        : UBase(message, std::forward<Args>(args)...) {}

    template<typename... Args>
    UWarning(std::string message, Args&&... args)
        : UBase(std::move(message), std::forward<Args>(args)...) {}

    void print();
};


/*
    needed to auto-print into console if not handled with try-catch block
*/
export void custom_terminate_handler();