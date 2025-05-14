#include <corelib.h>
#include <sstream>
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
    bool isAllAlpha(const std::string& str) {
        for (const char &ch : str) {
            if (!isalpha(ch))
                return false;
        }
        return true;
    }

    bool isUpper(const char* str) {
        for (; *str; str++) {
            if (isalpha(*str) && std::islower(*str))
                return false;
        }
        return true;
    }

    bool isUpper(const std::string str) {
        for (char ch : str) {
            if (isalpha(ch) && std::islower(ch))
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
    std::string ToUpper(std::string str) {
        for (auto &c : str)
            c = toupper(c);
        return str; 
    }
    std::string ToLower(std::string str) {
        for (auto &c : str)
            c = tolower(c);
        return str; 
    }
    char getCharFromEscaped(char in) {
        switch (in)
        {
        case '\n': return 'n';  // Newline
        case '\r': return 'r';  // Carriage return
        case '\t': return 't';  // Horizontal tab
        case '\a': return 'a';  // Bell (alert)
        case '\b': return 'b';  // Backspace
        case '\f': return 'f';  // Form feed (new page)
        case '\v': return 'v';  // Vertical tab
        case '\0': return '0';  // end of string
        default: return in;
        }
    }
    std::string getCharFromEscapedAsStr(char in, bool string) {
        if (in == '"')
            return string ? "\\\"" : "\"";
        if (in == '\'')
            return string ? "'" : "\\'";
        switch (in)
        {
        case '\n': return "n";  // Newline
        case '\r': return "r";  // Carriage return
        case '\t': return "t";  // Horizontal tab
        case '\a': return "a";  // Bell (alert)
        case '\b': return "b";  // Backspace
        case '\f': return "f";  // Form feed (new page)
        case '\v': return "v";  // Vertical tab
        case '\\': return "\\";   // Backslash
        case '\0': return "0";  // end of string
        default: return std::string(1, in);      // Return the character itself if not an escape sequence
        }
    }
}
namespace corelib::text {
    std::string join(const std::vector<std::string> &elements, const std::string &delimiter) {
        if (elements.empty()) return "";
        std::string joined = elements.front();
        for (auto it = elements.begin() + 1; it != elements.end(); ++it) {
            joined += delimiter + *it;
        }
        return joined;
    }
}
