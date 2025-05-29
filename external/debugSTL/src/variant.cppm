export module dstd.variant;
import std;
import std.compat;

template<typename T, typename... Ts>
union VariantUnion {
    T head;
    VariantUnion<Ts...> tail;

    VariantUnion() {}
    ~VariantUnion() {}
};

template<typename T>
union VariantUnion<T> {
    T head;

    VariantUnion() {}
    ~VariantUnion() {}
};

template<typename From, typename To>
constexpr bool is_narrowing_conversion_v = [] {
    struct tester {
        constexpr tester(To) {}
    };
    // Narrowing is only detected in list-initialization like this:
    return std::is_constructible_v<To, From> &&
           !std::is_constructible_v<tester, From>;
}();

export template<typename From, typename To>
concept isNarrowingConversion = !std::is_same_v<From, To> && std::is_arithmetic_v<From> && std::is_arithmetic_v<To> && (
    sizeof(From) > sizeof(To) || std::is_unsigned_v<From> && std::is_signed_v<To> || std::is_floating_point_v<From> && !std::is_floating_point_v<To>
);

template<typename T, typename... Ts>
concept one_of = (std::same_as<T, Ts> || ...);
template<typename T, typename ...Types>
concept constructible_from_one = (std::is_constructible_v<Types, T> + ...) == 1;
template<std::size_t i, typename ...Ts>
concept in_types_range = (i < sizeof...(Ts));
template<typename Fun, typename... Args>
concept one_invocable = (std::invocable<Fun, Args> || ...);
// Concept: IsConstructibleFromDecay<U, T> means U can be constructed from decay_t<T>
template<typename U, typename T>
concept ConstructibleFromDecay = std::is_constructible_v<U, std::decay_t<T>>;

export namespace dstd {
    template<typename...> class variant;
}

template<typename T>
struct is_variant : std::false_type {};

template<typename... Ts>
struct is_variant<dstd::variant<Ts...>> : std::true_type {};
template<typename T>
concept isVariant = is_variant<T>::value;
template<typename... Ts>
concept AllIsVariant = (is_variant<std::decay_t<Ts>>::value && ...);
template<typename... Ts>
concept NoneIsVariant = (!is_variant<std::decay_t<Ts>>::value && ...);
template<typename... Ts>
concept NoneIsSizeT = (!(std::is_same_v<size_t, Ts>) && ...);

template<typename T>
concept NotVariantUnion = !requires(T t) {t.head;};

template<typename ...Ts>
concept NoneIsVariantUnion = (NotVariantUnion<Ts> && ...);

template<typename Visitor, typename... Heads>
requires NoneIsVariant<Heads...> && NoneIsSizeT<Heads...> && NoneIsVariantUnion<Heads...>
decltype(auto) visit_impl(Visitor &visitor,  Heads&&... heads);
template<typename Visitor, typename Variant, typename ...Variants, typename ...Heads>
requires AllIsVariant<Variant, Variants...> && NoneIsVariant<Heads...> && (sizeof ...(Heads) > 0)
decltype(auto) visit_impl(Visitor &visitor, Variant &variant, Variants&&... variants, Heads&& ...heads);
template<typename Visitor, typename Variant, typename ...Variants, typename ...Heads>
requires AllIsVariant<Variant, Variants...> && (sizeof ...(Heads) == 0)
decltype(auto) visit_impl(Visitor &visitor, Variant &variant, Variants&&... variants);


