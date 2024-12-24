#include <parser.h>
#include <parser_defs.h>
Rule(cll_block) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '{') {
        printf("BRACE EXIT\n");
        return {};
    }
    pos++;
    ISC_STD::skip_spaces(pos);
    std::vector<::Parser::Rule> results;
    while(true) {
        ISC_STD::skip_spaces(pos);
        auto rule_begin_res = Rule_rule(pos);
        if (!rule_begin_res.result)
            break;
        pos += rule_begin_res.token.length();
        results.push_back(rule_begin_res.token);
    }

    ISC_STD::skip_spaces(pos);
    if (*pos != '}')
        return {};
    pos++;
    printf("matched block successfully, pos: %c, length: %ld\n", *pos, pos - in);
    RULE_SUCCESSD(in, pos, cll_block, results);
}
Rule(cll_spaced_block, int spaces_amount) {
    auto pos = in;
    std::vector<::Parser::Rule> results;
    while(ISC_STD::skip_spaces(pos) > spaces_amount) {
        // same pattern as with cll block
        auto res = Rule_rule(pos);
        if (!res.result)
            break;
        pos += res.token.length();
        results.push_back(res.token);
    }
    printf("matched block successfully\n");
    RULE_SUCCESSD(in, pos, cll_block, results);
}