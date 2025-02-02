#include <parser.h>
#include <internal_types.h>
#include <token_management.h>
#include <corelib.h>

void normalizeHelper(arr_t<Parser::Rule> &rules) {
    arr_t<Parser::Rule> ops;
    Parser::Rule prev_rule;
    
    bool in_op = false;
    int begin = -1;

    for (int i = 0; i < rules.size(); i++) {
        auto el = rules[i];
        auto rule_data = std::any_cast<obj_t>(el.data);
        auto rule = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));

        if (rule.name == Parser::Rules::Rule_group) {
            // Recursively normalize sub-rules
            auto group_rules = rule.as<obj_t>();
            auto group_val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(group_rules, "val"));
            normalizeHelper(group_val);
            corelib::map::set(group_rules, "val", std::any(group_val));
            rule.data = group_rules;
            corelib::map::set(rule_data, "val", std::any(rule));
            rules[i].data = rule_data;
        }

        if (rule.name == Parser::Rules::Rule_op) {
            if (!in_op) {
                in_op = true;
                ops.clear();
                ops.push_back(prev_rule);
                begin = i - 1;
            }
        } else {
            if (in_op) {
                // Add the current rule to the operator sequence
                ops.push_back(rule);
                
                // Create a new combined rule for the operator sequence
                auto new_rule = Tokens::make_rule(Parser::Rules::Rule_op, ops);
                obj_t new_rule_data = {
                    { "val", new_rule },
                    { "qualifier", Parser::Rule() }
                };
                auto new_token = Tokens::make_rule(Parser::Rules::Rule_rule, new_rule_data);

                // Replace the operator sequence in rules
                rules.erase(rules.begin() + begin, rules.begin() + i + 1);
                rules.insert(rules.begin() + begin, new_token);
                cpuf::printf("ops size: %$\n", ops.size());
                i = begin;
                in_op = false;
                ops.clear();
            }
        }

        prev_rule = rule;
    }

    // Handle remaining operator sequences at the end
    if (in_op && !ops.empty()) {
        auto new_rule = Tokens::make_rule(Parser::Rules::Rule_op, ops);
        obj_t new_rule_data = {
            { "val", new_rule },
            { "qualifier", Parser::Rule() }
        };
        auto new_token = Tokens::make_rule(Parser::Rules::Rule_rule, new_rule_data);
        rules.erase(rules.begin() + begin, rules.end());
        rules.push_back(new_token);
        cpuf::printf("ops size: %$\n", ops.size());
    }
}

void normalizeRule(Parser::Rule &member) {
    auto data = std::any_cast<obj_t>(member.data);
    auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));

    normalizeHelper(rules);

    corelib::map::set(data, "rule", std::any(rules));
    member.data = data;
}

void normalizeTree(Parser::Tree &tree) {
    for (auto &member : tree) {
        if (member.name == Parser::Rules::Rule) {
            normalizeRule(member);
        }
    }
}