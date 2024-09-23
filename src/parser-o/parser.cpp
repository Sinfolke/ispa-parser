#include "parser.h"

/*
    ###########################
            END RULES
    ###########################
*/

Tokenisator::Token_result END(const char* in) {
    if (*in == ';' or *in == '\n')
        return { true, 
                 in + 1, 
            { 
                getCurrentPos(in - 1), in, 1, Tokens::END
            }  
        };
    return {};
}
Tokenisator::Token_result STRICT_END(const char* in) {
    if (*in == ';')
        return { true, 
                 in + 1, 
            { 
                getCurrentPos(in - 1), in, 1, Tokens::END
            }  
        };
    return {};
}
Tokenisator::Token_result NEWLINE(const char* in) {
    if (*in == '\n')
        return { true, 
                 in + 1, 
            { 
                getCurrentPos(in - 1), in, 1, Tokens::END
            }  
        };
    return {};
}
// <not implemented> use parralel_parsing;
// spacemode mixed;
/*
    ###########################
            FILE RULES
    ###########################
*/
Tokenisator::Token_result ID(const char* in) {
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
    result.result = true;
    result.newpos = pos;
    result.token = Token(getCurrentPos(in), in, pos, Tokens::ID, current.full());
    return result;
}
static Import_path (const char* in) {    
    auto pos = in;
    while (
        not 
        (
            *pos == '^' ||
            *pos == '"' ||
            *pos == '<' ||
            *pos == '>' ||
            *pos == '|' ||
            *pos == ':' ||
            *pos == '?' ||
            *pos == '.' ||
        )
    ) ++pos;
    if (pos == in) return {};
    return { getCurrentPos(in), in, pos, Tokens::Priv_Import_path, string_part(in, pos) };
};
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




