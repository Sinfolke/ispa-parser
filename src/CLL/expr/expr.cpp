#include <parser.h>
#include <parser_defs.h>
std::string RulesToString(::Parser::Rules);

Rule(expr) {
    auto pos = in;
    printf("expr -> logical");
    auto res = expr_logical(pos);
    if (!res.result) {
        printf("comapre -> ");  
        res = expr_compare(pos);
        if (!res.result) {
            printf("arithmetic -> ");
            res = expr_arithmetic(pos);
            if (!res.result) {
                printf("group -> ");  
                res = expr_group(pos);
                if (!res.result) {
                    printf("copiable_method_call ->");
                    res = expr_copiable_method_call(pos);
                    if (!res.result) {
                        printf("any_data ");
                        res = any_data(pos);
                        if (!res.result) {
                            return {};
                        }
                    }
                }
            }
        }
    }
    printf("\nexpr length: %zu\n", res.token.length());
    pos += res.token.length();
    RULE_SUCCESSD(in, pos, expr, res.token);
}
Rule(expr_for_arithmetic) {
    auto pos = in;
    auto res = method_call(pos);
    if (!res.result) {
        res = any_data(pos);
        if (!res.result)
            return {};
    }
    pos += res.token.length();
    RULE_SUCCESSD(in, pos, expr, res.token);
}
Rule(expr_logical) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr_compare(pos);
    if (!expr_res.result)
        return {};
    pos += expr_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto logical_op_res = logical_op(pos);
    if (!logical_op_res.result)
        return {};
    pos += logical_op_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto expr_res2 = expr_compare(pos);
    if (!expr_res2.result)
        return {};
    pos += expr_res2.token.length();
    std::unordered_map<const char*, std::any> data {
        { "expr1", expr_res.token },
        { "op", logical_op_res.token },
        { "expr2", expr_res2.token }
    };
    RULE_SUCCESSD(in, pos, expr_logical, data);
}
Rule(expr_compare) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr_arithmetic(pos);
    if (!expr_res.result)
        return {};
    pos += expr_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto compare_op_res = compare_op(pos);
    if (!compare_op_res.result)
        return {};
    pos += compare_op_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto expr_res2 = expr_arithmetic(pos);
    if (!expr_res2.result)
        return {};
    pos += expr_res2.token.length();
    std::unordered_map<const char*, std::any> data {
        { "expr1", expr_res.token },
        { "op", compare_op_res.token },
        { "expr2", expr_res2.token }
    };
    RULE_SUCCESSD(in, pos, expr_compare, data);
}
Rule(expr_arithmetic) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr_for_arithmetic(pos);
    if (!expr_res.result)
        return {};
    pos += expr_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto arithmetic_op_res = op(pos);
    if (!arithmetic_op_res.result)
        return {};
    pos += arithmetic_op_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto expr_res2 = expr_for_arithmetic(pos);
    if (!expr_res2.result)
        return {};
    pos += expr_res2.token.length();
    std::unordered_map<const char*, std::any> data {
        { "expr1", expr_res.token },
        { "op", arithmetic_op_res.token },
        { "expr2", expr_res2.token }
    };
    RULE_SUCCESSD(in, pos, expr_arithmetic, data);
}
Rule(expr_group) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '(')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr(pos);
    if (!expr_res.result)
        return {};
    pos += expr_res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != ')')
        return {};
    pos++;
    std::unordered_map<const char*, std::any> data {
        { "expr", expr_res.token }
    };
    RULE_SUCCESSD(in, pos, expr_group, data);
}
Rule(expr_copiable_method_call) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '(')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto method_call_res = copiable_method_call(pos);
    if (!method_call_res.result)
        return {};
    pos += method_call_res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != ')')
        return {};
    pos++;
    RULE_SUCCESSD(in, pos, expr_copiable_method_call, method_call_res.token);
}