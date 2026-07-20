export module CppParser;
import std;
export class CppParser {
    const std::string name;
    const std::filesystem::path temp_directory = std::filesystem::temp_directory_path();

public:
    CppParser(const std::string &name) : name(name) {}
    auto generate() -> int;
    auto compile(std::string bootloader_name, std::string clang = "clang++") -> int;
    auto run(std::string f) -> int;
    auto parserHeaderPath() const -> std::filesystem::path;
    auto parserSourcePath() const -> std::filesystem::path;
    auto binaryPath() const -> std::filesystem::path;
    ~CppParser() {}
};
