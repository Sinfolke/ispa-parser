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

    // Backward-compatible fallback for fixtures stored in tests/input/basic/*.isc
    const auto basic_subdir = [&] {
        if (name_path.has_extension())
            return input_root / "basic" / name_path.filename();
        return input_root / "basic" / (name + ".isc");
    }();
    if (std::filesystem::exists(basic_subdir))
        return basic_subdir;

    // Legacy test name fallback: `basic` used to map to `basic.isc`.
    // In newer layouts grammars live in `tests/input/basic/*.isc`.
    if (name == "basic") {
        const auto templated_type = input_root / "basic" / "templated_type.isc";
        if (std::filesystem::exists(templated_type))
            return templated_type;
    }

    // Keep old behavior for diagnostics in callers when neither path exists.
    return direct;
}
auto File::getYamlConfigFile(std::string name) -> std::filesystem::path {
    return std::filesystem::path(TEST_ROOT_DIR) / "input" / (name + ".yaml");
}