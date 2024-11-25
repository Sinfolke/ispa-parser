#pragma once
#ifdef ENABLE_TRACER
#ifdef _WIN32
#include <windows.h>
#include <dbghelp.h>
#else
#include <dlfcn.h>
#endif
#include <stdio.h>
#include <vector>
struct stack_trace_t {
    void* func;
    void* caller;
    const char* getCallerName();
    const char* getFuncName();
#ifdef _WIN32
    static void initSymbolHandler();
    static void cleanupSymbolHandler();
    private:
        static std::string getSymbolName(void* addr);
#endif
    stack_trace_t(void* func, void* caller) : func(func), caller(caller) {}
};
extern std::vector<stack_trace_t> call_trace;
extern "C" {
    void __attribute__((no_instrument_function))
        __cyg_profile_func_enter(void *func, void *caller);

    void __attribute__((no_instrument_function))
    __cyg_profile_func_exit(void *func, void *caller);
}
#endif