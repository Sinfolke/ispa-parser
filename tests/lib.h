#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
int putCmd(std::string executable, const std::vector<std::string> &cmd) {
#ifdef _WIN32
    auto res = executable;
#else
    auto res = "./" + executable + ' ';
#endif
    for (const auto &el : cmd) {
        res += el;
        res += ' ';
    }
    return std::system(res.c_str());
}
int putCmdDirect(std::vector<std::string> cmd) {
    std::string res = ""; 
    std::for_each(cmd.begin(), cmd.end(), [&res](std::string el) {
        res += el;
    });
    return system(res.c_str());
}
std::string getFileNameWithoutExtension(const char* n) {
    std::string res = "";
    while (*n != '\0') {
        if (*n == '.')
            return res;
        else if (*n == '/' || *n == '\\') {
            res.clear();
            n++;
            continue;
        }
        res += *n;
        n++;
    }
    return res;
}