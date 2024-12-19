#include <parser.h>
#include <parser_defs.h>

Rule(expr_variable_value) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto id_res = var_refer(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    ISC_STD::skip_spaces(pos);
    std::unordered_map<const char*, std::any> data;
    data["name"] = id_res.token;
    auto res = op(pos);
    if (!res.result) {
        res = assignment_op(pos);
    }

    if (res.result) {
        data["op"] = res.token;
        // found
        ISC_STD::skip_spaces(pos);
        auto expr_res = expr(pos);
        if (expr_res.result)
            data["val"] = expr_res.token;
    }
    RULE_SUCCESSD(in, pos, expr_variable_value, data);
}