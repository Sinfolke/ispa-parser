#include <parser.h>
#include <parser_defs.h>
Rule(cll) {
    auto pos = in;
    ISPA_STD::skip_spaces(pos);
    if (*pos != '$')
        return {};
    pos++;
    ISPA_STD::skip_spaces(pos);
    // skip spaces
    auto res = cll_if(pos);
    if (!res.result) {
        res = loop_while(pos);
        if (!res.result) {
            res = loop_for(pos);
            if (!res.result) {
                res = cll_var(pos);
                if (!res.result) {
                    res = expr(pos);
                    if (!res.result) {
                        res = copiable_method_call(pos);
                        if (!res.result) {
                            res = method_call(pos);
                            if (!res.result)
                                return {};
                        }
                    }
                }
            }
        }
    }
    pos += res.token.length();
    // skip spaces
    // end
    auto end_res = end(pos);
    if (end_res.result)
        pos += end_res.token.length();
    RULE_SUCCESSD(in, pos, cll, res.token);
}