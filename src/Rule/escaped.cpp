#include <parser.h>
#include <parser_defs.h>
Rule(Rule_escaped) {
    auto pos = in;
    if (*pos != '\\')
        return {};
    pos++;
    std::string val(*pos, 1);
    pos++;
    auto num = number(pos);
    if (num.result) {
        pos += num.token.length();
    }
    std::unordered_map<const char*, std::any> data {
        { "c", val },
        { "num", num.token }
    };
    RULE_SUCCESSD(in, pos, Rule_escaped, data);
} 