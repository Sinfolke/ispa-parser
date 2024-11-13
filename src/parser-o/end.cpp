#include <parser.h>
#include <parser_defs.h>

Rule(end) {
    if (*in == ';' or *in == '\n')
        RULE_SUCCESS(in, in + 1, end);
    return {};
}
Rule(strict_end) {
    if (*in == ';')
        RULE_SUCCESS(in, in + 1, strcit_end);
    return {};
}
Rule(newline) {
    if (*in == '\n')
        RULE_SUCCESS(in, in + 1, newline);
    return {};
}