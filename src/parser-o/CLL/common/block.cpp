Rule(cll_block) {
    auto pos = in;
    if (*pos != '{')
        return {};
    auto res = cll(++pos);
    if (!res.result) {
        /* match rule & exit if not */
    }
    pos += cll_res.token.length();
    if (*pos != '}')
        return {};
    RULE_SUCCESSD(in, pos, cll_block, block_res.token);
}