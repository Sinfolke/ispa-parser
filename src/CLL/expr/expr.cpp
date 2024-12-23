#include <parser.h>
#include <parser_defs.h>
#include <any>
std::string RulesToString(::Parser::Rules);

Rule(expr) {
    auto pos = in;
    auto negative_res = op_not(pos);
    if (negative_res.result) {
        pos += negative_res.token.length();
    }
    printf("expr -> logical -> ");
    auto res = expr_logical(pos);
    if (!res.result) {
        printf("comapre -> ");  
        res = expr_compare(pos);
        if (!res.result) {
            printf("arithmetic -> ");
            res = expr_arithmetic(pos);
            if (!res.result) {
                printf("group -> ");  
                res = expr_group(pos);
                if (!res.result) {
                    printf("copiable_method_call ->");
                    res = expr_copiable_method_call(pos);
                    if (!res.result) {
                        printf("cll_function_call -> ");
                        res = cll_function_call(pos);
                        if (!res.result) {
                            printf("any_data ");
                            res = any_data(pos);
                            if (!res.result) {
                                return {};
                            }
                        }
                    }
                }
            }
        }
    }
    pos += res.token.length();
    printf("\nexpr length: %zu, pos: %c\n", res.token.length(), *pos);
    RULE_SUCCESSD(in, pos, expr, res.token);
}
Rule(expr_for_arithmetic) {
    auto pos = in;
    auto res = expr_group(pos);
    if (!res.result) {
        res = method_call(pos);
        if (!res.result) {
            res = cll_function_call(pos);
            if (!res.result) {
                res = any_data(pos);
                if (!res.result)
                    return {};
            }
        }
    }
    pos += res.token.length();
    RULE_SUCCESSD(in, pos, expr, res.token);
}
Rule(expr_logical) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr_compare(pos);
    if (!expr_res.result) {
        expr_res = expr_arithmetic(pos);
        if (!expr_res.result) {
            expr_res = expr_for_arithmetic(pos);
            if (!expr_res.result) {
                return {};
            }
        }
    }

    pos += expr_res.token.length();
    ISC_STD::skip_spaces(pos);
    printf("LOGICAL MATCHING LOGICAL OP\n");
    auto logical_op_res = logical_op(pos);
    if (!logical_op_res.result) {
        printf("OP UNMATCHED\n");
        return {};
    }
    printf("op: %s\n", RulesToString(std::any_cast<::Parser::Rule>(logical_op_res.token.data).name).c_str());
    pos += logical_op_res.token.length();
    ISC_STD::skip_spaces(pos);
    printf("pos: %c\n", *pos);
    auto expr2_res = expr_compare(pos);
    if (!expr2_res.result) {
        expr2_res = expr_arithmetic(pos);
        if (!expr2_res.result) {
            expr2_res = expr_for_arithmetic(pos);
            if (!expr2_res.result) {
                return {};
            }
        }
    }
    pos += expr2_res.token.length();
    std::unordered_map<const char*, std::any> data {
        { "expr1", expr_res.token },
        { "op", logical_op_res.token },
        { "expr2", expr2_res.token }
    };
    RULE_SUCCESSD(in, pos, expr_logical, data);
}
Rule(expr_compare) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr_arithmetic(pos);
    if (!expr_res.result) {
        expr_res = expr_group(pos);
        if (!expr_res.result) {
            expr_res = expr_for_arithmetic(pos);
            if (!expr_res.result) {
                return {};
            }
        }
    }
    pos += expr_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto compare_op_res = compare_op(pos);
    if (!compare_op_res.result)
        return {};
    pos += compare_op_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto expr2_res = expr_arithmetic(pos);
    if (!expr2_res.result) {
        expr2_res = expr_group(pos);
        if (!expr2_res.result) {
            expr2_res = expr_for_arithmetic(pos);
            if (!expr2_res.result)
                return {};
        }
    }
    pos += expr2_res.token.length();
    std::unordered_map<const char*, std::any> data {
        { "expr1", expr_res.token },
        { "op", compare_op_res.token },
        { "expr2", expr2_res.token }
    };
    RULE_SUCCESSD(in, pos, expr_compare, data);
}
Rule(expr_arithmetic) {
    auto pos = in;
    std::vector<::Parser::Rule> operators;
    std::vector<::Parser::Rule> values;
    ISC_STD::skip_spaces(pos);
    auto expr_res = expr_for_arithmetic(pos);
    if (!expr_res.result)
        return {};
    pos += expr_res.token.length();
    while(true) {
        ISC_STD::skip_spaces(pos);
        auto arithmetic_op_res = op(pos);
        if (!arithmetic_op_res.result)
            break;
        pos += arithmetic_op_res.token.length();
        ISC_STD::skip_spaces(pos);
        auto expr_res2 = expr_for_arithmetic(pos);
        if (!expr_res2.result)
            break;
        pos += expr_res2.token.length();        
        operators.push_back(arithmetic_op_res.token);
        values.push_back(expr_res2.token);
    }
    if (operators.empty()) {
        return {};
    }
    std::unordered_map<const char*, std::any> data {
        { "first", expr_res.token },
        { "operators", operators },
        { "values", values }
    };
    RULE_SUCCESSD(in, pos, expr_arithmetic, data);
}
Rule(expr_group) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '(')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto expr_res = cll_ternary(pos);
    if (!expr_res.result) {
        expr_res = expr(pos);
        if (!expr_res.result)
            return {};
    }
    pos += expr_res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != ')')
        return {};
    pos++;
    RULE_SUCCESSD(in, pos, expr_group, expr_res.token);
}
Rule(expr_copiable_method_call) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '(')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto method_call_res = copiable_method_call(pos);
    if (!method_call_res.result)
        return {};
    pos += method_call_res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != ')')
        return {};
    pos++;
    RULE_SUCCESSD(in, pos, expr_copiable_method_call, method_call_res.token);
}