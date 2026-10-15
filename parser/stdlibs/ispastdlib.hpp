/**
 * C++ ispa std lib 1.2
 * It contains standard declarations and every C++ generated parser would link against it
*/
#pragma once
#ifndef _ISPA_STD_LIB_CPP
#define _ISPA_STD_LIB_CPP
#include <sstream>
#include <map>
#include <vector>
#include <deque>
#include <string>
#include <any>
#include <stdexcept>
#include <fstream>
#include <variant>
#include <optional>
#include <limits>
#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <memory>
#ifdef _WIN32
#include <windows.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")
#else
#include <execinfo.h>
#include <cstdlib>
#endif
#ifndef STRINGIFY
/**
 * @brief does #x
 * 
 */
#define STRINGIFY(x) #x
#endif
#ifndef TOSTRING
/**
 * @brief Converts to a string literal non-quoted value
 * 
 */
#define TOSTRING(x) STRINGIFY(x)
#endif

/*
    Library version is not being updated with each change for now and remains 1.0
*/

#define _ISPA_STD_LIB_VER 1 // version of the library
#define _ISPA_STD_LIB_SUBVER 0 // the subversion of the library
// this defines the minimum version of an output to have a compatibility with the library version
// for example if the update did only change the way some classes work but not their structure, it is compatible with the downer version.
#define _ISPA_STD_LIB_BACKDOWN 1
#define _ISPA_STD_LIB_BACKDOWN_SUBVER 0
#define _ISPA_GITHUB "https://github.com/Sinfolke/ispa-parser-generator"
#define _ISPA_STD_LIBMARK \
    "ispastdlib.hpp " TOSTRING(_ISPA_STD_LIB_VER) "." TOSTRING(_ISPA_STD_LIB_SUBVER) ": "
#define _ISPA_STD_LIB_CPP
/**
 * @brief standard library for the ISPA-generated parser. Do not try to use it directly but use instead auto generated API
 * 
*/
namespace std {
    template<typename T, typename... Ts>
    auto operator<<(
        std::ostream& os,
        const std::variant<T, Ts...>& v
    ) -> std::ostream& {
        std::visit([&os](const auto& arg) {
            using Arg = std::decay_t<decltype(arg)>;

            if constexpr (!std::is_same_v<Arg, std::monostate>) {
                os << arg;
            }
        }, v);

        return os;
    }
}
namespace ISPA_STD {
    // Sequential {} formatting, compatible with C++17.
    template<typename T>
    std::string fmt_to_string(const T& value) {
        std::ostringstream out;
        out << value;
        return out.str();
    }

    template<typename StrT, typename... Args,
             typename = std::enable_if_t<
                 std::is_constructible_v<std::string, StrT>>>
    std::string fmt(const StrT& format, Args&&... args) {
        std::string res(format);
        std::size_t cursor = 0;

        auto replace_next = [&](const auto& arg) {
            auto pos = res.find("{}", cursor);
            if (pos == std::string::npos)
                return;

            auto value = fmt_to_string(arg);
            res.replace(pos, 2, value);
            cursor = pos + value.size();
        };

        (replace_next(args), ...);
        return res;
    }
    inline std::string capture_stacktrace() {
        std::ostringstream out;

#ifdef _WIN32
        constexpr USHORT max_frames = 64;
        void* frames[max_frames]{};

        const USHORT count = CaptureStackBackTrace(
            0, max_frames, frames, nullptr
        );

        HANDLE process = GetCurrentProcess();

        // Minimal implementation. For production, initialize
        // DbgHelp once per process and synchronize its use.
        if (!SymInitialize(process, nullptr, TRUE))
            return "Symbol initialization failed";

        SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);

        alignas(SYMBOL_INFO)
            char buffer[sizeof(SYMBOL_INFO) + 1024]{};

        auto* symbol = reinterpret_cast<SYMBOL_INFO*>(buffer);
        symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
        symbol->MaxNameLen = 1024;

        for (USHORT i = 0; i < count; ++i) {
            DWORD64 address =
                reinterpret_cast<DWORD64>(frames[i]);

            DWORD64 displacement = 0;

            out << "  #" << i << ' ';

            if (SymFromAddr(
                    process, address, &displacement, symbol)) {
                out << symbol->Name
                    << " +0x" << std::hex << displacement
                    << std::dec;
                    } else {
                        out << frames[i];
                    }

            out << '\n';
        }

        SymCleanup(process);

#else
        void* frames[64];
        int count = backtrace(frames, 64);

        char** symbols = backtrace_symbols(frames, count);

        if (!symbols)
            return "Stack trace unavailable";

        for (int i = 0; i < count; ++i)
            out << "  #" << i << ' ' << symbols[i] << '\n';

        std::free(symbols);
#endif

