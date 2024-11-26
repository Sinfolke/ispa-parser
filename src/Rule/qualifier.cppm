export module Parser.Rule.qualifier;
#include <parser_defs.h>

Rule(Rule_qualifier) {
    auto pos = in;
    if (*pos != '?' && *pos != '+' && *pos != '*')
        return {};
    RULE_SUCCESSD(in, pos, Rule_qualifier, *pos);
}