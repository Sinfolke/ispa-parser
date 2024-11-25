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
#include <vector>
#include <cstring>
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

    using Token = ISC_STD::_return<Tokens>;
    using Rule = ISC_STD::_return<Rules>;
    using TokenFlow = ISC_STD::TokenFlow<Tokens>;
    using Tree = ISC_STD::TokenFlow<Rules>;
    using Token_result = ISC_STD::match_result<Tokens>;
    using Rule_result = ISC_STD::match_result<Rules>;
    // a sequence of elements

    template<int SIZE> using Group = ISC_STD::Group<Tokens, Rules, SIZE>;
    #define TOKEN(x) Token_result x (const char* in);
    #define Rule(x, ...) Rule_result x (const char* in, ##__VA_ARGS__);
    /* Tokenizator FOR THIS PARSER */
    class Tokenisator : public ISC_STD::Tokenizator_base<Tokens> {
        public:
        TokenFlow makeTokenFlow();
        // Token methods
        TOKEN(END);
        TOKEN(STRICT_END);
        TOKEN(NEWLINE);
    };
    using cll_template_content_param1_t = Rule_result (Parser::*)(const char*);

    /* PARSER */
    class Parser /*: ISC_STD::Parser_base<Tokens, Rules>*/ {
    private:
        Rule(Import_path);
        Rule(Import_ext);
        Rule(Import_file);
        Rule(Import_general_dir);
        Rule(Import_rulespecific); 

        Rule(use_unit);

        Rule(Rule_rule);
        Rule(Rule_op);
        Rule(Rule_qualifier);
        Rule(Rule_group);
        Rule(Rule_csequence);
        Rule(Rule_csequence_symbol);
        Rule(Rule_csequence_escape);
        Rule(Rule_csequence_diapason);
        Rule(Rule_data_block);
        Rule(Rule_data_block_key);
        Rule(Rule_nested_rule);
        Rule(Rule_hex);
        Rule(Rule_bin);

        Rule(cll_type_abstract)

        Rule(expr_variable_value);
        Rule(expr_compare);
        Rule(expr_compare_side);
        Rule(expr_logical);
        Rule(expr_parenthesed);
        Rule(expr_parenthesed_variable_assignment)
        Rule(expr_not);

        size_t getCurrentPos(const char* pos);
        const char* text;
    public:
        Tree parse();

        // Rule methods
        Rule(end);
        Rule(strict_end);
        Rule(newline);
        Rule(id);
        Rule(Import);
        Rule(use);
        Rule(Rule)

        
        Rule(string);
        Rule(number);
        Rule(boolean);
        Rule(array);
        Rule(object);
        Rule(any_data);

        Rule(cll_block);
        Rule(cll_spaced_block);
        Rule(op);
        Rule(assignment_op);
        Rule(compare_op);
        Rule(logical_op);
        Rule(logical_and);
        Rule(logical_or);
        Rule(logical_andr);

        Rule(cll_template_typename);
        Rule(cll_template_int);
        Rule(cll_template_bool);
        Rule(cll_template_str);
        Rule(cll_template_arr);
        Rule(cll_template_obj);
        Rule(cll_template_any_data);
        Rule(cll_template_all)
        Rule(cll_template, cll_template_content_param1_t);

        Rule(cll_csupport_types);
        Rule(cll_type);

        Rule(cll_if);

        Rule(cll_ternary);

        Rule(expr);

        Rule(function_body_call);
        Rule(function_body_decl);
        Rule(function_arguments);
        Rule(function_parameters);
        Rule(cll_function_call);
        Rule(function_decl);

        Rule(method_call);
        Rule(copiable_method_call);

        Rule(cll_var);
        
        Rule(cll);
    };
    #undef TOKEN
    #undef Rule

}

#endif // ISC_OUT_PARSER