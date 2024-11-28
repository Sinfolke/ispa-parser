#include <parser.h>
#include <parser_defs.h>

Rule(op) {
    if (
        *in == '+' || *in == '-' || *in == '*' || *in == '/' || 
        *in == '%' || *in == '&' || *in == '|' || *in == '^' || 
        !strncmp(in, "<<", 2) || !strncmp(in, ">>", 2) || *in == '|' | *in == '&' || *in == '^'
    ) {
        return RULE_SUCCESSD(in, in + 1, op, *in);
    }
    return {};
}
Rule(assignment_op) {
    auto op_res = op(in);
    if (!op.result)
        return {};
    auto pos = in + op.token.length();
    if (*pos!= '=')
    return {};
    return RULE_SUCCESSD(in, pos, assignment_op, op.token);
}
Rule(logical_not) {
    if ( 
        *in == '!'
    ) {
        RULE_SUCCESS(in, in + 1, compare_op);
    } else if ( !strncmp(in, "not", 3)) {
        RULE_SUCCESS(in, in + 3, compare_op);
    } else return {};
}
Rule(logical_and) {
    if ( 
        *in == '&' && *(in + 1) == "&"
    ) {
        RULE_SUCCESS(in, in + 2, compare_op);
    } else if (( *in == 'a' && *(in + 1) == 'n' && *(in + 2) == 'd' )) {
        RULE_SUCCESS(in, in + 3, compare_op);
    } else return {};
}
Rule(logical_or) {
    if ( 
        (*in == '|' && *(in + 1) == "|") ||
        (*in == 'o' && *(in + 1) == "r")
    ) {
        RULE_SUCCESS(in, in + 2, compare_op);
    } else return {};
}
Rule(logical_andr) {
    if ( 
        strncmp(in, "|&", 2)
    ) {
        RULE_SUCCESS(in, in + 2, compare_op);
    } else if () {
        if (!strncmp(in, "and", 3))
            return {};
        ISC_STD::skipup(pos, " ");
        if (strncmp(in, "or", 3))
            return {};
        RULE_SUCCESS(in, in + 3, compare_op);
    } else return {};
}