template<typename Visitor, typename T, typename ... Ts, typename ...Variants, typename ...Heads>
decltype(auto) visit_impl_vu(Visitor &visitor, const VariantUnion<T, Ts...> &u, size_t idx, Variants&&... variants, Heads&& ...heads) {
    if constexpr (sizeof ...(Ts) != 0) {
        if (idx == 0) {
            return visit_impl(visitor, std::forward<Variants>(variants)..., std::forward<Heads>(heads)..., u.head);
        } else {
            return visit_impl_vu(visitor, u.tail, idx - 1, std::forward<Variants>(variants)..., std::forward<Heads>(heads)...);
        }
    } else {
        if (idx != 0)
            throw std::bad_variant_access();
        return visit_impl(visitor, std::forward<Variants>(variants)..., std::forward<Heads>(heads)..., u.head);
    }
}
template<typename Visitor, typename... Heads>
requires NoneIsVariant<Heads...> && NoneIsSizeT<Heads...> && NoneIsVariantUnion<Heads...>
decltype(auto) visit_impl(Visitor &visitor,  Heads&&... heads) {
    return visitor(std::forward<Heads>(heads)...);
}
template<typename Visitor, typename Variant, typename ...Variants, typename ...Heads>
requires AllIsVariant<Variant, Variants...> && NoneIsVariant<Heads...> && (sizeof ...(Heads) > 0)
decltype(auto) visit_impl(Visitor &visitor, Variant &variant, Variants&&... variants, Heads&& ...heads) {
    return visit_impl_vu(visitor, variant.getRawData(), variant.index(), variants..., heads...);
}
template<typename Visitor, typename Variant, typename ...Variants, typename ...Heads>
requires AllIsVariant<Variant, Variants...> && (sizeof ...(Heads) == 0)
decltype(auto) visit_impl(Visitor &visitor, Variant &variant, Variants&&... variants) {
    return visit_impl_vu(visitor, variant.getRawData(), variant.index(), variants...);
}
export namespace dstd {
    template<typename ...Types>
    class variant {
        VariantUnion<Types...> data;
        size_t index_storage = 0;

        template<typename T, typename... Ts> requires one_of<T, Ts...> friend bool holds_alternative(const variant<Ts...>& v);
        template<typename T, typename... Ts> requires one_of<T, Ts...> friend T& get(variant<Ts...>& v);
        template<std::size_t I, typename... Ts> requires in_types_range<I, Ts...> friend std::variant_alternative_t<I, variant<Ts...>>& get(variant<Ts...>& v);
        template<typename T, typename... Ts> requires one_of<T, Ts...> friend const T& get(const variant<Ts...>& v);
        template<std::size_t I, typename... Ts> requires in_types_range<I, Ts...> friend std::variant_alternative_t<I, variant<Ts...>>& get(const variant<Ts...>& v);

        template<bool exact, typename T, typename ...Args>
        void construct(Args&&... args) {
            construct_impl<exact, T>(data, args...);
        }
        template<bool exact, typename T, typename U, typename... Us, typename... Args>
        bool construct_impl(VariantUnion<U, Us...>& u, Args&&... args) {
            if constexpr (std::is_same_v<T, U>) {
                new (&u.head) U(std::forward<Args>(args)...);
                return true;
            } else if constexpr (!exact && std::is_constructible_v<U, T> && !isNarrowingConversion<T, U>) {
                new (&u.head) U(std::forward<Args>(args)...);
                return true;
            } else {
                return construct_impl<exact, T>(u.tail, std::forward<Args>(args)...);
            }
        }

        // Base case: reached the last type
        template<bool exact, typename T, typename U, typename... Args>
        bool construct_impl(VariantUnion<U>& u, Args&&... args) {
            if constexpr (std::is_same_v<T, U> || (!exact && std::is_constructible_v<U, T> && !isNarrowingConversion<T, U>)) {
                new (&u.head) U(std::forward<Args>(args)...);
                return true;
            } else {
                static_assert(sizeof...(Args) == 0, "No matching type found in VariantUnion");
                return false;
            }
        }

        // visit implementation
        template<typename Visitor, typename T, typename... Ts>
        decltype(auto) visit_impl(Visitor&& visitor, size_t idx, VariantUnion<T, Ts...>& u) {
            if (idx == 0) {
                return std::invoke(std::forward<Visitor>(visitor), u.head);
            } else {
                return visit_impl(std::forward<Visitor>(visitor), idx - 1, u.tail);
            }
        }

        // Base case
        template<typename Visitor, typename T>
        decltype(auto) visit_impl(Visitor&& visitor, size_t idx, VariantUnion<T>& u) {
            if (idx != 0) {
                throw std::runtime_error("variant index out of bounds");
            }
            return std::invoke(std::forward<Visitor>(visitor), u.head);
        }

        // destroy_impl for VariantUnion<T>
        // Recursive case
        template<typename T, typename... Ts>
        void destroy_element_dynamic(size_t idx, VariantUnion<T, Ts...>& u) {
            if (idx == 0) {
                u.head.~T();
            } else {
                destroy_element_dynamic(idx - 1, u.tail);
            }
        }

        // Base case: only one element left
        template<typename T>
        void destroy_element_dynamic(size_t idx, VariantUnion<T>& u) {
            if (idx == 0) {
                u.head.~T();
            } else {
                // Defensive: this should not happen
                std::terminate();
            }
        }

