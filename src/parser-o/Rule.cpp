#include <parser.h>
#include <parser_defs.h>
Rule(Rule) {
    auto pos = in;
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    Rule_result Rule_rule_res;
    while ((Rule_rule_res = Rule_rule(pos)).result) {
        // do something
    }

    Rule_result Rule_nested_rule_res;
    while ((Rule_nested_rule_res = Rule_rule(pos)).result) {
        // do something
    }
    auto strict_end_result = STRICT_END();
}