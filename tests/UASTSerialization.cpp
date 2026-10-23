#include <gtest/gtest.h>
import AST.Frontend;
import UAST.Python;
import LangAPI.Accessor;
import dstd;
import std;

namespace {
template<class> struct Variant : std::false_type {};
template<class... T> struct Variant<std::variant<T...>> : std::true_type {};

template<class T> void write(std::ostream& out, const T& value);
template<class T> void read(std::istream& in, T& value);

template<class T, std::size_t I = 0>
void readVariant(std::istream& in, T& value, std::size_t index) {
    if constexpr (I < std::variant_size_v<T>) {
        if (I == index) {
            std::variant_alternative_t<I, T> item{};
            read(in, item);
            value = std::move(item);
        } else readVariant<T, I + 1>(in, value, index);
    } else throw std::runtime_error("invalid variant index");
}

template<class T> void write(std::ostream& out, const T& value) {
    if constexpr (std::is_arithmetic_v<T> || std::is_enum_v<T>) {
        out.write(reinterpret_cast<const char*>(&value), sizeof(value));
    } else if constexpr (std::is_same_v<T, std::monostate>) {
    } else if constexpr (requires { typename T::element_type; }) {
        write(out, bool(value));
        if (value) write(out, *value);
    } else if constexpr (std::is_same_v<T, std::string>) {
        write(out, value.size());
        out.write(value.data(), value.size());
    } else if constexpr (Variant<T>::value) {
        write(out, value.index());
        std::visit([&](const auto& item) { write(out, item); }, value);
    } else if constexpr (requires { LangAPI::MembersAccess::get(value); }) {
        std::apply([&](const auto&... fields) { (write(out, fields), ...); }, LangAPI::MembersAccess::get(value));
    } else {
        write(out, value.size());
        for (const auto& item : value) write(out, item);
    }
}

template<class T> void read(std::istream& in, T& value) {
    if constexpr (std::is_arithmetic_v<T> || std::is_enum_v<T>) {
        in.read(reinterpret_cast<char*>(&value), sizeof(value));
    } else if constexpr (std::is_same_v<T, std::monostate>) {
    } else if constexpr (requires { typename T::element_type; }) {
        bool present{};
        read(in, present);
        if (present) { value = std::make_shared<typename T::element_type>(); read(in, *value); }
        else value.reset();
    } else if constexpr (std::is_same_v<T, std::string>) {
        std::size_t size{};
        read(in, size);
        value.resize(size);
        in.read(value.data(), size);
    } else if constexpr (Variant<T>::value) {
        std::size_t index{};
        read(in, index);
        readVariant(in, value, index);
    } else if constexpr (requires { LangAPI::MembersAccess::get(value); }) {
        std::apply([&](auto&... fields) { (read(in, fields), ...); }, LangAPI::MembersAccess::get(value));
    } else {
        std::size_t size{};
        read(in, size);
        value.resize(size);
        for (auto& item : value) read(in, item);
    }
}

template<class T> T roundTrip(const T& original) {
    std::stringstream wire;
    write(wire, original);
    T restored{};
    read(wire, restored);
    if (!wire.good()) throw std::runtime_error("deserialization failed");
    std::ostringstream again;
    write(again, restored);
    EXPECT_EQ(wire.str(), again.str());
    return restored;
}

template<class T, std::size_t Count> constexpr bool reflectsAllMembers =
    std::tuple_size_v<decltype(LangAPI::MembersAccess::get(std::declval<T&>()))> == Count;
static_assert(reflectsAllMembers<AST::SourcePosition, 5>);
static_assert(reflectsAllMembers<AST::PythonNode, 6>);
static_assert(reflectsAllMembers<AST::CaptureBinding, 3>);
static_assert(reflectsAllMembers<AST::PythonAction, 5>);
static_assert(reflectsAllMembers<AST::FailBlock, 4>);
static_assert(reflectsAllMembers<AST::FailBinding, 2>);
static_assert(reflectsAllMembers<AST::FailMarker, 3>);
static_assert(reflectsAllMembers<AST::RegionCapture, 2>);
static_assert(reflectsAllMembers<AST::DynamicPattern, 3>);
static_assert(reflectsAllMembers<AST::Counter, 4>);
static_assert(reflectsAllMembers<AST::SharedCounterRegistration, 2>);
static_assert(reflectsAllMembers<AST::VariableCapture, 2>);
static_assert(reflectsAllMembers<AST::DeclarationSyntax, 5>);
static_assert(reflectsAllMembers<AST::AdvancedRule, 2>);
static_assert(reflectsAllMembers<AST::SpacePattern, 1>);
}

TEST(UASTSerialization, EveryNewNode) {
    const AST::SourcePosition pos{"roundtrip.isc", 42, 11, 3, 7};
    const AST::PythonNode leaf{"ID", "value", "captured", pos, false, {}};
    const AST::PythonNode python{"expr", "expression", "", pos, false, {leaf}};
    const AST::CaptureBinding binding{"captured", true, true};
    AST::PythonAction action{python, {binding}, pos, "result"};
    action.code = UAST::parsePythonModule("ctx.ast.value = 3\n", {"roundtrip.isc", 42, 0, 3, 7});
    roundTrip(pos);
    roundTrip(leaf);
    roundTrip(python);
    roundTrip(binding);
    const auto restored = roundTrip(action);
    EXPECT_EQ(restored.target, "result");
    ASSERT_TRUE(std::holds_alternative<UAST::py::Module>(restored.code));
    EXPECT_EQ(std::get<UAST::py::Module>(restored.code).body.size(), 1u);
    EXPECT_EQ(restored.python.children.front().scalar, "captured");
    EXPECT_EQ(restored.position.file, "roundtrip.isc");
    EXPECT_EQ(restored.position.offset, 42u);
    EXPECT_EQ(restored.position.length, 11u);
    EXPECT_EQ(restored.position.line, 3u);
    EXPECT_EQ(restored.position.column, 7u);
    ASSERT_EQ(restored.bindings.size(), 1u);
    EXPECT_EQ(restored.bindings.front().name, "captured");
    EXPECT_TRUE(restored.bindings.front().optional);
    EXPECT_TRUE(restored.bindings.front().list);
    roundTrip(AST::FailBlock{{"fail", "handler"}, {"captured"}, action, pos});
    roundTrip(AST::FailBinding{{"handler", "fallback"}, pos});
    roundTrip(AST::FailMarker{{"handler"}, {"captured"}, pos});
    roundTrip(AST::RegionCapture{'%', pos});
    roundTrip(AST::DynamicPattern{"captured", action, pos});
    roundTrip(AST::Counter{"expression", "42", action, pos});
    roundTrip(AST::SharedCounterRegistration{"counter", pos});
    roundTrip(AST::VariableCapture{"captured", pos});
    roundTrip(AST::DeclarationSyntax{{"inline"}, {"param"}, {"templateParam"}, pos});
    roundTrip(AST::AdvancedRule{python, pos});
    roundTrip(AST::SpacePattern{pos});
    roundTrip(AST::FrontendFeature{action});
}
