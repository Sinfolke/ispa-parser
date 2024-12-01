#include <parser.h>
#include <parser_defs.h>
Rule(cll_block) {
    auto pos = in;
    if (*pos != '{')
        return {};
    ISC_STD::skip_spaces(pos);
    auto res = cll(++pos);
    if (!res.result) {
        /* match rule & exit if not */
        auto rule_begin_res = Rule_rule(pos);
        if (rule_begin_res.result)
            return {};
    }
    pos += res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != '}')
        return {};
    RULE_SUCCESSD(in, pos, cll_block, res.token);
}
Rule(cll_spaced_block, int spaces_amount) {
    auto pos = in;
    bool done = 0;
    std::vector<std::any> results;
    while(ISC_STD::skipup(pos, " ") > spaces_amount) {
        done = 1;
        // same pattern as with cll block
        auto res = cll(++pos);
        if (!res.result) {
            /* match rule & exit if not */
            auto rule_begin_res = Rule_rule(pos);
            if (rule_begin_res.result)
                return {};
        }
        pos += res.token.length();
        results.push_back(res.token);
    }
    if (!done)
        return {};
        
    // here it should past into array result tree
    RULE_SUCCESSD(in, pos, cll_block, results);
}