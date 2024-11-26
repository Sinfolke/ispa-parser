export module Parser.cll.expr;
#include <parser_defs.h>

Rule(expr) {
    auto pos = in;
    bool matched_grp = false;
    if (*pos == '(')
        matched_grp = true;

    
    auto res = any_data(pos);
    if (!any_data_res.result) {
        res = expr_compare(pos);
        if (!res.result) {
            res = expr_logical(pos);
            if (!res.result) {
                res = cll_function_call(pos);
                if (!res.result) {
                    res = cll_method_call(pos);
                    if (!res.result) {
                        res = expr_parenthesed(pos);
                        if (!res.result)
                            return {};
                    }
                }

            }
        }
    }
    pos += res.token.length();
    if (matched_grp && *pos != ')')
        return {};

    std::unordered_map<const char*, std::any> data {};
    RULE_SUCCESSD(in, pos, expr, data);
}