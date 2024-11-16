
#include <parser.h>
#include <parser_defs.h>

Rule(cll_ternary) {
    auto pos = in;
    auto expr_res = expr(pos);
    if (!expr_res.result)
        return {};

    pos += expr_res.token.length();
    if (*pos != '?')
        return {};

    auto expr_res2 = expr(pos);
    if (!expr_res2.result)
        return {};
    pos += expr_res2.token.length();

    if (*pos != ':')
        return {};

    auto expr_res3 = expr(pos);
    if (expr_res3.result)
        return {};
    
    std::unordered_map<const char*, std::string> data {
        { "cond", expr_res.token },
        { "first", expr_res2.token },
        { "second", expr_res3.token }
    };
    RULE_SUCCESSD(in, pos, cll_ternary, data);
}