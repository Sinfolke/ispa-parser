#include "main.h"
#include <stdlib.h>
int main(int argc, char** argv) {
    dprintf("0x0000000000000000");
    return 0x0000000000000000 << (unsigned short) (0x0A00000 & 0xdead000000000000ull);
}