        template <size_t I, typename U>
        void destroy_element(U& u) {
            if constexpr (I == 0) {
                u.head.~decltype(u.head)();
            } else {
                destroy_element<I-1>(u.tail);
            }
        }
        template<typename T, typename... Ts>
        struct type_index;

        // Exact match
        template<typename T, typename U, typename... Ts>
            requires std::same_as<T, U>
        struct type_index<T, U, Ts...> : std::integral_constant<size_t, 0> {};

        // Constructible and non-narrowing match
        template<typename T, typename U, typename... Ts>
            requires (!std::same_as<T, U>) && (ConstructibleFromDecay<U, T>) && (!isNarrowingConversion<T, U>)
        struct type_index<T, U, Ts...> : std::integral_constant<size_t, 0> {};

        // Recurse if no match or narrowing found
        template<typename T, typename U, typename... Ts>
            requires (!std::same_as<T, U>) && (!ConstructibleFromDecay<U, T> || isNarrowingConversion<T, U>)
        struct type_index<T, U, Ts...> : std::integral_constant<size_t, 1 + type_index<T, Ts...>::value> {};

        // Base case: no match
        template<typename T>
        struct type_index<T> {
            static_assert(sizeof(T) == 0, "type_index: type not found or not constructible in type list");
        };

        template<size_t I, typename... Ts>
        struct type_at;

        template<typename T, typename... Ts>
        struct type_at<0, T, Ts...> {
            using type = T;
        };

        template<size_t I, typename T, typename... Ts>
        struct type_at<I, T, Ts...> {
            using type = typename type_at<I - 1, Ts...>::type;
        };

        template<size_t I, typename... Ts>
        using type_at_t = typename type_at<I, Ts...>::type;

        template<typename T>
        static constexpr size_t index_of() {
            return type_index<T, Types...>::value;
        }

        void destroy() {
            destroy_element_dynamic(index_storage, data);
        }
        template<typename T, typename U, typename... Us>
        T& internal_get(size_t idx, VariantUnion<U, Us...>& u) const {
            if constexpr (std::is_same_v<T, U>) {
                // T and U are the same type
                if (idx != 0)
                    throw std::bad_variant_access();
                return u.head;  // safe to return
            } else {
                // T and U are different types, so we must recurse
                if (idx == 0)
                    throw std::bad_variant_access();
                return internal_get<T>(idx - 1, u.tail);
            }
        }

        template<typename T>
        const T& internal_get(size_t idx, VariantUnion<T>& u) const {
            if (idx != 0)
                throw std::bad_variant_access();
            return u.head;
        }

        template<typename T>
        const T& internal_get(size_t idx, const VariantUnion<T>& u) const {
            if (idx != 0)
                throw std::bad_variant_access();
            return u.head;
        }
        template<typename T, typename U, typename... Us>
        requires (sizeof ...(Us) > 0)
        const T& internal_get(size_t idx, const VariantUnion<U, Us...>& u) const {
            if constexpr (std::is_same_v<T, U>) {
                // T and U are the same type
                if (idx != 0)
                    throw std::bad_variant_access();
                return u.head;  // safe to return
            } else {
                // T and U are different types, so we must recurse
                if (idx == 0)
                    throw std::bad_variant_access();
                return internal_get<T>(idx - 1, u.tail);
            }
        }
        template<size_t I, typename U, typename... Us>
        auto& internal_get(size_t idx, const VariantUnion<U, Us...>& u) const {
            if constexpr (I == 0) {
                // T and U are the same type
                if (idx != 0)
                    throw std::bad_variant_access();
                return u.head;  // safe to return
            } else {
                // T and U are different types, so we must recurse
                return internal_get<I - 1>(idx - 1, u.tail);
            }
        }

        template<size_t I, typename T>
        auto& internal_get(size_t idx, const VariantUnion<T>& u) const {
            if (I != 0 || idx != 0)
                throw std::bad_variant_access();
            return u.head;
        }
        template<typename T, typename U, typename... Us>
        T& internal_get(size_t idx, VariantUnion<U, Us...>& u) {
            if constexpr (std::is_same_v<T, U>) {
                // T and U are the same type
                if (idx != 0)
                    throw std::bad_variant_access();
                return u.head;  // safe to return
            } else {
                // T and U are different types, so we must recurse
                return internal_get<T>(idx - 1, u.tail);
            }
        }

