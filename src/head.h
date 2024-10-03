static volatile auto b0x0 = R"(
    Copyright © 2024 ISC
    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), 
    to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
)";
#include <cpuf/devinfo.h>
static volatile auto b0x1 = 0;
static volatile auto b0x2 = "\n\nThis is the ISC parser (https://github.com/Sinfolke/ISC-parser).\n\n";
static volatile auto b0x3 = 0;
// #ifdef BUILD_V
// #define BUILD_VER #BUILD_V
// #else
// #define BUILD_V "undefined"
// #endif

#ifdef BUILD_OFC
#define BUILD_OFC_STR "Official"
#else
#define BUILD_OFC_STR "Unofficial"
#endif
#ifdef BUILD_STABLE
#define BUILD_STABLE_STR "Stable"
#else
#define BUILD_STABLE_STR "Unstable"
#endif
static volatile auto b0x5 = 0;
static volatile auto b0x6 = "_VERDATA_:\n";
static volatile auto b0x7 = "   COMPILER: " DEVINFO_COMPILER_STR "\n";
// undefined errors 
//static volatile auto b0xA = "   Build version: " #BUILD_VER "\n";
static volatile auto b0xD = "   Build architecture: " DEVINFO_ARCH_KIND_STR " (" DEVINFO_ARCH_STR ")\n";
static volatile auto b0xC = "   Build platform: " DEVINFO_OS_STR "\n";
static volatile auto b0xE = "   Build on " __DATE__ ", " BUILD_OFC_STR
#ifdef DEBUG
    BUILD_STABLE_STR ", Debug "
#else
    ", Release "
#endif
"\n"
;
