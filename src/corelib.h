#pragma once
#include <sstream>
#include <filesystem>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <logging.h>
namespace corelib {
    namespace file {
        std::string readFile(const std::filesystem::path filePath);
        std::string readFile(const std::string& filePath);
        std::vector<std::string> getFilesRecursively(const std::string& dir, const std::string& ext);
    }
    namespace text {
        bool startsWith(const std::string& str, const std::string& prefix);
        bool startsWithRange(const std::string& str, char from, char to);
        bool isUpper(const char* str);
        bool isUpper(const std::string str);
        bool isLower(const char* str);
        bool isLower(const std::string str);
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
        T get(std::unordered_map<const char*, T> map, const char* key) {
            for (const auto& pair : map) {
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
}