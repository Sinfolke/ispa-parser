#include <parser.h>
#include <internal_types.h>
#include <corelib.h>
void normalizeRule(Parser::Rule &member) {
    auto data = std::any_cast<obj_t>(member.data);
    auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
    
    for (auto &rule_rule : rules) {
        auto rule_rule_data = std::any_cast<obj_t>(rule_rule.data);
        auto rule = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(rule_rule_data, "val"));
        auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_rule_data, "qualifier"));

        for (auto el : rule) {
            
        }
    }
}

void normalizeTree(Parser::Tree &tree) {
    for (auto &member : tree) {
        if (member.name == Parser::Rules::Rule) {
            normalizeRule(member);
        }
    }
}