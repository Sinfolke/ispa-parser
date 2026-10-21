export module Algorithm.Cache;
import Algorithm.API;
import std;

export namespace Algorithm {
    namespace detail {
        inline auto validCacheName(const std::string& name) -> bool {
            const std::filesystem::path path{name};
            return !name.empty() && name != "." && name != ".." &&
                name.find('/') == std::string::npos && name.find('\\') == std::string::npos &&
                !path.has_root_path() && path.filename() == path;
        }
    }
    inline auto loadMetadata(const std::filesystem::path& directory) -> Metadata {
        Metadata metadata;
        if (!std::filesystem::exists(directory)) return metadata;
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            if (!entry.is_regular_file()) continue;
            std::ifstream in(entry.path(), std::ios::binary);
            if (!in) throw std::runtime_error("Cannot read algorithm cache: " + entry.path().string());
            metadata.cache.emplace(entry.path().filename().string(),
                std::string(std::istreambuf_iterator<char>(in), {}));
        }
        return metadata;
    }
    inline auto saveMetadata(const std::filesystem::path& directory, const Metadata& metadata) -> void {
        for (const auto& [name, bytes] : metadata.cache)
            if (!detail::validCacheName(name))
                throw std::invalid_argument("Invalid algorithm cache filename: " + name);
        // Publish a complete snapshot: an interrupted write must not pair a
        // new grammar stamp with old production records.
        const auto suffix = std::to_string(std::chrono::steady_clock::now().time_since_epoch().count());
        const auto pending = std::filesystem::path(directory.string() + ".pending-" + suffix);
        const auto previous = std::filesystem::path(directory.string() + ".previous-" + suffix);
        std::filesystem::create_directories(pending);
        struct Cleanup {
            std::filesystem::path path;
            ~Cleanup() { std::error_code error; std::filesystem::remove_all(path, error); }
        } cleanup{pending};
        for (const auto& [name, bytes] : metadata.cache) {
            std::ofstream out(pending / name, std::ios::binary | std::ios::trunc);
            out.exceptions(std::ios::badbit | std::ios::failbit);
            out.write(bytes.data(), static_cast<std::streamsize>(bytes.size()));
        }
        const bool existed = std::filesystem::exists(directory);
        if (existed) std::filesystem::rename(directory, previous);
        try {
            std::filesystem::rename(pending, directory);
        } catch (...) {
            if (existed) std::filesystem::rename(previous, directory);
            throw;
        }
        if (existed) std::filesystem::remove_all(previous);
    }
}
