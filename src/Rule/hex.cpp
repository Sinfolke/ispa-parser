#include <parser.h>
#include <parser_defs.h>
//#hex
Rule(Rule_hex) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    if (strncmp(pos, "0x", 2)) {
        return {};
    }
    ISC_STD::skipup(pos, " ");
    pos += 2;
    auto begin = pos;
    while (isdigit(*pos) || isupper(*pos) || islower(*pos)) {
        ++pos;
    }
    if (begin == pos) 
        return {};
    
    RULE_SUCCESSDD(in, pos, Rule_hex, std::string_view(begin, pos - begin));
    return {};

}