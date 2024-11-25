#include <parser/parser.h>
#include <parser/parser_defs.h>

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
Rule(Rule_csequence_diapason) {
    auto symbol_res = Rule_csequence_symbol(in);
    if (!symbol_res)
        return {};
    
    auto pos = in + symbol_res.token.length();
    // NO SPACE

    if (*pos != '-')
        return {};
    
    // NOSPACE

    auto symbol2_res = Rule_csequence_symbol(pos);

    if (!symbol2_res)
        return {};
    
    std::vector<Rule> data { symbol_res.token, symbol2_res.token };

    RULE_SUCCESSD(in, pos, Rule_csequence_symbol, data);
}