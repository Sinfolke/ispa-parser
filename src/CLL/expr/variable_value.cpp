#include <parser.h>
#include <parser_defs.h>

Rule(expr_variable_value) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    ISC_STD::skipup(pos, " ");
    std::unordered_map<const char*, std::any> data;
    data["name"] = id_res.token;
    auto res = op(pos);
    if (!res.result) {
        res = assignment_op(pos);
        if (!res.result)
            goto no;
    }
    data["op"] = res.token;
    // found
    ISC_STD::skipup(pos, " ");
    auto expr_res = expr(pos);
    if (!expr_res.result)
        goto no;
    
    data["val"] = expr_res.token;
    no:
    RULE_SUCCESSD(in, pos, expr_variable_value, data);
}