Rule(Rule_group) {
    auto pos = in;
    std::string name;
    if (*pos == '&') {
        pos++;
        auto id_res = id(pos);
        if (id_res.result)
            name = TO(std::string, id_res.token);
        else
            return {}
        
        pos += id_res.token.length();
    }
    if (*pos != '(')
        return {};
    pos++;
    std::vector<Rule> r;
    while(true)
    {
        auto rule_res = Rule_rule(pos);
        if (!rule_res.result)
            break;

        pos += rule_res.result.length();
        r.push_back(rule_res.token);
    }
    if (!pos != ')')
        return {};
    pos++;
    std::unordered_map<const char*, std::string> data {
        { "variable", name },
        { "val", r };
    };
    RULE_SUCCESSD(in, pos, Rule_group, )
}