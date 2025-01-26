#pragma once

/*
    Control optimization FOR FUNCTIONS in code
    This assumes the compiler supports these features. If not, it is ignored.
*/
#ifndef O_LEVEL
#error "O_LEVEL is required"
#endif
#ifdef _MSC_VER
    #pragma message("Note that gcc/clang would produce better executable than MSVC for this project")

    #define ENABLE_OPTIMIZATION \
        __pragma(optimize("t", on))

    #define DISABLE_OPTIMIZATION \
        __pragma(optimize("", off))

    #define ENABLE_O(opt) \
        ENABLE_OPTIMIZATION

    #define DISABLE_O(opt) \
        __pragma(float_control(precise, on, push)) // Ensure precise FP calculations

#elif defined(__clang__)
    #define ENABLE_OPTIMIZATION \
        __attribute__((optimize("-O" O_LEVEL)))

    #define DISABLE_OPTIMIZATION \
        __attribute__((optimize("-O0")))

    #define ENABLE_O(opt) \
        __attribute__((optimize("-f" opt)))

    #define DISABLE_O(opt) \
        __attribute__((optimize("-fno-" opt)))

#elif defined(__GNUC__)

    #define ENABLE_OPTIMIZATION \
        __attribute__((optimize("-O" O_LEVEL)))

    #define DISABLE_OPTIMIZATION \
        __attribute__((optimize("-O0")))

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

