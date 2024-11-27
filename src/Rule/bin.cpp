#include <parser.h>
#include <parser_defs.h>

//#bin
Rule(Rule_bin) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    if (!(*pos == '0' && *(pos+1) == 'b')) {
        return {};
    }
    auto begin = in + 2;
    auto pos = begin;
    ISC_STD::skipup(pos, " ");
    while (*pos == '0' || *pos == '1') {
        ++pos;
    }
    if (begin == pos) 
        return {};
    
    RULE_SUCCESSDD(in, pos, Rule_hex, std::string_view(begin, pos - begin));
    return {};

}