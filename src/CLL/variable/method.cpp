#include <parser.h>
#include <parser_defs.h>

Rule(method_call) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    
    pos += id_res.token.length();
    ISC_STD::skipup(pos, " ");
    if (*pos != '.')
        return {};
    pos++;
    ISC_STD::skipup(pos, " ");
    auto cll_function_call_res = cll_function_call(pos);

    if (!cll_function_call_res.result)
        return {};
    
    pos += cll_function_call_res.token.length();
    std::unordered_map<const char*, std::any> data {
        { "object", id_res.token },
        { "call", cll_function_call_res.token }
    };

    RULE_SUCCESSD(in, pos, method_call, data);
}

Rule(copiable_method_call) {
    auto pos = in;
    if (*pos != '=')
        return {};
    pos++;
    ISC_STD::skipup(pos, " ");
    auto method_call_res = method_call(pos);

    if (!method_call_res.result)
        return {};
    
    RULE_SUCCESSD(in, pos, copiable_method_call, method_call_res.token);
}