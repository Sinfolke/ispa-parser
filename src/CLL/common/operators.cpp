#include <parser.h>
#include <parser_defs.h>

Rule(op) {
    if (
        *in == '+' || *in == '-' || *in == '*' || *in == '/' || 
        *in == '%' || *in == '&' || *in == '|' || *in == '^' || 
         *in == '|' | *in == '&' || *in == '^'
    ) {
        RULE_SUCCESSD(in, in + 1, op, *in);
    } else if (!strncmp(in, "<<", 2) || !strncmp(in, ">>", 2)) {
        RULE_SUCCESSD(in, in + 2, op, *in);
    }
    return {};
}
Rule(assignment_op) {
    auto op_res = op(in);
    if (!op_res.result)
        return {};
    auto pos = in + op_res.token.length();
    if (*pos!= '=')
        return {};
    RULE_SUCCESSD(in, pos, assignment_op, op_res.token);
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
        !strncmp(in, "&&", 2)
    ) {
        RULE_SUCCESS(in, in + 2, compare_op);
    } else if (( *in == 'a' && *(in + 1) == 'n' && *(in + 2) == 'd' )) {
        RULE_SUCCESS(in, in + 3, compare_op);
    } else return {};
}
Rule(logical_or) {
    if ( 
        !strncmp(in, "||", 2) || !strncmp(in, "or", 2)
    ) {
        RULE_SUCCESS(in, in + 2, compare_op);
    } else return {};
}
Rule(logical_andr) {
    if ( 
        strncmp(in, "|&", 2)
    ) {
        RULE_SUCCESS(in, in + 2, compare_op);
    } else {
        auto pos = in;
        if (!strncmp(pos, "and", 3))
            return {};
        pos += 3;
        ISC_STD::skipup(pos, " ");
        if (strncmp(in, "or", 2))
            return {};
        pos += 2;
        RULE_SUCCESS(in, pos, compare_op);
    }
}