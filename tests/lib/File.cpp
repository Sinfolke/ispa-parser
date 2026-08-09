module File;
import std;

auto File::getTextFile(std::string name) -> std::filesystem::path {
    return std::filesystem::path(TEST_ROOT_DIR) / "input" / (name + ".txt");
}
auto File::getGrammarFile(std::string name) -> std::filesystem::path {
    const auto input_root = std::filesystem::path(TEST_ROOT_DIR) / "input";
    const std::filesystem::path name_path(name);

    const auto direct = [&] {
        if (name_path.is_absolute())
            return name_path;
        if (name_path.has_extension())
            return input_root / name_path;
        return input_root / (name + ".isc");
    }();

    if (std::filesystem::exists(direct))
        return direct;
    throw std::runtime_error("Grammar file not found: " + name);
}
auto File::getYamlConfigFile(std::string name) -> std::filesystem::path {
    std::filesystem::path file_path = name;
    file_path.replace_extension(".yaml");
    return std::filesystem::path(TEST_ROOT_DIR) / "input" / file_path;
}