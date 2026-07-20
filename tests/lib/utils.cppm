export module utils;
import cpuf.printf;
import std;
export namespace utils {
    template<typename ...Args>
    auto command(const char* f, const Args& ...args) -> int {
        std::cout << cpuf::sprintf(f, args...) << std::endl;
        return std::system(cpuf::sprintf(f, args...).c_str());
    }
}