export module Parser.cll.logical;
#include <parser_defs.h>
Rule(expr_logical) {
    auto pos = in;
    auto expr_res = expr(pos);
    if (!expr_res.result)
        return {};

    auto logical_op_res = logical_op(pos);
    if (!logical_op_res.result)
        return {};
    auto expr2_res = expr(pos);
    if (!expr2_res.result)
        return {};
}