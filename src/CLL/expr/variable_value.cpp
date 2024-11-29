#include <parser.h>
#include <parser_defs.h>

Rule(expr_variable_value) {
    auto pos = in;
    ISC_STD::skipup(pos, " ")
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    ISC_STD::skipup(pos, " ");
    std::unorederd_map<const char*, std::any> data;
    data["name"] = id_res.token;
    auto res = _operator(pos);
    if (!res.result) {
        res = assignment_operator(pos);
        if (!res.result)
            goto no;
    }
    data["op"] = res.token;
    // found
    ISC_STD::skipup(pos, " ");
    auto assignment_val_res = assingment_val(pos);
    if (!assignment_val_res.result)
        goto no;
    
    data["val"] = assingment_val_res.token;
    no:
    RULE_SUCCESSD(in, pos, variable_value, data);
}