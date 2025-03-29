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
class Tokenizator_No_Tokens_exception : public std::exception {
    public:
    const char* what() const noexcept override {
        return ISC_STD_LIBMARK "Tokenizator_No_Tokens_exception: the tokenizator has no tokens but some operation required them";
    }
};
class Tokenizator_No_Input_exception : public std::exception {
    public:
    const char* what() const noexcept override {
        return ISC_STD_LIBMARK "Tokenizator_No_Input_exception: the tokenizator has no input provided but the operation required it";
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
template<typename RETURN_T>
class node {
    std::size_t _startpos = std::string::npos;
    const char* _start = nullptr;
    const char* _end = nullptr;
    RETURN_T _name = RETURN_T::NONE;
    std::any _data;
    bool _empty = true;
    public:
    node(const std::size_t startpos, const char* start, const char* end, RETURN_T name) : _startpos(startpos), _start(start), _end(end), _name(name), _empty(false) {}
    node(const std::size_t startpos, const char* start, const char* end, RETURN_T name, std::any data) : _startpos(startpos), _start(start), _end(end), _name(name), _data(data), _empty(false) {}
    node() {}


    /**
     * @brief Returns the number of line of the current token or rule. Note it assume the start pointer is still valid
     * 
     * @return std::size_t 
     */
    std::size_t line() const {
        if (_startpos == std::string::npos || _start == nullptr)
            throw return_base_exception("line");
        std::size_t count = 0;
        std::size_t escaptions = 0;
        for (std::size_t i = _startpos; i >= 0; --i) {
            if (*(_start - i) == '\n') count++;
        }
        return count;
    }
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
    std::size_t length() const {
        if (_start == nullptr || _end == nullptr)
            throw return_base_exception("length");
        return _end - _start;
    }
    void clear() {
        _startpos = std::string::npos;
        _start = nullptr;
        _end = nullptr;
        _name = RETURN_T::NONE;
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
    node<RETURN_T>& operator=(const node<RETURN_T>& other) {
        if (this == &other)  // Protect against self-assignment
            return *this;
        _startpos = other._startpos;
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
    auto empty() {
        return _empty;
    }
    /**
     * get start position 
     */
    auto startpos() {
        return _startpos;
    }
    /**
     * Get start pointer of string. Note it might be not be valid until now
     */
    auto start() {
        return _start;
    }
    /**
     * Get end pointer of string. Note it might be not be valid until now
     */
    auto end() {
        return _end;
    }
    /**
     * Get name enum of this node
     */
    auto name() {
        return _name;
    }
    /**
     * get data of this node
     */
    auto data() {
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
using Tree = std::vector<node<RULE_T>>;

/**
 * @brief Join vector into string
 * 
 * @tparam T 
 * @param vec
 * @param del
 * @return std::string 
 */
template<typename T>
std::string join(const std::vector<T>& vec, const std::string& del = "") {
    std::string str;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        str += vec[i];
        str += del;
    }
    str += vec.back();
    return str;
}
/**
 * @brief Skip a specific amount of symbols
 * 
 * @param in 
 * @param text 
 * @return size_t 
 */
size_t skipup(const char*& in, const char* text);
// Skip a list of symbols
size_t skip_list(const char*& in, const char* text);
// Skip spaces
size_t skip_spaces(const char*& in);
// get file content into std::string
std::string readFileToString(const char* path, bool &success);

// skip spaces for tokens
template <typename Iterator, typename Tokens>
size_t skip_spaces(Iterator& pos) {
    auto prev = pos;
    while (pos->name() == Tokens::__WHITESPACE)
        ++pos;
    
    return std::distance(prev, pos);  // Works for any iterator
}

template<class TOKEN_T>
class Tokenizator_base {
protected:
    const char* _in = nullptr;
    TokenFlow<TOKEN_T> tokens;
/* internal integration functionality */
    /**
     * @brief Get the current position in the text (compares first input point with the current)
     * 
     * @param txt 
     * @return std::size_t 
     */
    std::size_t getCurrentPos(const char*const& txt) {
        return _in - txt;
    }
public:
    /**
     * Get one token
     */
    virtual node<TOKEN_T> makeToken() = 0;
    // constructors

    explicit Tokenizator_base(const std::string& in) : _in(const_cast<char*>(in.c_str())) {}
    explicit Tokenizator_base(char*& in) : _in(in) {}
    explicit Tokenizator_base(const char*& in) : _in(const_cast<char*>(in)) {}
    explicit Tokenizator_base() {}

    bool hasInput() {
        return _in != nullptr;
    }
    Tokenizator_base& setinput(const std::string& in) {
        _in = in.c_str();
        return *this;
    }
    Tokenizator_base& setinput(char*& in) {
        _in = in;
        return *this;
    }
    Tokenizator_base& setinput(const char*& in) {
        _in = in;
        return *this;
    }
    bool hasTokens() {
        return tokens.size() > 0;
    }
    /**
     * Get tokens as copy
     */
    TokenFlow<TOKEN_T> getTokens() {
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
    void clearTokens() {
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
            throw Tokenizator_No_Input_exception();
        node<TOKEN_T> result;
        while (*_in != '\0') {
            result = makeToken();
            if (result.empty())
                break;
            push(result);
        }
        return tokens;
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
     * Push another tokenizator tokens to current token flow. Note that if tokenizator has no token an Tokenizator_No_Tokens_exception is raised 
     */
    void push(const Tokenizator_base& tokenizator) {
        if (tokenizator.hasTokenFlow())
            tokens.push_back(tokenizator.tokens);
        else
            throw Tokenizator_No_Tokens_exception();
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

    Tokenizator_base& operator=(const Tokenizator_base& tokenizator) {
        tokens = tokenizator.tokens;
        _in = tokenizator._in;
        return *this;
    }
    bool operator==(const Tokenizator_base& tokenizator) {
        return tokens == tokenizator.tokens;
    }
    bool operator!=(const Tokenizator_base& tokenizator) {
        return tokens != tokenizator.tokens;
    }
};

/* PARSER */
template<class TOKEN_T, class RULE_T>
class Parser_base {
private:
    TokenFlow<TOKEN_T> tokens;
    Tree<RULE_T> tree;
public:
    /**
     * @brief Your parsed Tree. The Tree is std::vector. 
     * 
     */
    virtual node<RULE_T> getRule(size_t &tokensConsumed) = 0;
    // Constructors
    Parser_base() {}
    Parser_base(const Tokenizator_base<TOKEN_T>& tokenizator) {
        if (tokenizator.hasTokenFlow()) {
            tokens = tokenizator.tokens;
        } else if (tokenizator.hasInput()) {
            tokens = tokenizator.makeTokens();
        } else {
            throw Tokenizator_No_Tokens_exception();
        }
    }
    Parser_base(const std::string& in) {
        auto r = Tokenizator_base<TOKEN_T>().makeTokens(in);
        tokens = r;
    }
    Parser_base(const char* const in) {
        auto r = Tokenizator_base<TOKEN_T>().makeTokens(in);
        tokens = r;
    }

    // Parsing methods
    Tree<RULE_T> parse(const Tokenizator_base<TOKEN_T>& tokenizator) {
        if (tokenizator.hasTokenFlow()) {
            tokens = tokenizator.tokens;
        } else if (tokenizator.hasInput()) {
            tokens = tokenizator.makeTokens();
        } else {
            throw Tokenizator_No_Tokens_exception();
        }
        return parse();
    }
    Tree<RULE_T> parse(const std::string& in) {
        tokens = Tokenizator_base<TOKEN_T>().makeToken(in);
        return parse();
    }
    Tree<RULE_T> parse(const char* const in) {
        tokens = Tokenizator_base<TOKEN_T>().makeToken(in);
        return parse();
    }
    void clearInput() {
        tokens.clear();
    }
    /**
     * @brief Parser the tokens and get the tree
     * 
     * @return Tree<RULE_T> 
     */
    Tree<RULE_T> parse() {
        while(!tokens.empty()) {
            tree.push_back(getRule());
        }
    }
};


} // namespace __ISC_STD

#undef _ISC_GITHUB
#undef _ISC_INTERNAL_ERROR_MARK
#endif // ISC_STD_LIB_CPP