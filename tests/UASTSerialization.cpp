#include <gtest/gtest.h>
import AST.Frontend;
import LLIR.LangAPIMembersAccess;
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
    if constexpr (std::is_arithmetic_v<T>) {
        out.write(reinterpret_cast<const char*>(&value), sizeof(value));
    } else if constexpr (std::is_same_v<T, std::string>) {
        write(out, value.size());
        out.write(value.data(), value.size());
    } else if constexpr (Variant<T>::value) {
        write(out, value.index());
        std::visit([&](const auto& item) { write(out, item); }, value);
    } else if constexpr (requires { LLIR::Serialize::MembersAccess::get(value); }) {
        std::apply([&](const auto&... fields) { (write(out, fields), ...); }, LLIR::Serialize::MembersAccess::get(value));
    } else {
        write(out, value.size());
        for (const auto& item : value) write(out, item);
    }
}

template<class T> void read(std::istream& in, T& value) {
    if constexpr (std::is_arithmetic_v<T>) {
        in.read(reinterpret_cast<char*>(&value), sizeof(value));
    } else if constexpr (std::is_same_v<T, std::string>) {
        std::size_t size{};
        read(in, size);
        value.resize(size);
        in.read(value.data(), size);
    } else if constexpr (Variant<T>::value) {
        std::size_t index{};
        read(in, index);
        readVariant(in, value, index);
    } else if constexpr (requires { LLIR::Serialize::MembersAccess::get(value); }) {
        std::apply([&](auto&... fields) { (read(in, fields), ...); }, LLIR::Serialize::MembersAccess::get(value));
    } else {
        std::size_t size{};
        read(in, size);
        value.resize(size);
        for (auto& item : value) read(in, item);
    }
}

template<class T> void roundTrip(const T& original) {
    std::stringstream wire;
    write(wire, original);
    T restored{};
    read(wire, restored);
    ASSERT_TRUE(wire.good());
    std::ostringstream again;
    write(again, restored);
    EXPECT_EQ(wire.str(), again.str());
}
}

TEST(UASTSerialization, EveryNewNode) {
    const AST::SourcePosition pos{"roundtrip.isc", 42, 11, 3, 7};
    const AST::PythonNode leaf{"ID", "value", "captured", pos, false, {}};
    const AST::PythonNode python{"expr", "expression", "", pos, false, {leaf}};
    const AST::CaptureBinding binding{"captured", true, true};
    const AST::PythonAction action{python, {binding}, pos, "result"};
    roundTrip(pos);
    roundTrip(leaf);
    roundTrip(python);
    roundTrip(binding);
    roundTrip(action);
    roundTrip(AST::FailBlock{{"fail", "handler"}, {"captured"}, action, pos});
    roundTrip(AST::FailBinding{{"handler", "fallback"}, pos});
    roundTrip(AST::FailMarker{{"handler"}, {"captured"}, pos});
    roundTrip(AST::RegionCapture{'%', pos});
    roundTrip(AST::DynamicPattern{"captured", python, pos});
    roundTrip(AST::Counter{"expression", "42", python, pos});
    roundTrip(AST::SharedCounterRegistration{"counter", pos});
    roundTrip(AST::VariableCapture{"captured", pos});
    roundTrip(AST::DeclarationSyntax{{"inline"}, {"param"}, {"templateParam"}, pos});
    roundTrip(AST::AdvancedRule{python, pos});
    roundTrip(AST::FrontendFeature{action});
}
