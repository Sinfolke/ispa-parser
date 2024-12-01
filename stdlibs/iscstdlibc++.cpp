#include "iscstdlibc++.h"
size_t ISC_STD::skipup(const char*& in, const char* text)
{
    size_t counter = 0;
    size_t len = strlen(text);
    while(!strncmp(in, text, len)) {
        in += len;
        counter++;
    }
    return counter;
}