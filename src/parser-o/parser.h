/*
    The ISC generated parser 
    name: Parser
    This generated parser links with iscstdlibc++ with the version >=1.0

*/

#pragma once

#ifndef ISC_OUT_PARSER
#define ISC_OUT_PARSER
#include <iscstdlibc++.h>
#include <unordered_map>
#include <cctype>
// here it checks according to the backward version
#if _ISC_STD_LIB_VER < 0 // skip subver check
#error  "Your library version is too old. Please, update your library."
#elif (_ISC_STD_LIB_VER > 1 || _ISC_STD_LIB_SUBVER > 0) && (_ISC_STD_LIB_BACKDOWN > 1 || _ISC_STD_LIB_BACKDOWN_SUBVER > 0)
#error  "This parser is generated for the version 1.0 but your newer library is not compatible with it. Generally you would regenerate the parser for the newer library. However if not possible you should backward your library version"
#endif

namespace Parser { // according to name

    /* LIST OF ALL Token and Rule names */

    /**
     * @brief List of all token names including auto generated names
     * 
     */
    enum class Tokens {
        END, ID, Priv_Import_path
    };
    /**
     * @brief List of all Rule names including auto generated names
     */
    enum class Rules {
        _0,
    };

    /* TYPE DECLARATIONS FOR THIS PARSER  */
    //?? whether to add using Member = ISC_STD::Member<Tokens, Rules, 1>;

    using string_part =  ISC_STD::string_part;
    using Token = ISC_STD::_return<Tokens>;
    using Rule = ISC_STD::_return<Rules>;
    using Groups = ISC_STD::Groups<Tokens, Rules>;
    using TokenFlow = ISC_STD::TokenFlow<Tokens>;
    using Tree = ISC_STD::TokenFlow<Rules>;
    using Token_result = ISC_STD::match_result<Tokens>;
    using Rule_result = ISC_STD::match_result<Rules>;
    // a sequence of elements

    template<int SIZE> using Group = ISC_STD::Group<Tokens, Rules, SIZE>;
    #define TOKEN(x) Token_result x (const char* in);
    #define Rule(x) Rule_result x (const char* in);
    /* Tokenizator FOR THIS PARSER */
    class Tokenisator : public ISC_STD::Tokenisator_base<Tokens> {
        public:
        TokenFlow makeTokenFlow();
        // Token methods
        TOKEN(END);
        TOKEN(STRICT_END);
        TOKEN(NEWLINE);
    };

    /* PARSER */
    class Parser : ISC_STD::Parser_base<Tokens, Rules> {
    private:
        Rule(Import_path);
    public:
        Tree parse();

        // Rule methods
        Rule(id);
    };
    #undef TOKEN
    #undef Rule

}

#endif // ISC_OUT_PARSER