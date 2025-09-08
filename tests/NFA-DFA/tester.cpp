#include <lib.h>
#include <vector>
#include <iostream>
#ifndef __ROOT_DIR__
#error "__ROOT_DIR__ must be defined"
#endif
#ifndef __PROCESS_FILE__
#error "__PROCESS_FILE__ must be defined"
#endif
#ifndef __TEST_DIR__
#error "__TEST_DIR__ must be defined"
#endif
int main() {
    return putCmd("ispa",
        {
        __PROCESS_FILE__,
        "--lang", "cpp",
        "--dump", "NFA",
        "--dump", "DFA",
        "--dump-nfa-from-rule",
        "--dd", __TEST_DIR__ "/test-dump/" + getFileNameWithoutExtension(__PROCESS_FILE__)
    });
}