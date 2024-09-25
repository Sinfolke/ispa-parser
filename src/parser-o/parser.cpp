#include "parser.h"

/*
    ###########################
            END RULES
    ###########################
*/
#define TOKEN(x) Parser::Token_result Parser::Tokenisator::x (const char* in)
#define Rule(x) Parser::Rule_result Parser::Parser::x (const char* in)
#define TO(t, x) std::any_cast<x>()
#define TOKEN_SUCCESS(in, pos, name) return { \
    true, { \
        getCurrentPos(in), in, pos, Parser::Tokens::name \
    } \
};
#define TOKEN_SUCCESSD(in, pos, name, data) return { \
    true, { \
        getCurrentPos(in), in, pos, Parser::Tokens::name, data \
    } \
};
#define RULE_SUCCESS(in, pos, name) return { \
    true, { \
        getCurrentPos(in), in, pos, Parser::Parser::name \
    } \
};
#define RULE_SUCCESSD(in, pos, name, data) return { \
    true, { \
        getCurrentPos(in), in, pos, Parser::Parser::name, data \
    } \
};
TOKEN(END) {
    if (*in == ';' or *in == '\n')
        TOKEN_SUCCESS(in, in + 1, END);
    return {};
}
TOKEN(STRICT_END) {
    if (*in == ';')
        TOKEN_SUCCESS(in, in + 1, STRICT_END);
    return {};
}
TOKEN(NEWLINE) {
    if (*in == '\n')
        TOKEN_SUCCESS(in, in + 1, NEWLINE);
    return {};
}
// <not implemented> use parralel_parsing;
// spacemode mixed;
/*
    ###########################
            FILE RULES
    ###########################
*/
Rule(id) {
    int c = 0;
    const char* pos = in;
    Token_result result;
    Group<3> current;
    auto _local_start = pos;
    while (*pos >= '0' and *pos <= '9') {
        ++pos;
    }
    current.push(_local_start, pos);
    skipSpaces(pos);
    if (
        not 
        (
        *pos >= 'a' and *pos <= 'f' || 
        *pos >= 'A' and *pos <= 'F' || 
        *pos == '_'
        )
    ) {
        return {};
    }
    current.push(pos++, 1);
    _local_start = pos;
    skipSpaces(pos);
    while (
        *pos >= 'a' and *pos <= 'f' || 
        *pos >= 'A' and *pos <= 'F' || 
        *pos >= '0' and *pos <= '9' || 
        *pos == '_'
    ) {
        ++pos;
    }
    current.push(_local_start, pos);
    // construct result as valid
    // extract full string from the first group
    RULE_SUCCESSD(in, pos, id, current.fill());
}
Rule(Import_path) {    
    auto pos = in;
    //! <pattern> csequence
    while (
        not 
        (
            *pos == '"' ||
            *pos == '<' ||
            *pos == '>' ||
            *pos == '|' ||
            *pos == ':' ||
            *pos == '?' ||
            *pos == '.' ||
        )
    ) ++pos;
    if (pos == in) return {}; // zero match
    RULE_SUCCESSD(in, pos, Priv_Import_path, string_part(in, pos));
};
Rule(Import_ext) {    
    auto pos = in;
    std::vector<Rule_result> data;
    while(true) {
        if (*pos == '.') {
            ++pos;
            auto match_res = id(pos);
            if (match_res.result) {
                data.push_back(match_res);
                pos += match_res.token.length();
                continue;
            }
        }
        break;
    }
    if (pos == in) return {}; // zero match
    RULE_SUCCESSD(in, pos, Priv_Import_ext, data);
};
Rule(Import_file) {
    auto path_res = Import_path(in);
    if (!path_res.result) return {};
    auto pos = in + path_res.token.length();
    auto ext_res = Import_ext(pos);
    if (!ext_res.result) return {};
    pos += ext_res.token.length();
    // is is just a pain
    std::unordered_map<const char*, std::any> data = {
        { "path", path_res },
        { "ext", TO(std::vector<Rule_result>, ext_res.token.data).back() },
        { "fullext", ext_res },
        { "fullpath", std::string( TO(std::string_part, path_res.token.data )) + std::string(ISC_STD::join( TO(std::string_part, ext_res.token.data ) )) }
    };
    RULE_SUCCESSD(in, pos, Priv_Import_file, data);
}
import: 
    // import core/core.isc // single file import with exact extension
    // import core/core     // single file import without extension (first tryes to find the file with no extension, then with .isc extenison)
    // import [language/cpp] expr ID template preprocessor/directive/define // import from folder several files same time
    //      [another syntax of same action] import language/cpp [expr, ID, template, preprocessor/directive/define]
    // import language/cpp/data { INTLIT, BOOLLIT, STRLIT} // import some certain rules from the file
    // import language/cpp/data { INTLIT = INT, BOOLLIT = BOOL, STRLIT } // import certain rules from the file changing their incoming name in the current project
    // import [language/cpp] expr ID data { INTLIT = INT, BOOLIT = BOOL, STRLIT }, core/core.isc;


    'import' #file | #general_dir | #rulespecific (',' #file | #general_dir | #rulespecific)*
    data: %2 + matched(%3) ? %3.join() : "";

    #path:
        [^*"<>|:?\.]+
        data: %1;
    ;
    #ext:
        ('.' ID)*
        data: %2;
    ;
    #file:
        path ext*
        data:
            path: %1
            ext: %2[%2.size()]
            fullext: %2
            fullpath: %1 + %2.join()
        ;
    ;
    #general_dir:
        '[' path ']' file+
        data:
            path: %1,
            files: %2
        ;
    ;
    #rulespecific:
        file '{' (ID ('=' ID)? )+  '}'
        data:
            path: %1
            tokens: $1>%1
            tokens_current_name: $2>%2
        ;
    ;
;
use: 
    $object<string> data = {  %2.name: %2.value };
    for (int i = 0; i < $1>%2.size(); i++):
        data[$1>%2[i].name] = $1>%2[i].value;


    'use' #USE (',' #USE)*

    #USE:
        ID (':' [^,]+ | STRING)?

        data:
            name: %1,
            value: %2,
;

#undef TOKEN
#undef RULE


