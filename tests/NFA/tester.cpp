#include <lib.h>
#ifndef __ROOT_DIR__
#error "__ROOT_DIR__ must be defined"
#endif
#ifndef __PROCESS_FILE__
#error "__PROCESS_FILE__ must be defined"
#endif

int main() {
    putCmd({"build/ispa", __ROOT_DIR__ "/NFA/" __PROCESS_FILE__, "--lang", "cpp", });
}
