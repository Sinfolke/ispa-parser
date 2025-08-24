/**
 * C++ ispa std lib 1.2
 * It contains standard declarations and every C++ generated parser would link against it
*/
#pragma once
#ifndef _ISPA_STD_LIB_CPP
#define _ISPA_STD_LIB_CPP
#include <map>
#include <vector>
#include <deque>
#include <string>
#include <any>
#include <stdexcept>
#include <cctype>
#include <fstream>
#include <variant>
#include <optional>
#include <limits>
#include <functional>
#include <algorithm>
#include <iostream>
#include <unordered_set>
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

#define _ISC_STD_LIB_VER 1 // version of the library
#define _ISC_STD_LIB_SUBVER 0 // the subversion of the library
// this defines the minimum version of an output to have a compatibility with the library version
// for example if the update did only change the way some classes work but not their structure, it is compatible with the downer version.
#define _ISC_STD_LIB_BACKDOWN 1
#define _ISC_STD_LIB_BACKDOWN_SUBVER 0
#define _ISC_GITHUB "https://github.com/Sinfolke/ISC-parser"
#define ISC_STD_LIBMARK \
    "iscstdlibc++ " TOSTRING(_ISC_STD_LIB_VER) "." TOSTRING(_ISC_STD_LIB_SUBVER) ": "
#define _ISC_INTERNAL_ERROR_MARK \
        "NOTE: this exception is likely an internal error of the ISPA generator and is not on the user side.\n" \
        "Please, show the developer this issue (" _ISC_GITHUB ")\n" \
        "If this issue persist you may try to recompile the project by another version (try newer if your's is too old and vise versa)" \
