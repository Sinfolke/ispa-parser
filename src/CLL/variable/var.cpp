#include <parser.h>
#include <parser_defs.h>
Rule(cll_var) {
    auto pos = in;
    printf("Enter cll_var \n");
    ISC_STD::skip_spaces(pos);
    auto cll_type_res = cll_type(pos);
    if (!cll_type_res.result) {
        return {};
    }
    
    pos += cll_type_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto id_res = id(pos);

    if (!id_res.result) {
        return {};
    }
    
    pos += id_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto assignment_op_res = assignment_op(pos);
    if (!assignment_op_res.result) {
        printf("assingment_op_exit, pos: %c\n", *pos);
        return {};
    }
    
    pos += assignment_op_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr(pos);

    if (!expr_res.result)
        return {};
    pos += expr_res.token.length();
    std::unordered_map<const char*, std::any> data {
        { "type", cll_type_res.token },
        { "id", id_res.token },
        { "operator", assignment_op_res.token },
        { "value", expr_res.token }
    };
    RULE_SUCCESSD(in, pos, cll_var, data);
}
Rule(var_increament) {}