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
    auto res = var(pos);
    if (!res) {
        res = cond(pos);
        if (!res) {
            res = expr;
            if (!res) {
                res = copiable_method_call(pos);
                if (!res)
                    return {};
            }
        }
    }
    pos += res.token.length();
    // skip spaces
    // end
    RULE_SUCCESSD(in, pos, cll, res.token);
}