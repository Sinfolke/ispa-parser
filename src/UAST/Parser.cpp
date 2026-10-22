module;
#include <output/Parser.h>
module UAST.Parser;
import std;
namespace {
// Generic, metadata-driven snapshot of the generated tree (members()/members_str()).
struct Snapshot {
    using P = UAST::SourcePosition;
    using R = UAST::PythonNode;
    std::string file;
    template<class T> static consteval std::string_view type_name() {
#if defined(_MSC_VER)
        constexpr std::string_view signature = __FUNCSIG__;
        auto start = signature.find("type_name<");
        if (start == std::string_view::npos) return "unknown";
        start += 10;
        auto finish = signature.find(">(void)", start);
        if (finish == std::string_view::npos) return "unknown";
        auto name = signature.substr(start, finish - start);
#else
        constexpr std::string_view signature = __PRETTY_FUNCTION__;
        auto start = signature.find("T = ");
        if (start == std::string_view::npos) return "unknown";
        start += 4;
        auto finish = signature.find_first_of(";]", start);
        auto name = signature.substr(start, finish - start);
#endif
        auto ns = name.rfind("::");
        return ns == std::string_view::npos ? name : name.substr(ns + 2);
    }
    R operator()(const P& x, const P&) const {
        return {"SourcePosition", {}, {}, x, false, {
            {"string", "file", x.file, x, false, {}},
            {"integer", "offset", std::to_string(x.offset), x, false, {}},
            {"integer", "length", std::to_string(x.length), x, false, {}},
            {"integer", "line", std::to_string(x.line), x, false, {}},
            {"integer", "column", std::to_string(x.column), x, false, {}}
        }};
    }
    R operator()(std::monostate, const P& p) const { return {"absent", {}, {}, p, true, {}}; }
    R operator()(const std::string& x, const P& p) const { return {"string", {}, x, p, false, {}}; }
    R operator()(char x, const P& p) const { return {"char", {}, std::string(1,x), p, false, {}}; }
    R operator()(bool x, const P& p) const { return {"bool", {}, x ? "true" : "false", p, false, {}}; }
    template<class T> R operator()(const std::shared_ptr<T>& x, const P& p) const {
        return x ? (*this)(*x, p) : R{"pointer", {}, {}, p, true, {}};
    }
    template<class T> R operator()(const UAST::Node<T>& x, const P& parent) const {
        if (x.empty()) return {"node", {}, {}, parent, true, {}};
        auto p = UAST::positionOf(x, file);
        auto result = (*this)(x.data(), p);
        result.position = p;
        return result;
    }
    template<class... T> R operator()(const std::variant<T...>& x, const P& p) const {
        return {"variant", {}, std::to_string(x.index()), p, false,
            {std::visit([&](const auto& element) {return (*this)(element,p);}, x)}};
    }
    template<class T, class Alloc> R operator()(const std::vector<T,Alloc>& x, const P& p) const {
        R result{"sequence", {}, {}, p, false, {}};
        result.children.reserve(x.size());
        for (const auto& element : x) result.children.push_back((*this)(element,p));
        return result;
    }
    template<class T> requires requires(const T& x) { x.members(); T::members_str(); }
    R operator()(const T& x, const P& p) const {
        R result{std::string(type_name<T>()), {}, {}, p, false, {}};
        constexpr auto names = T::members_str();
        const auto tuple = x.members();
        static_assert(names.size() == std::tuple_size_v<decltype(tuple)>);
        result.children.reserve(names.size());
        std::apply([&](const auto&... values) {
            std::size_t index = 0;
            (([&] {
                auto child = (*this)(values, p);
                child.field = names[index++];
                result.children.push_back(std::move(child));
            }()), ...);
        }, tuple);
        return result;
    }
};
}

UAST::PythonNode UAST::describe(const UAST::advanced_rule& value, const UAST::SourcePosition& position) {
    return Snapshot{position.file}(value, position);
}
