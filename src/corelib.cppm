module;
#include <string>
#include <filesystem>
export module corelib;
export namespace corelib {
    namespace file {
        std::string readFile(const std::filesystem::path filePath);
        std::string readFile(const std::string& filePath);
        std::vector<std::string> getFilesRecursively(const std::string& dir, const std::string& ext);
    }
    namespace text {
        bool startsWith(const std::string& str, const std::string& prefix);
        bool startsWithRange(const std::string& str, char from, char to);
        bool isAllAlpha(const std::string& str);
        bool isUpper(const char* str);
        bool isUpper(const std::string str);
        bool isLower(const char* str);
        bool isLower(const std::string str);
        std::string ToUpper(std::string str);
        std::string ToLower(std::string str);
        std::string join(const std::vector<std::string> &elements, const std::string &delimiter);
        char getCharFromEscaped(char in);
        std::string getCharFromEscapedAsStr(char in, bool string);
    }
}
