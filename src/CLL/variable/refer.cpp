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
    if (*pos!= '[')
        return {};
    
    auto res = expr(pos);
    if (!res.result)
        return {};
    pos += res.token.length();
    if (*pos != ']')
        return {};
    
    std::unordered_map<const char*, std::any> data {
        { "name", id_res.token },
        { "data", res.token }
    };
    RULE_SUCCESSD(in, pos, var_refer, data);
}