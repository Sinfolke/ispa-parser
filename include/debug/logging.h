#pragma once
#ifndef __SOURCE_ROOT__
#error "__SOURCE_ROOT__ not defined. It was intended to define root directory of source code what is done via CMAKE"
#endif
#include <stdexcept>
#include <debug/relativePath.h>
#include <debug/tracer.h>
class Error : public std::exception {
public:
    const char* file;
    std::string message;
    size_t line;
    template<typename ...Args>
    Error(const char* file, size_t line, const char* format, Args&&... args)
        : file(getRelativePath(file)), line(line), message( sprintf(format, args...) ) {}
    void print();
    const char* what() const noexcept override;
};
// base user error class
class UBase : std::exception {
public:
    const std::string message;
    template<typename ...Args>
    UBase(const char* message, Args&&... args) : message( sprintf(message, args...) ) {}
    template<typename ...Args>
    UBase(char* message, Args&&... args) : message( sprintf(message, args...) ) {}
    template<typename ...Args>
    UBase(std::string message, Args&&... args) : message( sprintf(message, args...) ) {}


    void print();
    const char* what() const noexcept override;
};
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
#define Error(format, ...) Error(__FILE__, __LINE__, format, ##__VA_ARGS__)