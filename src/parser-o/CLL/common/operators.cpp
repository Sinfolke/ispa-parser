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
Rule(compare_op) {
    if ( 
        ( *in == '=' and *(in + 1) == '=' ) ||
        ( *in == '!' and *(in + 1) == '=') ||
        ( *in == '<' and *(in + 1) == '=') ||
        ( *in == '>' and *(in + 1) == '=')
    ) {
        RULE_SUCCESSD(in, in + 2, compare_op, std::string_view(in, 2));
    } else if (*in == '<' || *in == '>') {
        RULE_SUCCESSD(in, in + 1, compare_op, std::string_view(in, 1));
    } else return {};
}
Rule(compare_op) {
    if ( 
        ( *in == '|' and *(in + 1) == '|' ) ||
        ( *in == '&' and *(in + 1) == '&') ||
        ( *in == 'o' and *(in + 1) == 'r')
    ) {
        RULE_SUCCESSD(in, in + 2, compare_op, std::string_view(in, 2));
    } else if ((*in == 'a' && *(in + 1) == 'n' && *(in + 2) == 'd'){
        RULE_SUCCESSD(in, in + 1, compare_op, std::string_view(in, 3));
    } else return {};
}
LOGICAL_NOT:
    '!' | 'not'
LOGICAL_AND:
    '&&' | 'and'
LOGICAL_OR:
    '||' | 'or'
LOGICAL_ANDR:
    '|&' | ( 'and' \s* 'or' )