        return out.str();
    }

    class IspaInternalExcept : public std::exception {
        std::string msg;
        std::string issue;
        bool ispa_side;
        std::string stacktrace;

    public:
        template<typename... Args>
        IspaInternalExcept(
            const char* message,
            const char* issue,
            bool ispa_side,
            Args&&... args
        )
            : msg(fmt(message, std::forward<Args>(args)...)),
              issue(issue ? issue : "Unknown"),
              ispa_side(ispa_side),
              stacktrace(capture_stacktrace())
        {}

        const char* what() const noexcept override {
            return msg.c_str();
        }

        const std::string& err() const noexcept {
            return msg;
        }

        void show() const {
    #ifndef DEBUG
            std::cerr << fmt(
                "INTERNAL UNKNOWN ERROR: the generated parser "
                "encountered an unexpected internal error.\n"
                "This should not occur in a correctly operating "
                "parser generated by the open-source ISPA "
                "parser generator.\n\n"
                "Issue classification: {}\n"
                "Error origin: {}\n"
                "Error message: {}\n\n"
                "Stack trace:\n{}"
                "Mark: " _ISPA_STD_LIBMARK "\n"
                "Repository for contact: " _ISPA_GITHUB "\n",
                issue,
                ispa_side ? "ISPA standard library"
                          : "Generated parser",
                msg,
                stacktrace
            );
    #else
            std::cerr << fmt(
                "ISPA INTERNAL ERROR (DEBUG BUILD)\n\n"
                "Issue classification: {}\n"
                "Error origin: {}\n"
                "Error message: {}\n\n"
                "Stack trace:\n{}",
                issue,
                ispa_side ? "ISPA standard library"
                          : "Generated parser",
                msg,
                stacktrace
            );
    #endif
            std::cerr << '\n';
        }
    };
    class IspaAPIExcept : public std::exception {
        std::string msg;
#ifdef DEBUG
        std::string stacktrace;
#endif
    public:
        template<typename... Args>
        IspaAPIExcept(
            const char* message,
            Args&&... args
        )
            : msg(fmt(message, std::forward<Args>(args)...))
#ifdef DEBUG
              ,stacktrace(capture_stacktrace())
#endif
        {}

        const char* what() const noexcept override {
            return msg.c_str();
        }

        const std::string& err() const noexcept {
            return msg;
        }

        void show() const {
    #ifndef DEBUG
            std::cerr << fmt(
                "Error: {}",
                msg
            );
    #else
            std::cerr << fmt(
                "Error: {}\n",
                "Stack:\n{}\n",
                msg,
                stacktrace
            );
    #endif
            std::cerr << '\n';
        }
    };
    // prior C++20 span type
    template<typename T>
    class Span {
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using const_reference = const T&;
        using size_type = std::size_t;

        Span() : data_(nullptr), size_(0) {}

        Span(pointer data, size_type size)
            : data_(data), size_(size) {}

        template<std::size_t N>
        Span(T (&arr)[N]) // from raw array
            : data_(arr), size_(N) {}
        // Robust converting constructor (like std::span)
        template<typename U,
                 typename = std::enable_if_t<
                     std::is_convertible_v<U (*)[], T (*)[]>
                 >
        >
        Span(const Span<U>& other) noexcept
            : data_(other.data()), size_(other.size()) {}
        [[nodiscard]] pointer data() const { return data_; }
        [[nodiscard]] size_type size() const { return size_; }
        [[nodiscard]] bool empty() const { return size_ == 0; }
        reference operator[](size_type index) {
            return data_[index];
        }
        const_reference operator[](size_type index) const {
            return data_[index];
        }
        reference at(size_type index) const {
            if (index >= size_) throw std::out_of_range("Span::at");
            return data_[index];
        }

        pointer begin() const { return data_; }
        pointer end() const { return data_ + size_; }
    private:
        pointer data_;
        size_type size_;
    };
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Span<T>& span) {
        os << "[";
        for (auto i = 0; i < span.size(); ++i) {
            if (i != 0) os << ", ";
            os << span[i];
        }
        os << "]";
        return os;
    }
    template<typename T, std::size_t N>
    std::ostream& operator<<(std::ostream& os, const std::array<T, N>& arr) {
        os << "[";
        for (auto i = 0; i < arr.size(); ++i) {
            if (i != 0) os << ", ";
            os << arr[i];
        }
        os << "]";
        return os;
    }
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& arr) {
        os << "[";
        for (auto i = 0; i < arr.size(); ++i) {
            if (i != 0) os << ", ";
            os << arr[i];
        }
        os << "]";
        return os;
    }
    template<typename EnumT, typename DataStorageType, typename IT>
    struct MatchResult;
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

    template<typename Rules, typename Data, typename IT>
    struct is_match_result<MatchResult<Rules, Data, IT>>
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
    /*
     * An AST print API that simply generator's work on every language internals
     */
    template<typename OS>
    class ASTPrinter {
    public:
        explicit ASTPrinter(OS& output)
            : out(&output) {}

        explicit ASTPrinter(OS* output = nullptr)
            : out(output) {}

        void set_output(OS* output) {
            out = output;
        }

        void up(bool has_more_siblings = true) {
            branches.push_back(has_more_siblings);
        }

        void down() {
            if (!branches.empty())
                branches.pop_back();
        }

        void node(const char* name, bool last = false) {
            print_prefix(last);
            *out << name << '\n';
        }

        template<typename T>
        void node_with_value(
            const char* name,
            const T& value,
            bool last = false
        ) {
            print_named_value(name, value, last);
        }

        // Print a structured child without creating another printer.
        template<typename T>
        void subtree(
            const char* name,
            const T& value,
            bool last = false
        ) {
            node(name, last);
            up(!last);
            print_subtree(value);
            down();
        }

    private:
        template<typename T>
        void print_named_value(
            const char* name,
            const T& value,
            bool last
        ) {
            using Type = std::decay_t<T>;

            if constexpr (is_shared_ptr<Type>::value) {
                if (value) {
                    // Important: do not stream *value.
                    print_named_value(name, *value, last);
                } else {
                    print_prefix(last);
                    *out << name << ": nullptr\n";
                }
            } else if constexpr (
                is_vector<Type>::value ||
                is_variant<Type>::value ||
                has_write_to_output<Type, ASTPrinter<OS>>::value ||
                has_ast_print<Type, ASTPrinter<OS>>::value
            ) {
                subtree(name, value, last);

            } else {
                print_prefix(last);
                *out << name << ": " << value << '\n';
            }
        }
        template<typename T>
        void print_value(const T& value) {
            if constexpr (is_shared_ptr<std::decay_t<T>>::value) {
                if (value) {
                    print_value(*value);
                } else {
                    *out << "nullptr";
                }
            } else {
                *out << value;
            }
        }

        template<typename T>
        void print_subtree(const T& value) {
            using Type = std::decay_t<T>;

            if constexpr (is_shared_ptr<Type>::value) {
                if (value)
                    print_subtree(*value);
                else
                    node("nullptr", true);

            } else if constexpr (is_vector<Type>::value) {
                for (std::size_t i = 0; i < value.size(); ++i) {
                    const bool last = i + 1 == value.size();

                    node("item", last);
                    up(!last);
                    print_subtree(value[i]);
                    down();
                }

            } else if constexpr (is_variant<Type>::value) {
                std::visit([this](const auto& alternative) {
                    using Alt = std::decay_t<decltype(alternative)>;

                    if constexpr (!std::is_same_v<Alt, std::monostate>)
                        print_subtree(alternative);
                }, value);

            } else if constexpr (
                has_write_to_output<Type, ASTPrinter<OS>>::value
            ) {
                value.write_to_output(*this);

            } else if constexpr (
                has_ast_print<Type, ASTPrinter<OS>>::value
            ) {
                value.print(*this);

            } else {
                node_with_value("value", value, true);
            }
        }

        void print_prefix(bool last) {
            const std::size_t depth = branches.size();

            if (depth == 0)
                return;

            for (std::size_t i = 0; i + 1 < depth; ++i) {
                *out << (branches[i] ? "│   " : "    ");
            }

            *out << (last ? "└── " : "├── ");
        }

    private:
        OS* out = nullptr;
        std::vector<bool> branches;
    };
    template<class Destination, class Source>
    struct is_node_storage_conversion_allowed : std::false_type {};

    template<class T>
    struct is_node_storage_conversion_allowed<std::shared_ptr<T>, T> : std::true_type {};

    template<class T>
    struct is_node_storage_conversion_allowed<T, std::shared_ptr<T>> : std::true_type {};

    template<class EnumT, class DataStorageType,
             class = std::enable_if_t<std::is_class_v<DataStorageType>>>
    class Node {
        std::size_t _startpos = std::string::npos;
        std::size_t _length = 0;
        std::size_t _line = 0;
        std::size_t _column = 0;
        const char* _start = nullptr;
        const char* _end = nullptr;
        EnumT _name = EnumT::NONE;
        bool _empty = true;
        DataStorageType _data{};

        template<typename Other>
        void copy_metadata(const Other& other) {
            _startpos = other.startpos();
            _length = other.length();
            _line = other.line();
            _column = other.column();
            _start = other.start();
            _end = other.end();
            _name = other.name();
            _empty = other.empty();
        }

        // Conversions are instantiated only when invoked, not when a recursive
        // Node<EnumT, shared_ptr<Incomplete>> is first instantiated.
        template<typename SourceStorage>
        void assign_converted(const Node<EnumT, SourceStorage>& other) {
            if constexpr (is_shared_ptr<DataStorageType>::value &&
                          !is_shared_ptr<SourceStorage>::value) {
                using Element = typename is_shared_ptr<DataStorageType>::element_type;
                static_assert(std::is_same_v<Element, SourceStorage>,
                              "Incompatible value-to-pointer Node conversion");
                if (other.empty()) {
                    _data.reset();
                } else {
                    _data = std::make_shared<Element>(other.data());
                }
            } else if constexpr (!is_shared_ptr<DataStorageType>::value &&
                                 is_shared_ptr<SourceStorage>::value) {
                using Element = typename is_shared_ptr<SourceStorage>::element_type;
                static_assert(std::is_same_v<Element, DataStorageType>,
                              "Incompatible pointer-to-value Node conversion");
                if (other.empty() || !other.data()) {
                    _data = DataStorageType{};
                } else {
                    _data = *other.data();
                }
            } else {
                static_assert(!std::is_same_v<SourceStorage, SourceStorage>,
                              "Unsupported cross-storage Node conversion");
            }
            copy_metadata(other);
            if constexpr (is_shared_ptr<DataStorageType>::value) {
                if (!_data) _empty = true;
            }
        }

    public:
        Node() = default;

        Node(std::size_t startpos, const char* start, const char* end,
             std::size_t length, std::size_t line, std::size_t column, EnumT name)
            : _startpos(startpos), _length(length), _line(line),
              _column(column), _start(start), _end(end), _name(name) {}

        template<class... Args,
                 std::enable_if_t<(sizeof...(Args) > 0 &&
                                   std::is_constructible_v<DataStorageType, Args...>), int> = 0>
        Node(std::size_t startpos, const char* start, const char* end,
             std::size_t length, std::size_t line, std::size_t column,
             EnumT name, Args&&... args)
            : _startpos(startpos), _length(length), _line(line),
              _column(column), _start(start), _end(end), _name(name),
              _empty(false), _data(std::forward<Args>(args)...) {}

        Node(const Node&) = default;
        Node(Node&&) noexcept(std::is_nothrow_move_constructible_v<DataStorageType>) = default;
        Node& operator=(const Node&) = default;
        Node& operator=(Node&&) noexcept(std::is_nothrow_move_assignable_v<DataStorageType>) = default;

        template<typename SourceStorage,
                 std::enable_if_t<is_node_storage_conversion_allowed<DataStorageType, SourceStorage>::value, int> = 0>
        Node(const Node<EnumT, SourceStorage>& other) {
            assign_converted(other);
        }

        template<typename SourceStorage,
                 std::enable_if_t<is_node_storage_conversion_allowed<DataStorageType, SourceStorage>::value, int> = 0>
        Node& operator=(const Node<EnumT, SourceStorage>& other) {
            assign_converted(other);
            return *this;
        }

        template<typename IT>
        auto operator=(const MatchResult<EnumT, DataStorageType, IT>& mr) -> Node&;

        template<typename SourceDataType, typename IT>
        Node& operator=(MatchResult<EnumT, SourceDataType, IT>&& result) {
            *this = std::move(result.node);
            return *this;
        }

        template<typename SourceDataType, typename IT>
        Node& operator=(MatchResult<EnumT, SourceDataType, IT>& result) {
            *this = result.node;
            return *this;
        }

        std::size_t endpos() const {
            if (_startpos == std::string::npos || !_start || !_end)
                throw IspaAPIExcept("Can't retrieve end position on an empty token");
            return _startpos + static_cast<std::size_t>(_end - _start);
        }

        void clear() {
            _startpos = std::string::npos;
            _line = 0;
            _column = 0;
            _length = 0;
            _start = nullptr;
            _end = nullptr;
            _name = EnumT::NONE;
            _data = DataStorageType{};
            _empty = true;
        }

        bool empty() const { return _empty; }
        auto startpos() const { return _startpos; }
        auto line() const { return _line; }
        auto column() const { return _column; }
        auto length() const { return _length; }
        auto start() const { return _start; }
        auto end() const { return _end; }
        auto name() const { return _name; }
        DataStorageType& data() { return _data; }
        const DataStorageType& data() const { return _data; }

        void set_data(DataStorageType&& value) {
            _data = std::move(value);
            _empty = false;
        }
        void set_data(const DataStorageType& value) {
            _data = value;
            _empty = false;
        }

        static Node create(long long startpos, const char* start, long long length,
                           long long line, EnumT enumv, DataStorageType value) {
            // Column cannot be recovered safely from a pointer to the token's
            // beginning alone; callers needing column should use the full ctor.
            return Node{static_cast<std::size_t>(startpos), start,
                        start ? start + length : nullptr,
                        static_cast<std::size_t>(length),
                        static_cast<std::size_t>(line), 0, enumv,
                        std::move(value)};
        }

        void print(ASTPrinter<std::ostream>& printer) const {
            if (_empty) {
                printer.node("<empty>");
                return;
            }
            if constexpr (std::is_pointer_v<DataStorageType> ||
                          is_shared_ptr<DataStorageType>::value) {
                if (_data) _data->write_to_output(printer);
            } else {
                _data.write_to_output(printer);
            }
        }

        void print(std::ostream& os) const {
            if (_empty) {
                os << "<empty>";
                return;
            }
            if constexpr (std::is_pointer_v<DataStorageType> ||
                          is_shared_ptr<DataStorageType>::value) {
                if (_data) os << *_data;
                else os << "nullptr";
            } else {
                os << _data;
            }
        }

        auto to_string() const {
            if (_empty)
                throw IspaAPIExcept("Can't retrieve string representation of an empty node");
            if constexpr (std::is_pointer_v<DataStorageType> ||
                          is_shared_ptr<DataStorageType>::value) {
                if (!_data)
                    throw IspaAPIExcept("Can't retrieve string representation of a null pointer (std::shared_ptr)");
                return _data->to_string();
            } else {
                return _data.to_string();
            }
        }
    };

    template<typename ENUM_T, typename NodeType>
    auto operator<<(std::ostream &os, const Node<ENUM_T, NodeType> &node) -> std::ostream& {
        node.print(os);
        return os;
    }
    template<class EnumT, class DataStorageType, class IT>
    struct MatchResult {
        bool status = false;
        Node<EnumT, DataStorageType> node = {};
        IT it;
    };

    template<typename EnumT, typename DataStorageType, typename Enable>
    template<typename IT>
    auto Node<EnumT, DataStorageType, Enable>::operator=(
        const MatchResult<EnumT, DataStorageType, IT>& mr
    ) -> Node& {
        return *this = mr.node;
    }
    template<class TOKEN_T, typename Token>
    using TokenFlow = std::vector<Token>;
    template<class RULE_T, class DataStorageType>
    using Seq = std::vector<Node<RULE_T, DataStorageType>>;

    template<typename Tokens, typename Type>
    std::string to_string_helper(
        const ISPA_STD::Node<Tokens, Type>& node
    );

    template<typename... Ts>
    std::string to_string_helper(
        const std::variant<Ts...>& v
    );
    template<typename Tokens, typename Type>
    std::string to_string_helper(
        const ISPA_STD::Node<Tokens, Type>& node
    );

    template<typename... Ts>
    std::string to_string_helper(
        const std::variant<Ts...>& v
    );

    template<typename T, typename Allocator>
    std::string to_string_helper(
        const std::vector<T, Allocator>& values
    );
    inline std::string to_string_helper(const std::string& val) {
        return val;
    }

    inline std::string to_string_helper(std::string_view val) {
        return std::string(val);
    }

    inline std::string to_string_helper(const char* val) {
        return val ? std::string(val) : std::string();
    }

    // Characters
    inline std::string to_string_helper(char val) {
        return std::string(1, val);
    }

    // Booleans
    inline std::string to_string_helper(bool val) {
        return val ? "true" : "false";
    }

    // Integers
    inline std::string to_string_helper(short val) {
        return std::to_string(val);
    }

    inline std::string to_string_helper(unsigned short val) {
        return std::to_string(val);
    }

    inline std::string to_string_helper(int val) {
        return std::to_string(val);
    }

    inline std::string to_string_helper(unsigned int val) {
        return std::to_string(val);
    }

    inline std::string to_string_helper(long val) {
        return std::to_string(val);
    }

    inline std::string to_string_helper(unsigned long val) {
        return std::to_string(val);
    }

    inline std::string to_string_helper(long long val) {
        return std::to_string(val);
    }

    inline std::string to_string_helper(unsigned long long val) {
        return std::to_string(val);
    }

    // Floating-point
    inline std::string to_string_helper(float val) {
        return std::to_string(val);
    }

    inline std::string to_string_helper(double val) {
        return std::to_string(val);
    }

    inline std::string to_string_helper(long double val) {
        return std::to_string(val);
    }

    // Empty variant alternative
    inline std::string to_string_helper(std::monostate) {
        return "";
    }

    // Node overload
    template<typename Tokens, typename Type>
    std::string to_string_helper(
        const ISPA_STD::Node<Tokens, Type>& node
    ) {
        return node.to_string();
    }

    // Variant overload
    template<typename... Ts>
    std::string to_string_helper(const std::variant<Ts...>& v) {
        return std::visit(
            [](const auto& arg) -> std::string {
                return to_string_helper(arg);
            },
            v
        );
    }
    template<typename T, typename Allocator>
    std::string to_string_helper(
        const std::vector<T, Allocator>& values
    ) {
        std::string result;

        for (const auto& value : values) {
            result += to_string_helper(value);
        }

        return result;
    }
    // Base case: zero arguments
    inline std::string concat() {
        return {};
    }

    // Variadic concatenation using C++17 fold expressions
    template <typename... Args>
    std::string concat(Args&&... args) {
        return (to_string_helper(std::forward<Args>(args)) + ...);
    }
    template<typename To, typename From>
    void assign_compatible(To& target, const From& source);
    template<typename To, typename From>
    void assign_compatible(To& target, const From& source) {
        if constexpr (is_match_result_v<From>) {
            // MatchResult<Rules, T, IT> -> Node<Rules, T>
            // Then recursively convert to the destination type.
            assign_compatible(target, source.node);

        } else if constexpr (is_vector_v<To> && is_vector_v<From>) {
            target.clear();
            target.reserve(source.size());

            using Element = typename To::value_type;

            for (const auto& item : source) {
                Element converted{};
                assign_compatible(converted, item);
                target.push_back(std::move(converted));
            }

        } else if constexpr (is_variant_v<To> && is_variant_v<From>) {
            std::visit(
                [&](const auto& value) {
                    if (!assign_variant_alternative(target, value)) {
                        throw IspaInternalExcept("assign_compatible: incompatible variant alternative", "Parser", true);
                    }
                },
                source
            );

        } else if constexpr (std::is_assignable_v<To&, const From&>) {
            target = source;

        } else if constexpr (std::is_constructible_v<To, const From&>) {
            target = To(source);

        } else {
            static_assert(
                std::is_constructible_v<To, const From&>,
                "assign_compatible: unsupported conversion"
            );
        }
    }
    template<typename To, typename From, std::size_t I = 0>
    bool assign_variant_alternative(To& target, const From& source) {
        if constexpr (I == std::variant_size_v<To>) {
            return false;
        } else {
            using Alternative = std::variant_alternative_t<I, To>;

            if constexpr (std::is_constructible_v<Alternative, From>) {
                target.template emplace<I>(source);
                return true;
            }

            return assign_variant_alternative<To, From, I + 1>(
                target, source
            );
        }
    }
    namespace DFA::API {
        struct DFADebug;
        inline auto null_state = std::numeric_limits<std::size_t>::max();
        // Same numbering as NFA::TNFA::Action, so the converter emits the value as is.
        enum class Action { UNDEF, SET, SET_NEXT, COPY, APPEND, APPEND_NEXT };
        template<std::size_t Classes>
        using State = std::array<std::size_t, Classes>;
        template<std::size_t States, std::size_t Classes>
        using Table = std::array<State<Classes>, States>;
        using CharToClass = std::array<std::size_t, 256>;
        // Row: {op, a, b, next_state}.
        //   SET / SET_NEXT        reg[a] = position (NEXT: one past the character being consumed)
        //   COPY                  reg[a] = reg[b]
        //   APPEND / APPEND_NEXT  reg[a] = append(reg[b], position)   (b == null_state: empty list)
        template<std::size_t States>
        using LRTable = std::array<State<4>, States>;
        template<std::size_t Size>
        using DFADebugTable = std::array<DFADebug, Size>;
        using DebugIndex = std::unordered_map<long long, std::unordered_map<long long, long long>>;

        /*
         * Can be emit by parser generator.
         * This turns the DFA walker from class -> next state into something can be reversed to actual grammar structures
        */
        struct DFADebug {
            std::string member;
            std::string token_name;
            long long position_in_token;
            long long call;
            long long group;

            long long rule_run = null_state;
            long long offset = 0;
            long long length = 1;
            char ch = '\0';

            auto operator<(const DFADebug &other) const {
                return std::tie(member, token_name, position_in_token, call, group, rule_run, offset, length, ch) < std::tie(other.member, other.token_name, other.position_in_token, other.call, other.group, other.rule_run, other.offset, other.length, other.ch);
            }
            auto operator==(const DFADebug &other) const{
                return std::tie(member, token_name, position_in_token, call, group, rule_run, offset, length, ch) == std::tie(other.member, other.token_name, other.position_in_token, other.call, other.group, other.rule_run, other.offset, other.length, other.ch);
            }
        };

        // Capture k owns registers 2k (begin, or the head of a list capture's history)
        // and 2k + 1 (end). A register that was never written is `unset`.
        inline constexpr std::ptrdiff_t unset = -1;

        struct HistoryNode {
            std::ptrdiff_t pos;  // offset from the start of the token
            std::ptrdiff_t prev; // previous node, `unset` ends the list
        };

        class Captures {
            const char *base_ = nullptr;
            const std::ptrdiff_t *out_ = nullptr;
            const HistoryNode *history_ = nullptr;
            long long first_line_ = 1;

            auto begin_off(std::size_t k) const { return out_[2 * k]; }
            auto end_off(std::size_t k) const { return out_[2 * k + 1]; }

        public:
            Captures() = default;
            Captures(const char *base, const std::ptrdiff_t *out, const HistoryNode *history, long long first_line)
                : base_(base), out_(out), history_(history), first_line_(first_line) {}

            // scalar capture: both boundaries were recorded
            auto is_set(std::size_t k) const -> bool { return begin_off(k) != unset && end_off(k) != unset; }
            auto begin(std::size_t k) const -> const char * { return base_ + begin_off(k); }
            auto end(std::size_t k) const -> const char * { return base_ + end_off(k); }
            auto view(std::size_t k) const -> std::string_view {
                return std::string_view(begin(k), static_cast<std::size_t>(end_off(k) - begin_off(k)));
            }
            auto text(std::size_t k) const -> std::string { return std::string(view(k)); }
            auto character(std::size_t k) const -> char { return *begin(k); }

            // list capture: one entry per iteration, in input order
            auto list_views(std::size_t k) const -> std::vector<std::string_view> {
                std::vector<std::ptrdiff_t> positions;
                for (auto h = begin_off(k); h != unset; h = history_[h].prev)
                    positions.push_back(history_[h].pos);
                std::reverse(positions.begin(), positions.end());
                std::vector<std::string_view> spans;
                for (std::size_t i = 0; i + 1 < positions.size(); i += 2)
                    spans.emplace_back(base_ + positions[i], static_cast<std::size_t>(positions[i + 1] - positions[i]));
                return spans;
            }
            template<typename T = std::string>
            auto list(std::size_t k) const -> std::vector<T> {
                std::vector<T> out;
                for (const auto v : list_views(k)) {
                    if constexpr (std::is_same_v<T, char>)
                        out.push_back(v.empty() ? '\0' : v.front());
                    else
                        out.push_back(T(v));
                }
                return out;
            }

            auto line(std::size_t k) const -> long long {
                return first_line_ + std::count(base_, begin(k), '\n');
            }
            auto column(std::size_t k) const -> long long {
                const char *b = begin(k);
                const char *line_start = b;
                while (line_start > base_ && line_start[-1] != '\n')
                    --line_start;
                return (b - line_start) + 1;
            }
        };

        template<std::size_t Registers, std::size_t Outputs>
        struct TdfaLayout {
            static constexpr std::size_t registers = Registers;
            static constexpr std::size_t outputs = Outputs;
        };
    }
    namespace DFA::detail {
        // Debug trace of one DFA step.
        template<std::size_t debug_size>
        inline void trace_step(
            const API::DFADebugTable<debug_size> &debug_array,
            const API::DebugIndex &debug_index,
            std::size_t state,
            std::size_t cls,
            char current_ch,
            const char *pos,
            bool immediate_action
        ) {
            const API::DFADebug *debug = nullptr;

            // 2. Compute 1D index using base offset + char class
            // 1. Safe lookup without mutating map or inserting null keys
            if (debug_size > 0) {
                if (auto state_it = debug_index.find(state); state_it != debug_index.end()) {
                    if (auto cls_it = state_it->second.find(cls); cls_it != state_it->second.end()) {
                        debug = &debug_array[cls_it->second];
                    }
                }
            }

            if (debug) {
                std::stringstream ss;
                ss << debug->token_name << ": ";
                std::cout << ss.str() << debug->member;
                if (debug->call != -1) {
                    std::cout << "$call" << debug->call;
                }
                if (debug->group != -1) {
                    std::cout << "$group" << debug->group;
                }
                std::cout << "; " << debug->offset + 1 << "/" << debug->length << ";\n";
                std::cout << std::string(ss.str().size() + debug->offset, ' ');

                const auto &mem = debug->member;
                if (mem.size() >= 2 && mem.front() == '[') {
                    bool escaped = false;

                    for (std::size_t i = 1; i < mem.size(); ++i) {
                        char c = mem[i];

                        if (escaped) {
                            escaped = false;
                            if (current_ch == c) {
                                std::cout << std::string(i, ' ') << "^\n";
                                break;
                            }
                            continue; // Skip further range/escape processing for this character
                        }

                        if (c == '\\') {
                            escaped = true;
                            continue; // Skip to next character after setting escape flag
                        }

                        if (current_ch == c) {
                            std::cout << std::string(i, ' ') << "^\n";
                            break;
                        }

                        // Check range e.g., a-z
                        if (c == '-' && i > 1 && (i + 1) < mem.size() && mem[i + 1] != ']') {
                            char range_begin = mem[i - 1];
                            char range_end = mem[i + 1];

                            if (current_ch >= range_begin && current_ch <= range_end) {
                                std::cout << std::string(i - 1, ' ') << "^ ^\n";
                                break;
                            }
                        }
                    }
                } else {
                    std::cout << "^\n";
                }
            } else {
                std::cout << "State " << state << " char '"
                          << *(immediate_action ? pos + 1 : pos)
                          << "'\n";
            }
        }
    }
