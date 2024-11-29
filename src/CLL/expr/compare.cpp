#include <parser.h>
#include <parser_defs.h>

Rule(expr_compare) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    auto left = expr_compare_side(pos);
    if (!left.result) {
        left = expr(pos);
        if (!left.result)
            return {};
    }
    ISC_STD::skipup(pos, " ");
    auto compare_op_res = compare_op(pos);
    if (!compare_op_res.result)
        return {};
    ISC_STD::skipup(pos, " ");
    auto right = expr_compare_side(pos);
    if (!right.result) {
        right = expr(pos);
        if (!right.result)
            return {};
    }

    std::unordered_map<const char*, std::any> result {
        { "left", left.token },
        { "op", compare_op_res.token },
        { "right", right.token }
    };
    RULE_SUCCESSD(in, pos, expr_compare, data)
}
Rule(expr_compare_side) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    auto res = any_data(pos);
    if (!res) {
        res = id(pos);
        if (!res) {
            res = cll_function_call(pos);
            if (!res) {
                res = method_call(pos);
                if (!res)
                    return {};
            }
        }
    }
    RULE_SUCCESSD(in, pos, expr_compare_side, res.token);
}