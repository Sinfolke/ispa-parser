#include <parser.h>
#include <parser_defs.h>

Rule(Rule_op) {
    auto pos = in;
    std::string value;
    ISC_STD::skipup(pos, " ");
    if (*pos == '|')
        value == '|';
    else if (*pos == '&' && *pos == '|')
        value = "&|";
    else
        return {};
    
    RULE_SUCCESSD(in, pos, Rule_op, value);
}