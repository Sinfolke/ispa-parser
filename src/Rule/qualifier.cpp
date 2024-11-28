#include <parser.h>
#include <parser_defs.h>

Rule(Rule_qualifier) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    if (*pos != '?' && *pos != '+' && *pos != '*')
        return {};
    RULE_SUCCESSD(in, pos, Rule_qualifier, *pos);
}