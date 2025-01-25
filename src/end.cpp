#include <parser.h>
#include <parser_defs.h>

Rule(end) {
    if (*in == ';' || *in == '\n')
        RULE_SUCCESS(in, in + 1, end);
    return {};
}
Rule(strict_end) {
    if (*in == ';')
        RULE_SUCCESS(in, in + 1, strict_end);
    return {};
}
Rule(newline) {
    if (*in == '\n')
        RULE_SUCCESS(in, in + 1, newline);
    return {};
}