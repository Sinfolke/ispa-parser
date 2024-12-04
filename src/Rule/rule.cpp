#include <parser.h>
#include <parser_defs.h>
Rule(Rule_rule) {
    auto pos = in;
    bool is_cll=false, is_id=false, is_nested=false;
    ISC_STD::skip_spaces(pos);
    printf("Rule_group\n");
    auto res = Rule_group(pos);
    if (!res.result) {
        printf("Rule_csequence\n");
        res = Rule_csequence(pos);
        if (!res.result) {
            printf("Rule_string\n");
            res = string(pos);
            if (!res.result) {
                printf("Rule_hex\n");
                res = Rule_hex(pos);
                if (!res.result) {
                    printf("Rule_bin\n");
                    res = Rule_bin(pos);
                    if (!res.result) {
                        is_id = true;
                        if (*pos == '#') {
                            is_nested = true;
                        }
                        pos++;
                        ISC_STD::skip_spaces(pos);
                        res = id(pos);
                        if (!res.result) {
                            is_id=false;
                            is_nested=false;
                            is_cll=true;
                            printf("Rule_cll\n");
                            res = cll(pos);
                            if (!res.result)
                                return {};
                            else
                                printf("Matched cll\n");
                        }
                        
                    }
                }
            }
        }
    }
    pos += res.token.length();
    ISC_STD::skip_spaces(pos);
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
    printf("leaving Rule_rule\n");
    RULE_SUCCESSD(in, pos, Rule_rule, val);
    
}