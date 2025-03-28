#include "iscstdlibc++.h"
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
std::string ISPA_STD::readFileToString(const char* path, bool &success) {
    std::ifstream file(path, std::ios::in | std::ios::binary);  // Open the file in binary mode as well for safety
    if (!file) {
        success = 0;
        return "";
    }

    std::string str;
    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    str.reserve(fileSize);  // Reserve enough space for the string

    file.seekg(0, std::ios::beg);
    str.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    success = 1;
    return str;
}