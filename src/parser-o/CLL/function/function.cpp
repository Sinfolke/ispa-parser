// not gonna try declare these helper functions instead copy-paste their content as more quick solution
// static void function_body(void);
// static void function_in_parentheses(void);
#include <parser/parser.h>
#include <parser/parser_defs.h>

Rule(function_body_call) {
    auto pos = in;
    if (*pos != '(')
        return {};
    auto function_arguments_res = function_arguments(pos);
    if (!function_arguments_res.result)
        return {};
    pos += function_arguments_res.token.length();

    if (*pos != ')')
        return {};
    
    RULE_SUCCESSD(in, pos, function_body_call, function_arguments_res.token);
}
Rule(function_body_decl) {
    auto pos = in;
    if (*pos != '(')
        return {};
    auto function_parameters_res = function_parameters(pos);
    if (!function_parameters_res.result)
        return {};
    pos += function_parameters_res.token.length();

    if (*pos != ')')
        return {};
    
    RULE_SUCCESSD(in, pos, function_body_call, function_parameters_res.token);
}
Rule(function_arguments) {
    auto pos = in;
    auto any_data_res = any_data(pos);
    std::vector<Rule> _3 {};
    if (any_data_res.result) {
        pos += any_data_res.token.length();
        while (*pos == ',') {
            pos++;
            auto any_data2_res = any_data(pos);
            if (!any_data2_res)
                break;
            pos += any_data2_res.token.length();
            _3.push_back(any_data2_res.token);
        }
    }
    
    std::vector<Rule> data {
        any_data_res.token,
        _3
    };
    RULE_SUCCESSD(in, pos, function_arguments, data);
}
Rule(function_parameters) {
    auto pos = in;
    auto id_res = id(pos);
    std::vector<Rule> _3 {};
    if (id_res.result) {
        pos += id_res.token.length();
        while (*pos == ',') {
            pos++;
            auto id2_res = id(pos);
            if (!id2_res)
                break;
            pos += id2_res.token.length();
            _3.push_back(id2_res.token);
        }
    }
    
    std::vector<Rule> data {
        id_res.token,
        _3
    };
    RULE_SUCCESSD(in, pos, function_arguments, data);
}
Rule(cll_function_call) {
    auto pos = in;
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    auto function_body_call_res = function_body_call(pos);
    if (!function_body_call_res.result)
        return {};
    
    std::unordered_map<const char*, std::any> data {
        { "name", id_res.token },
        { "body", function_body_call_res.token }
    };
    RULE_SUCCESSD(in, pos, cll_function_call, data);
}