#include <parser.h>
#include <parser_defs.h>

Rule(var_refer) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    
    pos += id_res.token.length();
    ISC_STD::skip_spaces(pos);
    ::Parser::Rule_result expr_res;
    if (*pos == '[') {
        pos++;
        expr_res = expr(pos);
        if (!expr_res.result)
            return {};
        pos += expr_res.token.length();
        if (*pos != ']')
            return {};
        pos++;
    }
    std::unordered_map<const char*, std::any> data {
        { "name", id_res.token },
        { "data", expr_res.token }
    };
    RULE_SUCCESSD(in, pos, var_refer, data);
}