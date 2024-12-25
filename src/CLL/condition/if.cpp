#include <parser.h>
#include <parser_defs.h>
Rule(cll_if) {
    auto pos = in;
    int space_amount = ISC_STD::skip_spaces(pos);
    if (strncmp(pos, "if", 2))
        return {};
    pos += 2;
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr(pos);
    if (!expr_res.result)
        return {};
    pos += expr_res.token.length();
    printf("matched expr, pos: %c\n", *pos);
    auto res = cll_block(pos);
    if (!res.result) {
        res = cll_spaced_block(pos, space_amount);
        if (!res.result)
            return {};
    }
    pos += res.token.length();
    std::unordered_map<const char*, std::any> data {
        { "expr", expr_res.token },
        { "block", res.token }
    };
    printf("Matched condition, length: %ld\n", pos - in);
    RULE_SUCCESSD(in, pos, cll_if, data);
}