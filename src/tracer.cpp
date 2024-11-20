#include <tracer.h>
struct stack_trace_t {
    void* caller;
    void* func;
#ifdef _WIN32
    // Initialize symbol handler (should be called once in the application)
    static void initSymbolHandler() {
        SymInitialize(GetCurrentProcess(), nullptr, TRUE);
    }

    // Cleanup symbol handler (optional for graceful shutdown)
    static void cleanupSymbolHandler() {
        SymCleanup(GetCurrentProcess());
    }
#endif
    const char* getCallerName() {
#ifdef _WIN32
        return getSymbolName(caller);
#else
        Dl_info caller_info;
        dladdr(func, &caller_info);
        return caller_info.dli_sname;
#endif
    }
    const char* getFuncName() {
#ifdef _WIN32
        return getSmbolName(func);
#else
        Dl_info func_info;
        dladdr(func, &func_info);
        return func_info.dli_sname;
#endif
    }
#ifdef _WIN32
    private:
        static std::string getSymbolName(void* addr) {
            char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
            PSYMBOL_INFO symbol = reinterpret_cast<PSYMBOL_INFO>(buffer);

            symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
            symbol->MaxNameLen = MAX_SYM_NAME;

            DWORD64 displacement = 0;
            HANDLE process = GetCurrentProcess();
            return symbol->Name;
        }
#endif
};
std::vector<stack_trace_t> call_trace {};
void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *func, void *caller) {
    stack_trace_t stack(func, caller);
    call_trace.push_back(stack);
}

void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *func, void *caller) {
    call_trace.pop_back();
}
