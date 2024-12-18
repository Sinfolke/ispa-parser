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
        expr_res = expr(pos);
        if (!expr_res.result)
            return {};
        pos += expr_res.token.length();
        ISC_STD::skip_spaces(pos);
        if (*pos != ']')
            return {};
        pos++;
    }
    if (!strncmp(pos, "++", 2) || !strncmp(pos, "--", 2)) {
        pos += 2;
        post = 1;
    }
    std::unordered_map<const char*, std::any> data {
        { "name", id_res.token },
        { "brace_expression", expr_res.token },
        { "pre", pre },
        { "post", post }
    };
    RULE_SUCCESSD(in, pos, var_refer, data);
}