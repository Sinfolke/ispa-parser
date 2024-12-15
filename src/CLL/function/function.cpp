// not gonna try declare these helper functions instead copy-paste their content as more quick solution
// static void function_body(void);
// static void function_in_parentheses(void);
#include <parser.h>
#include <parser_defs.h>

Rule(function_body_call) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '(') {
        return {};
    }
    pos++;
    ISC_STD::skip_spaces(pos);
    auto function_arguments_res = function_arguments(pos);
    if (function_arguments_res.result) {
        pos += function_arguments_res.token.length();
    }
    ISC_STD::skip_spaces(pos);
    if (*pos != ')')
        return {};
    pos++;
    RULE_SUCCESSD(in, pos, function_body_call, function_arguments_res.token);
}
Rule(function_body_decl) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '(')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto function_parameters_res = function_parameters(pos);
    if (!function_parameters_res.result)
        return {};
    pos += function_parameters_res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != ')')
        return {};
    pos++;
    RULE_SUCCESSD(in, pos, function_body_call, function_parameters_res.token);
}
Rule(function_arguments) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto res = any_data(pos);
    if (!res.result) {
        return {};
    }
    pos += res.token.length();
    std::vector<::Parser::Rule> _3 {};
    if (res.result) {
        pos += res.token.length();
        while (*pos == ',') {
            pos++;
            ISC_STD::skip_spaces(pos);
            auto res2 = any_data(pos);
            if (!res2.result) {
                res2 = id(pos);
                if (!res2.result)
                    return {};
            }
            pos += res2.token.length();
            _3.push_back(res2.token);
            ISC_STD::skip_spaces(pos);
        }
    }
    
    std::vector<std::any> data {
        res.token,
        _3
    };
    RULE_SUCCESSD(in, pos, function_arguments, data);
}
Rule(function_parameters) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto id_res = id(pos);
    std::vector<::Parser::Rule> _3 {};
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    ISC_STD::skip_spaces(pos);
    while (*pos == ',') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto id2_res = id(pos);
        if (!id2_res.result)
            break;
        pos += id2_res.token.length();
        _3.push_back(id2_res.token);
        ISC_STD::skip_spaces(pos);
    }    
    std::vector<std::any> data {
        id_res.token,
        _3
    };
    RULE_SUCCESSD(in, pos, function_arguments, data);
}
Rule(cll_function_call) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    printf("Enter function call\n");
    auto id_res = id(pos);
    if (!id_res.result) {
        return {};
    }
    pos += id_res.token.length();
    ISC_STD::skip_spaces(pos);
    printf("Enter body call\n");
    auto function_body_call_res = function_body_call(pos);
    if (!function_body_call_res.result) {
        printf("Function body unsuccessfull call\n");
        return {};
    }
    pos += function_body_call_res.token.length();
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
    spaces = ISC_STD::skip_spaces(pos);

    if (strncmp(pos, "fn", 2))
        return {};
    pos += 2;
    ISC_STD::skip_spaces(pos);
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();

    ISC_STD::skip_spaces(pos);
    auto function_body_res = function_body_decl(pos);
    if (!function_body_res.result)
        return {};
    pos += function_body_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto val = function_value(pos, spaces);
    if (val.result)
        pos += val.token.length();
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
    std::vector<::Parser::Rule> val;
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    while(true) {
        //skipup("\n");
        int current_spaces_amount; // = skipup(" ")
        if (current_spaces_amount >= spaces) {
            auto res = cll_var(pos);
            if (!res.result) {
                res = cll_if(pos);
                if (!res.result) {
                    res = expr(pos);
                    if (!res.result) {
                        res = copiable_method_call(pos);
                        if (!res.result)
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