#include <parser/parser.h>
#include <parser/parser_defs.h>

Rule(expr_parenthesed) {
    auto pos = in;
    if (*pos != '(')
        return {};
    pos++;

    auto res = expr_parenthesed_variable_assignment(pos);
    if (!res.result) {
        res = copy_method_call(pos);
        if (!res.result) {
            res = cll_ternary(pos);
            if (!res)
                return {};
        }
    }
    pos += res.token.length();

    if (*pos != ')')
        return {};
}
Rule(expr_parenthesed_variable_assignment) {
    auto pos = in;
    auto id_res = id(pos);
    if (!id_res.result)
        return {};


    pos += id_res.token.length();

    auto assignment_operator_res = assignment_operator(pos);
    if (!assignment_operator_res.result)
        return {};
    
    pos += assignment_operator_res.token.length();

    auto assignment_val_res = assignment_val(pos);
    if (!assignment_val_res.result)
        return {};
    
    pos += assignment_val_res.token.length();

    std::unordered_map<const char*, std::any> data {
        { "name", id_res.token },
        { "operator", assignment_operator_res.token },
        { "val", assingment_val_res.token }
    };

    RULE_SUCCESSD(in, pos, expr_parenthesed_variable_assignment, data);
}