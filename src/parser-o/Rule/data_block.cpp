#include <parser/parser.h>
#include <parser/parser_defs.h>
//#data_block
Rule(data_block) {
    auto pos = in;
    while(*pos == '\n' || *pos == '\r')
        pos ++;
    if (in == pos)
        return {};
    
    
    if (strncmp(pos, "data", 4))
        return {};
    pos += 4;

    if (*pos!= ':')
        return {};
    pos++;

    auto data = ANY_DATA(pos);
    if (!data.result) {
        data = rule_data_block_inclosed_map(pos);
        if (!data.result)
            return {};
    }

    pos += data.token.length();

    if (*pos!= ';')
        return {};

    RULE_SUCCESSD(in, pos, data_block, data_res.token);
}
// #data_block #inclosed_map
Rule(Rule_data_block_inclosed_map) {
    auto pos = in;
    std::vector<Rule> keys;
    while (true) {
        auto key_res = rule_data_block_key(pos);
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
        { "val", "" any_data_res.token }
    };
    RULE_SUCCESSD(in, pos, Rule_data_block_key, data);
}