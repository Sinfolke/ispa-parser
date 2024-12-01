#include <parser.h>
#include <parser_defs.h>
//#data_block
Rule(Rule_data_block) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto start = pos;
    while(*pos == '\n' || *pos == '\r')
        pos ++;
    if (start == pos)
        return {};
    
    ISC_STD::skip_spaces(pos);
    if (strncmp(pos, "data", 4))
        return {};
    pos += 4;
    ISC_STD::skip_spaces(pos);
    if (*pos!= ':')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto data = any_data(pos);
    if (!data.result) {
        data = Rule_data_block_inclosed_map(pos);
        if (!data.result)
            return {};
    }

    pos += data.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos!= ';')
        return {};

    RULE_SUCCESSD(in, pos, Rule_data_block, data.token);
}
// #data_block #inclosed_map
Rule(Rule_data_block_inclosed_map) {
    auto pos = in;
    std::vector<::Parser::Rule> keys;
    while (true) {
        ISC_STD::skip_spaces(pos);
        auto key_res = Rule_data_block_key(pos);
        if (!key_res.result)
            break;
        pos += key_res.token.length();
        keys.push_back(key_res.token);
    }
    if (pos == in)
        return {};
    RULE_SUCCESSD(in, pos, Rule_data_block_inclosed_map, keys);

}
// #data_block #key
Rule(Rule_data_block_key) {
    auto pos = in;
    while ( *pos == '\n' || *pos == '\r')
        pos++;
    if (in == pos)
        return {};
    
    std::string name;
    auto id_res = id(pos);

    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    //name = TO(std::string, id.token.data);
    if (*pos != ':')
        return {};
    
    auto any_data_res = any_data(pos);

    if (!any_data_res.result)
        return {};
    
    std::unordered_map<std::string, std::any> data {
        { "name", id_res.token },
        { "val", any_data_res.token }
    };
    RULE_SUCCESSD(in, pos, Rule_data_block_key, data);
}