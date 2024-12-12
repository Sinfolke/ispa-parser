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
    ISC_STD::skip_spaces(pos);
    pos += left.token.length();
    auto compare_op_res = compare_op(pos);
    if (!compare_op_res.result) {
        compare_op_res = op(pos);
        if (!compare_op_res.result)
            return {};
    }
    ISC_STD::skip_spaces(pos);
    pos += compare_op_res.token.length();
    auto right = expr_compare_side(pos);
    if (!right.result) {
        right = expr(pos);
        if (!right.result)
            return {};
    }
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
    auto res = cll_function_call(pos);
    if (!res.result) {
        res = method_call(pos);
        if (!res.result) {
            res = var_refer(pos);
            if (!res.result) {
                res = any_data(pos);
                if (!res.result)
                    return {};
            }
        }
    }
    pos += res.token.length();
    RULE_SUCCESSD(in, pos, expr_compare_side, res.token);
}