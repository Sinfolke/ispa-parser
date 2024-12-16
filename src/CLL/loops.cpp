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
    if (strncmp(pos, "for", 3))
        return {};
    pos += 3;
    if (*pos != '(')
        return {};
    pos++;
    auto expr1_res = expr(pos);
    if (expr1_res.result)
        pos += expr1_res.token.length();
    if (*pos != ';')
        return {};
    auto expr2_res = expr(pos);
    if (expr2_res.result)
        pos += expr2_res.token.length();
    
    if (*pos != ';')
        return {};
    
    auto expr3_res = expr(pos);
    if (expr3_res.result)
        pos += expr3_res.token.length();

    if (*pos != ')')
        return {};
    pos++;

    auto block = cll_block(pos);
    if (!block.result) {
        // skip spaces here
        block = cll_spaced_block(pos, );
        if (!block.result)
            return {};
    }

    std::unordered_map<const char*, std::any> data {
        { "decl", expr1_res.token },
        { "cond", expr2_res.token },
        { "end", expr3_res.token },
        { "block", block.token }
    };
}