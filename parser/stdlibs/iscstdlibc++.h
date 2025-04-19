//!ISC_LIB_MANAGER C++ 1.1 ISC-parser Standard-library Versions iscstdlibcpp{VER}-{SUBVER}.h!\\

/**
 * C++ isc std lib 1.1
 * It contains standard declarations and every C++ generated parser would link toward it
 * It is for case you'd use two ISC parsers in one same project.
 * However it won't cancell that parser does not rely on any library
*/
#include <map>
#include <vector>
#include <deque>
#include <string>
#include <any>
#include <string_view>
#include <stdexcept>
#include <cctype>
#include <cstring>
#include <fstream>
#include <variant>
#include <optional>
#include <array>
#ifndef _ISC_STD_LIB
#define _ISC_STD_LIB

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
class return_base_exception : public std::exception {
    private:
        std::string mes;
        void fill(const std::string& method) {
            mes.resize(94 + 2*6 + 453 + 109);
            mes = 
            ISC_STD_LIBMARK "return_base_exception: the capture data has not been provided but called method '";
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
            ISC_STD_LIBMARK "return_base_exception: the capture data has not been provided but called method required it.\n"
            _ISC_INTERNAL_ERROR_MARK "\n"
            "E.G: This issue is because you have an opportunity to have token or rule be empty without first initialisation.\n"
            "But their methods like line etc. require those properties." 
            "When they are called but the object is still uninitialised you get this error\n"
            ;
        }
    public:
        return_base_exception(const char* method) {  fill(method);  }
        return_base_exception() {  fill();  }
    const char* what() const noexcept override {
        return mes.c_str();
    }
};
template<typename NODE_T>
class node {
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
    node(const std::size_t startpos, const char* start, const char* end, std::size_t length, std::size_t line, std::size_t column, NODE_T name) : _startpos(startpos), _start(start), _end(end), _length(length), _line(line), _column(column), _name(name), _empty(false) {}
    node(const std::size_t startpos, const char* start, const char* end, std::size_t length, std::size_t line, std::size_t column, NODE_T name, std::any data) : _startpos(startpos), _start(start), _end(end), _length(length), _line(line), _column(column), _name(name), _data(data), _empty(false) {}
    node() {}

