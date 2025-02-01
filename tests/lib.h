#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
void putCmd(std::vector<std::string> cmd) {
    std::string res = ""; 
    std::for_each(cmd.begin(), cmd.end(), [&res](std::string el) {
        res += el;
        res += ' ';
    });
    system(res.c_str());
}
void putCmdDirect(std::vector<std::string> cmd) {
    std::string res = ""; 
    std::for_each(cmd.begin(), cmd.end(), [&res](std::string el) {
        res += el;
    });
    system(res.c_str());
}