        template<typename T>
        T& internal_get(size_t idx, VariantUnion<T>& u) {
            if (idx != 0)
                throw std::bad_variant_access();
            return u.head;
        }
        template<size_t I, typename U, typename... Us>
        auto& internal_get(size_t idx, VariantUnion<U, Us...>& u) {
            if constexpr (I == 0) {
                // T and U are the same type
                if (idx != 0)
                    throw std::bad_variant_access();
                return u.head;  // safe to return
            } else {
                // T and U are different types, so we must recurse
                if (idx == 0)
                    throw std::bad_variant_access();
                return internal_get<I - 1>(idx - 1, u.tail);
            }
        }

        template<size_t I, typename T>
        auto& internal_get(size_t idx, VariantUnion<T>& u) {
            if (I != 0 || idx != 0)
                throw std::bad_variant_access();
            return u.head;
        }
        // for copying
        void copy_from(const variant& other) {
            if (other.index_storage == variant_npos) {
                std::cout << "Warning: variant become valueless by in copy assignment operator because assign variant is valueless" << std::endl;
                index_storage = other.index_storage; // valueless
                return;
            }

            try {
                copy_construct_at_index(other.index_storage, other.data);
                index_storage = other.index_storage;
            } catch (...) {
                index_storage = variant_npos; // valueless
                std::cout << "Warning: variant become valueless by in copy assignment operator because an exception is thrown" << std::endl;
            }
        }

        template<size_t I = 0>
        void copy_construct_at_index(size_t index, const VariantUnion<Types...>& other_data) {
            if constexpr (I < sizeof...(Types)) {
                if (index == I) {
                    using T = type_at_t<I, Types...>;
                    const T& other_val = internal_get<I>(index, other_data);
                    try {
                        new (&data.head) T(other_val);
                    } catch (std::exception &e) {
                        std::cout << "Warning: variant become valueless by in operator= with exception: " << e.what() << std::endl;
                        index_storage = std::variant_npos;
                    } catch (...) {
                        std::cout << "Warning: variant become valueless by unknown exception in operator=" << std::endl;
                        index_storage = std::variant_npos;
                    }
                } else {
                    copy_construct_at_index<I + 1>(index, other_data);
                }
            }
        }
        template<size_t I = 0>
        void move_construct_at_index(size_t index, VariantUnion<Types...>&& other_data) {
            if constexpr (I < sizeof...(Types)) {
                if (index == I) {
                    using T = type_at_t<I, Types...>;
                    T& other_val = internal_get<I>(index, other_data);
                    new (&data.head) T(std::move(other_val));
                } else {
                    move_construct_at_index<I + 1>(index, std::move(other_data));
                }
            }
        }