namespace DFA {
    template<
        typename Token,
        typename SemanticFunc,
        std::size_t table_states,
        std::size_t table_classes,
        std::size_t action_table_states,
        std::size_t debug_size,
        std::size_t registers,
        std::size_t outputs
    >
    auto run(
        const char* &pos,
        long long start_pos,
        long long &scanning_line,
        const API::Table<table_states, table_classes> &table,
        const API::CharToClass &class_table,
        const API::LRTable<action_table_states> &action_table,
        SemanticFunc semantic,
        const API::DFADebugTable<debug_size> &debug_array,
        const API::DebugIndex &debug_index,
        API::TdfaLayout<registers, outputs>
    ) -> Token {
        static_assert(registers >= outputs, "output registers are registers 0 .. outputs-1");

        const char *const start = pos;
        const long long start_line = scanning_line;

        std::array<std::ptrdiff_t, (registers > 0 ? registers : 1)> regs;
        regs.fill(API::unset);
        std::vector<API::HistoryNode> history;

        std::size_t state = 0;
        bool immediate_action = false;
        const char* last_pos = pos;
        std::size_t steps_without_progress = 0;
#ifdef ISPA_DEBUG_REGISTERS
        // Watch one register across the whole run — set this to whatever
        // register index you're chasing (12, per the TNFA.build trace for
        // ID's capture). Prints every SET/SET_NEXT/COPY/APPEND that touches
        // it, plus its value at every semantic dispatch, so you can see
        // exactly when (or whether) it gets written, and what it holds when
        // a semantic handler reads it.
        constexpr std::size_t WATCH_REG = 12;
        auto dump_regs = [&](const char *tag) {
            std::cerr << "[regtrace] " << tag << " state=" << state << " pos_off=" << (pos - start) << " regs=[";
            for (std::size_t i = 0; i < registers; ++i) {
                std::cerr << (regs[i] == API::unset ? std::string("_") : std::to_string(regs[i]));
                if (i + 1 < registers) std::cerr << ",";
            }
            std::cerr << "]\n";
        };
        dump_regs("start");
#endif

        while (state != API::null_state) {
            const char current_ch = *(immediate_action && *pos != '\0' ? pos + 1 : pos);
            if (debug_size > 1) { // because generator emits one <UNDEFINED> table
                detail::trace_step(debug_array, debug_index, state,
                                   class_table[static_cast<unsigned char>(current_ch)], current_ch, pos, immediate_action);
            }

            if (state < table.size()) {
                if (immediate_action) {
                    immediate_action = false;
                    if (*pos == '\n')
                        scanning_line++;
                    if (*pos != '\0')
                        ++pos;
                }
                const std::size_t next = table[state][class_table[static_cast<unsigned char>(*pos)]];
                if (next == API::null_state) {
#ifdef ISPA_DEBUG_REGISTERS
                    std::cerr << "[regtrace] DEAD END at state=" << state
                              << " char='" << *pos << "'\n";
                    dump_regs("dead-end");
#endif
                    break;
                }
                state = next;

                if (next < table.size() && *pos != '\0') {
                    if (*pos == '\n')
                        scanning_line++;
                    ++pos;
                } else {
                    immediate_action = true;
                }
            } else if (state < table.size() + action_table.size()) {
                const auto &row = action_table[state - table.size()];
                const auto action = static_cast<API::Action>(row[0]);
                const auto here = static_cast<std::ptrdiff_t>(pos - start);

                if (row[1] >= registers || (row[2] != API::null_state && row[2] >= registers))
                    throw std::runtime_error("DFA: register out of range");

#ifdef ISPA_DEBUG_REGISTERS
                const bool watching = (row[1] == WATCH_REG) ||
                                      (row[2] != API::null_state && row[2] == WATCH_REG);
                if (watching) {
                    std::cerr << "[regtrace] ACTION action=" << static_cast<int>(action)
                              << " dst=r" << row[1]
                              << " src=" << (row[2] == API::null_state ? "nil" : "r" + std::to_string(row[2]))
                              << " here=" << here << '\n';
                }
#endif

                switch (action) {
                    case API::Action::SET:
                    case API::Action::SET_NEXT:
                        regs[row[1]] = here + (action == API::Action::SET_NEXT ? 1 : 0);
                        break;
                    case API::Action::COPY:
                        regs[row[1]] = regs[row[2]];
                        break;
                    case API::Action::APPEND:
                    case API::Action::APPEND_NEXT:
                        history.push_back({
                            here + (action == API::Action::APPEND_NEXT ? 1 : 0),
                            row[2] == API::null_state ? API::unset : regs[row[2]]
                        });
                        regs[row[1]] = static_cast<std::ptrdiff_t>(history.size()) - 1;
                        break;
                    default:
                        throw std::runtime_error("DFA: unknown action; Report this error to github");
                }
#ifdef ISPA_DEBUG_REGISTERS
                if (watching) dump_regs("after-action");
#endif
                state = row[3];
            } else {
                const API::Captures captures(start, regs.data(), history.data(), start_line);
#ifdef ISPA_DEBUG_REGISTERS
                std::cerr << "[regtrace] SEMANTIC dispatch idx="
                          << (state - table.size() - action_table.size())
                          << " pos_off=" << (pos - start);
                dump_regs("pre-semantic");
#endif
                auto result = semantic(
                    state - table.size() - action_table.size(),
                    captures, start_pos, start, static_cast<long long>(pos - start), start_line
                );
                state = static_cast<std::size_t>(std::get<0>(result));
                if (state == API::null_state)
                    return std::get<1>(std::move(result));
                if (pos == last_pos) {
                    if (++steps_without_progress > 100) {
                        throw IspaInternalExcept(
                            "DFA: possible zero-width transition cycle at state {}, offset {}", "Lexer TDFA generation", true, state, std::to_string(pos - start)
                        );
                    }
                } else {
                    last_pos = pos;
                    steps_without_progress = 0;
                }
            }
        }
        return Token {};
    }
} // namespace DFA
    template<class TOKEN_T, typename Token>
    class Lexer_base {
    protected:
        const char* _in = nullptr;
        std::string _owned_input;
        TokenFlow<TOKEN_T, Token> tokens;
        long long line;
        std::size_t getCurrentPos(const char* pos) const {
            return pos - _in;
        }
        std::size_t skip_spaces(const char*& in) {
            auto prev = in;
            while (isspace(*in)) in++;
            return in - prev;
        }
        std::size_t __line(const char* pos) const {
            std::size_t count = 1;
            for (const char* in = _in; in < pos; in++)
                if (*in == '\n') count++;
            return count;
        }
        std::size_t __column(const char* pos) const {
            std::size_t count = 1;
            for (const char* in = _in; in < pos; in++)
                count = (*in == '\n') ? 0 : count + 1;
            return count;
        }
        void panic_mode(const char*& pos) {
            if (*pos != '\0') ++pos;
        }
        template<
            typename SemanticFunc,
            std::size_t table_states,
            std::size_t table_classes,
            std::size_t action_table_states,
            std::size_t debug_size,
            typename Layout
        >
        Token lookup(
            const DFA::API::Table<table_states, table_classes> &table,
            const DFA::API::CharToClass &class_table,
            const DFA::API::LRTable<action_table_states> &action_table,
            Layout layout,
            SemanticFunc semantic,
            const DFA::API::DFADebugTable<debug_size> &debug_array,
            const DFA::API::DebugIndex &debug_index,
            const char* &pos
        ) {
            if (*pos == '\0')
                return Token {};
            return DFA::run<Token>(pos, getCurrentPos(pos), line, table, class_table, action_table,
                                   semantic, debug_array, debug_index, layout);
        }

    public:
        class lazy_iterator {
            Lexer_base* owner = nullptr;
            std::size_t index = 0;

        public:
            lazy_iterator() = default;

            lazy_iterator(Lexer_base& lexer, std::size_t index = 0)
                : owner(&lexer), index(index) {}

            lazy_iterator(const lazy_iterator&) = default;
            lazy_iterator& operator=(const lazy_iterator&) = default;

            const Token& operator*() const {
                return owner->tokenAt(index);
            }

            const Token* operator->() const {
                return &owner->tokenAt(index);
            }

            lazy_iterator& operator++() {
                if (!isEnd())
                    ++index;
                return *this;
            }

            lazy_iterator operator++(int) {
                auto copy = *this;
                ++(*this);
                return copy;
            }

            void operator+=(std::size_t count) {
                while (count-- && !isEnd())
                    ++(*this);
            }

            bool isEnd() const {
                return !owner ||
                    std::holds_alternative<std::monostate>(
                        owner->tokenAt(index)
                    );
            }

            std::ptrdiff_t operator-(
                const lazy_iterator& other
            ) const {
                return static_cast<std::ptrdiff_t>(index)
                     - static_cast<std::ptrdiff_t>(other.index);
            }

            std::size_t distance() const {
                return index;
            }
        };

        // Iterates already-accumulated tokens; run makeTokens() before using this.
        class iterator {
            Lexer_base* owner = nullptr;
            typename TokenFlow<TOKEN_T, Token>::iterator pos;

        public:
            iterator() = default;
            iterator(Lexer_base& owner) : owner(&owner), pos(owner.tokens.begin()) {}

            iterator& operator=(const iterator& other) = default;
            void operator+=(std::size_t count) { pos += count; }
            iterator& operator++() { pos += 1; return *this; }
            iterator operator++(int) { auto tmp = *this; pos += 1; return tmp; }
            std::size_t operator-(const iterator& other) const { return pos - other.pos; }
            iterator operator+(std::size_t count) const { auto tmp = *this; tmp += count; return tmp; }

            bool isEnd() const { return std::holds_alternative<std::monostate>(*pos); }
            Token& operator*() const { return *pos; }
            Token* operator->() const { return &(*pos); }
            std::size_t distance() const { return pos - owner->tokens.begin(); }
        };
        /*
         * DO NOT OVERRIDE
         * This function is used internally as bridge between generator and std lib
         * you should override Lexer::push() instead
         * */
        virtual Token makeToken(const char*& pos) = 0;
        virtual void init() {}

        Lexer_base() { init(); }
        explicit Lexer_base(const std::string& in) : _owned_input(in), _in(_owned_input.c_str()) { init(); }
        explicit Lexer_base(const char* in) : _in(in) { init(); }
        explicit Lexer_base(const TokenFlow<TOKEN_T, Token>& tokens) : tokens(tokens) { init(); }
        virtual ~Lexer_base() = default;

        bool hasInput() const { return _in != nullptr; }
        bool hasTokens() const { return !tokens.empty(); }

        Lexer_base& setInput(const std::string& in) {
            _owned_input = in;
            _in = _owned_input.c_str();
            return *this;
        }
        Lexer_base& setInput(const char* in) {
            _owned_input.clear();
            _in = in;
            return *this;
        }

        const TokenFlow<TOKEN_T, Token>& getTokens() const { return tokens; }
        TokenFlow<TOKEN_T, Token>& getTokensReference() { return tokens; }
        void clearTokens() { tokens.clear(); }
        virtual void push(Token&& t) { tokens.push_back(std::move(t)); }
        virtual void push(const Token &t) { tokens.push_back(t); }
        virtual TokenFlow<TOKEN_T, Token>& makeTokens() {
            if (_in == nullptr)
                throw IspaAPIExcept("can't lex because no input provided. ");
            const char* pos = _in;
            while (*pos != '\0') {
                const char* before = pos;
                Token t = makeToken(pos);
                if (pos == before) {
                    throw IspaInternalExcept(
                        "no matches at position {}, on character {}, and no exception can handle it", "Lexer TDFA generation", true, getCurrentPos(pos), *pos
                    );
                }
                push(std::move(t));
            }
            push(std::monostate {});
            return tokens;
        }
        TokenFlow<TOKEN_T, Token>& makeTokens(const std::string& in) {
            setInput(in);
            return makeTokens();
        }
        TokenFlow<TOKEN_T, Token>& makeTokens(const char* in) {
            setInput(in);
            return makeTokens();
        }
        virtual TokenFlow<TOKEN_T, Token>& makeTokensFromFile(const char* path) {
            std::ifstream file(path, std::ios::in | std::ios::binary);
            if (!file)
                throw IspaAPIExcept("Failed to open file '{}'", path);

            std::string str;
            file.seekg(0, std::ios::end);
            str.reserve(static_cast<std::size_t>(file.tellg()));
            file.seekg(0, std::ios::beg);
            str.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
            return makeTokens(str);
        }
        virtual auto getErrors() -> const std::vector<std::string>& {
            throw IspaInternalExcept("Ispa is not yet able to generate errors and expose their API", "Not implemented", false);
        }
        virtual void append_token(const Token& token) {
            tokens.push_back(token);
        }
        Lexer_base& operator=(const Lexer_base& other) {
            if (this != &other) {
                tokens = other.tokens;
                _owned_input = other._owned_input;
                _in = _owned_input.empty() ? other._in : _owned_input.c_str();
            }
            return *this;
        }
        bool operator==(const Lexer_base& other) const { return tokens == other.tokens; }
        bool operator!=(const Lexer_base& other) const { return tokens != other.tokens; }
    };
    /* PARSER */
    template<class TOKEN_T, class RULE_T, typename MainNode, typename Token>
    class LLParser_base {
    protected:
        Lexer_base<TOKEN_T, Token>* lexer = nullptr;
        const char* text = nullptr;
        MainNode tree;
        // skip spaces for tokens
        template <typename SpaceTokenType, typename IT>
        void skip_spaces(IT& pos) {
            if (std::holds_alternative<Node<TOKEN_T, SpaceTokenType>>(*pos))
                ++pos;
        }
        void raise_error(const Token& node, const std::string& message) {
            std::visit([&](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (!std::is_same_v<T, std::monostate>) {
                    std::cerr << "Error at token " << (int) arg.name() << "(at position " << arg.startpos() << ")" << ": " << message << std::endl;
                    std::cerr << "Token: \n" << arg << std::endl;
                }
            }, node);
        }
        static void PANIC_MODE() {}
    public:
        // Constructors
        LLParser_base() {}
        LLParser_base(Lexer_base<TOKEN_T, Token>& lexer) {
            this->lexer = &lexer;
        }
        LLParser_base(const char* text) : text(text) {}
        virtual ~LLParser_base() {}
        // Parsing methods
        MainNode& parse(Lexer_base<TOKEN_T, Token>& lex) {
            lexer = &lex;
            return parse();
        }
        MainNode& parse(const char* txt) {
            text = txt;
            return parse();
        }
        void setInput(Lexer_base<TOKEN_T, Token> &lex) {
            if (!lex.hasTokens())
                lexer = &lex;
        }
        void setInput(const char* txt) {
            text = txt;
        }
        void clearInput() {
            lexer = nullptr;
            text = nullptr;
        }
    protected:
        /**
         * Parse NON-LAZILY input
         */
        virtual MainNode& parse() {
            if (lexer == nullptr)
                throw IspaAPIExcept("Can't parse because no input lexer is provided");
            if (!lexer->hasInput())
                lexer->makeTokens();
            parseFromTokens();
            return tree;
        }
        /*
         * Parse LAZILY input
         */
        virtual MainNode& parseLazy() {
            if (text == nullptr)
                throw IspaAPIExcept("Can't parse because no input text is provided");
            lazyParse();
            return tree;
        }
        /*
         * DO NOT OVERRIDE
         * This function is used internally as bridge between generator and std lib
         * you should override Lexer::parse() instead
         */
        virtual void parseFromTokens() = 0;
        /*
         * DO NOT OVERRIDE
         * This function is used internally as bridge between generator and std lib
         * you should override Lexer::parseLazy() instead
         */
        virtual void lazyParse() = 0;
    };
