Rule(Rule) {
    auto pos = in;
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    Rule_result Rule_rule_res;
    while ((Rule_rule_res = Rule_rule(pos)).result) {
        // do something
    }

    Rule_result Rule_nested_rule_res;
    while ((Rule_nested_rule_res = Rule_rule(pos)).result) {
        // do something
    }
    auto strict_end_result = STRICT_END();
}
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
//#nested_rule
Rule(Rule_nested_rule) {
    auto pos = in;
    while(*pos == '\n' || *pos == '\r')
        pos ++;
    if (in == pos)
        return {};
    
    if (*pos != '#')
        return {};
    pos++;

    // NO SPACE!!
    auto Rule_res = Rule(pos);

    if (!Rule_res.result)
        return {};
    
    RULE_SUCCESSD(in, pos, Rule_nested_rule, Rule_res.token);
}
//#hex
Rule(Rule_hex) {
    if (!(*in == '0' && *(in+1) == 'x')) {
        return {};
    }
    auto begin = in + 2;
    auto pos = begin;
    while (isdigit(*pos) || isupper(*pos) || islower(*pos)) {
        ++pos;
    }
    if (begin == pos) 
        return {};
    
    RULE_SUCCESSDD(in, pos, Rule_hex, std::string_view(begin, pos - begin));
    return {};

}
//#bin
Rule(Rule_bin) {
    if (!(*in == '0' && *(in+1) == 'b')) {
        return {};
    }
    auto begin = in + 2;
    auto pos = begin;
    while (*pos == '0' || *pos == '1') {
        ++pos;
    }
    if (begin == pos) 
        return {};
    
    RULE_SUCCESSDD(in, pos, Rule_hex, std::string_view(begin, pos - begin));
    return {};

}