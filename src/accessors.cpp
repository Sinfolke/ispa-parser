#include <parser.h>
#include <parser_defs.h>
Rule(accessors_group) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '$')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto number_res = number(pos);
    if (!number_res.result)
        return {};
    
    RULE_SUCCESSD(in, pos, accessors_group, number_res.token);
}
Rule(accessors_element) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '%')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto number_res = number(pos);
    if (!number_res.result)
        return {};
    
    RULE_SUCCESSD(in, pos, accessors_element, number_res.token);
}
Rule(accessors_char) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '^')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto number_res = number(pos);
    if (!number_res.result)
        return {};
    
    RULE_SUCCESSD(in, pos, accessors_char, number_res.token);
}