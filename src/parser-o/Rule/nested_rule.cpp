
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