    /**
     * @brief Get the end position based on startpos and length
     * 
     * @return long long 
     */
    std::size_t endpos() const {
        if (_startpos == std::string::npos || _end == nullptr || _start == nullptr)
            throw return_base_exception("endpos");
        return _startpos + (_end - _start);
    }
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
    template<typename T>
    T as() {
#ifdef DEBUG
        if (!data.has_value()) {
           std::cerr << "iscstdlibc++: No value in data\n";
           exit(1);
        } else if (data.type() != typeid(T)) {
            std::cerr << "iscstdlibc++: Data type mismatch. Expected: " << typeid(T).name() << " but got: " << data.type().name() << "\n";
            exit(1);
        }
#endif
        return std::any_cast<T>(_data);
    }
    node<NODE_T>& operator=(const node<NODE_T>& other) {
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
     * whether token is empty
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
    auto data() const {
        return _data;
    }

};
template<class RESULT_T>
struct match_result {
    bool status = false;
    node<RESULT_T> node;
};

template<class TOKEN_T>
using TokenFlow = std::vector<node<TOKEN_T>>;
template<class RULE_T>
using Tree = std::deque<node<RULE_T>>;
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
        for (char* in = const_cast<char*>(_in); in < pos; in++) {
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
     * A lazy iterator (accamulates only tokens that currently are accessed).
     * Be aware it acts independently of the lexer class and does not accamulate tokens for it
     * If you pass in parser class the input string a lazy iterator is going to be used and no tokens to lexer accamulated otherwise if you accamulate tokens in lexer class
     * and pass it in to parser class your tokens will be saved until clean
     */
    class lazy_iterator {
        Lexer_base<TOKEN_T>* owner = nullptr;
        node<TOKEN_T> current;
        const char* pos = nullptr;
        size_t counter = 0;
        public:
            lazy_iterator(Lexer_base<TOKEN_T>& owner, const char* in) : owner(&owner), pos(in) {}
            lazy_iterator(Lexer_base<TOKEN_T>* owner, const char* in) : owner(owner), pos(in) {}
            bool isEnd() {
                return current.empty();
            }
            void operator=(lazy_iterator iterator) {
                // add only first token that currently may be accessed
                // ommit others
                current = iterator.current;
                pos = iterator.pos;
                counter = iterator.counter;
            }
            void operator+=(size_t count) {
                current = owner->makeToken(pos);
                counter += count;
            }
            auto operator-(lazy_iterator iterator) {
                return counter - iterator.counter;
            }
            node<TOKEN_T>& operator*() {
                return current;
            }    
            lazy_iterator& operator++() {
                this->operator+=(1);
                return *this;
            }
            lazy_iterator operator++(int) {
                auto temp = *this;
                this->operator+=(1);
                return temp;
            }
            node<TOKEN_T>* operator->() {
                return &current;
            }
            auto getCounter() {
                return counter;
            }
    };
    /**
     * A regular iterator through tokens. Note that it won't iterate through tokens created by lazy iterator (which is done by default).
     * If you need to iterate through tokens after parsing, first accamulate tokens, then run parsing.
     */
    class iterator {
        Lexer_base<TOKEN_T>* owner = nullptr;
        typename TokenFlow<TOKEN_T>::iterator pos;
        public:
            iterator(const Lexer_base<TOKEN_T> &owner) : owner(&owner), pos(owner->tokens.begin()) {}
            iterator(Lexer_base<TOKEN_T>* owner) : owner(owner), pos(owner->tokens.begin()) {}
            bool isEnd() {
                return pos->empty();
            }
            void operator=(iterator iterator) {
                pos = iterator.pos;
            }
            void operator+=(size_t count) {
                pos += count;
            }
            auto operator-(iterator iterator) {
                return pos - iterator.pos;
            }
            node<TOKEN_T>& operator*() {
                return *pos;
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
            
            node<TOKEN_T>* operator->() {
                return &(*pos);
            }
            auto distance() {
                return pos - owner->tokens.begin();
            }
    };
    /**
     * Get one token
     */
    virtual node<TOKEN_T> makeToken(const char*& pos) = 0;
    // constructors

    explicit Lexer_base(const std::string& in) : _in(const_cast<char*>(in.c_str())) {}
    explicit Lexer_base(char*& in) : _in(in) {}
    explicit Lexer_base(const char*& in) : _in(const_cast<char*>(in)) {}
    explicit Lexer_base(TokenFlow<TOKEN_T> &tokens) : tokens(tokens) {}
    explicit Lexer_base() {}

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
     * Accamulate tokens (saving in this class) and return their reference
     */
    TokenFlow<TOKEN_T>& makeTokens() {
        if (_in == nullptr)
            throw Lexer_No_Input_exception();
        node<TOKEN_T> result;
        const char* pos = _in;
        while (*pos != '\0') {
            result = makeToken(pos);
            if (result.empty()) {
                if (!error_controller.empty()) {
                    errors.push_back(error_controller.begin()->second);
                    pos++;
                }
            } else {
                push(result);
            }
            error_controller.clear();
        }
        push(node<TOKEN_T>());
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
    void push(const node<TOKEN_T>& input_token) {
        tokens.push_back(input_token);
    }
    /**
     * @param tokenizator the tokenizator with tokens
     * Push another tokenizator tokens to current token flow. Note that if tokenizator has no token an Lexer_No_Tokens_exception is raised 
     */
    void push(const Lexer_base& tokenizator) {
        if (tokenizator.hasTokenFlow())
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
     * @param n the amount of tokens to pop
     * Pop a specific amount of tokens
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
    template<class T>
    void parseFromPos(T& pos) {
        while(!pos.isEnd()) {
            auto res = getRule(pos);
            if (!res.status) {
                // if (!error_controller.empty())
                //     errors.push_back(error_controller.begin()->second);
                for (auto el : error_controller) {
                    printf("Parser[error controller]: %zu:%zu: %s\n", el.second.line, el.second.column, el.second.message.c_str());
                }
                break;
            } else {
                tree.push_back(res.node);
                pos += res.node.length();
            }
            error_controller.clear();
        }
    }
    Lexer_base<TOKEN_T>* lexer = nullptr;
    const char* text = nullptr;
    Tree<RULE_T> tree;
    std::vector<error> errors;
    ErrorController error_controller;
    // skip spaces for tokens
    template <typename Iterator, typename Tokens>
    size_t skip_spaces(Iterator& pos) {
        auto prev = pos;
        while (pos->name() == Tokens::__WHITESPACE)
            ++pos;
        
        return std::distance(prev, pos);
    }
    void reportError(typename Lexer_base<TOKEN_T>::lazy_iterator pos, std::string msg) {
        if (error_controller.count(pos.getCounter()) == 0)
            error_controller[pos.getCounter()] = {pos->startpos(), pos->line(), pos->column(), "Expected " + msg};
    }
    void reportError(typename Lexer_base<TOKEN_T>::iterator pos, std::string msg) {
        if (error_controller.count(pos.distance()) == 0)
            error_controller[pos.distance()] = {pos->startpos(), pos->line(), pos->column(), "Expected " + msg};
    }
public:
    /**
     * @brief Your parsed Tree. The Tree is std::vector. 
     * 
     */
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
    Tree<RULE_T>& parse(Lexer_base<TOKEN_T>& lexer) {
        if (lexer.hasTokens()) {
            this->lexer = &lexer;
        }
        return parse();
    }
    Tree<RULE_T>& parse(const char* text) {
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
     * @brief Parser the tokens and get the tree
     * 
     * @return Tree<RULE_T> 
     */
    Tree<RULE_T>& parse() {
        if (lexer != nullptr) {
            parseFromTokens();
        } else if (text != nullptr) {
            lazyParse();
        } else  throw Parser_No_Input_exception();
        return tree;
    }
};
template <class TOKEN_T, class RULE_T, class Action, class ActionTable, class GotoTable, class RulesTable>
class LRParser_base : public LLParser_base<TOKEN_T, RULE_T> {
private:
    std::deque<std::pair<std::variant<TOKEN_T, RULE_T>, size_t>> stack;
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
        printf("Reduce: goto_table[%zu][%d]\n", (int) stack.back().second, (int) rule_name);
        // Perform the reduction
        const auto& goto_entry = goto_table[stack.back().second][static_cast<size_t>(rule_name)];
        if (!goto_entry.has_value()) {
            throw std::runtime_error("Invalid GOTO after reduction");
        }

        size_t next_state = goto_entry.value();
        stack.push_back({rule_name, next_state});
    } 
protected:
    match_result<RULE_T> getRule(typename Lexer_base<TOKEN_T>::lazy_iterator &pos) {
        return {};
    }
    match_result<RULE_T> getRule(typename Lexer_base<TOKEN_T>::iterator &pos) {
        return {};
    }
    template<class IT>
    void parseFromPos(IT& pos, const ActionTable &action_table, const GotoTable &goto_table, RulesTable rules_table) {
        stack.push_back({TOKEN_T::NONE, 0});
        while(true) {
            auto &current_state = stack.back().second;
            const auto &action = action_table[current_state][(size_t) pos->name()];
            printf("Token name: %d\n", (int) pos->name());
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
                throw std::runtime_error(("Action is not defined. stack size()" + std::to_string(stack.size())).c_str());
            }
        }
    }
};

} // namespace __ISC_STD

#undef _ISC_GITHUB
#undef _ISC_INTERNAL_ERROR_MARK
#endif // ISC_STD_LIB_CPP