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
Rule(function_decl) {
    bool is_declaration_only = true;
    bool is_typed = false;
    size_t spaces;
    std::string fun_name;
    std::vector<std::string> fun_type;

    auto pos = in;
    // skip spaces!
    //spaces = skipup(' ');

    if (strncmp(pos, "fn", 2))
        return {};
    
    pos += 2;
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();

    auto functon_body_res = function_body_decl(pos);
    if (!function_body_res.result)
        return {};
    
    auto val = function_value(pos);
    if (!val.result)
        return {};
    pos += val.token.length;
    //auto strict_end_res = strict_end(pos);

    std::unordered_map<const char*, std::any> data {
        { "is_declaration_only", is_declaration_only },
        { "is_typed", is_typed },
        { "name", fun_name },
        { "type", fun_type },
        { "value", val.token }
    };
    RULE_SUCCESSD(in, pos, function_decl, data);
}
Rule(function_value, int spaces) {
    bool is_declaration_only = false;
    std::vector<Rule> val;
    while(true) {
        //skipup("\n");
        int current_spaces_amount; // = skipup(" ")
        if (current_spaces_amount >= spaces) {
            auto res = var(pos);
            if (!res) {
                res = cond(pos);
                if (!res) {
                    res = expr(pos);
                    if (!res) {
                        res = copiable_method_call(pos);
                        if (!res)
                            break;
                    }
                }
            }
            pos += res.token.length();
            val.push_back(res.token);
        } else break;
    }
    RULE_SUCCESSD(in, pos, function_value, val);
}