#include <parser.h>
#include <parser_defs.h>
Rule(expr_not) {
    auto pos = in;
    if (*pos == '!' || !strncmp(in, "not", sizeof("not") - 1))
        RULE_SUCCESS(in, pos, expr_not);
    else
        return {};
}