#include "lib.h"
int main() {
    putCmd({"build/ispa", __ROOT_DIR__ "/" __PROCESS_FILE__, "--lang", "cpp", });
}