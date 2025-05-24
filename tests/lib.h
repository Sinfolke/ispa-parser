#include <vector>
#include <fstream>
#include <algorithm>
void putCmd(vector<std::string> cmd) {
    std::string res = ""; 
    std::for_each(cmd.begin(), cmd.end(), [&res](std::string el) {
        res += el;
        res += ' ';
    });
    system(res.c_str());
}
void putCmdDirect(vector<std::string> cmd) {
    std::string res = ""; 
    std::for_each(cmd.begin(), cmd.end(), [&res](std::string el) {
        res += el;
    });
    system(res.c_str());
}