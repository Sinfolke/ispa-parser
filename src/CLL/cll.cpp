#include <parser.h>
#include <parser_defs.h>
Rule(cll) {
    auto pos = in;
    // if (*pos != '\n') {
    //     printf("cll exit 1\n");
    //     return {};
    // }
    // pos++;
    // skip spaces
    ISC_STD::skip_spaces(pos);
    if (*pos != '$')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    // skip spaces
    printf("cll_var\n");
    auto res = cll_var(pos);
    if (!res.result) {
        printf("cll_if\n");
        res = cll_if(pos);
        if (!res.result) {
            printf("expr\n");
            res = expr(pos);
            if (!res.result) {
                printf("copiable_method_call\n");
                res = copiable_method_call(pos);
                if (!res.result) {
                    printf("method_call\n");
                    res = method_call(pos);
                    if (!res.result)
                        return {};
                }
            }
        }
    }
    pos += res.token.length();
    // skip spaces
    // end
    auto end_res = end(pos);
    if (!end_res.result)
        return {};
    pos += end_res.token.length();
    printf("Cll matched successfully\n");
    RULE_SUCCESSD(in, pos, cll, res.token);
}