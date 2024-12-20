#include <parser.h>
#include <parser_defs.h>

Rule(var_refer) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    bool pre = 0, post = 0;
    if (!strncmp(pos, "++", 2) || !strncmp(pos, "--", 2)) {
        pos += 2;
        pre = 1;
        ISC_STD::skip_spaces(pos);
    }
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    
    pos += id_res.token.length();
    ISC_STD::skip_spaces(pos);
    ::Parser::Rule_result expr_res;
    if (*pos == '[') {
        pos++;
        ISC_STD::skip_spaces(pos);
        printf("VAR_REFER_ENTER_EXPR\n");
        expr_res = expr(pos);
        if (!expr_res.result) {
            printf("EXIT, pos: %c", *pos);
            return {};
        }
        pos += expr_res.token.length();
        printf("VAR_REFER_EXPR_LEN: %zu\n", expr_res.token.length());
        ISC_STD::skip_spaces(pos);
        if (*pos != ']') {
            printf("EXIT on closing brace, pos: %c", *pos);
            return {};
        }
        pos++;
    }
    if (!strncmp(pos, "++", 2) || !strncmp(pos, "--", 2)) {
        pos += 2;
        post = 1;
    }
    printf("Leaving rule, pos: %c, len: %ld\n", *pos, pos - in);
    std::unordered_map<const char*, std::any> data {
        { "name", id_res.token },
        { "brace_expression", expr_res.token },
        { "pre", pre },
        { "post", post }
    };
    RULE_SUCCESSD(in, pos, var_refer, data);
}