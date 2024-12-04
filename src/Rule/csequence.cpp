#include <parser.h>
#include <parser_defs.h>

Rule(Rule_csequence) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '[')
        return {};
    pos++;
    bool _not = false;
    ISC_STD::skip_spaces(pos);
    if (*pos == '^') {
        _not = true;
        pos++;
    }
    std::vector<::Parser::Rule> dt;
    while(true) {
        ISC_STD::skip_spaces(pos);
        auto res = Rule_csequence_symbol(pos);
        if (!res.result) {
            res = Rule_csequence_diapason(pos);
            if (!res.result)
                break;
        }
        pos += res.token.length();
        dt.push_back(res.token);
    }
    ISC_STD::skip_spaces(pos);
    if (*pos!= ']')
        return {};
    pos++;
    std::unordered_map<const char*, std::any> data {
        { "not", _not },
        { "val", dt }
    };
    RULE_SUCCESSD(in, pos, Rule_csequence, data);
}

Rule(Rule_csequence_symbol)
{
    std::string data;
    auto pos = in;
    if (*in == '\\' || *in != ']')
    {
        data = *in;
        pos++;
    } else if (!strncmp(in, "\\]", 2))
    {
        data = *in;
        data += *in + 1;
        pos += 2;
    } else 
        return {};
    
    RULE_SUCCESSD(in, pos, Rule_csequence_symbol, data);

}
Rule(Rule_csequence_diapason) {
    auto symbol_res = Rule_csequence_symbol(in);
    if (!symbol_res.result)
        return {};
    
    auto pos = in + symbol_res.token.length();
    // NO SPACE

    if (*pos != '-')
        return {};
    
    // NOSPACE

    auto symbol2_res = Rule_csequence_symbol(pos);

    if (!symbol2_res.result)
        return {};
    
    std::vector<::Parser::Rule> data;
    data.push_back(symbol_res.token);
    data.push_back(symbol2_res.token);

    RULE_SUCCESSD(in, pos, Rule_csequence_symbol, data);
}