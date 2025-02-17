#include <parser.h>
#include <parser_defs.h>
std::string RulesToString(::Parser::Rules);
//#data_block
Rule(Rule_data_block) {
    auto pos = in;
    // ISC_STD::skip_spaces(pos);
    // auto start = pos;
    // while(*pos == '\n' || *pos == '\r')
    //     pos++;
    // if (start == pos)
    //     return {};
    ISC_STD::skip_spaces(pos);
    if (strncmp(pos, "data", 4)) {
        
        return {};
    }
    pos += 4;
    ISC_STD::skip_spaces(pos);
    if (*pos != ':') {
        
        return {};
    }
    pos++;
    ISC_STD::skip_spaces(pos);
    auto data = Rule_data_block_inclosed_map(pos);
    if (!data.result) {
        data = any_data(pos);
        if (!data.result)
            return {};
    }
    pos += data.token.length();
    ISC_STD::skip_spaces(pos);
    auto strict_end_res = strict_end(pos);
    if (!strict_end_res.result) {
        return {};
    }
    pos += strict_end_res.token.length();
    RULE_SUCCESSD(in, pos, Rule_data_block, data.token);
}
// #data_block #inclosed_map
Rule(Rule_data_block_inclosed_map) {
    auto pos = in;
    int matched=0;
    std::vector<::Parser::Rule> keys;
    while (true) {
        ISC_STD::skip_spaces(pos);
        auto key_res = Rule_data_block_key(pos);
        if (!key_res.result)
            break;
        pos += key_res.token.length();
        keys.push_back(key_res.token);
        matched=1;
    }
    if (!matched)
        return {};
    RULE_SUCCESSD(in, pos, Rule_data_block_inclosed_map, keys);

}
// #data_block #key
Rule(Rule_data_block_key) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    // while ( *pos == '\n' || *pos == '\r')
    //     pos++;
    // if (in == pos)
    //     return {};
    auto id_res = id(pos);
    
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != ':')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto any_data_res = cll_ternary(pos);

    if (!any_data_res.result) {
        any_data_res = expr(pos);
        if (!any_data_res.result)
            return {};
    }
    
    pos += any_data_res.token.length();
    // auto strict_end_res = strict_end(pos);
    // if (!strict_end_res.result)
    //     return {};
    // pos += strict_end_res.token.length();
    std::unordered_map<const char*, std::any> data {
        { "name", id_res.token },
        { "val", any_data_res.token }
    };
    RULE_SUCCESSD(in, pos, Rule_data_block_key, data);
}