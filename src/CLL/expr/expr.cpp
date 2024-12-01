#include <parser.h>
#include <parser_defs.h>

Rule(expr) {
    auto pos = in;
    bool matched_grp = false;
    ISC_STD::skip_spaces(pos);
    if (*pos == '(')
        matched_grp = true;

    ISC_STD::skip_spaces(pos);
    auto res = any_data(pos);
    if (!res.result) {
        res = expr_compare(pos);
        if (!res.result) {
            res = expr_logical(pos);
            if (!res.result) {
                res = cll_function_call(pos);
                if (!res.result) {
                    res = method_call(pos);
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
    ISC_STD::skip_spaces(pos);
    if (matched_grp && *pos != ')')
        return {};

    std::unordered_map<const char*, std::any> data {};
    RULE_SUCCESSD(in, pos, expr, data);
}