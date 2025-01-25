#include <parser.h>
#include <parser_defs.h>
Rule(cll_var) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto cll_type_res = cll_type(pos);
    if (cll_type_res.result) {
        pos += cll_type_res.token.length();
    }
    
    ISC_STD::skip_spaces(pos);
    auto id_res = id(pos);

    if (!id_res.result) {
        return {};
    }

    pos += id_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto assignment_op_res = assignment_op(pos);
    ::Parser::Rule_result expr_res;
    if (assignment_op_res.result) {
        pos += assignment_op_res.token.length();
        ISC_STD::skip_spaces(pos);
        expr_res = cll_ternary(pos);

        if (!expr_res.result) {
            expr_res = expr(pos);
            if (!expr_res.result) {
                return {};
            }
        }
        pos += expr_res.token.length();
    }

    std::unordered_map<const char*, std::any> data {
        { "type", cll_type_res.token },
        { "id", id_res.token },
        { "operator", assignment_op_res.token },
        { "value", expr_res.token }
    };
    RULE_SUCCESSD(in, pos, cll_var, data);
}
// Rule(cll_var_operator) {
//     auto pos = in;
//     auto res = cll_var_operator_post(pos);
//     if (!res.result) {
//         res = cll_var_operator_pre(pos);
//         if (!res.result) {
//             return {};
//         }
//     }
//     pos += res.token.length();
//     RULE_SUCCESSD(in, pos, cll_var_operator, res.token);
// }
// Rule(cll_var_operator_post) {
//     auto pos = in;
//     if (strncmp(pos, "++", 2)) {
//         return {};
//     }
//     pos += 2;
//     auto res = var_refer(pos);
//     if (!res.result)
//         return {};
    
//     pos += res.token.length();
//     RULE_SUCCESSD(in, pos, cll_var_operator_post, res.token);
// }
// Rule(cll_var_operator_pre) {
//     auto pos = in;
//     auto res = var_refer(pos);
//     if (!res.result)
//         return {};
    
//     pos += res.token.length();

//     if (strncmp(pos, "++", 2))
//         return {};
    
//     pos += 2;
//     RULE_SUCCESSD(in, pos, cll_var_operator_pre, res.token);
// }