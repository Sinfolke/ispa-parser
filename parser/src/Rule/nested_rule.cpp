#include <parser.h>
#include <parser_defs.h>
//#nested_rule
Rule(Rule_nested_rule) {
#undef Rule
    auto pos = in;
    // ISC_STD::skip_spaces(pos);
    // auto begin = pos;
    // while(*pos == '\n' || *pos == '\r')
    //     pos ++;
    // if (begin == pos)
    //     return {};
    ISPA_STD::skip_spaces(pos);
    if (*pos != '#') {
        return {};
    }
    pos++;
    auto Rule_res = Rule(pos);

    if (!Rule_res.result)
        return {};
    pos += Rule_res.token.length();
    // auto strict_end_res = strict_end(pos);
    // if (!strict_end_res.result)
    //     return {};
    // pos += Rule_res.token.length();
    RULE_SUCCESSD(in, pos, Rule_nested_rule, Rule_res.token);
}