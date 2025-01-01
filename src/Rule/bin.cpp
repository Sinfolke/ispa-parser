#include <parser.h>
#include <parser_defs.h>

//#bin
Rule(Rule_bin) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (strncmp(pos, "0b", 2)) {
        return {};
    }
    pos += 2;
    auto begin = pos;
    while (*pos == '0' || *pos == '1') {
        ++pos;
    }
    if (begin == pos) 
        return {};
    
    RULE_SUCCESSD(in, pos, Rule_hex, std::string_view(begin, pos - begin));
}