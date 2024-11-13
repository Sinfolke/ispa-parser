#include <parser.h>
#include <parser_defs.h>

using cll_template_content_param1_t = Rule_result (Parser::*)(const char*);

static std::tuple<bool, int, std::any> cll_template_content(const char* in, cll_template_content_param1_t p1) {
    // cll_type
    auto p1_1_res = p1(in);
    if (!p1_1_res.result)
        return {0, 0, 0};
    auto pos = in + p1_1_res.token.length();
    std::vector<cll_template_content_param1_t> cll_p1_seq;
    while(*pos == ',') {
        auto p1_2_res = p1();
        if (!p1_2_res.result)
            return {0, 0, 0};
        pos += p1_2_res.token.length();
        cll_p1_seq.push_back(p1_2_res.token);
    }
    std::vector<std::any> data = {
        p1_1_res.token,
        cll_p1_seq
    };
    return { true, pos, data };
}
Rule(cll_template_content_typename) {
    auto [result, pos, data] = cll_template_content(in, cll_type);
    if (!result) return {};
    RULE_SUCCESSD(in, pos, cll_template_content_typename, data);
}
Rule(cll_template_content_int) {
    auto [result, pos, data] = cll_template_content(in, number);
    if (!result) return {};
    RULE_SUCCESSD(in, pos, cll_template_content_typename, data);
}
Rule(cll_template_content_bool) {
    auto [result, pos, data] = cll_template_content(in, boolean);
    if (!result) return {};
    RULE_SUCCESSD(in, pos, cll_template_content_typename, data);
}
Rule(cll_template_content_string) {
    auto [result, pos, data] = cll_template_content(in, string);
    if (!result) return {};
    RULE_SUCCESSD(in, pos, cll_template_content_typename, data);
}
Rule(cll_template_content_array) {
    auto [result, pos, data] = cll_template_content(in, array);
    if (!result) return {};
    RULE_SUCCESSD(in, pos, cll_template_content_typename, data);
}
Rule(cll_template_content_object) {
    auto [result, pos, data] = cll_template_content(in, object);
    if (!result) return {};
    RULE_SUCCESSD(in, pos, cll_template_content_typename, data);
}
Rule(cll_template_content_any_data) {
    auto [result, pos, data] = cll_template_content(in, any_data);
    if (!result) return {};
    RULE_SUCCESSD(in, pos, cll_template_content_typename, data);
}
Rule(cll_template_content_all) {
    std::vector<std::string> vals;
    auto pos = in;
    for (;; pos++) {
        if (*pos == '<') {
            vals.push_back("");
        } else {
            vals[vals.size() - 1] += *pos;
        }
    }
}
Rule(cll_template, cll_template_content_param1_t content) {
    auto pos = in;
    if (*pos != '<')
        return {};
    auto content_res = content();
    if (!content.res)
        return {};
    pos += content_res.token.length();
    std::vector<Token> data = { content_res.token };
    while(*pos == ',') {
        ++pos;
        content_res = content();
        if (!content_res.result)
            break;
        pos += content_res.token.length();
        // add data here
        data.push_back(content_res.token);
    }
    if (*pos != '>')
        return {};
    RULE_SUCCESSD(in, pos, cll_template, data);
}