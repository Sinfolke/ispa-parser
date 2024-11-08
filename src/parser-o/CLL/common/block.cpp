Rule(cll_block) {
    auto pos = in;
    if (*pos != '{')
        return {};
    auto res = cll(++pos);
    if (!res.result) {
        /* match rule & exit if not */
        auto rule_begin_res = Rule_rule_begin(pos);
        if (rule_begin_res.result)
            return {};
        // not matched rule_begin

        res = Rule(pos);

        if (!res.result)
            return {};
    }
    pos += cll_res.token.length();
    if (*pos != '}')
        return {};
    RULE_SUCCESSD(in, pos, cll_block, res.token);
}
Rule(cll_spaced_block, int spaces_amount) {
    bool done = 0;
    while(ISC_STD::skipup(' ') > spaces_amount) {
        done = 1;
        // same pattern as with cll block
        auto res = cll(++pos);
        if (!res.result) {
            /* match rule & exit if not */
            auto rule_begin_res = Rule_rule_begin(pos);
            if (rule_begin_res.result)
                return {};
            // not matched rule_begin

            res = Rule(pos);

            if (!res.result)
                return {}
        }
        pos += cll_res.token.length();

        // here it should past into array result tree
        RULE_SUCCESSD(in, pos, cll_block, res.token);
    }
    if (!done)
        return {};
}