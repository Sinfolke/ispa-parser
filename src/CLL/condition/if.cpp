#include <parser/parser.h>
#include <parser/parser_defs.h>
Rule(cll_if) {
    auto pos = in;
    int space_amount = 0;
    while(*pos == ' ')
    {
        space_amount++;
        pos++;
    }
    if (strncmp(pos, "if", sizeof("if")))
        return {};
    
    auto expr_res = expr(pos);
    if (!expr_res.result)
        return {}
    
    auto res = cll_block(pos);
    if (!res.result) {
        res = cll_spaced_block(pos, space_amount);
        if (!res.result)
            return {};
    }

    std::unordered_map<const char*, std::any> data {
        { "expr", expr_res.token },
        { "block", res.token }
    };
    RULE_SUCCESSD(in, pos, cll_if, data);
}