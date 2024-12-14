#include <parser.h>
#include <parser_defs.h>

Rule(expr_compare) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto left = expr_compare_side(pos);
    if (!left.result) {
        left = expr(pos);
        if (!left.result)
            return {};
    }
    pos += left.token.length();
    printf("Matched first side\n");
    ISC_STD::skip_spaces(pos);
    auto compare_op_res = compare_op(pos);
    if (!compare_op_res.result) {
        compare_op_res = op(pos);
        if (!compare_op_res.result)
            return {};
    }
    printf("Matched op\n");
    pos += compare_op_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto right = expr_compare_side(pos);
    if (!right.result) {
        right = expr(pos);
        if (!right.result)
            return {};
    }
    printf("Matched second side");
    pos += right.token.length();
    std::unordered_map<const char*, std::any> data {
        { "left", left.token },
        { "op", compare_op_res.token },
        { "right", right.token }
    };
    RULE_SUCCESSD(in, pos, expr_compare, data);
}
Rule(expr_compare_side) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    printf("[expr_compare_side] ANY_DATA -> ");
    auto res = any_data(pos);
    if (!res.result) {
        printf("var_reder -> ");
        res = var_refer(pos);
        if (!res.result) {
            printf("cll_function_call -> ");
            res = cll_function_call(pos);
            if (!res.result) {
                printf("Unmatch until method_call ");
                printf("method_call -> ");
                res = method_call(pos);
                if (!res.result)
                    return {};
            }
        }
    }
    pos += res.token.length();
    RULE_SUCCESSD(in, pos, expr_compare_side, res.token);
}