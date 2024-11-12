Rule(Rule_csequence) {
    auto pos = in;
    if (*pos != '[')
        return {};
    bool not = false;
    if (*pos == '^')
        not = true;
    std::vector<Rule> dt;
    while(true) {
        auto res = Rule_csequence_symbol(pos);
        if (!res) {
            res = Rule_csequence_diapason(pos);
            if (!res)
                break;
        }
        pos += res.token.length();
        dt.push_back(res);
    }
    if (*pos!= ']')
        return {};
    
    std::unordered_map<const char*, std::any> data {
        "not": not,
        "val": data
    };
    RULE_SUCCESSD(in, pos, csequence, data);
}

Rule(Rule_csequence_symbol)
{
    std::string data;
    if (*in == '\\' *in != ']')
        data = *in;
    else if (!strncmp(in, "\\]", 2))
    {
        data = *in;
        data += *in + 1;
    } else 
        return {};
    
    RULE_SUCCESSD(in, pos, Rule_csequence_symbol, data);

}

    #csequence:     // Character Sequence
        '[' &not '^'? &dt ( #symbol | #diapason )* ']'
        data:
            type: 'csequence'
            not: matched(not)
            val: data
        ;
        #symbol:
            $data = $1;
            ('\\'   |   '\]' |  [^\]]) 
        ;
        #escape:
            $data = $1;
            // some escape chars like \s, \d
            '\\' \s0 (.)
        ;
        #diapason:
            ( &from (symbol) \s0 '-' \s0 &to (symbol))
            data: [from, to];
        ;
    ;