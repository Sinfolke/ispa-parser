// not gonna try declare these helper functions instead copy-paste their content as more quick solution
// static void function_body(void);
// static void function_in_parentheses(void);

Rule(function_body_call) {
    auto pos = in;
    if (*pos != '(')
        return {};
    auto function_arguments_res = function_arguments(pos);
    if (!function_arguments_res.result)
        return {};
    pos += function_arguments_res.token.length();

    if (*pos != ')')
        return {};
    
    RULE_SUCCESSD(in, pos, function_body_call, function_arguments_res.token);
}
Rule(function_body_decl) {
    auto pos = in;
    if (*pos != '(')
        return {};
    auto function_parameters_res = function_parameters(pos);
    if (!function_parameters_res.result)
        return {};
    pos += function_parameters_res.token.length();

    if (*pos != ')')
        return {};
    
    RULE_SUCCESSD(in, pos, function_body_call, function_parameters_res.token);
}