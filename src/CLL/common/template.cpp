#include <parser.h>
#include <parser_defs.h>
Rule(cll_template_typename) {
    // Inline cll_template_content logic
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto p1_1_res = cll_type(in); // Replace with the appropriate function
    if (!p1_1_res.result)
        return {};
    pos += p1_1_res.token.length();
    std::vector<std::any> cll_p1_seq;
    while (*pos == ',') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto p1_2_res = cll_type(pos);
        if (!p1_2_res.result)
            return {};
        pos += p1_2_res.token.length();
        cll_p1_seq.push_back(p1_2_res.token);
    }
    std::vector<std::any> data = { p1_1_res.token, cll_p1_seq };
    RULE_SUCCESSD(in, pos, cll_template_typename, data);
}

Rule(cll_template_int) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto p1_1_res = number(in); // Inline content logic for number
    if (!p1_1_res.result)
        return {};
    pos += p1_1_res.token.length();
    std::vector<std::any> cll_p1_seq;
    while (*pos == ',') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto p1_2_res = number(pos);
        if (!p1_2_res.result)
            return {};
        pos += p1_2_res.token.length();
        cll_p1_seq.push_back(p1_2_res.token);
    }
    std::vector<std::any> data = { p1_1_res.token, cll_p1_seq };
    RULE_SUCCESSD(in, pos, cll_template_int, data);
}

Rule(cll_template_bool) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto p1_1_res = boolean(in); // Inline content logic for boolean
    if (!p1_1_res.result)
        return {};
    pos += p1_1_res.token.length();
    std::vector<std::any> cll_p1_seq;
    while (*pos == ',') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto p1_2_res = boolean(pos);
        if (!p1_2_res.result)
            return {};
        pos += p1_2_res.token.length();
        cll_p1_seq.push_back(p1_2_res.token);
    }
    std::vector<std::any> data = { p1_1_res.token, cll_p1_seq };
    RULE_SUCCESSD(in, pos, cll_template_bool, data);
}

Rule(cll_template_str) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto p1_1_res = string(in); // Inline content logic for string
    if (!p1_1_res.result)
        return {};
    pos += p1_1_res.token.length();
    std::vector<std::any> cll_p1_seq;
    while (*pos == ',') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto p1_2_res = string(pos);
        if (!p1_2_res.result)
            return {};
        pos += p1_2_res.token.length();
        cll_p1_seq.push_back(p1_2_res.token);
    }
    std::vector<std::any> data = { p1_1_res.token, cll_p1_seq };
    RULE_SUCCESSD(in, pos, cll_template_str, data);
}

Rule(cll_template_arr) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto p1_1_res = array(in); // Inline content logic for array
    if (!p1_1_res.result)
        return {};
    pos += p1_1_res.token.length();
    std::vector<std::any> cll_p1_seq;
    while (*pos == ',') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto p1_2_res = array(pos);
        if (!p1_2_res.result)
            return {};
        pos += p1_2_res.token.length();
        cll_p1_seq.push_back(p1_2_res.token);
    }
    std::vector<std::any> data = { p1_1_res.token, cll_p1_seq };
    RULE_SUCCESSD(in, pos, cll_template_arr, data);
}

Rule(cll_template_obj) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto p1_1_res = object(in); // Inline content logic for object
    if (!p1_1_res.result)
        return {};
    pos += p1_1_res.token.length();
    std::vector<std::any> cll_p1_seq;
    while (*pos == ',') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto p1_2_res = object(pos);
        if (!p1_2_res.result)
            return {};
        pos += p1_2_res.token.length();
        cll_p1_seq.push_back(p1_2_res.token);
    }
    std::vector<std::any> data = { p1_1_res.token, cll_p1_seq };
    RULE_SUCCESSD(in, pos, cll_template_obj, data);
}

Rule(cll_template_any_data) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto p1_1_res = any_data(in); // Inline content logic for any_data
    if (!p1_1_res.result)
        return {};
    pos += p1_1_res.token.length();
    std::vector<std::any> cll_p1_seq;
    while (*pos == ',') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto p1_2_res = any_data(pos);
        if (!p1_2_res.result)
            return {};
        pos += p1_2_res.token.length();
        cll_p1_seq.push_back(p1_2_res.token);
    }
    std::vector<std::any> data = { p1_1_res.token, cll_p1_seq };
    RULE_SUCCESSD(in, pos, cll_template_any_data, data);
}

// Rule(cll_template, cll_template_content_param1_t content) {
//     auto pos = in;
//     ISC_STD::skip_spaces(pos);
//     if (*pos != '<')
//         return {};
//     pos++;
//     ISC_STD::skip_spaces(pos);
//     auto content_res = content(pos);
//     if (!content_res.result)
//         return {};
//     pos += content_res.token.length();
//     std::vector<std::any> data;
//     data.push_back(content_res.token);
//     while(*pos == ',') {
//         ++pos;
//         ISC_STD::skip_spaces(pos);
//         content_res = content(pos);
//         if (!content_res.result)
//             break;
//         pos += content_res.token.length();
//         // add data here
//         data.push_back(content_res.token);
//         ISC_STD::skip_spaces(pos);
//     }
//     ISC_STD::skip_spaces(pos);
//     if (*pos != '>')
//         return {};
//     RULE_SUCCESSD(in, pos, cll_template, data);
// }