#pragma once

#include <cstddef>
#include <concepts>
#include <optional>
#include <stdexcept>
#include <string>
#include <type_traits>
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
    template<std::integral Integer>
        requires (!std::same_as<std::remove_cv_t<Integer>, bool>)
    static CountSpec fixed(Integer value, std::size_t minimum = 0) {
        if constexpr (std::is_signed_v<Integer>)
            if (value < 0) throw std::invalid_argument("a repetition count cannot be negative");
        if (!std::in_range<std::size_t>(value))
            throw std::out_of_range("repetition count exceeds the supported range");
        const auto count = static_cast<std::size_t>(value);
        return {{}, count, count < minimum ? minimum : count};
    }
};
}
