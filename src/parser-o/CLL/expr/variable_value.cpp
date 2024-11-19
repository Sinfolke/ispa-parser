#include <parser.h>
#include <parser_defs.h>

Rule(expr_variable_value) {
    auto pos = in;
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    
    auto res = _operator(pos);
    if (!res.result) {
        res = assignment_operator(pos);
        if (!res.result)
            goto no;
    }
    // found
    auto assignment_val_res = assingment_val(pos);
    if (!assignment_val_res.result)
        goto no;
    no:
}