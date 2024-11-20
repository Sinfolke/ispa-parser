#include <dlfcn.h>
#include <stdio.h>
#include <vector>
struct stack_trace_t {
    void* caller;
    void* func;
    Dl_info getCallerInfo();
    Dl_info getFuncInfo();
};
extern std::vector<stack_trace_t> call_trace;
void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *func, void *caller);

void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *func, void *caller);