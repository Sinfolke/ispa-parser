/**
 * ispastdlib/traits.hpp - is_shared_ptr / is_vector / is_variant / is_match_result / has_ast_print
 * Part of the split ISPA std lib; include <ispastdlib.hpp> for everything.
 */
#pragma once
#include <ispastdlib/core.hpp>

namespace ISPA_STD {
    template<typename DataStorageType, typename IT>
    struct MatchResult;
    template<typename DataStorageType, typename Enable>
    class Node;
    template<typename... Ts>
    class RawToken;
    template<typename T>
    struct is_shared_ptr {
        static constexpr bool value = false;
        using element_type = void;
    };

    template<typename T>
    struct is_shared_ptr<std::shared_ptr<T>> {
        static constexpr bool value = true;
        using element_type = T;
    };
    template<typename T>
    struct is_vector : std::false_type {};

    template<typename T, typename Alloc>
    struct is_vector<std::vector<T, Alloc>> : std::true_type {};

    template<typename T>
    struct is_variant : std::false_type {};

    template<typename... Ts>
    struct is_variant<std::variant<Ts...>> : std::true_type {};

    template<typename T>
    inline constexpr bool is_vector_v =
        is_vector<std::decay_t<T>>::value;

    template<typename T>
    inline constexpr bool is_variant_v =
        is_variant<std::decay_t<T>>::value;
    template<typename T>
    struct is_match_result : std::false_type {};

    template<typename Data, typename IT>
    struct is_match_result<MatchResult<Data, IT>>
        : std::true_type {};

    template<typename T>
    inline constexpr bool is_match_result_v =
        is_match_result<std::decay_t<T>>::value;
    template<typename T, typename Printer, typename = void>
    struct has_ast_print : std::false_type {};

    template<typename T, typename Printer>
    struct has_ast_print<
        T,
        Printer,
        std::void_t<
            decltype(
                std::declval<const T&>().print(
                    std::declval<Printer&>()
                )
            )
        >
    > : std::true_type {};
    template<typename T, typename Printer, typename = void>
    struct has_write_to_output : std::false_type {};

    template<typename T, typename Printer>
    struct has_write_to_output<
        T,
        Printer,
        std::void_t<
            decltype(
                std::declval<const T&>().write_to_output(
                    std::declval<Printer&>()
                )
            )
        >
    > : std::true_type {};
    template<typename T>
    struct is_node : std::false_type {};

    template<typename DataStorageType, typename Enable>
    struct is_node<Node<DataStorageType, Enable>> : std::true_type {};

    template<typename T>
    inline constexpr bool is_node_v = is_node<std::decay_t<T>>::value;

    template<typename T>
    struct is_raw_token : std::false_type {};

    template<typename... Ts>
    struct is_raw_token<RawToken<Ts...>> : std::true_type {};

    template<typename T>
    inline constexpr bool is_raw_token_v = is_raw_token<std::decay_t<T>>::value;
    // Helper detection traits for C++17 (place at namespace or class scope)
    template <typename T, typename = void>
    struct has_to_string : std::false_type {};

    template <typename T>
    struct has_to_string<T, std::void_t<decltype(std::declval<const T&>().to_string())>> : std::true_type {};

    template <typename T, typename = void>
    struct is_streamable : std::false_type {};

    template <typename T>
    struct is_streamable<T, std::void_t<decltype(std::declval<std::ostringstream&>() << std::declval<const T&>())>> : std::true_type {};
} // namespace ISPA_STD
