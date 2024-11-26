export module parser.cll;

export import parser.cll.block;
export import parser.cll.operators;
export import parser.cll.template;
export import parser.cll.type;

export import parser.cll.if;
export import parser.cll.ternary;

export import parser.cll.compare;
export import parser.cll.expr;
export import parser.cll.logical;
export import parser.cll.not;
export import parser.cll.parenthesed;
export import parser.cll.variable_value;

export import parser.cll.function;

export import parser.cll.method;
export import parser.cll.var;

#include <parser_defs.h>
Rule(cll) {
    auto pos = in;
    if (*pos != '\n')
        return {};
    pos++;
    // skip spaces
    if (*pos != '$')
        return {};
    pos++;
    // skip spaces
    auto res = var(pos);
    if (!res) {
        res = cond(pos);
        if (!res) {
            res = expr;
            if (!res) {
                res = copiable_method_call(pos);
                if (!res)
                    return {};
            }
        }
    }
    pos += res.token.length();
    // skip spaces
    // end
    RULE_SUCCESSD(in, pos, cll, res.token);
}