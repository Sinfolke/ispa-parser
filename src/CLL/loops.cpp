#include <parser.h>
#include <parser_defs.h>

Rule(loop_while) {
    auto pos = in;
    if (strncmp(pos, "while", strlen("while")))
        return {};
    pos += strlen("while");
    auto expr_res = expr(pos);
    if (!expr_res.result)
        return {};
    
    auto block = cll_block(pos);
    if (!block.result) {
        block = cll_spaced_block(pos);
        if (!block.result)
            return {};
    }
    pos += block.token.length();

    std::unordered_map<const char*, std::any> data {
        { "cond", expr_res.token },
        { "block", block.token }
    };
    RULE_SUCCESSD(in, pos, loop_while, data);
}
Rule(loop_for) {
    auto pos = in;
}