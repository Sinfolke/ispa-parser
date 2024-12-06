#include <parser.h>
#include <parser_defs.h>
Rule(Rule_rule) {
    auto pos = in;
    bool is_cll=false, is_id=false, is_nested=false, with_qualifier = true;
    ISC_STD::skip_spaces(pos);
    printf("Rule_group -> ");
    auto res = Rule_group(pos);
    if (!res.result) {
        printf("Rule_csequence -> ");
        res = Rule_csequence(pos);
        if (!res.result) {
            printf("Rule_string -> ");
            res = string(pos);
            if (!res.result) {
                printf("accessor -> ");
                res = accessor(pos);
                if (!res.result) {
                    printf("Rule_hex -> ");
                    res = Rule_hex(pos);
                    if (!res.result) {
                        printf("Rule_bin -> ");
                        res = Rule_bin(pos);
                        if (!res.result) {
                            is_id = true;
                            printf("nested_rule_call -> ");
                            if (*pos == '#') {
                                is_nested = true;
                            }
                            pos++;
                            ISC_STD::skip_spaces(pos);
                            res = id(pos);
                            if (!res.result) {
                                with_qualifier = false;
                                res = Rule_op(pos);
                                if (!res.result) {
                                    is_id=false;
                                    is_nested=false;
                                    is_cll=true;
                                    with_qualifier=false;
                                    printf("Rule_cll -> ");
                                    res = cll(pos);
                                    if (!res.result)
                                        return {};
                                    else
                                        printf("Matched cll");
                                }

                            }
                            
                        }
                    }
                }
            }
        }
    }
    printf("\n");
    pos += res.token.length();
    ISC_STD::skip_spaces(pos);
    ::Parser::Rule_result qualifier_res;
    if (with_qualifier) {
        qualifier_res = Rule_qualifier(pos);        
        if (qualifier_res.result) {
            pos += qualifier_res.token.length();
        }
    }
    std::unordered_map<const char*, std::any> val {
        { "is_id", is_id },
        { "is_nested", is_nested },
        { "is_cll", is_cll },
        { "val", res.token },
        { "qualifier", qualifier_res.token }
    };
    RULE_SUCCESSD(in, pos, Rule_rule, val);
    
}