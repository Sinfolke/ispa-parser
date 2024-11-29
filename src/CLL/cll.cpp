#include <parser.h>
#include <parser_defs.h>
Rule(cll) {
    auto pos = in;
    if (*pos != '\n')
        return {};
    pos++;
    // skip spaces
    if (*pos != '$')
        return {};
    pos++;
    // skip spaces
    auto res = cll_var(pos);
    if (!res.result) {
        res = cll_if(pos);
        if (!res.result) {
            res = expr(pos);
            if (!res.result) {
                res = copiable_method_call(pos);
                if (!res.result)
                    return {};
            }
        }
    }
    pos += res.token.length();
    // skip spaces
    // end
    RULE_SUCCESSD(in, pos, cll, res.token);
}