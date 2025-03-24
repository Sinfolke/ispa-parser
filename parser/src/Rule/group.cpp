#include <parser.h>
#include <parser_defs.h>

Rule(Rule_group) {
    auto pos = in;
    std::any name;
    ISPA_STD::skip_spaces(pos);
    if (*pos == '&') {
        pos++;
        ISPA_STD::skip_spaces(pos);
        auto res = method_call(pos);
        if (!res.result) {
            res = id(pos);
            if (!res.result) {
                return {};
            }
        }
        
        pos += res.token.length();
        name = res.token;
        ISPA_STD::skip_spaces(pos);
    }
    if (*pos != '(') {
        return {};
    }
    pos++;
    ISPA_STD::skip_spaces(pos);
    std::vector<::Parser::Rule> r;
    while(true)
    {
        ISPA_STD::skip_spaces(pos);
        auto rule_res = Rule_rule(pos);
        if (!rule_res.result) {
            break;
        }

        pos += rule_res.token.length();
        r.push_back(rule_res.token);
        if (*pos == ')')
            break;
    }
    ISPA_STD::skip_spaces(pos);
    if (*pos != ')') {
        return {};
    }
    pos++;
    std::unordered_map<const char*, std::any> data {
        { "variable", name },
        { "val", r }
    };
    RULE_SUCCESSD(in, pos, Rule_group, data);
}