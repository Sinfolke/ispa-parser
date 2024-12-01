#include <parser.h>
#include <parser_defs.h>
Rule(expr_logical) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr(pos);
    if (!expr_res.result)
        return {};
    ISC_STD::skip_spaces(pos);
    auto logical_op_res = logical_op(pos);
    if (!logical_op_res.result)
        return {};
    ISC_STD::skip_spaces(pos);
    auto expr2_res = expr(pos);
    if (!expr2_res.result)
        return {};
    
    std::unordered_map<const char*, std::any> data {
        { "left", expr_res.token },
        { "op", logical_op_res.token },
        { "right", expr2_res.token }
    };
    RULE_SUCCESSD(in, pos, expr_logical, data);
}