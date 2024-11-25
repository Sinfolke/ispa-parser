#include <parser/parser.h>
#include <parser/parser_defs.h>
Rule(cll_var) {
    auto pos = in;
    auto cll_type_res = cll_type(pos);
    if (!cll_type_res.result)
        return {};
    
    pos += cll_type_res.token.length();

    auto id_res = id(pos);

    if (!id_res.result) 
        return {};
    
    pos += id_res.token.length();

    auto assignment_op_res = assingment_op(pos);
    if (!assignment_op_res.result)
        return {};
    
    pos += assignment_op_res.token.length();

    auto expr_res = expr(pos);

    if (!expr_res.result)
        return {};
    
    std::unordered_map<const char*, std::any> data {
        { "type", cll_type_res.token },
        { "id", id_res.token },
        { "operator", assignment_op_res.token },
        { "value", expr_res.token }
    };
    RULE_SUCCESSD(in, pos, cll_var, data);
}