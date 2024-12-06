#include <parser.h>
#include <parser_defs.h>

Rule(Rule_op) {
    auto pos = in;
    std::string value;
    ISC_STD::skip_spaces(pos);
    if (*pos == '|') {
        value = '|';
        pos++;
    } else if (strncmp(pos, "&|", 2)) {
        value = "&|";
        pos += 2;
    } else {
        return {};
    }
    RULE_SUCCESSD(in, pos, Rule_op, value);
}