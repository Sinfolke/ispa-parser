#include <parser.h>
#include <internal_types.h>
#include <token_management.h>
#include <corelib.h>
#include <treeNormalizer.h>

void normalizeHelper(arr_t<Parser::Rule> &rules) {
    arr_t<Parser::Rule> ops;
    Parser::Rule prev_rule;
    bool in_op = false, prev_op = false;
    std::vector<Parser::Rule>::iterator begin;

    for (auto it = rules.begin(); it != rules.end(); it++) {
        auto el = *it;
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
            it->data = rule_data;
        } else if (rule.name == Parser::Rules::cll) {
            auto data = rule.as<Parser::Rule>();
            if (data.name == Parser::Rules::cll_if || data.name == Parser::Rules::loop_while) {
                auto dt = data.as<obj_t>();
                auto block_rule = std::any_cast<Parser::Rule>(corelib::map::get(dt, "block"));
                auto block = block_rule.as<arr_t<Parser::Rule>>();
                normalizeHelper(block);
                block_rule.data = std::any(block);
                corelib::map::set(dt, "block", std::any(block_rule));
                data.data = std::any(dt);
                rule.data = data;
                corelib::map::set(rule_data, "val", std::any(rule));
                it->data = rule_data;
            }
        }

        if (rule.name == Parser::Rules::Rule_op) {
            if (!in_op) {
                in_op = true;
                ops.push_back(Tokens::make_rule(Parser::Rules::Rule_rule, obj_t { {"val", prev_rule}, {"qualifier", Parser::Rule()} }));
                begin = it - 1;
            }
            prev_op = true;
        } else if (prev_op) {
            // Add the current rule to the operator sequence
            ops.push_back(Tokens::make_rule(Parser::Rules::Rule_rule, obj_t { {"val", rule}, {"qualifier", Parser::Rule()} }));
            prev_op = false;
        } else if (in_op) {
            // Create a new combined rule for the operator sequence
            auto new_rule = Tokens::make_rule(Parser::Rules::Rule_op, ops);
            obj_t new_rule_data = {
                { "val", new_rule },
                { "qualifier", Parser::Rule() }
            };
            auto new_token = Tokens::make_rule(Parser::Rules::Rule_rule, new_rule_data);

            // Replace the operator sequence in rules
            it = rules.erase(begin, it);
            it = rules.insert(it, new_token);
            in_op = false;
            prev_op = false;
            ops.clear();
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
        rules.erase(begin, rules.end());
        rules.push_back(new_token);
    }
}

void normalizeRule(Parser::Rule &member, bool is_nested) {
    obj_t data;
    if (is_nested) {
        data = std::any_cast<obj_t>(std::any_cast<Parser::Rule>(member.data).data);
    } else {
        data = std::any_cast<obj_t>(member.data);
    }
    auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
    auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));

    normalizeHelper(rules);
    normalizeTree(nested_rules, true);

    corelib::map::set(data, "rule", std::any(rules));
    corelib::map::set(data, "nestedRules", std::any(nested_rules));
    member.data = data;
    if (is_nested)
        member.name = Parser::Rules::Rule;
}

void normalizeTree(Parser::Tree &tree, bool is_nested) {
    for (auto &member : tree) {
        if (member.name == Parser::Rules::Rule || is_nested) {
            normalizeRule(member, is_nested);
        }
    }
}