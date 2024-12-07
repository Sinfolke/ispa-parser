#include <parser.h>
#include <parser_defs.h>
//#nested_rule
Rule(Rule_nested_rule) {
    auto pos = in;
    // ISC_STD::skip_spaces(pos);
    // auto begin = pos;
    // while(*pos == '\n' || *pos == '\r')
    //     pos ++;
    // if (begin == pos)
    //     return {};
    ISC_STD::skip_spaces(pos);
    if (*pos != '#')
        return {};
    pos++;

    // NO SPACE!!
#undef Rule
    auto Rule_res = Rule(pos);

    if (!Rule_res.result)
        return {};
    
    RULE_SUCCESSD(in, pos, Rule_nested_rule, Rule_res.token);
}