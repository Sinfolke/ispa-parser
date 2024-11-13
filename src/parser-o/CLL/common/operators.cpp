#include <parser.h>
#include <parser_defs.h>

Rule(op) {
    if (
        *in == '+' || *in == '-' || *in == '*' || *in == '/' || 
        *in == '%' || *in == '&' || *in == '|' || *in == '^' || 
        *in == '<<' || *in == '>>' || *in == '|' | *in == '&' || *in == '^' || 
        *in == '<<' || *in == '>>'
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
    } else if (( *in == 'n' && *(in + 1) == 'o' && *(in + 2) == 't' )) {
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
        *in == '|' && *(in + 1) == "&"
    ) {
        RULE_SUCCESS(in, in + 2, compare_op);
    } else if () {
        if ( !( *in == 'a' && *(in + 1) == 'n' && *(in + 2) == 'd' ) )
            return {};
        // TODO: skip spaces
        if ( !( *in == 'o' && *(in + 1) == 'r' ) )
            return {};
        RULE_SUCCESS(in, in + 3, compare_op);
    } else return {};
}