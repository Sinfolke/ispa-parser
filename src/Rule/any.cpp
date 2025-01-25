#include <parser.h>
#include <parser_defs.h>

Rule(Rule_any) {
    auto pos = in;
    if (*pos != '.')
        return {};
    pos++;
    RULE_SUCCESS(in, pos, Rule_any);
}