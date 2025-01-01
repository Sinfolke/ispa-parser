#pragma once
#include <debug/logging.h>
#include <filesystem>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
namespace corelib {
    namespace file {
        std::string readFile(const std::filesystem::path filePath);
        std::string readFile(const std::string& filePath);
        std::vector<std::string> getFilesRecursively(const std::string& dir, const std::string& ext);
    }
    namespace text {
        bool startsWith(const std::string& str, const std::string& prefix);
        bool startsWithRange(const std::string& str, char from, char to);
    }
    namespace map {
        template<typename T>
        bool has(std::unordered_map<const char*, T>& map, const char* key) {
            for (const auto pair : map) {
                if (!strcmp(pair.first, key))
                    return true;
            }
            return false;
        }
        template<typename T>
        T get(std::unordered_map<const char*, T>& map, const char* key) {
            for (const auto pair : map) {
                if (!strcmp(pair.first, key))
                    return pair.second;
            }
            throw Error("Key %s does not exists in map", key);
        }
    };
}