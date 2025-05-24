//!ISPA_LIB_MANAGER C++ 1.1 ISC-parser Standard-library Versions iscstdlibcpp{VER}-{SUBVER}.h!\\

/**
 * C++ ispa std lib 1.1
 * It contains standard declarations and every C++ generated parser would link toward it
 * It is for case you'd use two ISC parsers in one same project.
 * However it won't cancell that parser does not rely on any library
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
#include <cstring>
#include <fstream>
#include <variant>
#include <optional>
#include <queue>
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

namespace {
    template<typename T>
    constexpr std::size_t biggest_sz() {
        return sizeof(T);
    }

    template<typename T1, typename T2, typename... Ts>
    constexpr std::size_t biggest_sz() {
        return sizeof(T1) > biggest_sz<T2, Ts...>() ? sizeof(T1) : biggest_sz<T2, Ts...>();
    }
}
/**
 * @brief For the C++ here are common class declarations and structures
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
class node_exception : public std::exception {
    private:
        std::string mes;
        void fill(const std::string& method) {
            mes.resize(94 + 2*6 + 453 + 109);
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
using TokenFlow = vector<Node<TOKEN_T>>;
template<class RULE_T>
using Seq = vector<Node<RULE_T>>;
struct error {
    std::size_t pos;
    std::size_t line;
    std::size_t column;
    std::string message;
};

using ErrorController = std::map<std::size_t, error, std::greater<std::size_t>>;
template<class TOKEN_T>
class Lexer_base {
protected:
    const char* _in = nullptr;
    TokenFlow<TOKEN_T> tokens;
    vector<error> errors;
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
public:
    /**
     * A lazy iterator (accumulates only tokens that currently are accessed).
     * Be aware it acts independently of the lexer class and does not accumulate tokens for it
     */
    class lazy_iterator {
        Lexer_base<TOKEN_T>* owner = nullptr;
        Node<TOKEN_T> current;
        const char* pos = nullptr;
        size_t counter = 0;

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

        void operator+=(size_t count) {
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

        size_t distance() const {
            return counter;
        }
    };

    /**
     * A regular iterator through tokens. Note that it won't iterate through tokens created by lazy iterator (which is done by default).
     * If you need to iterate through tokens after parsing, first accumulate tokens, then run parsing.
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
            void operator+=(size_t count) {
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
            size_t operator-(const iterator &iterator) const  {
                return pos - iterator.pos;
            }
            iterator operator+(size_t count) const {
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
        size_t fileSize = file.tellg();
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
class LLParser_base {
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
    vector<error> errors;
    ErrorController error_controller;
    // skip spaces for tokens
    template <class IT>
    size_t skip_spaces(IT& pos) {
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
    vector<std::pair<std::variant<TOKEN_T, RULE_T>, size_t>> stack;
    template <class IT>
    void shift(IT& pos, size_t state) {
        stack.push_back({pos->name(), state});
        pos++;
    }
    void reduce(const size_t rules_id, const GotoTable &goto_table, const RulesTable rules_table) {
        const auto &rule_data = rules_table[rules_id];
        const auto &rule_name = rule_data.first;
        const auto &reduce_size = rule_data.second;
        if (stack.size() < reduce_size) {
            throw std::runtime_error("Stack underflow during reduce");
        }
        stack.erase(stack.end() - reduce_size, stack.end());
        printf("Reduce: goto_table[%d][%d]\n", (int) stack.back().second, (int) rule_name);
        // Perform the reduction
        const auto& goto_entry = goto_table[stack.back().second][static_cast<size_t>(rule_name)];
        if (!goto_entry.has_value()) {
            throw std::runtime_error("Invalid GOTO after reduction");
        }

        size_t next_state = goto_entry.value();
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
            const auto &action = action_table[current_state][(size_t) pos->name()];
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
    void shift(IT& pos, size_t state) {
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
        return dfa_token_cache.empty() ? action_table[current_state][(size_t) pos->name()] : action_table[current_state][(size_t) dfa_token_cache.front().name()];
    }
    template<class IT>
    const Action* resolveDFA(IT &pos, size_t dfa_index, const DFATable &dfa_table) {
        const Action* initial_action = nullptr;
        printf("Resolving conflict in DFA table\n");
        size_t current_dfa_length = dfa_token_cache.size();
        for (size_t offset = 0;; offset++) {
            if (offset >= current_dfa_length)
                dfa_token_cache.push_back(*pos++);
            const auto &[action, table] = dfa_table[dfa_index];
            size_t i = 1;
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
} // namespace __ISC_STD

#undef _ISC_GITHUB
#undef _ISC_INTERNAL_ERROR_MARK
#endif // _ISPA_STD_LIB_CPP