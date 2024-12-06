#include <parser.h>
#include <parser_defs.h>

Rule(expr) {
    auto pos = in;
    bool matched_grp = false;
    ISC_STD::skip_spaces(pos);
    if (*pos == '(')
        matched_grp = true;

    std::vector<::Parser::Rule> data;
    ISC_STD::skip_spaces(pos);
    auto res = any_data(pos);
    if (!res.result) {
        res = expr_compare(pos);
        if (!res.result) {
            res = cll_function_call(pos);
            if (!res.result) {
                res = method_call(pos);
                if (!res.result) {
                    res = expr_parenthesed(pos);
                    if (!res.result) {
                        int count = 0;
                        while((res = expr_logical(pos)).result) {
                            data.push_back(res.token);
                            pos += res.token.length();
                            count++;
                        }
                        if (!count)
                            return {};
                    }
                }
            }

        }
    }
    pos += res.token.length();
    if (data.empty()) {
        data.push_back(res.token);
    }
    ISC_STD::skip_spaces(pos);
    if (matched_grp && *pos != ')')
        return {};
    RULE_SUCCESSD(in, pos, expr, data);
}