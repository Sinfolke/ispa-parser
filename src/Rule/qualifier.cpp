#include <parser.h>
#include <parser_defs.h>

Rule(Rule_qualifier) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '?' && *pos != '+' && *pos != '*')
        return {};
    pos++;
    RULE_SUCCESSD(in, pos, Rule_qualifier, *pos);
}