
#include <parser.h>
#include <parser_defs.h>

Rule(cll_ternary) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr(pos);
    if (!expr_res.result)
        return {};

    pos += expr_res.token.length();
    ISC_STD::skip_spaces(pos);
    printf("Pass first expression");
    if (*pos != '?')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto expr_res2 = expr(pos);
    if (!expr_res2.result)
        return {};
    pos += expr_res2.token.length();
    ISC_STD::skip_spaces(pos);
    printf("Pass second expression\n");
    if (*pos != ':')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto expr_res3 = expr(pos);
    if (!expr_res3.result)
        return {};
    printf("\ntotal length: %ld\n", pos - in);
    std::unordered_map<const char*, std::any> data {
        { "cond", expr_res.token },
        { "first", expr_res2.token },
        { "second", expr_res3.token }
    };
    RULE_SUCCESSD(in, pos, cll_ternary, data);
}