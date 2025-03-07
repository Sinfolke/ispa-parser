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
    std::string str = "";
    while (*pos == '0' || *pos == '1') {
        str += *pos;
        pos++;
    }
    if (begin == pos) 
        return {};
    
    RULE_SUCCESSD(in, pos, Rule_bin, str);
}