module;
#include <sstream>
#include <filesystem>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <logging.cppm>
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
    namespace map {
        template<typename T>
        bool has(std::unordered_map<const char*, T>& map, const char* key) {
            for (const auto& pair : map) {
                if (!strcmp(pair.first, key))
                    return true;
            }
            return false;
        }
        template<typename T>
        T& get(std::unordered_map<const char*, T> &map, const char* key) {
            for (auto& pair : map) {
                if (!strcmp(pair.first, key))
                    return pair.second;
            }
            throw Error("Key '%s' does not exists in map", key);
        }
        template<typename T>
        void set(std::unordered_map<const char*, T>& map, const char* key, T value) {
            for (const auto& pair : map) {
                if (!strcmp(pair.first, key)) {
                    map[pair.first] = value;
                    return;
                }
            }
            throw Error("Key '%s' does not exists in map", key);
        }
    };
    namespace sort {
        template<typename Iterator, typename Compare>
        void bubbleSort(Iterator begin, Iterator end, Compare compare) {
            std::size_t n = std::distance(begin, end);
            if (n == 0) return;  // Prevent infinite loop on empty range
        
            for (std::size_t i = 0; i < n - 1; ++i) {
                bool swapped = false;
                for (auto it = begin; std::next(it) != std::prev(end, i); ++it) {
                    auto next_it = std::next(it);
                    if (compare(*next_it, *it)) {
                        std::iter_swap(it, next_it);
                        swapped = true;
                    }
                }
                if (!swapped) break;  // Stop early if no swaps occurred
            }
        }
        
    }
}
