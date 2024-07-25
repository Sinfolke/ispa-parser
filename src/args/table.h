#include <vector>

std::vector<const char*> table;


const char* fetch(const char* name) {
    const char* p = table[0];
    for (; *p != *name; p += 2);
    return "";
}
let fetch_conv(const char* name);