#include <parser.h>
#include <parser_defs.h>
Rule(Rule_rule) {
    auto pos = in;
    auto res = Rule_group(pos);
    bool is_cll=false, is_id=false, is_nested=false;
    ISC_STD::skipup(pos, " ");
    if (!res.result) {
        res = Rule_csequence(pos);
        if (!res.result) {
            res = string(pos);
            if (!res.result) {
                res = Rule_hex(pos);
                if (!res.result) {
                    res = Rule_bin(pos);
                    if (!res.result) {
                        is_id = true;
                        if (*pos == '#') {
                            is_nested = true;
                        }
                        pos++;
                        ISC_STD::skipup(pos, " ");
                        res = id(pos);
                        if (!res.result) {
                            is_id=false;
                            is_nested=false;
                            is_cll=true;
                            res = cll(pos);
                            if (!res.result)
                                return {};
                            
                        }
                        
                    }
                }
            }
        }
    }
    ISC_STD::skipup(pos, " ");
    auto qualifier_res = Rule_qualifier(pos);
    
    ::Parser::Rule qualifier;
    if (qualifier_res.result)
        qualifier = qualifier_res.token;

    std::unordered_map<const char*, std::any> val {
        { "is_id", is_id },
        { "is_nested", is_nested },
        { "is_cll", is_cll },
        { "val", res.token },
        { "qualifier", qualifier }
    };
    RULE_SUCCESSD(in, pos, Rule_rule, val);
    
}