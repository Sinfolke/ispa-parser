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
        "NOTE: this exception is likely an internal error of the ISC compiler and is not on the user side.\n" \
        "Please, show up the developer this issue (" _ISC_GITHUB ")\n" \
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
namespace ISC_STD {
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
            mes += "etc. require those properties."
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
struct _return_base {
public:
    std::size_t startpos;
    std::string_view str; // char* start, long long len

    _return_base(const std::size_t& startpos, const char* start, const std::size_t& len) : str(start, len), startpos(startpos) {}
    _return_base(const std::size_t& startpos, const char* start, const char* end) : str(start, end - start), startpos(startpos) {}
    _return_base() {
        startpos = std::string::npos;
    }

    /**
     * @brief Returns the number of line of the current token or rule
     * 
     * @return std::size_t 
     */
    std::size_t line() const {
        if (startpos == std::string::npos)
            throw return_base_exception("line");
        std::size_t count = 0;
        std::size_t escaptions = 0;
        for (std::size_t i = startpos; i >= 0; --i) {
            if (*(str.data() - i) == '\n') count++;
        }
        return count;
    }
    /**
     * @brief Get the end position based on startpos and length
     * 
     * @return long long 
     */
    std::size_t endpos() const {
        if (startpos == std::string::npos)
            throw return_base_exception("endpos");
        return startpos + str.length();
    }
    std::size_t length() const {
        if (startpos == std::string::npos)
            throw return_base_exception("length");
        return str.length();
    }
    bool empty() const noexcept {
        return startpos == std::string::npos || str.empty();
    }
    _return_base operator=(const _return_base& other) {
        startpos = other.startpos;
        str = other.str;
        return *this;
    }
};
template<class RETURN_T>
struct _return : public _return_base {
    using _return_base::_return_base;
    _return(const std::size_t& startpos, const char* start, const std::size_t& len) : _return_base(startpos, start, len) {}
    _return(const std::size_t& startpos, const char* start, const std::size_t& len, const RETURN_T& name) : _return_base(startpos, start, len), name(name) {}
    _return(const std::size_t& startpos, const char* start, const std::size_t& len, const RETURN_T& name, std::any& data) : _return_base(startpos, start, len), name(name), data(data) {}
    _return(const std::size_t& startpos, const char* start, const char* end) : _return_base(startpos, start, end) {}
    _return(const std::size_t& startpos, const char* start, const char* end, const RETURN_T name) : _return_base(startpos, start, end), name(name) {}
    _return(const std::size_t& startpos, const char* start, const char* end, const RETURN_T name, std::any data) : _return_base(startpos, start, end), name(name), data(data) {}
    _return(const RETURN_T& name) : _return_base(), name(name) {}
    _return(const RETURN_T& name, std::any data) : _return_base(), name(name), data(data) {}
    const RETURN_T name = RETURN_T::NONE;
    std::any data;
    _return<RETURN_T> operator=(_return<RETURN_T> const& other) {
        startpos = other.startpos;
        return *this;
    }
};


template<class RESULT_T>
struct match_result {
    bool result = false;
    _return<RESULT_T> token;
};

template<class TOKEN_T>
using TokenFlow = std::vector<_return<TOKEN_T>>;
template<class RULE_T>
using Tree = std::vector<_return<RULE_T>>;

template<class TOKEN_T>
class Tokenizator_base {
private:
    const char* _in = nullptr;
protected:
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
    void skipSpaces(const char* in) {
        while(std::isspace(*in)) ++in;
    }
    const char* skipSpacesForCopy(const char* const in) {
        auto _in = in;
        return skipSpaces(_in);
    }
public:
    TokenFlow<TOKEN_T> tokens;
    // Constructors
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

    bool hasTokenFlow() {
        return tokens.size() > 0;
    }
    Tokenizator_base& clearTokenFlow() {
        tokens.clear();
    }
    // Tokenization methods
    TokenFlow<TOKEN_T> makeTokenFlow(const std::string& in) {
        _in = in.c_str();
        makeTokenFlow();
    }
    TokenFlow<TOKEN_T> makeTokenFlow(const char*& in) {
        _in = in;
        makeTokenFlow();
    }
    // for now must be implemented by the instance
    // TokenFlow<TOKEN_T> makeTokenFlow() {
    //     return {};
    // }

    
    Tokenizator_base& push(const TokenFlow<TOKEN_T>& input_tokens) {
        tokens.append_range(input_tokens);
        return *this;
    }
    Tokenizator_base& push(const _return<TOKEN_T>& input_token) {
        tokens.push_back(input_token);
        return *this;
    }
    Tokenizator_base& push(const Tokenizator_base& tokenizator) {
        if (tokenizator.hasTokenFlow())
            tokens.push_back(tokenizator.tokens);
        else {
            throw Tokenizator_No_Tokens_exception();
        }
        return *this;
    }
    Tokenizator_base& pop() {
        tokens.pop_back();
        return *this;
    }
    Tokenizator_base& pop(const std::size_t& n) {
        if (n > tokens.size()) {
            //throw std::length_error("(ISC-parser) pop(): the number of elements to pop is higher actual size");
            tokens.clear();
        } else {
            tokens.erase(tokens.end() - n, tokens.end());
        }
        return *this;
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
public:
    /**
     * @brief Your parsed Tree. The Tree is std::vector. 
     * 
     */
    Tree<RULE_T> tree;

    // Constructors
    Parser_base() {}
    Parser_base(const Tokenizator_base<TOKEN_T>& tokenizator) {
        if (tokenizator.hasTokenFlow()) {
            tokens = tokenizator.tokens;
        } else if (tokenizator.hasInput()) {
            tokens = tokenizator.makeTokenFlow();
        } else {
            throw Tokenizator_No_Tokens_exception();
        }
    }
    Parser_base(const std::string& in) {
        auto r = Tokenizator_base<TOKEN_T>().makeTokenFlow(in);
        tokens = r;
    }
    Parser_base(const char* const in) {
        auto r = Tokenizator_base<TOKEN_T>().makeTokenFlow(in);
        tokens = r;
    }

    // Parsing methods
    Tree<RULE_T> parse(const Tokenizator_base<TOKEN_T>& tokenizator) {
        if (tokenizator.hasTokenFlow()) {
            tokens = tokenizator.tokens;
        } else if (tokenizator.hasInput()) {
            tokens = tokenizator.makeTokenFlow();
        } else {
            throw Tokenizator_No_Tokens_exception();
        }
        return parse();
    }
    Tree<RULE_T> parse(const std::string& in) {
        tokens = Tokenizator_base<TOKEN_T>().makeTokenFlow(in);
        return parse();
    }
    Tree<RULE_T> parse(const char* const in) {
        tokens = Tokenizator_base<TOKEN_T>().makeTokenFlow(in);
        return parse();
    }
    /**
     * @brief Parser the tokens and get the tree
     * 
     * @return Tree<RULE_T> 
     */
    Tree<RULE_T> parse();
};


} // namespace __ISC_STD

#undef _ISC_GITHUB
#undef _ISC_INTERNAL_ERROR_MARK
#endif // ISC_STD_LIB_CPP