#ifdef ISPA_EXPERIMENTAL
    template <class TOKEN_T, class RULE_T, class MAIN_NODE, class Token, class Action, class ActionTable, class GotoTable, class RulesTable>
    class LRParser_base : public LLParser_base<TOKEN_T, RULE_T, MAIN_NODE, Token> {
    protected:
        std::vector<std::pair<std::variant<TOKEN_T, RULE_T>, std::size_t>> stack;
        template <class IT>
        void shift(IT& pos, std::size_t state) {
            stack.push_back({pos->name(), state});
            pos++;
        }
        void reduce(const std::size_t rules_id, const GotoTable &goto_table, const RulesTable rules_table) {
            const auto &rule_data = rules_table[rules_id];
            const auto &rule_name = rule_data.first;
            const auto &reduce_size = rule_data.second;
            if (stack.size() < reduce_size) {
                throw std::runtime_error("Stack underflow during reduce");
            }
            stack.erase(stack.end() - reduce_size, stack.end());
            printf("Reduce: goto_table[%d][%d]\n", (int) stack.back().second, (int) rule_name);
            // Perform the reduction
            const auto& goto_entry = goto_table[stack.back().second][static_cast<std::size_t>(rule_name)];
            if (!goto_entry.has_value()) {
                throw std::runtime_error("Invalid GOTO after reduction");
            }

            std::size_t next_state = goto_entry.value();
            stack.push_back({rule_name, next_state});
        }
        virtual std::string TokensToString(TOKEN_T token) = 0;
        virtual std::string RulesToString(RULE_T rule) = 0;
        template<class IT>
        void parseFromPos(IT& pos, const ActionTable &action_table, const GotoTable &goto_table, RulesTable rules_table) {
            stack.push_back({TOKEN_T::NONE, 0});
            while(true) {
                auto &current_state = stack.back().second;
                const auto &action = action_table[current_state][(std::size_t) pos->name()];
                printf("Token name: %s", TokensToString(pos->name()).c_str());
                if (pos->data().has_value()) {
                    printf("[%s]", std::any_cast<std::string>(pos->data()).c_str());
                }
                printf(", state: %zu\n", current_state);
                if (action.has_value()) {
                    auto& act = action.value();
                    printf("action: %d, next state: %zu\n", (int) act.type, act.state);
                    if (act.type == Action::SHIFT)
                        shift(pos, act.state);
                    else if (act.type == Action::REDUCE)
                        reduce(act.state, goto_table, rules_table);
                    else if (act.type == Action::ACCEPT)
                        break;
                    else
                        throw std::runtime_error("Error state");
                } else {
                    throw std::runtime_error(("Action is not defined. stack size: " + std::to_string(stack.size())).c_str());
                }
            }
            printf("Accepted. distance: %zu\n", pos.distance());
            stack.clear();
        }
    };
    template <class TOKEN_T, class RULE_T, class MAIN_NODE, class Token, class Action, class ActionTable, class GotoTable, class RulesTable, class DFATable>
    class ELRParser_base : public LRParser_base<TOKEN_T, RULE_T, MAIN_NODE, Token, Action, ActionTable, GotoTable, RulesTable> {
    private:
        // cache tokens because of lazy iterator which makes tokens on dereference
        std::deque<Node<TOKEN_T, Token>> dfa_token_cache;
    protected:
        template <class IT>
        void shift(IT& pos, std::size_t state) {
            if (dfa_token_cache.empty()) {
                printf("Pushing directly\n");
                this->stack.push_back({pos->name(), state});
                pos++;
            } else {
                printf("Pushing from DFA cache, next token: ");
                printf("%s", TokensToString(pos->name()).c_str());
                if (pos->data().has_value()) {
                    printf("[%s]", std::any_cast<std::string>(pos->data()).c_str());
                }
                printf("\n");
                this->stack.push_back({dfa_token_cache.front().name(), state});
                dfa_token_cache.pop_back();
            }
        }
        template<class IT>
        const std::optional<Action>& getAction(IT &pos, const ActionTable &action_table) {
            auto &current_state = this->stack.back().second;
            return dfa_token_cache.empty() ? action_table[current_state][(std::size_t) pos->name()] : action_table[current_state][(std::size_t) dfa_token_cache.front().name()];
        }
        template<class IT>
        const Action* resolveDFA(IT &pos, std::size_t dfa_index, const DFATable &dfa_table) {
            const Action* initial_action = nullptr;
            printf("Resolving conflict in DFA table\n");
            std::size_t current_dfa_length = dfa_token_cache.size();
            for (std::size_t offset = 0;; offset++) {
                if (offset >= current_dfa_length)
                    dfa_token_cache.push_back(*pos++);
                const auto &[action, table] = dfa_table[dfa_index];
                std::size_t i = 1;
                while(table[i].first != dfa_token_cache[offset].name() && table[i].second != 0) i++;
                const auto &go_state = table[i].second;
                if (initial_action == nullptr) {
                    initial_action = &action;
                }
                if (go_state == 0) {
                    if (table[0].second != 0) {
                        dfa_index = table[0].second;
                        continue;
                    }
                    if (action.type == Action::ERR) {
                        printf("Returning initial action %d, state %zu\n", (int) initial_action->type, initial_action->state);
                        return initial_action;
                    }
                    printf("returning action %d, state %zu\n", (int) action.type, action.state);
                    return &action;
                }
                dfa_index = go_state;

            }
        }
        template<class IT>
        void peformAction(IT &pos, Action act, GotoTable goto_table, RulesTable rules_table, DFATable dfa_table) {
            switch (act.type)
            {
            case Action::SHIFT:
                shift(pos, act.state);
                break;
            case Action::REDUCE:
                this->reduce(act.state, goto_table, rules_table);
                break;
            case Action::DFA_RESOLVE: {
                const auto resolved = resolveDFA(pos, act.state, dfa_table);
                if (!resolved) throw std::runtime_error("Unresolvable DFA lookahead");
                peformAction(pos, *resolved, goto_table, rules_table, dfa_table);
                break;
            }
            default:
                throw std::runtime_error("Error action");
            }
        }
        template<class IT>
        void parseFromPos(IT& pos, const ActionTable &action_table, const GotoTable &goto_table, RulesTable rules_table, DFATable dfa_table) {
            this->stack.push_back({TOKEN_T::NONE, 0});
            while(true) {
                auto &current_state = this->stack.back().second;
                const auto &action = getAction(pos, action_table);
                if (dfa_token_cache.empty()) {
                    printf("Token name: %s", TokensToString(pos->name()).c_str());
                    if (pos->data().has_value()) {
                        printf("[%s]", std::any_cast<std::string>(pos->data()).c_str());
                    }
                    printf(", state: %zu\n", current_state);
                } else {
                    printf("Token name: %s", TokensToString(dfa_token_cache.front().name()).c_str());
                    if (pos->data().has_value()) {
                        printf("[%s]", std::any_cast<std::string>(pos->data()).c_str());
                    }
                    printf(", state: %zu\n", current_state);
                }

                if (action.has_value()) {
                    auto& act = action.value();
                    printf("action: %d, next state: %zu\n", (int) act.type, act.state);
                    if (act.type == Action::ACCEPT)
                        break;
                    peformAction(pos, act, goto_table, rules_table, dfa_table);
                } else {
                    throw std::runtime_error(("Action is not defined. stack size: " + std::to_string(this->stack.size())).c_str());
                }
            }
            printf("Accepted. distance: %zu\n", pos.distance());
            // clear
            this->stack.clear();
            dfa_token_cache.clear();
        }
    };
#endif
} // namespace ISPA_STD
#endif // _ISPA_STD_LIB_CPP
