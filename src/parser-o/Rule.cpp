#include <parser.h>
#include <parser_defs.h>
Rule(Rule) {
    auto pos = in;
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    std::vector<Rule> rule_results {};
    Rule_result Rule_rule_res;
    while ((Rule_rule_res = Rule_rule(pos)).result) {
        // do something
        rule_results.push_back(Rule_rule_res.token);
        pos += Rule_rule_res.token.length();
    }
    std::vector<Rule> nested_rule_results {};
    Rule_result Rule_nested_rule_res;
    while ((Rule_nested_rule_res = Rule_rule(pos)).result) {
        // do something
        nested_rule_results.push_back(Rule_nested_rule_res.token);
        pos += Rule_nested_rule_res.token.length();
    }
    auto strict_end_result = STRICT_END();

    auto id_res_data = TO(std::string, id_res.token.data);
    const char* kind = (id_res_data[0] >= 'A' && id_res_data[0] <= 'Z') ? "token" : "rule";
    std::unordered_map<const char*, std::any> data {
        { "name", id_res.token },
        { "kind", kind },
        { "rule", rule_results },
        { "nestedRules", nested_rule_results }
    };
}