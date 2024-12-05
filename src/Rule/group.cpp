#include <parser.h>
#include <parser_defs.h>

Rule(Rule_group) {
    auto pos = in;
    std::string name;
    ISC_STD::skip_spaces(pos);
    if (*pos == '&') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto id_res = id(pos);
        if (id_res.result)
            name = TO(std::string, id_res.token);
        else
            return {};
        
        pos += id_res.token.length();
        ISC_STD::skip_spaces(pos);
    }
    if (*pos != '(') {
        printf("Exit 1\n");
        return {};
    }
    pos++;
    ISC_STD::skip_spaces(pos);
    std::vector<::Parser::Rule> r;
    int i = 0;
    while(true)
    {
        ISC_STD::skip_spaces(pos);
        auto rule_res = Rule_rule(pos);
        printf("IT %d\n", i++);
        if (!rule_res.result)
            break;

        pos += rule_res.token.length();
        r.push_back(rule_res.token);
    }
    ISC_STD::skip_spaces(pos);
    if (*pos != ')') {
        printf("Exit 2");
        return {};
    }
    pos++;
    std::unordered_map<const char*, std::any> data {
        { "variable", name },
        { "val", r }
    };
    RULE_SUCCESSD(in, pos, Rule_group, data);
}