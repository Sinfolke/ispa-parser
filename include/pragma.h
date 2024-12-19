#pragma once

/*
    Control optimization FOR FUNCTIONS in code
    This assumes the compiler supports these features. If not, it is ignored.
*/

#ifdef _MSC_VER
    #warning "MSVC is bad in optimization control. Consider better use of GCC/Clang instead (if you could)"
    #define ENABLE_OPTIMIZATION \
        __pragma(optimize("t", on))

    #define DISABLE_OPTIMIZATION \
        __pragma(optimize("", off))

    #define ENABLE_O(opt) \
        __pragma(optimize(opt, on))

    #define DISABLE_O(opt) \
        // what we can do here is to only disable the fast-math
        // this gonna save program from being incorrect but nothing more
        __pragma(fp_contract(off)) // Disable FP contraction

#elif defined(__clang__)
    #define ENABLE_OPTIMIZATION \
        __attribute__((optimize("on")))

    #define DISABLE_OPTIMIZATION \
        __attribute__((optimize("off")))

    #define ENABLE_O(opt) \
        __attribute__((optimize("-f" opt)))

    #define DISABLE_O(opt) \
        __attribute__((optimize("-fno-" opt)))

#elif defined(__GNUC__)
    #ifndef O_LEVEL
        #define O_LEVEL "2"
    #endif

    #define ENABLE_OPTIMIZATION \
        _Pragma("GCC optimize (\"" O_LEVEL "\")")

    #define DISABLE_OPTIMIZATION \
        _Pragma("GCC optimize (\"O0\")")

    #define ENABLE_O(opt) \
        __attribute__((optimize("-f" opt)))

    #define DISABLE_O(opt) \
        __attribute__((optimize("-fno-" opt)))

#else
    #warning "Optimization control unsupported. Output executable is about to be less optimized. Use GCC or Clang to get it faster"
    #define ENABLE_OPTIMIZATION
    #define DISABLE_OPTIMIZATION
    #define ENABLE_O(opt)
    #define DISABLE_O(opt)
#endif

