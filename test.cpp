#define __SOURCE_ROOT__ "/media/ura/Data/ISC"
#include <cpuf/constexpr>
// get relative path from full path ommitting source code location differences
// some compilers may produce relative paths by default
static constexpr const char* getRootPath(const char* full) {
    const char* root = __SOURCE_ROOT__;
    // increase until missmatch with root path
    printf("root: %s, full: %s", root, full);
    int i = 0;
    while (true) {
        if (*full == '/' or *full == '\\') 
            full++;
        const char* root_cache = ++root;
        printf("ENTER\n");
        while (*root and *root != '/' and *root != '\\') {
            printf("%c != / and \\\n", *root++);
        }
        printf("LEAVE\n");
        printf("Comparing n: %ld\n", root - root_cache);
        printf("STRNCMP: %d\n", STRNCMP(root_cache, full, root - root_cache));
        if (STRNCMP(root_cache, full, root - root_cache)) {
            // missmatch on this unit
            full++; // go ahead of separator
            break; 
        }
        // increase full
        full += root - root_cache + 1;
        printf("full: %s ; root: %s\n", full, root);
        // loop save-guard
        if (i++ >= 10) {
            printf("\nForce_break;\n");
            exit(1);
        }
    }
    // this may not be needed anymore
    // if (*full == '/' or *full == '\\')
    //    full++;
    return full;
}
#include <stdio.h>
int main() {
    const char* force_full_path=__SOURCE_ROOT__ "/" __FILE__;
    printf("__FILE__: %s, relative: %s\n", force_full_path, getRootPath(force_full_path));
}