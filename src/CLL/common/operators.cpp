#include <parser.h>
#include <parser_defs.h>
Rule(op) {
    std::string val;
    auto pos = in;
    if (
        *in == '+' || *in == '-' || *in == '*' || *in == '/' || 
        *in == '%' || *in == '&' || *in == '|' || *in == '^'
    ) {
        val = *pos;
        pos++;
    } else if (!strncmp(in, "<<", 2) || !strncmp(in, ">>", 2)) {
        val = *pos;
        pos++;
        val += *pos;
        pos++;
    } else {
        return {};
    }
    RULE_SUCCESSD(in, pos, op, val);
    return {};
}
Rule(compare_op) {
    auto pos = in;
    std::string val;
    if (!strncmp(pos, "==", 2) || !strncmp(pos, "!=", 2) || !strncmp(pos, ">=", 2) || !strncmp(pos, "<=", 2)) {
        val.assign(pos, 2);
        pos += 2;
    } else if (*pos == '<' || *pos == '>') {
        val.assign(pos, 1);
        pos++;
    } else {
        return {};
    }
    RULE_SUCCESSD(in, pos, compare_op, val);
}
Rule(assignment_op) {
    auto pos = in;
    auto op_res = op(in);
    if (op_res.result)
        pos += op_res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != '=')
        return {};
    pos++;
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
    } else if (!strncmp(in, "and", 3)) {
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
        ISC_STD::skip_spaces(pos);
        if (strncmp(in, "or", 2))
            return {};
        pos += 2;
        RULE_SUCCESS(in, pos, compare_op);
    }
}
Rule(logical_op) {
    auto pos = in;
    auto res = logical_not(pos);
    if (!res.result) {
        res = logical_and(pos);
        if (!res.result) {
            res = logical_or(pos);
            if (!res.result) {
                res = logical_andr(pos);
                if (!res.result)
                    return {};
            }
        }
    }
    RULE_SUCCESSD(in, pos, logical_op, res.token);
}