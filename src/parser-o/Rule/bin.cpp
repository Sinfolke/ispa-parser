#include <parser.h>
#include <parser_defs.h>
//#bin
Rule(Rule_bin) {
    if (!(*in == '0' && *(in+1) == 'b')) {
        return {};
    }
    auto begin = in + 2;
    auto pos = begin;
    while (*pos == '0' || *pos == '1') {
        ++pos;
    }
    if (begin == pos) 
        return {};
    
    RULE_SUCCESSDD(in, pos, Rule_hex, std::string_view(begin, pos - begin));
    return {};

}