    public:
        /* EXTENSION !!! */
        auto &getRawData() const {
            return data;
        }
        static constexpr size_t variant_npos = static_cast<size_t>(-1);
        variant(std::source_location loc = std::source_location::current()) {
            try {
                new (&data.head) decltype(data.head)();
                index_storage = 0;
            } catch (std::exception &e) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant become valueless by in move constructor with exception: " << e.what() << std::endl;
                index_storage = std::variant_npos;
            } catch (...) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant become valueless by unknown exception in move constructor" << std::endl;
                index_storage = std::variant_npos;
            }
        };

        ~variant() {
            destroy();
        }

        template<typename T, typename ...Args>
        requires one_of<T, Types...> || constructible_from_one<T, Types...>
        variant(T&& value, Args... args, const std::source_location loc = std::source_location::current()) {
            try {
                construct<false, T>(std::forward<T>(value), args...);
                index_storage = index_of<T>();
            } catch (std::exception &e) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant become valueless by in move constructor with exception: " << e.what() << std::endl;
                index_storage = std::variant_npos;
            } catch (...) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant become valueless by unknown exception in move constructor" << std::endl;
                index_storage = std::variant_npos;
            }
        }
        template<typename T, typename ...Args>
        requires one_of<T, Types...> || constructible_from_one<T, Types...>
        variant(T &value, Args... args, const std::source_location loc = std::source_location::current()) {
            try {
                construct<false, T>(std::forward<T>(value), args...);
                index_storage = index_of<T>();
            } catch (std::exception &e) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant become valueless by in move constructor with exception: " << e.what() << std::endl;
                index_storage = std::variant_npos;
            } catch (...) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant become valueless by unknown exception in move constructor" << std::endl;
                index_storage = std::variant_npos;
            }
        }
        template<typename T, typename... Args>
        requires one_of<T, Types...> || constructible_from_one<T, Types...>
        explicit variant(std::in_place_type_t<T>, Args&&... args, const std::source_location loc = std::source_location::current()) {
            try {
                construct<true, T>(std::forward<Args>(args)...);  // construct in-place
                index_storage = index_of<T>();
            } catch (std::exception &e) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant become valueless by in move constructor with exception: " << e.what() << std::endl;
                index_storage = std::variant_npos;
            } catch (...) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant become valueless by unknown exception in move constructor" << std::endl;
                index_storage = std::variant_npos;
            }
        }
        variant(variant&& other, const std::source_location loc = std::source_location::current()) noexcept {
            try {
                if (other.index_storage == std::numeric_limits<size_t>::max()) {

                    std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                    std::cout << "Warning: variant become valueless by in move constructor because assign variant is valueless" << std::endl;
                    index_storage = other.index_storage;
                    // No active member, nothing to construct
                } else {
                    move_construct_at_index(other.index_storage, std::move(other.data));
                    index_storage = other.index_storage;
                }
            } catch (std::exception &e) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant become valueless by in move constructor with exception: " << e.what() << std::endl;
                index_storage = std::variant_npos;
            } catch (...) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant become valueless by unknown exception in move constructor" << std::endl;
                index_storage = std::variant_npos;
            }
        }
        variant(const variant& other, const std::source_location loc = std::source_location::current()) {
            try {
                if (other.index_storage == std::variant_npos) {
                    std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                    std::cout << "Warning: variant become valueless by in move constructor because assign variant is valueless" << std::endl;
                    index_storage = std::variant_npos;
                } else {
                    copy_construct_at_index(other.index_storage, other.data);
                    index_storage = other.index_storage;
                }
            } catch (std::exception& e) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant became valueless by exception in copy constructor: " << e.what() << std::endl;
                index_storage = std::variant_npos;
            } catch (...) {
                std::cout << "[" << loc.file_name() << ":" << loc.line() << "] ";
                std::cout << "Warning: variant became valueless by unknown exception in copy constructor" << std::endl;
                index_storage = std::variant_npos;
            }
        }
        variant& operator=(const variant& other) {
            if (this != &other) {
                destroy();
                copy_from(other);
            }
            return *this;
        }
        [[nodiscard]] auto index() const noexcept -> const size_t& {
            return index_storage;
        }
        [[nodiscard]] auto valueless_by_exception() const noexcept -> bool {
            return index_storage == variant_npos;
        }
        template<typename T, typename... Args>
        requires one_of<T, Types...> || constructible_from_one<T, Types...>
        T& emplace(Args&&... args) {
            destroy();
            construct_impl<T>(data, std::forward<Args>(args)...);
            index_storage = index_of<T>();
            return get<T>(*this);
        }

        auto swap(variant &other) noexcept {
            std::swap(index_storage, other.index_storage);
            std::swap(data, other.data);
        }
        template<typename Visitor>
        requires one_invocable<Visitor, Types...>
        decltype(auto) visit(Visitor&& visitor) {
            return visit_impl(std::forward<Visitor>(visitor), index_storage, data);
        }
    };
    template <typename Visitor, typename... Variants>
    decltype(auto) visit(Visitor&& visitor, Variants&&... variants) {
        return ::visit_impl(visitor, std::forward<Variants>(variants)...);
    }
    template<typename T, typename... Types>
    requires one_of<T, Types...>
    bool holds_alternative(const variant<Types...>& v) {
        return v.index() == variant<Types...>::template index_of<T>();
    }
    template<typename T, typename... Types>
    requires one_of<T, Types...>
    T& get(variant<Types...>& v) {
        if (v.valueless_by_exception()) {
            throw std::bad_variant_access();
        }
        if (v.index() != v.template index_of<T>()) {
            throw std::bad_variant_access();
        }
        return v.template internal_get<T>(v.index(), v.data);
    }
    template<std::size_t I, typename... Types>
    requires in_types_range<I, Types...>
    std::variant_alternative_t<I, variant<Types...>>& get(variant<Types...>& v) {
        if (v.valueless_by_exception()) {
            throw std::bad_variant_access();
        }
        if (v.index() != I)
            throw std::bad_variant_access();
        return v.internal_get(v.index(), v.data);
    }
    template<typename T, typename... Types>
    requires one_of<T, Types...>
    T* get_if(variant<Types...>& v) {
        if (v.index() != variant<Types...>::template index_of<T>())
            return nullptr;
        return &get<T>(v);
    }
    template<std::size_t I, typename... Types>
    requires in_types_range<I, Types...>
    constexpr std::variant_alternative_t<I, variant<Types...>>& get_if(variant<Types...>& v) {
        if (v.index() != I)
            return nullptr;
        return &get<I>(v);
    }

    template<typename T, typename... Types>
    requires one_of<T, Types...>
    const T& get(const variant<Types...>& v) {
        if (v.valueless_by_exception()) {
            throw std::bad_variant_access();
        }
        if (v.index() != v.template index_of<T>()) {
            throw std::bad_variant_access();
        }
        return v.template internal_get<T>(v.index(), v.data);
    }
    template<std::size_t I, typename... Types>
    requires in_types_range<I, Types...>
    std::variant_alternative_t<I, variant<Types...>>& get(const variant<Types...>& v) {
        if (v.valueless_by_exception()) {
            throw std::bad_variant_access();
        }
        if (v.index() != I)
            throw std::bad_variant_access();
        return v.internal_get(v.index(), v.data);
    }
    template<typename T, typename... Types>
    requires one_of<T, Types...>
    const T* get_if(const variant<Types...>& v) {
        if (v.index() != variant<Types...>::template index_of<T>())
            return nullptr;
        return &get<T>(v);
    }
    template<std::size_t I, typename... Types>
    requires in_types_range<I, Types...>
    constexpr std::variant_alternative_t<I, variant<Types...>>& get_if(const variant<Types...>& v) {
        if (v.index() != I)
            return nullptr;
        return &get<I>(v);
    }
    template<typename ...Types>
    requires requires(const variant<Types...>& lhs, const variant<Types...>& rhs)
    {
        visit([](auto&& a, auto&& b) {
            return a == b;
        }, lhs, rhs) -> std::template same_as<bool>;
    }
    constexpr bool operator==(const variant<Types...>& lhs, const variant<Types...>& rhs) {
        return visit([](auto&& a, auto&& b) {
            return a == b;
        }, lhs, rhs);
    }

    template<typename ...Types>
    requires requires(const variant<Types...>& lhs, const variant<Types...>& rhs)
    {
        visit([](auto&& a, auto&& b) {
            return a != b;
        }, lhs, rhs) -> std::template same_as<bool>;
    }
    constexpr bool operator!=(const variant<Types...>& lhs, const variant<Types...>& rhs) {
        return visit([](auto&& a, auto&& b) {
            return a != b;
        }, lhs, rhs);
    }

    template<typename ...Types>
    requires requires(const variant<Types...>& lhs, const variant<Types...>& rhs)
    {
        visit([](auto&& a, auto&& b) {
            return a > b;
        }, lhs, rhs) -> std::template same_as<bool>;
    }
    constexpr bool operator>(const variant<Types...>& lhs, const variant<Types...>& rhs) {
        return visit([](auto&& a, auto&& b) {
            return a > b;
        }, lhs, rhs);
    }

    template<typename ...Types>
    requires requires(const variant<Types...>& lhs, const variant<Types...>& rhs)
    {
        visit([](auto&& a, auto&& b) {
            return a < b;
        }, lhs, rhs) -> std::template same_as<bool>;
    }
    constexpr bool operator<(const variant<Types...>& lhs, const variant<Types...>& rhs) {
        return visit([](auto&& a, auto&& b) {
            return a < b;
        }, lhs, rhs);
    }
    template<typename ...Types>
    requires requires(const variant<Types...>& lhs, const variant<Types...>& rhs)
    {
        visit([](auto&& a, auto&& b) {
            return a >= b;
        }, lhs, rhs) -> std::template same_as<bool>;
    }
    constexpr bool operator>=(const variant<Types...>& lhs, const variant<Types...>& rhs) {
        return visit([](auto&& a, auto&& b) {
            return a < b;
        }, lhs, rhs);
    }
    template<typename ...Types>
    requires requires(const variant<Types...>& lhs, const variant<Types...>& rhs)
    {
        visit([](auto&& a, auto&& b) {
            return a <= b;
        }, lhs, rhs) -> std::template same_as<bool>;
    }
    constexpr bool operator<=(const variant<Types...>& lhs, const variant<Types...>& rhs) {
        return visit([](auto&& a, auto&& b) {
            return a < b;
        }, lhs, rhs);
    }
}
namespace std {
    template<typename ...Types>
    void swap(dstd::variant<Types...>& lhs, dstd::variant<Types...>& rhs) noexcept {
        lhs.swap(rhs);
    }
}