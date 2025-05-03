#include <Parser.h>
#include <internal_types.h>
#include <corelib.h>
#include <internal_types.h>
#include <corelib.h>
#include <algorithm>
#include <tree.h>
void Tree::normalizeHelper(Parser::arr_t<Parser::Rule> &rules, std::vector<std::string> fullname, std::vector<std::vector<std::string>> &nested_rule_names) {
    std::vector<Parser::Rule> ops;
    Parser::Rule prev_rule;
    bool in_op = false, prev_op = false;
    Parser::arr_t<Parser::Rule>::iterator begin;
    for (auto it = rules.begin(); it != rules.end(); it++) {
        auto &el = *it;
        auto &rule = Parser::get::Rule_rule(el);
        if (rule.val.type() == typeid(Parser::Rule)) {
            auto &val = std::any_cast<Parser::Rule&>(rule.val);
            if (val.name() == Parser::Rules::Rule_group) {
                // Recursively normalize sub-rules
                auto &group_val = Parser::get::Rule_group(val);
                normalizeHelper(group_val, fullname, nested_rule_names);
            } else if (val.name() == Parser::Rules::cll) {
                auto &cll = Parser::get::cll(val);
                switch (cll.name()) {
                    case Parser::Rules::cll_if:
                    {
                        auto &block_rule = Parser::get::cll_if(cll).block;
                        auto &block = Parser::get::cll_block(block_rule);
                        normalizeHelper(block, fullname, nested_rule_names);
                        break;
                    }
                    case Parser::Rules::cll_loop_while:
                    {
                        auto &block_rule = Parser::get::cll_loop_while(cll).block;
                        auto &block = Parser::get::cll_block(block_rule);
                        normalizeHelper(block, fullname, nested_rule_names);
                        break;
                    }
                    // case Parser::Rules::cll_loop_for:
                    // {
                    //     auto &block_rule = Parser::get::cll_loop_for(cll);
                    //     auto &block = Parser::get::cll_block(block_rule);
                    //     normalizeHelper(block, fullname, nested_rule_names);
                    // } 
                    default:
                        break;
                }
            } else if (val.name() == Parser::Rules::Rule_name && val.data().type() != typeid(std::vector<std::string>)) {
                auto data = Parser::get::Rule_name(val);
    
                std::vector<std::string> rule_name;
                // if (is_nested)
                //     rule_name.assign(fullname.begin(), fullname.end());
                // rule_name.push_back(std::any_cast<std::string>(name.data));
                // for (auto &nested : nested_rule_names)
                //     rule_name.push_back(std::any_cast<std::string>(nested.data));
                
                auto res = std::find_if(nested_rule_names.begin(), nested_rule_names.end(), [&data](std::vector<std::string> &el) {
                    return el == std::vector<std::string>{Parser::get::ID(data.name)};
                });
                if (res != nested_rule_names.end()) {
                    rule_name = *res;
                } else {
                    if (!data.is_nested.empty()) {
                        rule_name.assign(fullname.begin(), fullname.end());
                    }
                    rule_name.push_back(Parser::get::ID(data.name));
                }
                for (const auto &nested : data.nested_name) {
                    rule_name.push_back(Parser::get::ID(nested));
                }
                val.data() = std::any(rule_name);
            }
        } else {
            auto val = std::any_cast<Parser::Token>(rule.val);

            if (val.name() == Parser::Tokens::Rule_OP) {
                if (!in_op) {
                    in_op = true;
                    begin = it - 1;
                    ops.push_back(*begin);
                }
                prev_op = true;
            }
        }
        if (prev_op) {
            // Add the current rule to the operator sequence
            ops.push_back(el);
            prev_op = false;
        } else if (in_op) {
            // Create a new combined rule for the operator sequence
            const auto &begin_rule = Parser::get::Rule_rule(*begin);
            auto new_token = make_token(Parser::Tokens::Rule_OP, ops);
            Parser::Types::Rule_rule_data new_rule_rule_data;
            new_rule_rule_data.prefix = begin_rule.prefix;
            new_rule_rule_data.quantifier = Parser::Rule();
            new_rule_rule_data.val = new_token;
            auto new_rule = make_rule(Parser::Rules::Rule_rule, new_rule_rule_data);
            // Replace the operator sequence in rules
            it = rules.erase(begin, it);
            it = rules.insert(it, new_rule);
            in_op = false;
            prev_op = false;
            ops.clear();
        }
    }



    // Handle remaining operator sequences at the end
    if (in_op && !ops.empty()) {
        const auto &begin_rule = Parser::get::Rule_rule(*begin);
        auto new_token = make_token(Parser::Tokens::Rule_OP, ops);
        Parser::Types::Rule_rule_data new_rule_rule_data;
        new_rule_rule_data.prefix = begin_rule.prefix;
        new_rule_rule_data.quantifier = Parser::Rule();
        new_rule_rule_data.val = new_token;
        auto new_rule = make_rule(Parser::Rules::Rule_rule, new_rule_rule_data);
        rules.erase(begin, rules.end());
        rules.push_back(new_rule);

    }
}
void Tree::normalize() {
    std::vector<std::string> fullname;
    std::vector<std::vector<std::string>> nested_rule_names;
    for (auto &[name, member] : treeMap) {
        if (fullname.empty())
            nested_rule_names.clear();
        normalizeHelper(member.rules, fullname, nested_rule_names);
    }
}