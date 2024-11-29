#include <parser.h>
#include <parser_defs.h>
Rule(expr_logical) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    auto expr_res = expr(pos);
    if (!expr_res.result)
        return {};
    ISC_STD::skipup(pos, " ");
    auto logical_op_res = logical_op(pos);
    if (!logical_op_res.result)
        return {};
    ISC_STD::skipup(pos, " ");
    auto expr2_res = expr(pos);
    if (!expr2_res.result)
        return {};
}