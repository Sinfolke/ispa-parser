#include <iscstdlibc++.h>
#include <fstream>
size_t ISPA_STD::skipup(const char*& in, const char* text)
{
    size_t counter = 0;
    size_t len = strlen(text);
    while(!strncmp(in, text, len)) {
        in += len;
        counter++;
    }
    return counter;
}
size_t ISPA_STD::skip_list(const char*& in, const char* text)
{
    size_t counter = 0;
    for (size_t i = 0; i < strlen(text); i++) {
        if (*in == text[i]) {
            in++;
            i = 0;
            counter++;
        }
    }
    return counter;
}
size_t ISPA_STD::skip_spaces(const char*& in) {
    auto prev = in;
    while(isspace(*in))
        in++;
    
    return in - prev;
}