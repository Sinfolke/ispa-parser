#include <parser.h>
#include <parser_defs.h>
Rule(Rule_rule) {
    auto pos = in;
    auto res = Rule_group(pos);
    bool is_cll=false, is_id=false, is_nested=false;
    if (!res) {
        res = Rule_csequence(pos);
        if (!res) {
            res = string(pos);
            if (!res) {
                res = Rule_hex(pos);
                if (!res) {
                    res = Rule_bin(pos);
                    if (!res) {
                        is_id = true;
                        if (*pos == '#') {
                            is_nested = true;
                        }
                        res = Rule_id(pos);
                        if (!res) {
                            id_id=false;
                            is_nested=false;
                            is_cll=true;
                            res = cll(pos);
                            if (!cll)
                                return {};
                            
                        }
                        
                    }
                }
            }
        }
    }
    auto qualifier_res = Rule_qualifier(pos);
    Rule qualifier;
    if (qualifier_res.result)
        qualifier = qualifier_res.token;

    std::unordered_map<const char*, std::string> val {
        { "is_id", is_id },
        { "is_nested", is_nested },
        { "is_cll", is_cll },
        { "val", res.token },
        { "qualifier", qualifier }
    };
    RULE_SUCCESSD(in, pos, Rule_rule, data);
    
}