//#define _ISC_STD_LIB_CPP
/**
 * @brief standard library for the ISPA-generated parser. Do not try to use it directly but use instead auto generated API
 * 
*/
namespace ISPA_STD {
/**
 * @brief An error thrown when you're trying to access some features required with tokens only
 *
 */
class Lexer_No_Tokens_exception : public std::exception {
    public:
    const char* what() const noexcept override {
        return ISC_STD_LIBMARK "Lexer_No_Tokens_exception: the tokenizator has no tokens but some operation required them";
    }
};
class Lexer_No_Input_exception : public std::exception {
    public:
    const char* what() const noexcept override {
        return ISC_STD_LIBMARK "Lexer_No_Input_exception: the tokenizator has no input provided but the operation required it";
    }
};
class Parser_No_Input_exception : public std::exception {
    public:
    const char* what() const noexcept override {
        return ISC_STD_LIBMARK "Parser_No_Input_exception: the parser has no input provided but the operation required it";
    }
};
class AdvancedDFA_exception : public std::exception {
    std::string message;
public:
    AdvancedDFA_exception(const char* message) {
        this->message = "ispastdlib Internal Error in Advanced DFA: ";
        this->message += message;
    }
    [[nodiscard]] auto what() const noexcept -> const char* override {
        return message.c_str();
    }
};
class node_exception : public std::exception {
    private:
        std::string mes;
        void fill(const std::string& method) {
            mes =
            ISC_STD_LIBMARK "node_exception: the capture data has not been provided but called method '";
            mes += method;
            mes +=
            "' required it.\n"
            _ISC_INTERNAL_ERROR_MARK "\n"
            "E.G: This issue is because you have an opportunity to have token or rule be empty without first initialisation.\n"
            "But their methods like ";
            mes += method;
            mes += " etc. require those properties."
            "When they are called but the object is still uninitialised you get this error\n";
        }
        void fill() {
            mes =
            ISC_STD_LIBMARK "node_exception: the capture data has not been provided but called method required it.\n"
            _ISC_INTERNAL_ERROR_MARK "\n"
            "E.G: This issue is because you have an opportunity to have token or rule be empty without first initialisation.\n"
            "But their methods like line etc. require those properties."
            "When they are called but the object is still uninitialised you get this error\n"
            ;
        }
    public:
        node_exception(const char* method) {  fill(method);  }
        node_exception() {  fill();  }
    const char* what() const noexcept override {
        return mes.c_str();
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

        Span(T* data, size_type size)
            : data_(data), size_(size) {}

        template<std::size_t N>
        Span(T (&arr)[N]) // from raw array
            : data_(arr), size_(N) {}

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
template<class TOKEN_T, const char* (*ToString)(TOKEN_T)>
class bad_get : public std::bad_cast {
    TOKEN_T required_name;
    TOKEN_T get_name;
    std::string message; // cache the message for `what()`
public:
    bad_get(TOKEN_T required_name, TOKEN_T get_name, std::string namespace_name = "<Parser>")
        : required_name(required_name), get_name(get_name) {
        message = std::string("Expected ") + namespace_name + "::get::" + ToString(required_name) + "(), but got " + namespace_name + "::get::" + ToString(get_name) + "()";
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};
template<typename NODE_T>
class Node {
    std::size_t _startpos = std::string::npos;
    std::size_t _length = 0;
    std::size_t _line = 0;
    std::size_t _column = 0;
    const char* _start = nullptr;
    const char* _end = nullptr;
    NODE_T _name = NODE_T::NONE;
    std::any _data = {};
    bool _empty = true;
public:
    Node(const std::size_t startpos, const char* start, const char* end, std::size_t length, std::size_t line, std::size_t column, NODE_T name) : _startpos(startpos), _start(start), _end(end), _length(length), _line(line), _column(column), _name(name), _empty(false) {}
    Node(const std::size_t startpos, const char* start, const char* end, std::size_t length, std::size_t line, std::size_t column, NODE_T name, std::any data) : _startpos(startpos), _start(start), _end(end), _length(length), _line(line), _column(column), _name(name), _data(data), _empty(false) {}
    Node() {}

    /**
     * @brief Get the end position based on startpos and length
     *
     * @return long long
     */
    std::size_t endpos() const {
        if (_startpos == std::string::npos || _end == nullptr || _start == nullptr)
            throw node_exception("endpos");
        return _startpos + (_end - _start);
    }
    /* clear rule */
    void clear() {
        _startpos = std::string::npos;
        _line = 0;
        _column = 0;
        _length = 0;
        _start = nullptr;
        _end = nullptr;
        _name = NODE_T::NONE;
        _data = {};
        _empty = true;
    }
    Node<NODE_T>& operator=(const Node<NODE_T>& other) {
        if (this == &other)  // Protect against self-assignment
            return *this;
        _startpos = other._startpos;
        _line = other._line;
        _column = other._column;
        _length = other._length;
        _start = other._start;
        _end = other._end;
        _name = other._name;
        _data = other._data;
        _empty = other._empty;
        return *this;
    }
    /**
     * whether node is empty
     */
    auto empty() const {
        return _empty;
    }
    /**
     * get start position
     */
    auto startpos() const {
        return _startpos;
    }
    /**
     * get line
     */
    auto line() const {
        return _line;
    }
    /**
     * get column
     */
    auto column() const {
        return _column;
    }
    /**
     * get length of the node
     */
    std::size_t length() const {
        return _length;
    }
    /**
     * Get start pointer of string. Note it might be not be valid until now
     */
    auto start() const {
        return _start;
    }
    /**
     * Get end pointer of string. Note it might be not be valid until now
     */
    auto end() const {
        return _end;
    }
    /**
     * Get name enum of this node
     */
    auto name() const {
        return _name;
    }
    /**
     * get data of this node
     */
    auto &data() {
        return _data;
    }
    /**
     * get data of this node
     */
    const auto &data() const {
        return _data;
    }

};
template<class RESULT_T>
struct match_result {
    bool status = false;
    Node<RESULT_T> node = {};
};

template<class TOKEN_T>
using TokenFlow = std::vector<Node<TOKEN_T>>;
template<class RULE_T>
using Seq = std::vector<Node<RULE_T>>;
struct error {
    std::size_t pos;
    std::size_t line;
    std::size_t column;
    std::string message;
};
namespace DFAAPI {
    // constants
    inline constexpr std::size_t null_state = std::numeric_limits<std::size_t>::max();
    template<class> inline constexpr bool always_false = false;

    // store types
    using MemberBegin = std::vector<std::size_t>;
    using GroupBegin = std::vector<std::pair<std::size_t, std::size_t>>;

    using CharTableDataVector = std::vector<std::string>;
    template<typename TOKEN_T> using CallableTokenDataVector = std::vector<Node<TOKEN_T>>;
    template<typename TOKEN_T> using MultiTableDataVector = std::vector<std::variant<std::string, Node<TOKEN_T>>>;

    // struct forward declarations
    template<typename TOKEN_T> struct SpanMultiTable;
    template<typename TOKEN_T, typename builderParameterType>
    struct EmptyState;
    template<typename Key> struct Transition;
    template<typename T>   struct SpanState;
    template<std::size_t MAX, typename T> using State = std::array<T, MAX>;

    // empty state declaration
    template<typename TOKEN_T> using CharEmptyState = EmptyState<TOKEN_T, CharTableDataVector>;
    template<typename TOKEN_T> using CallableTokenEmptyState = EmptyState<TOKEN_T, CallableTokenDataVector<TOKEN_T>>;
    template<typename TOKEN_T> using MultiTableEmptyState = EmptyState<TOKEN_T, MultiTableDataVector<TOKEN_T>>;

    // transition types
    using CharTransition = Transition<char>;
    template<typename TOKEN_T> using TokenTransition = Transition<TOKEN_T>;
    template<typename TOKEN_T> using CallableTokenTransition = Transition<match_result<TOKEN_T> (*)(const char*)>;
    template<typename TOKEN_T> using CharTableTransition = Transition<Span<const std::variant<SpanState<CharTransition>, CharEmptyState<TOKEN_T>>>>;
    template<typename TOKEN_T> using CallableTokenTableTransition = Transition<Span<const std::variant<SpanState<CallableTokenTransition<TOKEN_T>>, CallableTokenEmptyState<TOKEN_T>>>>;
    template<typename TOKEN_T> using MultiTableTransition = Transition<SpanMultiTable<TOKEN_T>>;
    template<typename TOKEN_T>
    using AnyTransition = std::variant<
        CharTransition,
        CallableTokenTransition<TOKEN_T>,
        CharTableTransition<TOKEN_T>,
        CallableTokenTableTransition<TOKEN_T>,
        MultiTableTransition<TOKEN_T>
    >;
    // state types
    template<std::size_t N> using CharTableState = State<N, CharTransition>;
    template<typename TOKEN_T, std::size_t N> using TokenTableState = State<N, TokenTransition<TOKEN_T>>;
    template<typename TOKEN_T, std::size_t N> using CallableTokenState = State<N, CallableTokenTransition<TOKEN_T>>;
    template<typename TOKEN_T, std::size_t N> using MultiTableState = State<N, AnyTransition<TOKEN_T>>;
    // span state types
    using SpanCharTableState = SpanState<CharTransition>;
    template<typename TOKEN_T> using SpanTokenTableState = SpanState<TokenTransition<TOKEN_T>>;
    template<typename TOKEN_T> using SpanCallableTokenState = SpanState<CallableTokenTransition<TOKEN_T>>;
    template<typename TOKEN_T> using SpanMultiTableState = SpanState<AnyTransition<TOKEN_T>>;

    // non-span table types
    template<typename TOKEN_T, std::size_t N> using CharTable = std::array<std::variant<SpanState<CharTransition>, CharEmptyState<TOKEN_T>>, N>;
    template<typename TOKEN_T, std::size_t N> using TokenTable = std::array<SpanState<TokenTransition<TOKEN_T>>, N>;
    template<typename TOKEN_T, std::size_t N> using CallableTokenTable = std::array<std::variant<SpanState<CallableTokenTransition<TOKEN_T>>, CallableTokenEmptyState<TOKEN_T>>, N>;
    template<typename TOKEN_T, std::size_t N> using MultiTable = std::array<std::variant<SpanCharTableState, SpanCallableTokenState<TOKEN_T>, SpanMultiTableState<TOKEN_T>, MultiTableEmptyState<TOKEN_T>>, N>;

    // span table types
    template<typename TOKEN_T> using SpanCharTable = Span<const std::variant<SpanState<CharTransition>, CharEmptyState<TOKEN_T>>>;
    template<typename TOKEN_T> using SpanTokenTable = Span<const SpanState<TokenTransition<TOKEN_T>>>;
    template<typename TOKEN_T> using SpanCallableTokenTable = Span<const std::variant<SpanState<CallableTokenTransition<TOKEN_T>>, CallableTokenEmptyState<TOKEN_T>>>;

    // structures

    template<typename TOKEN_T, typename builderParameterType>
    struct EmptyState {
        TOKEN_T name;
        std::function<std::any (const MemberBegin &, const GroupBegin &, const builderParameterType&)> ast_builder;
    };
    template<typename Key>
    struct Transition {
        Key symbol;
        std::size_t next;
        bool new_cst_node;
        bool new_member;
        bool close_cst_node;
        std::size_t new_group;
        std::size_t group_close;
        std::size_t accept;
    };
    template<typename T>
    struct SpanState {
        std::size_t else_goto;
        std::size_t any_goto;
        std::size_t else_goto_accept;
        Span<const T> transitions;
    };
    template<typename TOKEN_T>
    struct SpanMultiTable {
        Span<const std::variant<SpanCharTableState, SpanCallableTokenState<TOKEN_T>, SpanMultiTableState<TOKEN_T>, MultiTableEmptyState<TOKEN_T>>> states;
    };
    template<typename TOKEN_T, typename STORAGE_T>
    void cst_store(STORAGE_T &storage, std::size_t pos, const DFAAPI::MemberBegin &mb, const CharTableDataVector &dv) {
        std::cout << "member begin size: " << mb.size() << ", data vector size: " << dv.size() << ", pos: " << pos;
        std::flush(std::cout);
        auto start = mb[pos];
        auto end = pos + 1 == mb.size() ? dv.size() : mb[pos + 1];
        auto offset = end - start;

        if constexpr (std::is_same_v<STORAGE_T, std::vector<decltype(dv[0])>>) {
            storage.assign(dv.begin() + start, dv.begin() + end);
        } else {
            if (offset > 1)
                throw std::runtime_error("ISPA internal error: node type error: offset is over 1, but the data type is not a vector");

            if (offset) {
                const auto &str = dv[start];
                if constexpr (std::is_same_v<STORAGE_T, char>) {
                    storage = str.empty() ? '\0' : str[0];
                } else if constexpr (std::is_same_v<STORAGE_T, std::string>) {
                    storage = str;
                } else {
                    throw std::runtime_error("ISPA internal error: unsupported storage type for CharTableDataVector");
                }
            }
        }
    }
    template<typename TOKEN_T, typename STORAGE_T, typename DATAVECTOR>
    void cst_store(STORAGE_T &storage, std::size_t pos, const DFAAPI::MemberBegin &mb, const DATAVECTOR &dv) {
        std::cout << "member begin size: " << mb.size() << ", data vector size: " << dv.size() << ", pos: " << pos;
        auto start = mb[pos];
        auto end = pos + 1 == mb.size() ? dv.size() : mb[pos + 1];
        auto offset = end - start;
        if constexpr (std::is_same_v<STORAGE_T, std::vector<decltype(dv[0])>>) {
            storage.assign(dv.begin() + start, dv.begin() + end);
        } else {
            if (offset > 1)
                throw std::runtime_error("ISPA internal error: node type error: offset is over 1, but the data type is not a vector");
            if (offset) {
                if constexpr (std::is_same_v<STORAGE_T, char> || std::is_same_v<STORAGE_T, std::string>) {
                    throw std::runtime_error("Ispa internal error: expected string type for CallableToken");
                } else if constexpr (std::is_same_v<STORAGE_T, Node<TOKEN_T>>) {
                    storage.data() = dv[start];
                } else {
                    storage = dv[start];
                }
            }
        }
    }
    template<typename TOKEN_T, typename STORAGE_T>
    void cst_store(STORAGE_T &storage, std::size_t pos, const DFAAPI::MemberBegin &mb, const MultiTableDataVector<TOKEN_T> &dv) {
        std::cout << "member begin size: " << mb.size() << ", data vector size: " << dv.size() << ", pos: " << pos;
        std::flush(std::cout);
        auto start = mb[pos];
        auto end = pos + 1 == mb.size() ? dv.size() : mb[pos + 1];
        auto offset = end - start;

        if constexpr (std::is_same_v<STORAGE_T, std::vector<decltype(dv[0])>>) {
            storage.assign(dv.begin() + start, dv.begin() + end);
        } else {
            if (offset > 1)
                throw std::runtime_error("ISPA internal error: node type error: offset is over 1, but the data type is not a vector");

            if (offset) {
                if constexpr (std::is_same_v<STORAGE_T, char> || std::is_same_v<STORAGE_T, std::string>) {
                    if (!std::holds_alternative<std::string>(dv[start]))
                        throw std::runtime_error("ISPA internal error: expected string type while holding one more token");
                    const auto &str = std::get<std::string>(dv[start]);
                    if constexpr (std::is_same_v<STORAGE_T, char>) {
                        storage = str.empty() ? '\0' : str[0];
                    } else {
                        storage = str;
                    }
                } else if constexpr (std::is_same_v<STORAGE_T, Node<TOKEN_T>>) {
                    if (std::holds_alternative<std::string>(dv[start])) {
                        storage.data() = std::get<std::string>(dv[start]);
                    } else {
                        storage.data() = std::get<Node<TOKEN_T>>(dv[start]);
                    }
                } else {
                    if constexpr (std::is_same_v<STORAGE_T, std::string>) {
                        if (std::holds_alternative<std::string>(dv[start])) {
                            storage = std::get<std::string>(dv[start]);
                        } else {
                            throw std::runtime_error("Variant does not hold a string for storage assignment");
                        }
                    } else if constexpr (std::is_same_v<STORAGE_T, Node<TOKEN_T>>) {
                        if (std::holds_alternative<Node<TOKEN_T>>(dv[start])) {
                            storage = std::get<Node<TOKEN_T>>(dv[start]);
                        } else {
                            throw std::runtime_error("Variant does not hold a Node<TOKEN_T> for storage assignment");
                        }
                    } else if constexpr (std::is_same_v<STORAGE_T, std::vector<Node<TOKEN_T>>>) {
                        if (std::holds_alternative<Node<TOKEN_T>>(dv[start])) {
                            storage.push_back(std::get<Node<TOKEN_T>>(dv[start]));
                        } else {
                            throw std::runtime_error("Variant does not hold a Node<TOKEN_T> for storage assignment");
                        }
                    } else {
                        static_assert(always_false<STORAGE_T>, "Unsupported type for storage assignment");
                    }
                }
            }
        }
    }

    template<typename TOKEN_T, typename T, typename DATAVECTOR>
    void cst_group_store(T &storage, std::size_t pos, const DFAAPI::GroupBegin gb, const DATAVECTOR &dv) {
        if (pos >= gb.size())
            return;
        std::cout << "T: " << typeid(T).name() << std::endl;
        auto [start, end] = gb[pos];
        if constexpr (std::is_same_v<T, std::string>) {
            for (; start != end; ++start) {
                if constexpr (std::is_same_v<DATAVECTOR, CharTableDataVector>) {
                    storage += dv[start];
                } else if constexpr (std::is_same_v<DATAVECTOR, CallableTokenDataVector<TOKEN_T>>) {
                    throw std::runtime_error("Ispa internal error: group cannot be assigned as complete entity with callable token data vector");
                } else {
                    if (!std::holds_alternative<std::string>(dv[start]))
                        throw std::runtime_error("Ispa internal error: group cannot be assigned as complete entity when one of parts is not a string");
                    storage += std::get<std::string>(dv[start]);
                }
            }
        } else {
            // is is std::vector expecting group value sequence
            if constexpr (std::is_same_v<DATAVECTOR, CallableTokenDataVector<TOKEN_T>>) {
                storage.assign(dv.begin() + start, dv.begin() + end);
            } else {
                for (; start != end; ++start) {
                    storage.push_back(std::get<Node<TOKEN_T>>(dv[start]));
                }
            }

        }
    }
    inline void openGroups(GroupBegin &gb, std::vector<std::size_t> &inclosed_groups, std::size_t index, std::size_t &lowest_open_index, std::size_t group_begin_index) {
        if (lowest_open_index >= index)
            return;
        auto how_much_to_open = index - lowest_open_index;
        for (; how_much_to_open > 0; --how_much_to_open) {
            inclosed_groups.push_back(gb.size());
            gb.emplace_back(group_begin_index, 0);
        }
        lowest_open_index = index + 1;
    }
    inline void closeGroups(GroupBegin &gb, std::vector<std::size_t> &inclosed_groups, std::size_t index, std::size_t group_end_index) {
        // Close all groups up to and including the specified closing_group_index
        while (!inclosed_groups.empty()) {
            auto current_group = inclosed_groups.back();

            // Close it
            gb[current_group].second = group_end_index;
            inclosed_groups.pop_back();

            if (current_group == index) {
                // Done closing all nested groups within this group
                break;
            }
        }
    }
}
template<typename TOKEN_T>
using fcdt_variant = std::variant<std::monostate, DFAAPI::SpanCallableTokenTable<TOKEN_T>, DFAAPI::SpanCharTable<TOKEN_T>, DFAAPI::SpanMultiTable<TOKEN_T>, match_result<TOKEN_T> (*) (const char*)>;
template<typename TOKEN_T>
using fcdt_table = std::array<fcdt_variant<TOKEN_T>, std::numeric_limits<unsigned char>::max() + 1>;

template<typename TOKEN_T>
class DFA {
protected:
    template <typename IT>
    static auto find_key(const DFAAPI::SpanCharTableState &state, IT &pos) -> const DFAAPI::CharTransition* {
        for (const auto &t : state.transitions) {
            if (t.symbol == *pos) {
                printf("lookup for symbol %c successful\n", *pos);
                return &t;
            }
        }
        return nullptr;
    }
    template <typename IT>
    static auto find_key(const DFAAPI::SpanCallableTokenState<TOKEN_T> &state, IT &pos) -> std::pair<const DFAAPI::CallableTokenTransition<TOKEN_T>*, Node<TOKEN_T>> {
        for (const auto &t : state.transitions) {
            auto res = t.symbol(pos);
            if (res.status) {
                return std::make_pair(&t, res.node);
            }
        }
        return std::make_pair(nullptr, Node<TOKEN_T>{});
    }
    template <typename IT>
    static auto find_key(const DFAAPI::SpanTokenTableState<TOKEN_T> &state, IT &pos) -> const DFAAPI::TokenTransition<TOKEN_T>* {
        for (const auto &t : state.transitions) {
            if (t.symbol == pos->name()) {
                return &t;
            }
        }
        return nullptr;
    }
    template<typename IT, typename PanicModeFunc>
    static auto match(const DFAAPI::SpanCharTable<TOKEN_T> table, IT pos, PanicModeFunc panic_mode) -> match_result<TOKEN_T> {
        std::size_t state = 0;
        DFAAPI::MemberBegin member_begin;
        DFAAPI::GroupBegin group_begin;
        DFAAPI::CharTableDataVector data;

        std::vector<std::size_t> inclosed_groups;
        std::size_t lowest_open_index = 0;
        auto start = pos;
        bool closed = true;
        do {
            //printf("table.size: %zu, state: %zu\n", table.size(), state);
            fflush(stdout);
            const auto &s = std::get<DFAAPI::SpanCharTableState>(table[state]);
            decltype(auto) new_state = find_key(s, pos);
            if (new_state != nullptr) {
                pos++;
                state = new_state->next;
                if (new_state->new_member) {
                    member_begin.push_back(data.size());
                }
                if (new_state->group_close != DFAAPI::null_state) {
                    DFAAPI::closeGroups(group_begin, inclosed_groups, new_state->group_close, data.size());
                }
                if (new_state->new_group != DFAAPI::null_state) {
                    DFAAPI::openGroups(group_begin, inclosed_groups, new_state->new_group, lowest_open_index, data.size());
                }
                if (new_state->close_cst_node) {
                    closed = true;
                }
                if (new_state->new_cst_node) {
                    data.emplace_back();
                    closed = false;
                }
                if (!closed) {
                    data.back() += new_state->symbol;
                }
            } else if (s.else_goto) {
                state = s.else_goto;
            } else {
                if constexpr (!std::is_same_v<PanicModeFunc, std::nullptr_t>) {
                    if (panic_mode != nullptr) {
                        // TODO: Throw error here
                        panic_mode(pos);
                        continue;
                    }
                }
                return {};
            }
        } while (!std::holds_alternative<DFAAPI::CharEmptyState<TOKEN_T>>(table[state]));
        for (const auto id : inclosed_groups) {
            group_begin[id].second = data.size();
        }
        const auto e_state = std::get<DFAAPI::CharEmptyState<TOKEN_T>>(table[state]);
        return match_result<TOKEN_T> {true, Node<TOKEN_T> { 0 /*todo*/, start, pos, static_cast<std::size_t>(std::distance(start, pos)), 0 /*todo*/, 0 /*todo*/, e_state.name, e_state.ast_builder(member_begin, group_begin, data) }};
    }
    template<typename IT, typename PanicModeFunc>
    static auto match(const DFAAPI::SpanCallableTokenTable<TOKEN_T> table, IT pos, PanicModeFunc panic_mode) -> match_result<TOKEN_T>  {
        std::size_t state = 0;
        DFAAPI::MemberBegin member_begin;
        DFAAPI::GroupBegin group_begin;
        DFAAPI::CallableTokenDataVector<TOKEN_T> data;

        std::vector<std::size_t> inclosed_groups;
        std::size_t lowest_open_index = 0;
        auto start = pos;
        bool closed = true;
        do {
            const auto &s = std::get<DFAAPI::SpanCallableTokenState<TOKEN_T>>(table[state]);
            auto [transition, result] = find_key(s, pos);
            if (transition != nullptr) {
                pos += result.length();
                state = transition->next;
                if (transition->new_member) {
                    member_begin.push_back(data.size());
                }
                if (transition->group_close != DFAAPI::null_state) {
                    DFAAPI::closeGroups(group_begin, inclosed_groups, transition->group_close, data.size());
                }
                if (transition->new_group != DFAAPI::null_state) {
                    DFAAPI::openGroups(group_begin, inclosed_groups, transition->new_group, lowest_open_index, data.size());
                }
                if (transition->close_cst_node)
                    closed = true;
                if (transition->new_cst_node)
                    closed = false;

                if (!closed)
                    data.push_back(result);
            } else if (s.else_goto) {
                state = s.else_goto;
            } else {
                if constexpr (!std::is_same_v<PanicModeFunc, std::nullptr_t>) {
                    if (panic_mode != nullptr) {
                        // TODO: Throw error here
                        panic_mode(pos);
                        continue;
                    }
                }
                return {};
            }
        } while (!std::holds_alternative<DFAAPI::CallableTokenEmptyState<TOKEN_T>>(table[state]));
        for (const auto id : inclosed_groups) {
            group_begin[id].second = data.size();
        }
        const auto e_state = std::get<DFAAPI::CallableTokenEmptyState<TOKEN_T>>(table[state]);
        return match_result<TOKEN_T> {true, Node<TOKEN_T> {0 /*todo*/, start, pos, static_cast<std::size_t>(std::distance(start, pos)), 0 /*todo*/, 0 /*todo*/, e_state.name, e_state.ast_builder(member_begin, group_begin, data) }};
    }
    template<typename IT, typename PanicModeFunc>
    static auto decide(const DFAAPI::SpanTokenTable<TOKEN_T> &table, IT &pos, PanicModeFunc panic_mode) -> std::size_t {
        std::size_t state = 0;
        std::size_t accept = std::numeric_limits<std::size_t>::max();
        do {
            decltype(auto) new_state = find_key(table[state], pos);
            if (new_state != nullptr) {
                pos++;
                state = new_state->next;
                if (new_state->accept != std::numeric_limits<std::size_t>::max()) {
                    accept = new_state->accept;
                }
            } else if (table[state].else_goto) {
                state = table[state].else_goto;
                if (table[state].else_goto_accept != DFAAPI::null_state) {
                    accept = table[state].else_goto_accept;
                }
            } else {
                if constexpr (!std::is_same_v<PanicModeFunc, std::nullptr_t>) {
                    if (panic_mode != nullptr) {
                        // TODO: Throw error here
                        panic_mode();
                    }
                }
            }
        } while (table[state].transitions.data() != nullptr);
        return accept;
    }
};
template<typename TOKEN_T>
class AdvancedDFA : DFA<TOKEN_T> {
    static auto find_key(const DFAAPI::SpanCharTableState &state, const char* pos) -> const DFAAPI::CharTransition* {
        for (const auto &transition : state.transitions) {
            if (*pos == transition.symbol) {
                printf("lookup for symbol %c successfull\n", *pos);
                return &transition;
            }
        }
        return nullptr;
    }
    static auto find_key(const DFAAPI::SpanCallableTokenState<TOKEN_T> &state, const char* pos) -> std::pair<const DFAAPI::CallableTokenTransition<TOKEN_T>*, Node<TOKEN_T>> {
        for (const auto &transition : state.transitions) {
            auto res = transition.symbol(pos);
            if (res.status) {
                return {&transition, res.node};
            }
        }
        return std::make_pair(nullptr, Node<TOKEN_T>{});
    }
    template<class... Ts>
    struct overload : Ts... {
        using Ts::operator()...;
        overload(Ts... ts) : Ts(ts)... {} // This line is essential
    };
protected:
    template<typename PanicModeFunc>
    static auto match(const DFAAPI::SpanMultiTable<TOKEN_T> &table, const char* pos, PanicModeFunc panic_mode) -> match_result<TOKEN_T> {
        std::flush(std::cout);
        std::size_t state = 0;
        DFAAPI::MemberBegin member_begin;
        DFAAPI::GroupBegin group_begin;
        DFAAPI::MultiTableDataVector<TOKEN_T> data;

        std::vector<std::size_t> inclosed_groups;
        std::size_t lowest_open_index;
        auto start = pos;
        bool closed = true;
        bool failed = false;
        do {
            std::visit(overload {
                [&](const DFAAPI::SpanCharTableState &t) {
                    decltype(auto) new_state = find_key(t, pos);
                    if (new_state == nullptr) {
                        if (t.else_goto) {
                            state = t.else_goto;
                            return;
                        }
                        failed = true;
                        return;
                    }
                    pos++;
                    state = new_state->next;
                    if (new_state->new_member) {
                        member_begin.push_back(data.size());
                    }
                    if (new_state->group_close != DFAAPI::null_state) {
                        DFAAPI::closeGroups(group_begin, inclosed_groups, new_state->group_close, data.size());
                    }
                    if (new_state->new_group != DFAAPI::null_state) {
                        DFAAPI::openGroups(group_begin, inclosed_groups, new_state->new_group, lowest_open_index, data.size());
                    }
                    if (new_state->close_cst_node)
                        closed = true;
                    if (new_state->new_cst_node) {
                        data.emplace_back();
                        closed = false;
                    }
                    if (!closed)
                        std::get<std::string>(data.back()) += new_state->symbol;
                },
                [&](const DFAAPI::SpanCallableTokenState<TOKEN_T> &t) {
                    // guard: even if no new_cst_node, this kind is always stored separately
                    decltype(auto) new_state = find_key(t, pos);
                    if (new_state.first == nullptr) {
                        if (t.else_goto) {
                            state = t.else_goto;
                            return;
                        }
                        failed = true;
                        return;
                    }
                    pos += new_state.second.length();
                    if (new_state.first->new_member) {
                        member_begin.push_back(data.size());
                    }
                    if (new_state.first->group_close != DFAAPI::null_state) {
                        DFAAPI::closeGroups(group_begin, inclosed_groups, new_state.first->group_close, data.size());
                    }
                    if (new_state.first->new_group != DFAAPI::null_state) {
                        DFAAPI::openGroups(group_begin, inclosed_groups, new_state.first->new_group, lowest_open_index, data.size());
                    }
                    if (new_state.first->close_cst_node)
                        closed = true;
                    if (new_state.first->new_cst_node)
                        closed = false;
                    state = new_state.first->next;
                    data.push_back(new_state.second);
                },
                [&](const DFAAPI::SpanMultiTableState<TOKEN_T> &t) {
                    bool matched = false;
                    for (const auto &option : t.transitions) {
                        // Each option is:
                        //   std::variant<SpanCharTableState, SpanCallableTokenState<TOKEN_T>, SpanMultiTableState<TOKEN_T>, SpanEmptyTableState>
                        std::visit([&](const auto &t) {
                            if constexpr (std::is_same_v<std::decay_t<decltype(t)>, DFAAPI::CharTransition>) {
                                if (*pos == t.symbol) {
                                    pos++;
                                    state = t.next;
                                    if (t.new_member) {
                                        member_begin.push_back(data.size());
                                    }
                                    if (t.group_close != DFAAPI::null_state) {
                                        DFAAPI::closeGroups(group_begin, inclosed_groups, t.group_close, data.size());
                                    }
                                    if (t.new_group != DFAAPI::null_state) {
                                        DFAAPI::openGroups(group_begin, inclosed_groups, t.new_group, lowest_open_index, data.size());
                                    }
                                    if (t.close_cst_node)
                                        closed = true;
                                    if (t.new_cst_node) {
                                        data.emplace_back();
                                        closed = false;
                                    }
                                    if (!closed)
                                        std::get<std::string>(data.back()) += t.symbol;
                                    matched = true;
                                }
                            } else if constexpr (std::is_same_v<std::decay_t<decltype(t)>, DFAAPI::CallableTokenTransition<TOKEN_T>>) {
                                if (auto res = t.symbol(pos); res.status) {
                                    pos += res.node.length();
                                    if (t.new_member) {
                                        member_begin.push_back(data.size());
                                    }
                                    if (t.group_close != DFAAPI::null_state) {
                                        DFAAPI::closeGroups(group_begin, inclosed_groups, t.group_close, data.size());
                                    }
                                    if (t.new_group != DFAAPI::null_state) {
                                        DFAAPI::openGroups(group_begin, inclosed_groups, t.new_group, lowest_open_index, data.size());
                                    }
                                    if (t.close_cst_node)
                                        closed = true;
                                    if (t.new_cst_node)
                                        closed = false;
                                    state = t.next;
                                    if (!closed)
                                        data.push_back(res.node);
                                    matched = true;
                                }
                            } else if constexpr (std::is_same_v<std::decay_t<decltype(t)>, DFAAPI::MultiTableTransition<TOKEN_T>>) {
                                if (auto res = AdvancedDFA<TOKEN_T>::match(t.symbol, pos, nullptr); res.status) {
                                    pos += res.node.length();
                                    if (t.new_member) {
                                        member_begin.push_back(data.size());
                                    }
                                    if (t.group_close != DFAAPI::null_state) {
                                        DFAAPI::closeGroups(group_begin, inclosed_groups, t.group_close, data.size());
                                    }
                                    if (t.new_group != DFAAPI::null_state) {
                                        DFAAPI::openGroups(group_begin, inclosed_groups, t.new_group, lowest_open_index, data.size());
                                    }
                                    if (t.close_cst_node)
                                        closed = true;
                                    if (t.new_cst_node)
                                        closed = false;
                                    if (!closed)
                                        data.push_back(res.node);
                                    matched = true;
                                }
                            } else if constexpr (std::is_same_v<std::decay_t<decltype(t)>, DFAAPI::CharTableTransition<TOKEN_T>> || std::is_same_v<std::decay_t<decltype(t)>, DFAAPI::CallableTokenTableTransition<TOKEN_T>>) {
                                printf("t.symbol size: %zu, pos: %c\n", t.symbol.size(), *pos);
                                if (auto res = DFA<TOKEN_T>::match(t.symbol, pos, nullptr); res.status) {
                                    printf("Successfull match\n");
                                    pos += res.node.length();
                                    if (t.new_member) {
                                        member_begin.push_back(data.size());
                                    }
                                    if (t.group_close != DFAAPI::null_state) {
                                        DFAAPI::closeGroups(group_begin, inclosed_groups, t.group_close, data.size());
                                    }
                                    if (t.new_group != DFAAPI::null_state) {
                                        DFAAPI::openGroups(group_begin, inclosed_groups, t.new_group, lowest_open_index, data.size());
                                    }
                                    if (t.close_cst_node)
                                        closed = true;
                                    if (t.new_cst_node)
                                        closed = false;
                                    if (!closed)
                                        data.push_back(res.node);
                                    matched = true;
                                } else {
                                    printf("Not matched\n");
                                }
                            } else {
                                throw std::runtime_error("Undefined multitable type");
                            }

                        }, option);
                        if (matched) {
                            break; // If matched, stop iterating other options
                        }
                    }

                    if (!matched) {
                        // Fallback to else_goto if exists
                        if (t.else_goto) {
                            state = t.else_goto;
                        } else {
                            failed = true;
                        }
                    }
                },
                [](const auto &unexpected) {
                    // or
                    throw std::runtime_error("ISPA_STD: unreachable lambda");
                }
            }, table.states[state]);
        } while (!std::holds_alternative<DFAAPI::MultiTableEmptyState<TOKEN_T>>(table.states[state]) && !failed);
        if (failed) {
            printf("Failed is set: leaving\n");
            return {};
        }
        for (const auto id : inclosed_groups) {
            group_begin[id].second = data.size();
        }
        const auto &e_state = std::get<DFAAPI::MultiTableEmptyState<TOKEN_T>>(table.states[state]);
        return match_result<TOKEN_T> {true, Node<TOKEN_T> { 0 /*todo*/, start, pos, static_cast<std::size_t>(std::distance(start, pos)), 0 /*todo*/, 0 /*todo*/, e_state.name, e_state.ast_builder(member_begin, group_begin, data) }};
    }
};
using ErrorController = std::map<std::size_t, error, std::greater<std::size_t>>;
template<class TOKEN_T>
class Lexer_base : AdvancedDFA<TOKEN_T> {
protected:
    const char* _in = nullptr;
    TokenFlow<TOKEN_T> tokens;
    std::vector<error> errors;
    ErrorController error_controller;
    /* internal integration functionality */
    /**
     * @brief Get the current position in the text (compares first input point with the current)
     * 
     * @param txt 
     * @return std::size_t 
     */
    std::size_t getCurrentPos(const char* in) {
        return in - _in;
    }
    /**
     * @brief skip the spaces
     * 
     * @param in the input
     * @return std::size_t
     */
    std::size_t skip_spaces(const char*& in) {
        auto prev = in;
        while(isspace(*in))
            in++;
        
        return in - prev;
    }
        /**
     * @brief Returns the number of line of the current token or rule. Note it assume the start pointer is still valid
     * 
     * @return std::size_t 
     */
    std::size_t __line(const char* pos) const {
        std::size_t count = 1;
        std::size_t escaptions = 0;
        for (const char* in = _in; in < pos; in++) {
            if (*in == '\n') count++;
        }
        return count;
    }
    /**
     * @brief Returns the position in line of token. Note it assume the start pointer is still valid
     * 
     * @return std::size_t 
     */
    std::size_t __column(const char* pos) const {
        std::size_t count = 1;
        std::size_t escaptions = 0;
        for (char* in = const_cast<char*>(_in); in < pos; in++) {
            if (*in == '\n') 
                count = 0;
            else 
                count++;
        }
        return count;
    }
    void reportError(const char* pos, std::string mes) {
        if (error_controller.count(pos - _in) == 0)
            error_controller[pos - _in] = {getCurrentPos(pos), __line(pos), __column(pos), "Expected " + mes};
    }
    static void panic_mode(const char* &pos) {
        if (*pos != '\0')
            ++pos;
    }
    auto fcdt_lookup(const fcdt_table<TOKEN_T> &fcdt, const char* &pos) -> Node<TOKEN_T> {
        while (*pos != '\0') {
            const auto &option = fcdt[*pos];
            std::printf("pos: %d, c: %c\n", (int) (pos - _in), *pos);
            if (std::holds_alternative<std::monostate>(option)) {
                panic_mode(pos);
                continue;
            }
            if (std::holds_alternative<DFAAPI::SpanCharTable<TOKEN_T>>(option)) {
                if (auto val = DFA<TOKEN_T>::match(std::get<DFAAPI::SpanCharTable<TOKEN_T>>(option), pos, &Lexer_base<TOKEN_T>::panic_mode); val.status) {
                    pos += val.node.length();
                    printf("[chartable] result node length: %zu\n", val.node.length());
                    return val.node;
                }
            } else if (std::holds_alternative<DFAAPI::SpanCallableTokenTable<TOKEN_T>>(option)) {
                if (auto val = DFA<TOKEN_T>::match(std::get<DFAAPI::SpanCallableTokenTable<TOKEN_T>>(option), pos, &Lexer_base<TOKEN_T>::panic_mode); val.status) {
                    pos += val.node.length();
                    printf("result node length: %zu", val.node.length());
                    return val.node;
                }
            } else if (std::holds_alternative<DFAAPI::SpanMultiTable<TOKEN_T>>(option)) {
                if (auto val = AdvancedDFA<TOKEN_T>::match(std::get<DFAAPI::SpanMultiTable<TOKEN_T>>(option), pos, &Lexer_base<TOKEN_T>::panic_mode); val.status) {
                    pos += val.node.length();
                    printf("[multitable] result node length: %zu\n", val.node.length());
                    return val.node;
                }
            }
            panic_mode(pos);
        }
        // end of input -> return eof token
        return Node<TOKEN_T>{};
    }
public:
    /**
     * A lazy iterator (accumulates only tokens that currently are accessed).
     * Be aware it acts independently of the lexer class and does not accumulate tokens for it
     */
    class lazy_iterator {
        Lexer_base<TOKEN_T>* owner = nullptr;
        Node<TOKEN_T> current;
        const char* pos = nullptr;
        std::size_t counter = 0;

        void advance() {
            if (isEnd())
                return;
            current = owner->makeToken(pos);
            if (!current.empty())
                counter++;
        }

    public:
        lazy_iterator(Lexer_base<TOKEN_T>& owner, const char* in)
            : owner(&owner), pos(in) {
            current = owner.makeToken(pos);
            counter = current.empty() ? 0 : 1;
        }

        lazy_iterator(Lexer_base<TOKEN_T>* owner, const char* in)
            : owner(owner), pos(in) {
            current = owner->makeToken(pos);
            counter = current.empty() ? 0 : 1;
        }

        lazy_iterator(const lazy_iterator &iterator)
            : owner(iterator.owner), pos(iterator.pos), counter(iterator.counter), current(iterator.current) {}

        bool isEnd() const {
            return current.empty();
        }

        lazy_iterator& operator=(const lazy_iterator& other) {
            if (this != &other) {
                owner = other.owner;
                pos = other.pos;
                current = other.current;
                counter = other.counter;
            }
            return *this;
        }

        lazy_iterator& operator++() {
            advance();
            return *this;
        }

        lazy_iterator operator++(int) {
            auto temp = *this;
            advance();
            return temp;
        }

        void operator+=(std::size_t count) {
            while (count-- > 0 && !isEnd())
                advance();
        }

        ptrdiff_t operator-(const lazy_iterator &iterator) const {
            return static_cast<ptrdiff_t>(counter) - static_cast<ptrdiff_t>(iterator.counter);
        }

        const Node<TOKEN_T>& operator*() const {
            return current;
        }

        const Node<TOKEN_T>* operator->() const {
            return &current;
        }

        std::size_t distance() const {
            return counter;
        }
    };

    /**
     * A regular iterator through tokens. Note that it won't iterate through tokens created by lazy iterator (which is done by default).
     * If you need to iterate through tokens after parsing, first accumulate tokens, then run parsing. That implies you must first create lexer class then parser class to do so
     */
    class iterator {
        Lexer_base<TOKEN_T>* owner = nullptr;
        typename TokenFlow<TOKEN_T>::iterator pos;
        public:
            iterator(Lexer_base<TOKEN_T> &owner) : owner(&owner), pos(owner->tokens.begin()) {}
            iterator(Lexer_base<TOKEN_T>* owner) : owner(owner), pos(owner->tokens.begin()) {}

            iterator& operator=(const iterator& other) {
                owner = other.owner;
                pos = other.pos;
                return *this;
            }            
            void operator+=(std::size_t count) {
                pos += count;
            }

            iterator& operator++() {
                this->operator+=(1);
                return *this;
            }
            iterator operator++(int) {
                auto temp = *this;
                this->operator+=(1);
                return temp;
            }
            std::size_t operator-(const iterator &iterator) const  {
                return pos - iterator.pos;
            }
            iterator operator+(std::size_t count) const {
                iterator temp = *this;
                temp += count;
                return temp;
            }
            bool isEnd() const {
                return pos->empty();
            }
            Node<TOKEN_T>& operator*() const {
                return *pos;
            } 
            Node<TOKEN_T>* operator->() const {
                return &(*pos);
            }
            auto distance() const {
                return pos - owner->tokens.begin();
            }
    };
    /**
     * Get one token
     */
    virtual Node<TOKEN_T> makeToken(const char*& pos) = 0;
    // constructors

    Lexer_base(const std::string& in) : _in(in.c_str()) {}
    Lexer_base(const char* in) : _in(in) {}
    Lexer_base(TokenFlow<TOKEN_T> &tokens) : tokens(tokens) {}
    Lexer_base() {}

    bool hasInput() const {
        return _in != nullptr;
    }
    Lexer_base& setinput(const std::string& in) {
        _in = in.c_str();
        return *this;
    }
    Lexer_base& setinput(char*& in) {
        _in = in;
        return *this;
    }
    Lexer_base& setinput(const char*& in) {
        _in = in;
        return *this;
    }
    bool hasTokens() const {
        return tokens.size() > 0;
    }
    /**
     * Get tokens as copy
     */
    TokenFlow<TOKEN_T> getTokens() const {
        return tokens;
    }
    /**
     * Get tokens by reference
     */
    TokenFlow<TOKEN_T>& getTokensReference() {
        return tokens;
    }
    /**
     * Clear tokens
     */
    void clearTokens() const {
        tokens.clear();
    }
    /**
     * @param in the input string
     * Get tokens from std::string
     */
    TokenFlow<TOKEN_T>& makeTokens(const std::string& in) {
        _in = in.c_str();
        makeTokens();
        return tokens;
    }
    /**
     * @param in the input C string
     * Get tokens from C string
     */
    TokenFlow<TOKEN_T>& makeTokens(const char*& in) {
        _in = in;
        makeTokens();
        return tokens;
    }
    /**
     * Get tokens from file by path. Note std::runtime_error is thrown if failed to open the file
     */
    TokenFlow<TOKEN_T>& makeTokensFromFile(const char* path) {
        std::ifstream file(path, std::ios::in | std::ios::binary);  // Open the file in binary mode as well for safety
        if (!file) {
            throw std::runtime_error(std::string("Failed to open file '") + path + "'");
        }
    
        std::string str;
        file.seekg(0, std::ios::end);
        std::size_t fileSize = file.tellg();
        str.reserve(fileSize);  // Reserve enough space for the string
    
        file.seekg(0, std::ios::beg);
        str.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        makeTokens(str);
        return tokens;
    }

    /**
     * Accumulate tokens (saving in this class) and return their reference
     */
    TokenFlow<TOKEN_T>& makeTokens() {
        if (_in == nullptr)
            throw Lexer_No_Input_exception();
        Node<TOKEN_T> result;
        const char* pos = _in;
        while (*pos != '\0') {
            result = makeToken(pos);
            if (result.empty()) {
                if (!error_controller.empty()) {
                    const auto &el = error_controller.begin()->second;
                    printf("Lexer[error controller]: %zu:%zu: %s\n", el.line, el.column, el.message.c_str());
                    errors.push_back(el);
                }
                pos++;
            } else {
                push(result);
            }
            error_controller.clear();
        }
        push(Node<TOKEN_T>());
        return tokens;
    };
    auto& getErrors() const {
        return errors;
    };
    /**
     * @param input_tokens the input tokens
     * Push flow of tokens
     */
    void push(const TokenFlow<TOKEN_T>& input_tokens) {
        tokens.append_range(input_tokens);
    }
    /**
     * @param input_token the input token
     * Push a token
     */
    void push(const Node<TOKEN_T>& input_token) {
        tokens.push_back(input_token);
    }
    /**
     * @param tokenizator the tokenizator with tokens
     * Push another lexer's tokens to the current one
     */
    void push(const Lexer_base& tokenizator) {
        if (tokenizator.hasTokens())
            tokens.push_back(tokenizator.tokens);
        else
            throw Lexer_No_Tokens_exception();
    }
    /**
     * Pop the last token
     */
    void pop() {
        tokens.pop_back();
    }
    /**
     * @param n the number of tokens to pop
     * Pop specific number of tokens
     */
    void pop(const std::size_t& n) {
        if (n > tokens.size())
            throw std::length_error(ISC_STD_LIBMARK "Tokenizator_base::pop(): the number of elements to pop is higher actual size");
        tokens.erase(tokens.end() - n, tokens.end());
    }

    Lexer_base& operator=(const Lexer_base& tokenizator) {
        tokens = tokenizator.tokens;
        _in = tokenizator._in;
        return *this;
    }
    bool operator==(const Lexer_base& tokenizator) {
        return tokens == tokenizator.tokens;
    }
    bool operator!=(const Lexer_base& tokenizator) {
        return tokens != tokenizator.tokens;
    }
};
/* PARSER */
template<class TOKEN_T, class RULE_T>
class LLParser_base : DFA<TOKEN_T> {
protected:
    template<class IT>
    void parseFromPos(IT& pos) {
        auto res = getRule(pos);
        if (!res.status) {
            if (!error_controller.empty())
                errors.push_back(error_controller.begin()->second);
            for (auto el : error_controller) {
                printf("Parser[error controller]: %zu:%zu: %s\n", el.second.line, el.second.column, el.second.message.c_str());
            }
        } else {
            tree = res.node;
        }
        error_controller.clear();
    }
    Lexer_base<TOKEN_T>* lexer = nullptr;
    const char* text = nullptr;
    Node<RULE_T> tree;
    std::vector<error> errors;
    ErrorController error_controller;
    // skip spaces for tokens
    template <class IT>
    std::size_t skip_spaces(IT& pos) {
        auto prev = pos;
        while (pos->name() == TOKEN_T::__WHITESPACE)
            ++pos;
        
        return pos - prev;
    }
    void reportError(typename Lexer_base<TOKEN_T>::lazy_iterator pos, std::string msg) {
        if (error_controller.count(pos.distance()) == 0)
            error_controller[pos.distance()] = {pos->startpos(), pos->line(), pos->column(), "Expected " + msg};
    }
    void reportError(typename Lexer_base<TOKEN_T>::iterator pos, std::string msg) {
        if (error_controller.count(pos.distance()) == 0)
            error_controller[pos.distance()] = {pos->startpos(), pos->line(), pos->column(), "Expected " + msg};
    }
    static void PANIC_MODE() {}
public:
    virtual match_result<RULE_T> getRule(typename Lexer_base<TOKEN_T>::lazy_iterator &pos) = 0;
    virtual match_result<RULE_T> getRule(typename Lexer_base<TOKEN_T>::iterator &pos) = 0;
    virtual void parseFromTokens() = 0;
    virtual void lazyParse() = 0;
    // Constructors
    LLParser_base() {}
    LLParser_base(const Lexer_base<TOKEN_T>& lexer) {
        if (lexer.hasTokens())
            this->lexer = &lexer;
    }
    LLParser_base(const char* text) : text(text) {}
    // Parsing methods
    Node<RULE_T>& parse(Lexer_base<TOKEN_T>& lexer) {
        if (lexer.hasTokens()) {
            this->lexer = &lexer;
        }
        return parse();
    }
    Node<RULE_T>& parse(const char* text) {
        this->text = text;
        return parse();
    }
    void setInput(Lexer_base<TOKEN_T> &lexer) {
        if (!lexer.hasTokens())
            this->lexer = &lexer;
    }
    void setInput(const char* text) {
        this->text = text;
    }
    void clearInput() {
        lexer = nullptr;
        text = nullptr;
    }
    auto getErrors() {
        return errors;
    }
    /**
     * @brief Parser the tokens based on input provided before
     * 
     * @return Tree<RULE_T> 
     */
    Node<RULE_T>& parse() {
        if (lexer != nullptr) {
            parseFromTokens();
        } else if (text != nullptr) {
            lazyParse();
        } else throw Parser_No_Input_exception();
        return tree;
    }
};
template <class TOKEN_T, class RULE_T, class Action, class ActionTable, class GotoTable, class RulesTable>
class LRParser_base : public LLParser_base<TOKEN_T, RULE_T> {
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
    match_result<RULE_T> getRule(typename Lexer_base<TOKEN_T>::lazy_iterator &pos) {
        return {};
    }
    match_result<RULE_T> getRule(typename Lexer_base<TOKEN_T>::iterator &pos) {
        return {};
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
template <class TOKEN_T, class RULE_T, class Action, class ActionTable, class GotoTable, class RulesTable, class DFATable>
class ELRParser_base : public LRParser_base<TOKEN_T, RULE_T, Action, ActionTable, GotoTable, RulesTable> {
private:
    // cache tokens because of lazy iterator which makes tokens on dereference
    std::deque<Node<TOKEN_T>> dfa_token_cache;
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
} // namespace ISPA_STD

#undef _ISC_GITHUB
#undef _ISC_INTERNAL_ERROR_MARK
#endif // _ISPA_STD_LIB_CPP