#include <parser.h>
#include <parser_defs.h>
Rule(accessors_group) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '$')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto number_res = number(pos);
    if (!number_res.result)
        return {};

    pos += number_res.token.length();
    RULE_SUCCESSD(in, pos, accessors_group, number_res.token);
}
Rule(accessors_element) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '%')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto number_res = number(pos);
    if (!number_res.result)
        return {};
    pos += number_res.token.length();
    RULE_SUCCESSD(in, pos, accessors_element, number_res.token);
}
Rule(accessors_char) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '^')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto number_res = number(pos);
    if (!number_res.result)
        return {};
    pos += number_res.token.length();
    RULE_SUCCESSD(in, pos, accessors_char, number_res.token);
}
Rule(accessor_all) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto res = accessors_group(pos);
    if (!res.result) {
        res = accessors_element(pos);
        if (!res.result) {
            res = accessors_char(pos);
            if (!res.result) 
                return {};
        }
    }
    pos += res.token.length();
    RULE_SUCCESSD(in, pos, accessor_all, res.token);
}
Rule(accessor) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto res = accessor_all(pos);
    if (!res.result)
        return {};
    pos += res.token.length();
    ISC_STD::skip_spaces(pos);
    std::vector<::Parser::Rule> results;
    while (*pos == '>') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto res = accessor_all(pos);
        if (!res.result)
            break;
        results.push_back(res.token);
        pos += res.token.length();
    }
    std::unordered_map<const char*, std::any> data {
        { "first", res.token },
        { "second", results }
    };
    RULE_SUCCESSD(in, pos, accessor, data);
}