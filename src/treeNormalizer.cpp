#include <parser.h>
#include <internal_types.h>
#include <token_management.h>
#include <corelib.h>
#include <treeNormalizer.h>

void normalizeHelper(arr_t<Parser::Rule> &rules, arr_t<std::string> fullname, arr_t<std::pair<std::string, arr_t<std::string>>> &nested_rule_names) {
    arr_t<Parser::Rule> ops;
    Parser::Rule prev_rule;
    bool in_op = false, prev_op = false;
    arr_t<Parser::Rule>::iterator begin;
    bool assign_back = false;
    for (auto it = rules.begin(); it != rules.end(); it++) {
        auto el = *it;
        auto rule_data = std::any_cast<obj_t>(el.data);
        auto rule = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));

        if (rule.name == Parser::Rules::Rule_group) {
            // Recursively normalize sub-rules
            auto group_rules = rule.as<obj_t>();
            auto group_val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(group_rules, "val"));
            normalizeHelper(group_val, fullname, nested_rule_names);
            corelib::map::set(group_rules, "val", std::any(group_val));
            rule.data = group_rules;
            assign_back = true;
        } else if (rule.name == Parser::Rules::cll) {
            auto data = rule.as<Parser::Rule>();
            if (data.name == Parser::Rules::cll_if || data.name == Parser::Rules::loop_while) {
                auto dt = data.as<obj_t>();
                auto block_rule = std::any_cast<Parser::Rule>(corelib::map::get(dt, "block"));
                auto block = block_rule.as<arr_t<Parser::Rule>>();
                normalizeHelper(block, fullname, nested_rule_names);
                block_rule.data = std::any(block);
                corelib::map::set(dt, "block", std::any(block_rule));
                data.data = std::any(dt);
                rule.data = data;
                assign_back = true;
            }
        } else if (rule.name == Parser::Rules::Rule_other && rule.data.type() != typeid(rule_other)) {
            auto data = std::any_cast<obj_t>(rule.data);
            auto is_nested = std::any_cast<bool>(corelib::map::get(data, "is_nested"));
            auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nested_name"));

            arr_t<std::string> rule_name;
            // if (is_nested)
            //     rule_name.assign(fullname.begin(), fullname.end());
            // rule_name.push_back(std::any_cast<std::string>(name.data));
            // for (auto &nested : nested_rule_names)
            //     rule_name.push_back(std::any_cast<std::string>(nested.data));
            
            auto res = std::find_if(nested_rule_names.begin(), nested_rule_names.end(), [&name](std::pair<std::string, arr_t<std::string>> &el) {
                return el.first == std::any_cast<std::string>(name.data);
            });
            if (res != nested_rule_names.end()) {
                rule_name = res->second;
            } else {
                if (is_nested) {
                    rule_name.assign(fullname.begin(), fullname.end());
                }
                rule_name.push_back(std::any_cast<std::string>(name.data));
            }
            for (auto &nested : nested_rules) {
                rule_name.push_back(std::any_cast<std::string>(nested.data));
            }
            rule.data = rule_other {std::any_cast<std::string>(name.data), rule_name, false };
            assign_back = true;
        }

        if (assign_back) {
            corelib::map::set(rule_data, "val", std::any(rule));
            it->data = rule_data;
            assign_back = false;
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
void getNestedNames(arr_t<Parser::Rule> &nested_rules, arr_t<std::pair<std::string, arr_t<std::string>>> &nested_rule_names, arr_t<std::string> &fullname) {
    for (auto &el : nested_rules) {
        auto data = std::any_cast<Parser::Rule>(el.data);
        auto val = std::any_cast<obj_t>(data.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(val, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        fullname.push_back(name_str);
        nested_rule_names.push_back({name_str, fullname});
        fullname.pop_back();
    }
}
void normalizeRule(Parser::Rule &member, arr_t<std::string> &fullname, arr_t<std::pair<std::string, arr_t<std::string>>> &nested_rule_names) {
    obj_t data;
    if (!fullname.empty()) {
        data = std::any_cast<obj_t>(std::any_cast<Parser::Rule>(member.data).data);
    } else {
        data = std::any_cast<obj_t>(member.data);
    }
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    auto name_str = std::any_cast<std::string>(name.data);
    auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
    auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));

    fullname.push_back(name_str);
    getNestedNames(nested_rules, nested_rule_names, fullname);
    normalizeHelper(rules, fullname, nested_rule_names);
    normalizeTree(nested_rules, fullname, nested_rule_names);
    fullname.pop_back();
    corelib::map::set(data, "rule", std::any(rules));
    corelib::map::set(data, "nestedRules", std::any(nested_rules));
    member.data = data;
    if (!fullname.empty())
        member.name = Parser::Rules::Rule;
}

void normalizeTree(Parser::Tree &tree, arr_t<std::string> &fullname, arr_t<std::pair<std::string, arr_t<std::string>>> &nested_rule_names) {
    for (auto &member : tree) {
        if (fullname.empty())
            nested_rule_names.clear();
        if (member.name == Parser::Rules::Rule || !fullname.empty()) {
            normalizeRule(member, fullname, nested_rule_names);
        }
    }
}