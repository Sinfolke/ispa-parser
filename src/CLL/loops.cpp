#include <parser.h>
#include <parser_defs.h>

Rule(loop_while) {
    auto pos = in;
    auto spaces = ISC_STD::skip_spaces(pos);
    if (strncmp(pos, "while", strlen("while")))
        return {};
    pos += strlen("while");
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr(pos);
    if (!expr_res.result)
        return {};
    pos += expr_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto block = cll_block(pos);
    if (!block.result) {
        block = cll_spaced_block(pos, spaces);
        if (!block.result)
            return {};
    }
    pos += block.token.length();

    std::unordered_map<const char*, std::any> data {
        { "expr", expr_res.token },
        { "block", block.token }
    };
    RULE_SUCCESSD(in, pos, loop_while, data);
}
Rule(loop_for) {
    auto pos = in;
    auto spaces = ISC_STD::skip_spaces(pos);
    if (strncmp(pos, "for", 3))
        return {};
    pos += 3;
    ISC_STD::skip_spaces(pos);
    if (*pos != '(')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto res1 = cll_var(pos);
    if (!res1.result) {
        res1 = expr(pos);
    }
    if (res1.result) {
        pos += res1.token.length();
        ISC_STD::skip_spaces(pos);
    }
    if (*pos != ';')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);

    auto expr2_res = expr(pos);
    if (expr2_res.result) {
        pos += expr2_res.token.length();
        ISC_STD::skip_spaces(pos);
    }
    if (*pos != ';')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto expr3_res = expr(pos);
    if (expr3_res.result) {
        pos += expr3_res.token.length();
        ISC_STD::skip_spaces(pos);
    }
    if (*pos != ')') {
        return {};
    }
    pos++;
    ISC_STD::skip_spaces(pos);

    auto block = cll_block(pos);
    if (!block.result) {
        // skip spaces here
        block = cll_spaced_block(pos, spaces);
        if (!block.result) {
            return {};
        }
    }
    pos += block.token.length();
    std::unordered_map<const char*, std::any> data {
        { "decl", res1.token },
        { "cond", expr2_res.token },
        { "end", expr3_res.token },
        { "block", block.token }
    };
    RULE_SUCCESSD(in, pos, loop_for, data);
}