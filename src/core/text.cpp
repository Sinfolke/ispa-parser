#include <core/text.h>
namespace core {
    bool startsWith(const std::string& str, const std::string& prefix) {
        // Ensure the prefix is not longer than the string
        if (prefix.size() > str.size()) {
            return false;
        }

        // Compare the beginning of the string with the prefix
        return std::equal(prefix.begin(), prefix.end(), str.begin());
    }
    bool startsWithRange(const std::string& str, char from, char to) {
        return (str[0] >= from && str[0] <= to);
    }
}