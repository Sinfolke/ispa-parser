#pragma once

#include <cstddef>
#include <optional>
#include <string>
#include <utility>

namespace ISPA_STD {
// A count measures successful matcher invocations, never payloads or bytes.
struct CountSpec {
    std::string name;
    std::optional<std::size_t> count;
    std::size_t minimum = 0;

    static CountSpec named(std::string name, std::size_t minimum = 0) {
        return {std::move(name), std::nullopt, minimum};
    }
    static CountSpec fixed(std::size_t count, std::size_t minimum = 0) {
        return {{}, count, count < minimum ? minimum : count};
    }
};
}
