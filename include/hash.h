#include <vector>
#include <set>
#include <algorithm>
namespace std {
    template <typename T>
    struct hash<vector<T>> {
        size_t operator()(const vector<T>& vec) const noexcept {
            size_t seed = vec.size();  // Start with size as base
            for (const auto& elem : vec) {
                // Combine element hash with seed using the same method as boost::hash_combine
                seed ^= hash<T>{}(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
}
namespace std {
    template<typename T>
    struct hash<set<T>> {
        size_t operator()(const set<T>& set) const noexcept {
            size_t seed = set.size();  // Include size in hash
            for (const auto& elem : set) {
                seed ^= hash<T>{}(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
}
namespace std {
    template<typename T1, typename T2>
    struct hash<std::pair<T1, T2>> {
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            std::size_t h1 = std::hash<T1>{}(p.first);
            std::size_t h2 = std::hash<T2>{}(p.second);
            // Combine the hashes (standard way)
            return h1 ^ (h2 << 1); // or use boost::hash_combine style if needed
        }
    };
}