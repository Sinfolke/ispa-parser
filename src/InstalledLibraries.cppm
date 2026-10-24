export module InstalledLibraries;
import std;

export namespace InstalledLibraries {
namespace fs = std::filesystem;

struct Discovery {
    std::vector<std::string> source_directories;
    std::map<std::string, std::string> dependencies;
};

// The installed executable lives at <install>/versions/<tag>/ispa[.exe].
// Build-tree executables instead use the platform's normal data directory.
fs::path root(const fs::path& executable) {
    if (const char* override_path = std::getenv("ISPA_PKG_ROOT"); override_path && *override_path)
        return fs::absolute(override_path);
    if (const char* install_path = std::getenv("ISPA_INSTALL_DIR"); install_path && *install_path)
        return fs::absolute(fs::path(install_path) / "libraries");
    std::error_code error;
    const auto binary = fs::weakly_canonical(executable, error);
    if (!error && binary.parent_path().parent_path().filename() == "versions")
        return binary.parent_path().parent_path().parent_path() / "libraries";
#ifdef _WIN32
    if (const char* local = std::getenv("LOCALAPPDATA"); local && *local)
        return fs::path(local) / "Programs" / "ISPA" / "libraries";
#else
    if (const char* data = std::getenv("XDG_DATA_HOME"); data && *data)
        return fs::path(data) / "ispa" / "libraries";
#endif
    if (const char* home = std::getenv("HOME"); home && *home)
        return fs::path(home) / ".local" / "share" / "ispa" / "libraries";
    return {};
}

Discovery discover(const fs::path& library_root) {
    Discovery result;
    std::error_code error;
    if (!fs::is_directory(library_root, error)) return result;
    std::vector<fs::path> packages;
    for (const auto& entry : fs::directory_iterator(library_root))
        if (entry.is_directory() && !entry.path().filename().string().starts_with('.'))
            packages.push_back(entry.path());
    std::sort(packages.begin(), packages.end());

    std::map<std::string, std::set<std::string>> candidates;
    for (const auto& package : packages) {
        for (const auto& kind : {"grammar", "python"}) {
            const auto directory = package / "ispalib" / kind;
            if (fs::is_directory(directory)) result.source_directories.push_back(directory.string());
        }
        std::vector<fs::path> manifests;
        for (const auto& item : fs::recursive_directory_iterator(package))
            if (item.is_regular_file() && item.path().extension() == ".ispa-export")
                manifests.push_back(item.path());
        std::sort(manifests.begin(), manifests.end());
        for (const auto& manifest : manifests) {
            auto prefix = manifest;
            prefix.replace_extension();
            if (!fs::is_regular_file(prefix.string() + ".h") &&
                !fs::is_regular_file(prefix.string() + ".py")) continue;
            candidates[manifest.stem().string()].insert(prefix.string());
        }
        if (manifests.size() == 1) {
            auto prefix = manifests.front();
            prefix.replace_extension();
            if (fs::is_regular_file(prefix.string() + ".h") ||
                fs::is_regular_file(prefix.string() + ".py"))
                candidates[package.filename().string()].insert(prefix.string());
        }
    }
    for (const auto& [name, prefixes] : candidates)
        if (prefixes.size() == 1) result.dependencies.emplace(name, *prefixes.begin());
    return result;
}

std::string pluginPrefix(const fs::path& executable_directory, const std::string& kind,
                         const std::string& name) {
#ifdef _WIN32
    constexpr auto extension = ".dll";
#elif defined(__APPLE__)
    constexpr auto extension = ".dylib";
#else
    constexpr auto extension = ".so";
#endif
    for (const auto& prefix : {"libispa-", "ispa-"}) {
        const auto candidate = executable_directory / (std::string(prefix) + kind + "-" + name);
        if (fs::is_regular_file(candidate.string() + extension)) return candidate.string();
    }
    return "libispa-" + kind + "-" + name;
}
}
