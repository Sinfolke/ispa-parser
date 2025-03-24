#include <parser.h>
#include <parser_defs.h>
Rule(cll_block) {
    auto pos = in;
    ISPA_STD::skip_spaces(pos);
    if (*pos != '{') {
        
        return {};
    }
    pos++;
    ISPA_STD::skip_spaces(pos);
    std::vector<::Parser::Rule> results;
    while(true) {
        ISPA_STD::skip_spaces(pos);
        auto rule_begin_res = Rule_rule(pos);
        if (!rule_begin_res.result)
            break;
        pos += rule_begin_res.token.length();
        results.push_back(rule_begin_res.token);
    }

    ISPA_STD::skip_spaces(pos);
    if (*pos != '}')
        return {};
    pos++;
    
    RULE_SUCCESSD(in, pos, cll_block, results);
}
Rule(cll_spaced_block, int spaces_amount) {
    auto pos = in;
    std::vector<::Parser::Rule> results;
    while(ISPA_STD::skip_spaces(pos) > spaces_amount) {
        // same pattern as with cll block
        auto res = Rule_rule(pos);
        if (!res.result)
            break;
        pos += res.token.length();
        results.push_back(res.token);
    }
    
    RULE_SUCCESSD(in, pos, cll_spaced_block, results);
}