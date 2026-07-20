export module File;

import std;

export namespace File {
    auto getTextFile(std::string name) -> std::filesystem::path;
    auto getGrammarFile(std::string name) -> std::filesystem::path;
    auto getYamlConfigFile(std::string name) -> std::filesystem::path;
}