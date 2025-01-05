#include <parser.h>
#include <parser_defs.h>

Rule(Rule_other) {
    auto pos = in;
    bool is_nested = false;
    ISC_STD::skip_spaces(pos);
    if (*pos == '#') {
        is_nested = true;
        pos++;
    }
    ISC_STD::skip_spaces(pos);
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    std::vector<::Parser::Rule> nested_names;
    while(*pos == '.') {
        auto id_res2 = id(pos + 1);
        if (!id_res2.result)
            break;
        pos += id_res2.token.length() + 1;
        nested_names.push_back(id_res2.token);
    }
    std::unordered_map<const char*, std::any> data {
        { "is_nested", is_nested },
        { "name", id_res.token },
        { "nested_name", nested_names }
    };
    RULE_SUCCESSD(in, pos, Rule_other, data);
}