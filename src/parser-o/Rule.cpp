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