#include <parser.h>
#include <parser_defs.h>
//#hex
Rule(Rule_hex) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (strncmp(pos, "0x", 2)) {
        return {};
    }
    ISC_STD::skip_spaces(pos);
    pos += 2;
    auto begin = pos;
    while (isdigit(*pos) || *pos >= 'A' && *pos <= 'F' || *pos >= 'a' && *pos <= 'f') {
        ++pos;
    }
    if (begin == pos) 
        return {};
    
    RULE_SUCCESSD(in, pos, Rule_hex, std::string_view(begin, pos - begin));
    return {};

}