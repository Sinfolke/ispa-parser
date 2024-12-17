#include <parser.h>
#include <parser_defs.h>
std::string RulesToString(::Parser::Rules);
Rule(expr) {
    auto pos = in;
    bool matched_grp = false;
    ISC_STD::skip_spaces(pos);
    if (*pos == '(') {
        pos++;
        matched_grp = true;
    }

    std::vector<::Parser::Rule> data;
    ISC_STD::skip_spaces(pos);
    printf("Enter expr\n");
    printf("expr_compare -> ");
    auto res = expr_compare(pos);
    if (!res.result) {
        printf("expr cll_function_call -> ");
        res = cll_function_call(pos);
        if (!res.result) {
            printf("expr method_call -> ");
            res = method_call(pos);
            if (!res.result) {
                printf("expr any_data -> ");
                res = any_data(pos);
                if (!res.result) {
                    printf("expr parenthesed -> ");
                    res = expr_parenthesed(pos);
                    if (!res.result) {
                        int count = 0;
                        printf("expr_logical");
                        while((res = expr_logical(pos)).result) {
                            data.push_back(res.token);
                            pos += res.token.length();
                            count++;
                        }
                        if (!count)
                            return {};
                    }
                }
            }
        }

    }    
    pos += res.token.length();
    printf("\n, expr length: ");
    if (data.empty()) {
        data.push_back(res.token);
    }
    ISC_STD::skip_spaces(pos);
    if (*pos == ')') {
        if (matched_grp)
            pos++;
        else
            return {};
    }
    printf("matched expr successfully, name: %s, length: %ld\n", RulesToString(res.token.name).c_str(), pos - in);
    RULE_SUCCESSD(in, pos, expr, data);
}
Rule(expr_no_compare) {
    auto pos = in;
    bool matched_grp = false;
    ISC_STD::skip_spaces(pos);
    if (*pos == '(') {
        matched_grp = true;
        pos++;
    }
    std::vector<::Parser::Rule> data;
    ISC_STD::skip_spaces(pos);
    printf("Enter expr\n");
    printf("expr cll_function_call -> ");
    auto res = cll_function_call(pos);
    if (!res.result) {
        printf("expr method_call -> ");
        res = method_call(pos);
        if (!res.result) {
            printf("expr any_data -> ");
            res = any_data(pos);
            if (!res.result) {
                printf("expr parenthesed -> ");
                res = expr_parenthesed(pos);
                if (!res.result) {
                    int count = 0;
                    printf("expr_logical");
                    while((res = expr_logical(pos)).result) {
                        data.push_back(res.token);
                        pos += res.token.length();
                        count++;
                    }
                    if (!count)
                        return {};
                }
            }
        }
    }

    pos += res.token.length();
    printf("\n, expr length: ");
    if (data.empty()) {
        data.push_back(res.token);
    }
    ISC_STD::skip_spaces(pos);
    if (*pos == ')') {
        if (matched_grp)
            pos++;
        else
            return {};
    }
    printf("matched expr successfully, name: %s, length: %ld\n", RulesToString(res.token.name).c_str(), pos - in);
    RULE_SUCCESSD(in, pos, expr, data);
}
Rule(expr_no_logical) {
    auto pos = in;
    bool matched_grp = false;
    ISC_STD::skip_spaces(pos);
    if (*pos == '(') {
        pos++;
        matched_grp = true;
    }

    std::vector<::Parser::Rule> data;
    ISC_STD::skip_spaces(pos);
    printf("Enter expr\n");
    printf("expr_compare -> ");
    auto res = expr_compare(pos);
    if (!res.result) {
        printf("expr cll_function_call -> ");
        res = cll_function_call(pos);
        if (!res.result) {
            printf("expr method_call -> ");
            res = method_call(pos);
            if (!res.result) {
                printf("expr any_data -> ");
                res = any_data(pos);
                if (!res.result) {
                    printf("expr parenthesed -> ");
                    res = expr_parenthesed(pos);
                    if (!res.result) {
                        return {};
                    }
                }
            }
        }

    }    
    pos += res.token.length();
    printf("\n, expr length: ");
    if (data.empty()) {
        data.push_back(res.token);
    }
    ISC_STD::skip_spaces(pos);
    if (*pos == ')') {
        if (matched_grp)
            pos++;
        else
            return {};
    }
    printf("matched expr successfully, name: %s, length: %ld\n", RulesToString(res.token.name).c_str(), pos - in);
    RULE_SUCCESSD(in, pos, expr, data);
}