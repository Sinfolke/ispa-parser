import std;
import dstd.variant;
constexpr void assert(bool cond, const char* message, std::source_location loc = std::source_location::current()) {
    if (!cond) {
        std::cout << "[" << loc.file_name() << ":" << loc.line() << "]: " << std::endl;
        throw std::runtime_error(message);
    }
}

constexpr void assert(bool cond, std::source_location loc = std::source_location::current()) {
    if (!cond) {
        std::cout << "[" << loc.file_name() << ":" << loc.line() << "]: \n" << std::endl;
        throw std::runtime_error("Assertion failed");
    }
}
class ThrowMe {
public:
    ThrowMe() {
        throw std::runtime_error("ThrowMe");
    }
};
int main() {
    dstd::variant<int, double, std::string> v1(42);
    assert(dstd::get<int>(v1) == 42);

    dstd::variant<int, double, std::string> v2(3.14);
    assert(dstd::get<double>(v2) == 3.14);

    dstd::variant<int, double, std::string> v3("hello");
    assert(dstd::get<std::string>(v3) == "hello");

    assert(dstd::holds_alternative<int>(v1));
    assert(!dstd::holds_alternative<double>(v1));

    try {
        dstd::get<double>(v1);
        assert(false); // Should not reach here
    } catch (const std::bad_variant_access&) {
        // Expected
    }

    dstd::variant<int, std::string> a("copy_test");
    dstd::variant<int, std::string> b = a; // copy
    assert(dstd::get<std::string>(b) == "copy_test");

    dstd::variant<int, std::string> c = std::move(a); // move
    assert(dstd::get<std::string>(c) == "copy_test");

    a = std::string("assigned");
    assert(dstd::holds_alternative<std::string>(a));
    assert(dstd::get<std::string>(a) == "assigned");

    dstd::variant<int, std::string> visit_me("visit me");

    auto result = dstd::visit([](auto&& val) -> std::string {
        using T = std::decay_t<decltype(val)>;
        if constexpr (std::is_same_v<T, int>)
            return std::to_string(val);
        else
            return val;
    }, visit_me);

    assert(result == "visit me");

    // valueless by exception check
    try {
        dstd::variant<int, ThrowMe> throw_me(std::in_place_type<ThrowMe>);
        assert(throw_me.valueless_by_exception(), "Not valueless");
        dstd::get<ThrowMe>(throw_me);
        assert(false, "Not throw on valueless");
        assert(!dstd::holds_alternative<ThrowMe>(throw_me), "Not holds");
    } catch (std::bad_variant_access &e) {}

    // default constructor check
    dstd::variant<int, std::string> def;
    assert(dstd::holds_alternative<int>(def));

    // self move and std::move
    v1 = v1;
    v1 = std::move(v1);
    dstd::variant<int, double, std::string> vi("test");
    dstd::visit([](auto&& x) {
        using T = std::decay_t<decltype(x)>;
        if constexpr (std::is_same_v<T, std::string>)
            assert(x == "test");
    }, vi);

}

