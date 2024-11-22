#include <parser/parser.h>
#include <parser/parser_defs.h>
//#hex
Rule(Rule_hex) {
    if (!(*in == '0' && *(in+1) == 'x')) {
        return {};
    }
    auto begin = in + 2;
    auto pos = begin;
    while (isdigit(*pos) || isupper(*pos) || islower(*pos)) {
        ++pos;
    }
    if (begin == pos) 
        return {};
    
    RULE_SUCCESSDD(in, pos, Rule_hex, std::string_view(begin, pos - begin));
    return {};

}