
/*
    The ISC generated parser 
    name: Parser
    This generated parser links with iscstdlibc++ with the version >=1.0

*/
/*
    The parser does rely onto iscstdlibc++, as it would avoid dublications,
    especially when a multiple ISC parsers are used onto same project.

    There are following goods in the separation:
        no dublication,
        easy change of library,
        break out onto partitions
    But you would need to add into include directory the library.

    The parser may be independent (e.g the library can be located on the current dir). 
    This is good when distributing as just "parser" to other users.
    A parser shouldn't generally by independent when it is a part of project and often better to add into include dir
*/
#pragma once

#ifndef ISC_OUT_PARSER
#define ISC_OUT_PARSER
#include <iscstdlibc++.h>
// here it checks according to the backward version
#if _ISC_STD_LIB_VER < 0 // skip subver check
#error  "Your library version is too old. Please, update your library."
#elif (_ISC_STD_LIB_VER > 1 || _ISC_STD_LIB_SUBVER > 0) && _(_ISC_STD_LIB_BACKDOWN > 1 || _ISC_STD_LIB_BACKDOWN_SUBVER > 0)
#error  "This parser is generated for the version 1.0 but your newer library is not compatible with it. Generally you would regenerate the parser for the newer library. However if not possible you should backward your library version"
#endif

namespace Parser { // according to name

    /* LIST OF ALL Token and Rule names */

    /**
     * @brief List of all token names including auto generated names
     * 
     */
    enum class Tokens {
        NUMBER, OP, COP, END, NONE,
    };
    /**
     * @brief List of all rule names including auto generated names
     */
    enum class Rules {
        expr,
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

    /* Tokenizator FOR THIS PARSER */
    class Tokenizator : public ISC_STD::Tokenizator_base<Tokens> {
        public:
        TokenFlow makeTokenFlow();
        // Token methods
        Token_result NUMBER(const char* in);
        Token_result OP(const char* in);
        Token_result COP(const char* in);
        Token_result END(const char* in);
    };

    /* PARSER */
    class Parser : ISC_STD::Parser_base<Tokens, Rules> {
    public:
        Tree parse();

        // Rule methods
        Rule_result expr(const Token* _in);
    };


}

#endif // ISC_OUT_PARSER