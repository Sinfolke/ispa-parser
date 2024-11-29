#include <parser.h>
#include <parser_defs.h>
Rule(expr_not) {
    auto pos = in;
    if (*pos == '!' || !strncmp(in, "not", 3))
        RULE_SUCCESS(in, pos, expr_not);
    else
        return {};
}