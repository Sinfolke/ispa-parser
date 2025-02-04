#include <corelib.h>
#include <sstream>
#include <debug/logging.h>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
namespace fs = std::filesystem;
namespace corelib::file {
    // Function to read the content of a file into a string
    std::string readFile(const fs::path filePath) {
        std::ifstream file(filePath, std::ios::in | std::ios::binary);
        if (!file) {
            throw UError("Failed to open file: %$", filePath.string());
        }

        std::string content((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
        return content;
    }
    std::string readFile(const std::string& filePath) {
        std::ifstream file(filePath, std::ios::in | std::ios::binary);
        if (!file) {
            throw UError("Failed to open file: %s", filePath.c_str());
        }

        std::string content((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
        return content;
    }
    // Function to recursively get file contents
    std::vector<std::string> getFilesRecursively(const std::string& dir, const std::string& ext = "") {
        std::vector<std::string> contents;

        try {
            for (const auto& entry : fs::recursive_directory_iterator(dir)) {
                if (entry.is_regular_file() && 
                    (ext.empty() || entry.path().extension() == ext)) {
                    contents.push_back(entry.path().string());
                }
            }
        } catch (const std::exception& e) {
            throw UError("Error accessing directory %s: %$", dir, e.what());
        }

        return contents;
    }
}
namespace corelib::text {
    bool startsWith(const std::string& str, const std::string& prefix) {
        // Ensure the prefix is not longer than the string
        if (prefix.size() > str.size()) {
            return false;
        }

        // Compare the beginning of the string with the prefix
        return std::equal(prefix.begin(), prefix.end(), str.begin());
    }
    bool startsWithRange(const std::string& str, char from, char to) {
        return (str[0] >= from && str[0] <= to);
    }


    bool isUpper(const char* str) {
        for (; *str; str++) {  // Iterate until null terminator
            if (!std::isupper(*str))
                return false;
        }
        return true;
    }

    bool isUpper(const std::string str) {
        for (char ch : str) {
            if (!std::isupper(ch))
                return false;
        }
        return true;
    }
    bool isLower(const char* str) {
        return !isUpper(str);
    }
    bool isLower(const std::string str) {
        return !isUpper(str);
    }
}