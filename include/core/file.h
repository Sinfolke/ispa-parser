#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <debug/logging.h>
std::string readFile(const std::filesystem::path filePath);
std::string readFile(const std::string& filePath);
std::vector<std::string> getFilesRecursively(const std::string& dir, const std::string& ext);